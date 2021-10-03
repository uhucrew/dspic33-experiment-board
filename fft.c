#include <xc.h>
#include <p33EP512MC202.h>

#include <dsp.h>
//#include <dsp_factors_32b.h>

#include "fft.h"
#include "window.h"
#include "spi_x.h"

#ifdef SPIBUF_IN_EDS
__eds__ extern fractional spi_da_buffer_0[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE<<1),space(xmemory),eds));
__eds__ extern fractional spi_da_buffer_1[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE<<1),space(xmemory),eds));
#else
extern fractional spi_da_buffer_0[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE<<1),space(xmemory)));
extern fractional spi_da_buffer_1[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE<<1),space(xmemory)));
#endif
extern volatile bool spi_da_buffer_empty[2];
extern fractional *spi_da_ptr;
extern fractional *spi_da_buffer_end;


fractcomplex twiddle_factors[FFT_POINTS>>1] __attribute__((aligned(FFT_POINTS<<1),space(xmemory)));
fractcomplex fft_buffer[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<2),space(ymemory),address(YMEM_BASE_FFT)));
extern fractional fft_temp_buffer[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<1),space(xmemory)));
uint16_t fft_bin_buffer[FFT_NUM_BINS] __attribute__((aligned(FFT_NUM_BINS<<1),space(xmemory)));
fractional fft_bins[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<1)));
        
volatile uint32_t fft_max_frequency;

fractcomplex twiddle_factors_ifft[IFFT_POINTS>>1] __attribute__((aligned(IFFT_POINTS<<1),space(xmemory)));
fractcomplex ifft_buffer[IFFT_POINTS] __attribute__((aligned(IFFT_POINTS<<2),space(ymemory),address(YMEM_BASE_IFFT)));
fractional ifft_bins[IFFT_POINTS] __attribute__((aligned(IFFT_POINTS<<1),space(xmemory)));

void fft_init() {
    TwidFactorInit(FFT_BITS, &twiddle_factors[0], 0);
}

//return frequency of maximum
uint32_t fft_compute() {
    int16_t fft_max_value_bin;
    fractional fft_max_value;

    apply_window(FFT_POINTS, &fft_temp_buffer[0], &fft_buffer[0]);
    FFTComplexIP(FFT_BITS, &fft_buffer[0], &twiddle_factors[0], COEFFS_IN_DATA);
    //FFTComplex32bIP(FFT_BITS, (long*)&fft_buffer[0], (long *)&twdlFctr32b[0], COEFFS_IN_DATA);
    BitReverseComplex(FFT_BITS, &fft_buffer[0]);
    SquareMagnitudeCplx(FFT_POINTS, &fft_buffer[0], &fft_bins[0]);

    fft_max_value = VectorMax(FFT_POINTS>>1, &fft_bins[0], &fft_max_value_bin);
    if (fft_max_value_bin == 0 || fft_max_value_bin >= (FFT_POINTS>>1) - 2) {
        fft_max_frequency = 0;
    }
    else {
        if (mono) {
            fft_max_frequency = fft_max_value_bin * FREQ_POINT_STEP_MONO / 10;
        }
        else {
            fft_max_frequency = fft_max_value_bin * FREQ_POINT_STEP / 10;
        }
    }
    return fft_max_frequency;
}


//buffer_copy_offset_sum(FFT_NUM_BINS, FFT_POINTS / 2 / FFT_NUM_BINS, (fractional *)&fft_bins[0], (fractional *)&fft_bin_buffer[0]);
void fft_build_bins() {
    uint16_t i, j;
    static uint16_t bin_size = FFT_POINTS / 2 / FFT_NUM_BINS;
    uint32_t bin_sum;
    uint16_t bin_max = 0;
   
    for (i = 0; i < FFT_NUM_BINS; i++) {
        bin_sum = 0;
        for (j = 0; j < bin_size; j++) {
            if (i == 0 && j == 0) continue;
            bin_sum += fft_bins[i * bin_size + j];
        }
        fft_bin_buffer[i] = (uint16_t)bin_sum;
        if ((uint16_t)bin_sum > bin_max) bin_max = (uint16_t)bin_sum;
    }

    if (bin_max <= 32) {
        return;
    }
    else {
        volatile fractional bin_scale_factor = Float2Fract(32.0 / (float)bin_max);
        for (i = 0; i < FFT_NUM_BINS; i++) {
            dsp_accA = __builtin_mpy(bin_scale_factor, fft_bin_buffer[i], NULL, NULL, 0, NULL, NULL, 0); 
            fft_bin_buffer[i] = __builtin_sac(dsp_accA, 0);
        }
    }
}


void ifft_init() {
    TwidFactorInit(IFFT_BITS, &twiddle_factors_ifft[0], 1);
}

void ifft_fill_buffer(int16_t fft_bins_start) {
    uint16_t i, offset;

    offset = 54;
    //DC component of signal
    ifft_buffer[0].real = 0;
    ifft_buffer[0].imag = 0;
    for (i = 1; i < IFFT_POINTS>>1; i++) {
        ifft_buffer[i].real = fft_buffer[i + offset].real;
        ifft_buffer[i].imag = fft_buffer[i + offset].imag;
        ifft_buffer[IFFT_POINTS - i].real = fft_buffer[i + offset].real;
        ifft_buffer[IFFT_POINTS - i].imag = fft_buffer[i + offset].imag;
    }
    return;

    //copy IFFT_POINTS / 2 and mirror in the middle of spectrum
    fft_bins_start -= 1;
    for (i = 1; i < IFFT_POINTS>>1; i++) {
        ifft_buffer[i].real = 0;//fft_bins[fft_bins_start + i];
        ifft_buffer[i].imag = 0;
        ifft_buffer[IFFT_POINTS - i].real = 0;//fft_bins[fft_bins_start + i];
        ifft_buffer[IFFT_POINTS - i].imag = 0;
    }
}

void ifft_compute() {
    IFFTComplexIP(IFFT_BITS, &ifft_buffer[0], &twiddle_factors_ifft[0], COEFFS_IN_DATA);
}

void ifft_output_buffer() {
    uint16_t i;

    for (i = 0; i < IFFT_POINTS; i++) {
        *spi_da_ptr++ = ifft_buffer[i].real<<8;
        *spi_da_ptr++ = 0;
        *spi_da_ptr++ = ifft_buffer[i].real<<8;
        *spi_da_ptr++ = 0;
    }

    if (spi_da_ptr >= spi_da_buffer_end) {
        spi_da_ptr =  spi_da_buffer_0;
    }
}

