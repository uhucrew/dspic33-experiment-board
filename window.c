#include <xc.h>
#include <dsp.h>

#include "spi_x.h"
#include "window.h"


fractional window_fn_buffer[FFT_POINTS] __attribute__((space(ymemory),address(0xc000)));

void setup_window_fn_buffer(__eds__ fractional *window_fn_buffer, __prog__ fractional *window_function_data) {
    static uint16_t i;

    for (i = 0; i < FFT_POINTS; i++) {
        window_fn_buffer[i] = window_function_data[i];
    }
}


#ifdef SPIBUF_IN_EDS
void apply_window(uint16_t points, __eds__ fractional *buffer, __eds__ fractional *outbuffer, fractional *window_fn_buffer_ptr) {
#else
void apply_window(uint16_t points, fractional *buffer, fractional *outbuffer, fractional *window_fn_buffer_ptr) {
#endif
    static uint16_t i;
    fractional buffer_val;
    fractional window_fn_buffer_val;
    volatile register int acc_a asm("A");
    
    acc_a = __builtin_clr_prefetch(&buffer, &buffer_val, 2, &window_fn_buffer_ptr, &window_fn_buffer_val, 0, 0, 0);
    for (i = 0; i < points; i++) {
        acc_a = __builtin_mpy(buffer_val, window_fn_buffer_val, &buffer, &buffer_val, 2, &window_fn_buffer_ptr, &window_fn_buffer_val, 2);
        /*
        (*outbuffer++) = __builtin_ACCH(acc_a);
        acc_a = __builtin_mpy(buffer_val, window_fn_buffer_val, &buffer, &buffer_val, 2, &window_fn_buffer_ptr, &window_fn_buffer_val, 0);
        (*outbuffer++) = __builtin_ACCH(acc_a);
        */
    }
}
