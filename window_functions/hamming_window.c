#include <xc.h>
#include <dsp.h>


__prog__ fractional hamming_window[512] __attribute__((space(auto_psv))) = {
    0x0b21,  0x0b23,  0x0b26,  0x0b2c,  0x0b33,  0x0b3e,  0x0b4a,  0x0b59,
    0x0b6a,  0x0b7d,  0x0b92,  0x0baa,  0x0bc4,  0x0be0,  0x0bfe,  0x0c1f,
    0x0c42,  0x0c67,  0x0c8e,  0x0cb8,  0x0ce3,  0x0d11,  0x0d41,  0x0d74,
    0x0da8,  0x0ddf,  0x0e17,  0x0e52,  0x0e8f,  0x0ece,  0x0f10,  0x0f53,
    0x0f99,  0x0fe0,  0x102a,  0x1075,  0x10c3,  0x1113,  0x1165,  0x11b9,
    0x120f,  0x1266,  0x12c0,  0x131c,  0x137a,  0x13da,  0x143b,  0x149f,
    0x1504,  0x156b,  0x15d5,  0x1640,  0x16ac,  0x171b,  0x178c,  0x17fe,
    0x1872,  0x18e8,  0x195f,  0x19d8,  0x1a53,  0x1ad0,  0x1b4e,  0x1bce,
    0x1c4f,  0x1cd2,  0x1d57,  0x1ddd,  0x1e65,  0x1eee,  0x1f79,  0x2005,
    0x2093,  0x2122,  0x21b2,  0x2244,  0x22d7,  0x236c,  0x2402,  0x2499,
    0x2532,  0x25cb,  0x2666,  0x2703,  0x27a0,  0x283f,  0x28de,  0x297f,
    0x2a21,  0x2ac4,  0x2b68,  0x2c0d,  0x2cb3,  0x2d5a,  0x2e01,  0x2eaa,
    0x2f54,  0x2ffe,  0x30aa,  0x3156,  0x3203,  0x32b1,  0x335f,  0x340e,
    0x34be,  0x356e,  0x3620,  0x36d1,  0x3784,  0x3836,  0x38ea,  0x399d,
    0x3a52,  0x3b06,  0x3bbc,  0x3c71,  0x3d27,  0x3ddd,  0x3e94,  0x3f4a,
    0x4001,  0x40b9,  0x4170,  0x4227,  0x42df,  0x4397,  0x444f,  0x4507,
    0x45bf,  0x4677,  0x472f,  0x47e6,  0x489e,  0x4956,  0x4a0d,  0x4ac4,
    0x4b7c,  0x4c32,  0x4ce9,  0x4d9f,  0x4e55,  0x4f0b,  0x4fc0,  0x5075,
    0x512a,  0x51de,  0x5291,  0x5345,  0x53f7,  0x54a9,  0x555a,  0x560b,
    0x56bb,  0x576b,  0x581a,  0x58c8,  0x5975,  0x5a22,  0x5acd,  0x5b78,
    0x5c22,  0x5ccc,  0x5d74,  0x5e1b,  0x5ec2,  0x5f67,  0x600c,  0x60af,
    0x6152,  0x61f3,  0x6293,  0x6332,  0x63d0,  0x646d,  0x6509,  0x65a3,
    0x663c,  0x66d4,  0x676b,  0x6800,  0x6894,  0x6926,  0x69b8,  0x6a47,
    0x6ad6,  0x6b63,  0x6bee,  0x6c78,  0x6d01,  0x6d88,  0x6e0d,  0x6e91,
    0x6f13,  0x6f94,  0x7013,  0x7090,  0x710c,  0x7186,  0x71fe,  0x7275,
    0x72ea,  0x735d,  0x73ce,  0x743e,  0x74ac,  0x7518,  0x7582,  0x75ea,
    0x7650,  0x76b5,  0x7717,  0x7778,  0x77d7,  0x7833,  0x788e,  0x78e7,
    0x793e,  0x7993,  0x79e6,  0x7a37,  0x7a85,  0x7ad2,  0x7b1d,  0x7b65,
    0x7bac,  0x7bf0,  0x7c33,  0x7c73,  0x7cb1,  0x7ced,  0x7d27,  0x7d5e,
    0x7d94,  0x7dc7,  0x7df8,  0x7e27,  0x7e54,  0x7e7f,  0x7ea7,  0x7ecd,
    0x7ef1,  0x7f13,  0x7f32,  0x7f50,  0x7f6b,  0x7f83,  0x7f9a,  0x7fae,
    0x7fc0,  0x7fd0,  0x7fde,  0x7fe9,  0x7ff2,  0x7ff9,  0x7ffd,  0x7fff,
    0x7fff,  0x7ffd,  0x7ff9,  0x7ff2,  0x7fe9,  0x7fde,  0x7fd0,  0x7fc0,
    0x7fae,  0x7f9a,  0x7f83,  0x7f6b,  0x7f50,  0x7f32,  0x7f13,  0x7ef1,
    0x7ecd,  0x7ea7,  0x7e7f,  0x7e54,  0x7e27,  0x7df8,  0x7dc7,  0x7d94,
    0x7d5e,  0x7d27,  0x7ced,  0x7cb1,  0x7c73,  0x7c33,  0x7bf0,  0x7bac,
    0x7b65,  0x7b1d,  0x7ad2,  0x7a85,  0x7a37,  0x79e6,  0x7993,  0x793e,
    0x78e7,  0x788e,  0x7833,  0x77d7,  0x7778,  0x7717,  0x76b5,  0x7650,
    0x75ea,  0x7582,  0x7518,  0x74ac,  0x743e,  0x73ce,  0x735d,  0x72ea,
    0x7275,  0x71fe,  0x7186,  0x710c,  0x7090,  0x7013,  0x6f94,  0x6f13,
    0x6e91,  0x6e0d,  0x6d88,  0x6d01,  0x6c78,  0x6bee,  0x6b63,  0x6ad6,
    0x6a47,  0x69b8,  0x6926,  0x6894,  0x6800,  0x676b,  0x66d4,  0x663c,
    0x65a3,  0x6509,  0x646d,  0x63d0,  0x6332,  0x6293,  0x61f3,  0x6152,
    0x60af,  0x600c,  0x5f67,  0x5ec2,  0x5e1b,  0x5d74,  0x5ccc,  0x5c22,
    0x5b78,  0x5acd,  0x5a22,  0x5975,  0x58c8,  0x581a,  0x576b,  0x56bb,
    0x560b,  0x555a,  0x54a9,  0x53f7,  0x5345,  0x5291,  0x51de,  0x512a,
    0x5075,  0x4fc0,  0x4f0b,  0x4e55,  0x4d9f,  0x4ce9,  0x4c32,  0x4b7c,
    0x4ac4,  0x4a0d,  0x4956,  0x489e,  0x47e6,  0x472f,  0x4677,  0x45bf,
    0x4507,  0x444f,  0x4397,  0x42df,  0x4227,  0x4170,  0x40b9,  0x4001,
    0x3f4a,  0x3e94,  0x3ddd,  0x3d27,  0x3c71,  0x3bbc,  0x3b06,  0x3a52,
    0x399d,  0x38ea,  0x3836,  0x3784,  0x36d1,  0x3620,  0x356e,  0x34be,
    0x340e,  0x335f,  0x32b1,  0x3203,  0x3156,  0x30aa,  0x2ffe,  0x2f54,
    0x2eaa,  0x2e01,  0x2d5a,  0x2cb3,  0x2c0d,  0x2b68,  0x2ac4,  0x2a21,
    0x297f,  0x28de,  0x283f,  0x27a0,  0x2703,  0x2666,  0x25cb,  0x2532,
    0x2499,  0x2402,  0x236c,  0x22d7,  0x2244,  0x21b2,  0x2122,  0x2093,
    0x2005,  0x1f79,  0x1eee,  0x1e65,  0x1ddd,  0x1d57,  0x1cd2,  0x1c4f,
    0x1bce,  0x1b4e,  0x1ad0,  0x1a53,  0x19d8,  0x195f,  0x18e8,  0x1872,
    0x17fe,  0x178c,  0x171b,  0x16ac,  0x1640,  0x15d5,  0x156b,  0x1504,
    0x149f,  0x143b,  0x13da,  0x137a,  0x131c,  0x12c0,  0x1266,  0x120f,
    0x11b9,  0x1165,  0x1113,  0x10c3,  0x1075,  0x102a,  0x0fe0,  0x0f99,
    0x0f53,  0x0f10,  0x0ece,  0x0e8f,  0x0e52,  0x0e17,  0x0ddf,  0x0da8,
    0x0d74,  0x0d41,  0x0d11,  0x0ce3,  0x0cb8,  0x0c8e,  0x0c67,  0x0c42,
    0x0c1f,  0x0bfe,  0x0be0,  0x0bc4,  0x0baa,  0x0b92,  0x0b7d,  0x0b6a,
    0x0b59,  0x0b4a,  0x0b3e,  0x0b33,  0x0b2c,  0x0b26,  0x0b23,  0x0b21
};
