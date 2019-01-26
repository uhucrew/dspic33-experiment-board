#include <xc.h>
#include <p33EP512MC202.h>

#include <dsp.h>

#include "fft.h"


fractcomplex twiddle_factors[FFT_POINTS / 2] __attribute__((aligned(FFT_POINTS<<1),space(xmemory)));
fractcomplex fft_buffer[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<2),space(ymemory),address(YMEM_BASE)));
uint16_t fft_bin_buffer[FFT_NUM_BINS] __attribute__((aligned(FFT_NUM_BINS),space(xmemory)));
fractional fft_bins[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<1)));

void fft_init() {
    TwidFactorInit(FFT_BITS, &twiddle_factors[0], 0);
}


void fft_compute() {
    FFTComplexIP(FFT_BITS, &fft_buffer[0], &twiddle_factors[0], COEFFS_IN_DATA);
    BitReverseComplex(FFT_BITS, &fft_buffer[0]);
    SquareMagnitudeCplx(FFT_POINTS, &fft_buffer[0], &fft_bins[0]);
}



void fft_build_bins() {
    uint16_t i, j;
    static uint16_t bin_offset = FFT_POINTS / FFT_NUM_BINS;
    uint32_t bin_sum;
    for (i = 0; i < FFT_NUM_BINS; i++) {
        fft_bin_buffer[i] = (fractional)(&fft_buffer[0])[i].real;
        fft_buffer[i].imag = (fractional)(&fft_buffer[0])[i].real;
        continue;
        bin_sum = 0;
        for (j = 0; j < bin_offset; j++) {
            bin_sum += fft_buffer[i * bin_offset + j].real;
        }
        fft_bin_buffer[i] = (uint16_t)(bin_sum>>3);
    }
}
