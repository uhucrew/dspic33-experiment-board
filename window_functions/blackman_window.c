#include <xc.h>
#include <dsp.h>


__prog__ fractional blackman_window[1024] __attribute__((space(prog))) = {
    0x0000,  0x0000,  0x0000,  0x0001,  0x0002,  0x0003,  0x0004,  0x0005,
    0x0007,  0x0009,  0x000b,  0x000d,  0x0010,  0x0013,  0x0016,  0x0019,
    0x001d,  0x0020,  0x0024,  0x0028,  0x002d,  0x0031,  0x0036,  0x003b,
    0x0041,  0x0046,  0x004c,  0x0052,  0x0058,  0x005f,  0x0065,  0x006c,
    0x0073,  0x007b,  0x0083,  0x008b,  0x0093,  0x009b,  0x00a4,  0x00ad,
    0x00b6,  0x00bf,  0x00c9,  0x00d3,  0x00dd,  0x00e7,  0x00f2,  0x00fd,
    0x0108,  0x0114,  0x011f,  0x012b,  0x0138,  0x0144,  0x0151,  0x015e,
    0x016b,  0x0179,  0x0187,  0x0195,  0x01a4,  0x01b2,  0x01c1,  0x01d1,
    0x01e0,  0x01f0,  0x0200,  0x0211,  0x0222,  0x0233,  0x0244,  0x0256,
    0x0268,  0x027a,  0x028d,  0x02a0,  0x02b3,  0x02c7,  0x02da,  0x02ef,
    0x0303,  0x0318,  0x032d,  0x0343,  0x0359,  0x036f,  0x0385,  0x039c,
    0x03b3,  0x03cb,  0x03e3,  0x03fb,  0x0414,  0x042c,  0x0446,  0x045f,
    0x0479,  0x0494,  0x04af,  0x04ca,  0x04e5,  0x0501,  0x051d,  0x053a,
    0x0557,  0x0574,  0x0592,  0x05b0,  0x05ce,  0x05ed,  0x060d,  0x062c,
    0x064d,  0x066d,  0x068e,  0x06af,  0x06d1,  0x06f3,  0x0716,  0x0739,
    0x075c,  0x0780,  0x07a4,  0x07c9,  0x07ee,  0x0813,  0x0839,  0x085f,
    0x0886,  0x08ad,  0x08d5,  0x08fd,  0x0926,  0x094f,  0x0978,  0x09a2,
    0x09cc,  0x09f7,  0x0a23,  0x0a4e,  0x0a7a,  0x0aa7,  0x0ad4,  0x0b02,
    0x0b30,  0x0b5e,  0x0b8d,  0x0bbd,  0x0bed,  0x0c1d,  0x0c4e,  0x0c7f,
    0x0cb1,  0x0ce3,  0x0d16,  0x0d4a,  0x0d7d,  0x0db2,  0x0de6,  0x0e1c,
    0x0e51,  0x0e88,  0x0ebe,  0x0ef6,  0x0f2d,  0x0f66,  0x0f9e,  0x0fd8,
    0x1011,  0x104c,  0x1086,  0x10c2,  0x10fd,  0x113a,  0x1176,  0x11b4,
    0x11f1,  0x1230,  0x126f,  0x12ae,  0x12ee,  0x132e,  0x136f,  0x13b0,
    0x13f2,  0x1435,  0x1478,  0x14bb,  0x14ff,  0x1544,  0x1589,  0x15ce,
    0x1614,  0x165b,  0x16a2,  0x16e9,  0x1732,  0x177a,  0x17c3,  0x180d,
    0x1857,  0x18a2,  0x18ed,  0x1939,  0x1985,  0x19d2,  0x1a1f,  0x1a6d,
    0x1abb,  0x1b0a,  0x1b59,  0x1ba9,  0x1bf9,  0x1c4a,  0x1c9b,  0x1ced,
    0x1d3f,  0x1d92,  0x1de5,  0x1e39,  0x1e8d,  0x1ee2,  0x1f37,  0x1f8d,
    0x1fe3,  0x203a,  0x2091,  0x20e9,  0x2141,  0x219a,  0x21f3,  0x224c,
    0x22a6,  0x2301,  0x235c,  0x23b7,  0x2413,  0x2470,  0x24cd,  0x252a,
    0x2588,  0x25e6,  0x2644,  0x26a3,  0x2703,  0x2763,  0x27c3,  0x2824,
    0x2885,  0x28e7,  0x2949,  0x29ac,  0x2a0f,  0x2a72,  0x2ad6,  0x2b3a,
    0x2b9e,  0x2c03,  0x2c69,  0x2cce,  0x2d34,  0x2d9b,  0x2e02,  0x2e69,
    0x2ed0,  0x2f38,  0x2fa1,  0x3009,  0x3072,  0x30dc,  0x3145,  0x31af,
    0x321a,  0x3284,  0x32ef,  0x335b,  0x33c6,  0x3432,  0x349e,  0x350b,
    0x3578,  0x35e5,  0x3652,  0x36c0,  0x372e,  0x379c,  0x380b,  0x3879,
    0x38e8,  0x3957,  0x39c7,  0x3a37,  0x3aa6,  0x3b17,  0x3b87,  0x3bf8,
    0x3c68,  0x3cd9,  0x3d4a,  0x3dbc,  0x3e2d,  0x3e9f,  0x3f11,  0x3f83,
    0x3ff5,  0x4067,  0x40da,  0x414c,  0x41bf,  0x4232,  0x42a5,  0x4318,
    0x438b,  0x43fe,  0x4471,  0x44e5,  0x4558,  0x45cc,  0x4640,  0x46b3,
    0x4727,  0x479b,  0x480f,  0x4882,  0x48f6,  0x496a,  0x49de,  0x4a52,
    0x4ac6,  0x4b3a,  0x4bad,  0x4c21,  0x4c95,  0x4d09,  0x4d7c,  0x4df0,
    0x4e63,  0x4ed7,  0x4f4a,  0x4fbe,  0x5031,  0x50a4,  0x5117,  0x518a,
    0x51fc,  0x526f,  0x52e1,  0x5354,  0x53c6,  0x5438,  0x54aa,  0x551b,
    0x558d,  0x55fe,  0x566f,  0x56e0,  0x5751,  0x57c1,  0x5831,  0x58a1,
    0x5911,  0x5980,  0x59ef,  0x5a5e,  0x5acd,  0x5b3b,  0x5ba9,  0x5c17,
    0x5c84,  0x5cf1,  0x5d5e,  0x5dcb,  0x5e37,  0x5ea2,  0x5f0e,  0x5f79,
    0x5fe4,  0x604e,  0x60b8,  0x6121,  0x618a,  0x61f3,  0x625b,  0x62c3,
    0x632b,  0x6391,  0x63f8,  0x645e,  0x64c4,  0x6529,  0x658d,  0x65f2,
    0x6655,  0x66b9,  0x671b,  0x677d,  0x67df,  0x6840,  0x68a1,  0x6901,
    0x6960,  0x69bf,  0x6a1d,  0x6a7b,  0x6ad8,  0x6b35,  0x6b91,  0x6bed,
    0x6c47,  0x6ca2,  0x6cfb,  0x6d54,  0x6dac,  0x6e04,  0x6e5b,  0x6eb2,
    0x6f07,  0x6f5c,  0x6fb1,  0x7004,  0x7057,  0x70aa,  0x70fb,  0x714c,
    0x719c,  0x71ec,  0x723b,  0x7289,  0x72d6,  0x7323,  0x736e,  0x73b9,
    0x7404,  0x744d,  0x7496,  0x74de,  0x7525,  0x756b,  0x75b1,  0x75f6,
    0x763a,  0x767d,  0x76bf,  0x7701,  0x7741,  0x7781,  0x77c0,  0x77fe,
    0x783c,  0x7878,  0x78b4,  0x78ef,  0x7929,  0x7962,  0x799a,  0x79d1,
    0x7a07,  0x7a3d,  0x7a71,  0x7aa5,  0x7ad8,  0x7b0a,  0x7b3b,  0x7b6b,
    0x7b9a,  0x7bc8,  0x7bf5,  0x7c22,  0x7c4d,  0x7c78,  0x7ca1,  0x7cca,
    0x7cf2,  0x7d18,  0x7d3e,  0x7d63,  0x7d87,  0x7daa,  0x7dcc,  0x7ded,
    0x7e0d,  0x7e2c,  0x7e4a,  0x7e67,  0x7e83,  0x7e9e,  0x7eb8,  0x7ed1,
    0x7ee9,  0x7f00,  0x7f16,  0x7f2c,  0x7f40,  0x7f53,  0x7f65,  0x7f76,
    0x7f86,  0x7f96,  0x7fa4,  0x7fb1,  0x7fbd,  0x7fc8,  0x7fd2,  0x7fdb,
    0x7fe4,  0x7feb,  0x7ff1,  0x7ff6,  0x7ffa,  0x7ffd,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7ffd,  0x7ffa,  0x7ff6,  0x7ff1,  0x7feb,  0x7fe4,
    0x7fdb,  0x7fd2,  0x7fc8,  0x7fbd,  0x7fb1,  0x7fa4,  0x7f96,  0x7f86,
    0x7f76,  0x7f65,  0x7f53,  0x7f40,  0x7f2c,  0x7f16,  0x7f00,  0x7ee9,
    0x7ed1,  0x7eb8,  0x7e9e,  0x7e83,  0x7e67,  0x7e4a,  0x7e2c,  0x7e0d,
    0x7ded,  0x7dcc,  0x7daa,  0x7d87,  0x7d63,  0x7d3e,  0x7d18,  0x7cf2,
    0x7cca,  0x7ca1,  0x7c78,  0x7c4d,  0x7c22,  0x7bf5,  0x7bc8,  0x7b9a,
    0x7b6b,  0x7b3b,  0x7b0a,  0x7ad8,  0x7aa5,  0x7a71,  0x7a3d,  0x7a07,
    0x79d1,  0x799a,  0x7962,  0x7929,  0x78ef,  0x78b4,  0x7878,  0x783c,
    0x77fe,  0x77c0,  0x7781,  0x7741,  0x7701,  0x76bf,  0x767d,  0x763a,
    0x75f6,  0x75b1,  0x756b,  0x7525,  0x74de,  0x7496,  0x744d,  0x7404,
    0x73b9,  0x736e,  0x7323,  0x72d6,  0x7289,  0x723b,  0x71ec,  0x719c,
    0x714c,  0x70fb,  0x70aa,  0x7057,  0x7004,  0x6fb1,  0x6f5c,  0x6f07,
    0x6eb2,  0x6e5b,  0x6e04,  0x6dac,  0x6d54,  0x6cfb,  0x6ca2,  0x6c47,
    0x6bed,  0x6b91,  0x6b35,  0x6ad8,  0x6a7b,  0x6a1d,  0x69bf,  0x6960,
    0x6901,  0x68a1,  0x6840,  0x67df,  0x677d,  0x671b,  0x66b9,  0x6655,
    0x65f2,  0x658d,  0x6529,  0x64c4,  0x645e,  0x63f8,  0x6391,  0x632b,
    0x62c3,  0x625b,  0x61f3,  0x618a,  0x6121,  0x60b8,  0x604e,  0x5fe4,
    0x5f79,  0x5f0e,  0x5ea2,  0x5e37,  0x5dcb,  0x5d5e,  0x5cf1,  0x5c84,
    0x5c17,  0x5ba9,  0x5b3b,  0x5acd,  0x5a5e,  0x59ef,  0x5980,  0x5911,
    0x58a1,  0x5831,  0x57c1,  0x5751,  0x56e0,  0x566f,  0x55fe,  0x558d,
    0x551b,  0x54aa,  0x5438,  0x53c6,  0x5354,  0x52e1,  0x526f,  0x51fc,
    0x518a,  0x5117,  0x50a4,  0x5031,  0x4fbe,  0x4f4a,  0x4ed7,  0x4e63,
    0x4df0,  0x4d7c,  0x4d09,  0x4c95,  0x4c21,  0x4bad,  0x4b3a,  0x4ac6,
    0x4a52,  0x49de,  0x496a,  0x48f6,  0x4882,  0x480f,  0x479b,  0x4727,
    0x46b3,  0x4640,  0x45cc,  0x4558,  0x44e5,  0x4471,  0x43fe,  0x438b,
    0x4318,  0x42a5,  0x4232,  0x41bf,  0x414c,  0x40da,  0x4067,  0x3ff5,
    0x3f83,  0x3f11,  0x3e9f,  0x3e2d,  0x3dbc,  0x3d4a,  0x3cd9,  0x3c68,
    0x3bf8,  0x3b87,  0x3b17,  0x3aa6,  0x3a37,  0x39c7,  0x3957,  0x38e8,
    0x3879,  0x380b,  0x379c,  0x372e,  0x36c0,  0x3652,  0x35e5,  0x3578,
    0x350b,  0x349e,  0x3432,  0x33c6,  0x335b,  0x32ef,  0x3284,  0x321a,
    0x31af,  0x3145,  0x30dc,  0x3072,  0x3009,  0x2fa1,  0x2f38,  0x2ed0,
    0x2e69,  0x2e02,  0x2d9b,  0x2d34,  0x2cce,  0x2c69,  0x2c03,  0x2b9e,
    0x2b3a,  0x2ad6,  0x2a72,  0x2a0f,  0x29ac,  0x2949,  0x28e7,  0x2885,
    0x2824,  0x27c3,  0x2763,  0x2703,  0x26a3,  0x2644,  0x25e6,  0x2588,
    0x252a,  0x24cd,  0x2470,  0x2413,  0x23b7,  0x235c,  0x2301,  0x22a6,
    0x224c,  0x21f3,  0x219a,  0x2141,  0x20e9,  0x2091,  0x203a,  0x1fe3,
    0x1f8d,  0x1f37,  0x1ee2,  0x1e8d,  0x1e39,  0x1de5,  0x1d92,  0x1d3f,
    0x1ced,  0x1c9b,  0x1c4a,  0x1bf9,  0x1ba9,  0x1b59,  0x1b0a,  0x1abb,
    0x1a6d,  0x1a1f,  0x19d2,  0x1985,  0x1939,  0x18ed,  0x18a2,  0x1857,
    0x180d,  0x17c3,  0x177a,  0x1732,  0x16e9,  0x16a2,  0x165b,  0x1614,
    0x15ce,  0x1589,  0x1544,  0x14ff,  0x14bb,  0x1478,  0x1435,  0x13f2,
    0x13b0,  0x136f,  0x132e,  0x12ee,  0x12ae,  0x126f,  0x1230,  0x11f1,
    0x11b4,  0x1176,  0x113a,  0x10fd,  0x10c2,  0x1086,  0x104c,  0x1011,
    0x0fd8,  0x0f9e,  0x0f66,  0x0f2d,  0x0ef6,  0x0ebe,  0x0e88,  0x0e51,
    0x0e1c,  0x0de6,  0x0db2,  0x0d7d,  0x0d4a,  0x0d16,  0x0ce3,  0x0cb1,
    0x0c7f,  0x0c4e,  0x0c1d,  0x0bed,  0x0bbd,  0x0b8d,  0x0b5e,  0x0b30,
    0x0b02,  0x0ad4,  0x0aa7,  0x0a7a,  0x0a4e,  0x0a23,  0x09f7,  0x09cc,
    0x09a2,  0x0978,  0x094f,  0x0926,  0x08fd,  0x08d5,  0x08ad,  0x0886,
    0x085f,  0x0839,  0x0813,  0x07ee,  0x07c9,  0x07a4,  0x0780,  0x075c,
    0x0739,  0x0716,  0x06f3,  0x06d1,  0x06af,  0x068e,  0x066d,  0x064d,
    0x062c,  0x060d,  0x05ed,  0x05ce,  0x05b0,  0x0592,  0x0574,  0x0557,
    0x053a,  0x051d,  0x0501,  0x04e5,  0x04ca,  0x04af,  0x0494,  0x0479,
    0x045f,  0x0446,  0x042c,  0x0414,  0x03fb,  0x03e3,  0x03cb,  0x03b3,
    0x039c,  0x0385,  0x036f,  0x0359,  0x0343,  0x032d,  0x0318,  0x0303,
    0x02ef,  0x02da,  0x02c7,  0x02b3,  0x02a0,  0x028d,  0x027a,  0x0268,
    0x0256,  0x0244,  0x0233,  0x0222,  0x0211,  0x0200,  0x01f0,  0x01e0,
    0x01d1,  0x01c1,  0x01b2,  0x01a4,  0x0195,  0x0187,  0x0179,  0x016b,
    0x015e,  0x0151,  0x0144,  0x0138,  0x012b,  0x011f,  0x0114,  0x0108,
    0x00fd,  0x00f2,  0x00e7,  0x00dd,  0x00d3,  0x00c9,  0x00bf,  0x00b6,
    0x00ad,  0x00a4,  0x009b,  0x0093,  0x008b,  0x0083,  0x007b,  0x0073,
    0x006c,  0x0065,  0x005f,  0x0058,  0x0052,  0x004c,  0x0046,  0x0041,
    0x003b,  0x0036,  0x0031,  0x002d,  0x0028,  0x0024,  0x0020,  0x001d,
    0x0019,  0x0016,  0x0013,  0x0010,  0x000d,  0x000b,  0x0009,  0x0007,
    0x0005,  0x0004,  0x0003,  0x0002,  0x0001,  0x0000,  0x0000,  0x0000
};
