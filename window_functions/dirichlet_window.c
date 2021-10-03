#include <xc.h>
#include <dsp.h>


__prog__ fractional dirichlet_window[1024] __attribute__((space(prog))) = {
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff
};
