#include <xc.h>
#include <p33EP512MC202.h>

#include "SSD1306/lcd.h"


void show_fft_range(int16_t start, uint16_t marker) {
    fb_clear_rectangle(0, 25, 127, 31);

    if (start < 0) start = 0;
    if (start > 96) start = 96;
    fb_draw_v_line(start, 26, 5, 1);
    fb_draw_v_line(start + 31, 26, 5, 1);
    fb_draw_h_line(start, 28, 32, 1);

    if (marker != 0) {
        fb_draw_v_line(marker, 26, 5, 1);
    }
}
