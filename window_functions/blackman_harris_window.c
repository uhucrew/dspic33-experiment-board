#include <xc.h>
#include <dsp.h>


__prog__ fractional blackman_harris_window[512] __attribute__((space(auto_psv))) = {
    0x0002,  0x0002,  0x0002,  0x0003,  0x0003,  0x0004,  0x0005,  0x0005,
    0x0007,  0x0008,  0x0009,  0x000b,  0x000d,  0x000f,  0x0011,  0x0013,
    0x0016,  0x0018,  0x001b,  0x001f,  0x0022,  0x0026,  0x002a,  0x002e,
    0x0033,  0x0038,  0x003d,  0x0043,  0x0049,  0x004f,  0x0056,  0x005d,
    0x0065,  0x006d,  0x0075,  0x007e,  0x0088,  0x0092,  0x009d,  0x00a8,
    0x00b4,  0x00c0,  0x00ce,  0x00db,  0x00ea,  0x00f9,  0x0109,  0x011a,
    0x012c,  0x013e,  0x0152,  0x0166,  0x017b,  0x0191,  0x01a8,  0x01c0,
    0x01da,  0x01f4,  0x020f,  0x022c,  0x0249,  0x0268,  0x0288,  0x02aa,
    0x02cd,  0x02f1,  0x0316,  0x033d,  0x0365,  0x038f,  0x03bb,  0x03e8,
    0x0416,  0x0446,  0x0478,  0x04ab,  0x04e1,  0x0518,  0x0550,  0x058b,
    0x05c8,  0x0606,  0x0646,  0x0689,  0x06cd,  0x0713,  0x075c,  0x07a7,
    0x07f3,  0x0842,  0x0893,  0x08e7,  0x093c,  0x0994,  0x09ef,  0x0a4b,
    0x0aab,  0x0b0c,  0x0b70,  0x0bd7,  0x0c40,  0x0cab,  0x0d19,  0x0d8a,
    0x0dfd,  0x0e73,  0x0eec,  0x0f67,  0x0fe5,  0x1065,  0x10e9,  0x116f,
    0x11f8,  0x1283,  0x1312,  0x13a3,  0x1437,  0x14ce,  0x1568,  0x1604,
    0x16a3,  0x1746,  0x17eb,  0x1892,  0x193d,  0x19ea,  0x1a9b,  0x1b4e,
    0x1c04,  0x1cbd,  0x1d78,  0x1e36,  0x1ef7,  0x1fbb,  0x2082,  0x214b,
    0x2217,  0x22e5,  0x23b6,  0x248a,  0x2560,  0x2639,  0x2715,  0x27f2,
    0x28d3,  0x29b5,  0x2a9a,  0x2b82,  0x2c6b,  0x2d57,  0x2e45,  0x2f35,
    0x3027,  0x311b,  0x3211,  0x3309,  0x3403,  0x34ff,  0x35fc,  0x36fb,
    0x37fc,  0x38fe,  0x3a01,  0x3b06,  0x3c0c,  0x3d14,  0x3e1c,  0x3f26,
    0x4031,  0x413c,  0x4249,  0x4356,  0x4463,  0x4572,  0x4681,  0x4790,
    0x489f,  0x49af,  0x4abf,  0x4bce,  0x4cde,  0x4dee,  0x4efd,  0x500c,
    0x511a,  0x5228,  0x5336,  0x5442,  0x554e,  0x5658,  0x5762,  0x586a,
    0x5971,  0x5a77,  0x5b7b,  0x5c7e,  0x5d7f,  0x5e7e,  0x5f7b,  0x6077,
    0x6170,  0x6267,  0x635b,  0x644d,  0x653d,  0x662a,  0x6715,  0x67fc,
    0x68e1,  0x69c2,  0x6aa1,  0x6b7c,  0x6c54,  0x6d28,  0x6dfa,  0x6ec7,
    0x6f91,  0x7057,  0x7119,  0x71d7,  0x7291,  0x7347,  0x73f9,  0x74a6,
    0x754f,  0x75f4,  0x7694,  0x7730,  0x77c6,  0x7859,  0x78e6,  0x796e,
    0x79f2,  0x7a70,  0x7aea,  0x7b5e,  0x7bcd,  0x7c37,  0x7c9c,  0x7cfb,
    0x7d55,  0x7daa,  0x7df9,  0x7e42,  0x7e86,  0x7ec5,  0x7efe,  0x7f31,
    0x7f5f,  0x7f87,  0x7fa9,  0x7fc6,  0x7fdd,  0x7fee,  0x7ffa,  0x7fff,
    0x7fff,  0x7ffa,  0x7fee,  0x7fdd,  0x7fc6,  0x7fa9,  0x7f87,  0x7f5f,
    0x7f31,  0x7efe,  0x7ec5,  0x7e86,  0x7e42,  0x7df9,  0x7daa,  0x7d55,
    0x7cfb,  0x7c9c,  0x7c37,  0x7bcd,  0x7b5e,  0x7aea,  0x7a70,  0x79f2,
    0x796e,  0x78e6,  0x7859,  0x77c6,  0x7730,  0x7694,  0x75f4,  0x754f,
    0x74a6,  0x73f9,  0x7347,  0x7291,  0x71d7,  0x7119,  0x7057,  0x6f91,
    0x6ec7,  0x6dfa,  0x6d28,  0x6c54,  0x6b7c,  0x6aa1,  0x69c2,  0x68e1,
    0x67fc,  0x6715,  0x662a,  0x653d,  0x644d,  0x635b,  0x6267,  0x6170,
    0x6077,  0x5f7b,  0x5e7e,  0x5d7f,  0x5c7e,  0x5b7b,  0x5a77,  0x5971,
    0x586a,  0x5762,  0x5658,  0x554e,  0x5442,  0x5336,  0x5228,  0x511a,
    0x500c,  0x4efd,  0x4dee,  0x4cde,  0x4bce,  0x4abf,  0x49af,  0x489f,
    0x4790,  0x4681,  0x4572,  0x4463,  0x4356,  0x4249,  0x413c,  0x4031,
    0x3f26,  0x3e1c,  0x3d14,  0x3c0c,  0x3b06,  0x3a01,  0x38fe,  0x37fc,
    0x36fb,  0x35fc,  0x34ff,  0x3403,  0x3309,  0x3211,  0x311b,  0x3027,
    0x2f35,  0x2e45,  0x2d57,  0x2c6b,  0x2b82,  0x2a9a,  0x29b5,  0x28d3,
    0x27f2,  0x2715,  0x2639,  0x2560,  0x248a,  0x23b6,  0x22e5,  0x2217,
    0x214b,  0x2082,  0x1fbb,  0x1ef7,  0x1e36,  0x1d78,  0x1cbd,  0x1c04,
    0x1b4e,  0x1a9b,  0x19ea,  0x193d,  0x1892,  0x17eb,  0x1746,  0x16a3,
    0x1604,  0x1568,  0x14ce,  0x1437,  0x13a3,  0x1312,  0x1283,  0x11f8,
    0x116f,  0x10e9,  0x1065,  0x0fe5,  0x0f67,  0x0eec,  0x0e73,  0x0dfd,
    0x0d8a,  0x0d19,  0x0cab,  0x0c40,  0x0bd7,  0x0b70,  0x0b0c,  0x0aab,
    0x0a4b,  0x09ef,  0x0994,  0x093c,  0x08e7,  0x0893,  0x0842,  0x07f3,
    0x07a7,  0x075c,  0x0713,  0x06cd,  0x0689,  0x0646,  0x0606,  0x05c8,
    0x058b,  0x0550,  0x0518,  0x04e1,  0x04ab,  0x0478,  0x0446,  0x0416,
    0x03e8,  0x03bb,  0x038f,  0x0365,  0x033d,  0x0316,  0x02f1,  0x02cd,
    0x02aa,  0x0288,  0x0268,  0x0249,  0x022c,  0x020f,  0x01f4,  0x01da,
    0x01c0,  0x01a8,  0x0191,  0x017b,  0x0166,  0x0152,  0x013e,  0x012c,
    0x011a,  0x0109,  0x00f9,  0x00ea,  0x00db,  0x00ce,  0x00c0,  0x00b4,
    0x00a8,  0x009d,  0x0092,  0x0088,  0x007e,  0x0075,  0x006d,  0x0065,
    0x005d,  0x0056,  0x004f,  0x0049,  0x0043,  0x003d,  0x0038,  0x0033,
    0x002e,  0x002a,  0x0026,  0x0022,  0x001f,  0x001b,  0x0018,  0x0016,
    0x0013,  0x0011,  0x000f,  0x000d,  0x000b,  0x0009,  0x0008,  0x0007,
    0x0005,  0x0005,  0x0004,  0x0003,  0x0003,  0x0002,  0x0002,  0x0002
};
