#include <xc.h>
#include <dsp.h>


__prog__ fractional kaiser_window[512] __attribute__((space(auto_psv))) = {
    0x0000,  0x0000,  0x0000,  0x0000,  0x0000,  0x0000,  0x0000,  0x0000,
    0x0000,  0x0001,  0x0001,  0x0001,  0x0001,  0x0001,  0x0001,  0x0002,
    0x0002,  0x0002,  0x0002,  0x0003,  0x0003,  0x0004,  0x0004,  0x0005,
    0x0005,  0x0006,  0x0007,  0x0008,  0x0008,  0x0009,  0x000b,  0x000c,
    0x000d,  0x000e,  0x0010,  0x0012,  0x0014,  0x0016,  0x0018,  0x001a,
    0x001c,  0x001f,  0x0022,  0x0025,  0x0029,  0x002c,  0x0030,  0x0034,
    0x0039,  0x003e,  0x0043,  0x0048,  0x004e,  0x0055,  0x005b,  0x0062,
    0x006a,  0x0072,  0x007b,  0x0084,  0x008d,  0x0097,  0x00a2,  0x00ae,
    0x00ba,  0x00c7,  0x00d4,  0x00e2,  0x00f2,  0x0101,  0x0112,  0x0124,
    0x0136,  0x014a,  0x015e,  0x0174,  0x018b,  0x01a2,  0x01bb,  0x01d5,
    0x01f0,  0x020d,  0x022b,  0x024a,  0x026b,  0x028d,  0x02b1,  0x02d6,
    0x02fd,  0x0325,  0x034f,  0x037b,  0x03a9,  0x03d8,  0x040a,  0x043d,
    0x0472,  0x04aa,  0x04e3,  0x051f,  0x055d,  0x059d,  0x05df,  0x0624,
    0x066b,  0x06b5,  0x0701,  0x0750,  0x07a1,  0x07f5,  0x084c,  0x08a6,
    0x0902,  0x0961,  0x09c3,  0x0a28,  0x0a91,  0x0afc,  0x0b6a,  0x0bdc,
    0x0c50,  0x0cc8,  0x0d43,  0x0dc2,  0x0e44,  0x0ec9,  0x0f52,  0x0fde,
    0x106e,  0x1101,  0x1198,  0x1232,  0x12d0,  0x1371,  0x1417,  0x14bf,
    0x156c,  0x161c,  0x16d0,  0x1788,  0x1843,  0x1902,  0x19c5,  0x1a8c,
    0x1b56,  0x1c24,  0x1cf6,  0x1dcb,  0x1ea4,  0x1f81,  0x2061,  0x2145,
    0x222d,  0x2318,  0x2406,  0x24f8,  0x25ee,  0x26e7,  0x27e3,  0x28e2,
    0x29e5,  0x2aeb,  0x2bf4,  0x2d00,  0x2e0f,  0x2f20,  0x3035,  0x314d,
    0x3267,  0x3383,  0x34a2,  0x35c4,  0x36e8,  0x380e,  0x3936,  0x3a60,
    0x3b8c,  0x3cb9,  0x3de9,  0x3f1a,  0x404c,  0x4180,  0x42b4,  0x43ea,
    0x4521,  0x4658,  0x4790,  0x48c9,  0x4a02,  0x4b3b,  0x4c74,  0x4dad,
    0x4ee6,  0x501e,  0x5156,  0x528d,  0x53c3,  0x54f9,  0x562d,  0x575f,
    0x5891,  0x59c0,  0x5aee,  0x5c1a,  0x5d43,  0x5e6b,  0x5f90,  0x60b2,
    0x61d1,  0x62ee,  0x6407,  0x651d,  0x6630,  0x673f,  0x684a,  0x6951,
    0x6a54,  0x6b53,  0x6c4e,  0x6d44,  0x6e36,  0x6f22,  0x700a,  0x70ec,
    0x71c9,  0x72a1,  0x7373,  0x7440,  0x7507,  0x75c8,  0x7682,  0x7737,
    0x77e5,  0x788d,  0x792f,  0x79ca,  0x7a5e,  0x7aeb,  0x7b72,  0x7bf1,
    0x7c6a,  0x7cdb,  0x7d45,  0x7da8,  0x7e04,  0x7e58,  0x7ea4,  0x7ee9,
    0x7f27,  0x7f5d,  0x7f8b,  0x7fb2,  0x7fd1,  0x7fe8,  0x7ff7,  0x7fff,
    0x7fff,  0x7ff7,  0x7fe8,  0x7fd1,  0x7fb2,  0x7f8b,  0x7f5d,  0x7f27,
    0x7ee9,  0x7ea4,  0x7e58,  0x7e04,  0x7da8,  0x7d45,  0x7cdb,  0x7c6a,
    0x7bf1,  0x7b72,  0x7aeb,  0x7a5e,  0x79ca,  0x792f,  0x788d,  0x77e5,
    0x7737,  0x7682,  0x75c8,  0x7507,  0x7440,  0x7373,  0x72a1,  0x71c9,
    0x70ec,  0x700a,  0x6f22,  0x6e36,  0x6d44,  0x6c4e,  0x6b53,  0x6a54,
    0x6951,  0x684a,  0x673f,  0x6630,  0x651d,  0x6407,  0x62ee,  0x61d1,
    0x60b2,  0x5f90,  0x5e6b,  0x5d43,  0x5c1a,  0x5aee,  0x59c0,  0x5891,
    0x575f,  0x562d,  0x54f9,  0x53c3,  0x528d,  0x5156,  0x501e,  0x4ee6,
    0x4dad,  0x4c74,  0x4b3b,  0x4a02,  0x48c9,  0x4790,  0x4658,  0x4521,
    0x43ea,  0x42b4,  0x4180,  0x404c,  0x3f1a,  0x3de9,  0x3cb9,  0x3b8c,
    0x3a60,  0x3936,  0x380e,  0x36e8,  0x35c4,  0x34a2,  0x3383,  0x3267,
    0x314d,  0x3035,  0x2f20,  0x2e0f,  0x2d00,  0x2bf4,  0x2aeb,  0x29e5,
    0x28e2,  0x27e3,  0x26e7,  0x25ee,  0x24f8,  0x2406,  0x2318,  0x222d,
    0x2145,  0x2061,  0x1f81,  0x1ea4,  0x1dcb,  0x1cf6,  0x1c24,  0x1b56,
    0x1a8c,  0x19c5,  0x1902,  0x1843,  0x1788,  0x16d0,  0x161c,  0x156c,
    0x14bf,  0x1417,  0x1371,  0x12d0,  0x1232,  0x1198,  0x1101,  0x106e,
    0x0fde,  0x0f52,  0x0ec9,  0x0e44,  0x0dc2,  0x0d43,  0x0cc8,  0x0c50,
    0x0bdc,  0x0b6a,  0x0afc,  0x0a91,  0x0a28,  0x09c3,  0x0961,  0x0902,
    0x08a6,  0x084c,  0x07f5,  0x07a1,  0x0750,  0x0701,  0x06b5,  0x066b,
    0x0624,  0x05df,  0x059d,  0x055d,  0x051f,  0x04e3,  0x04aa,  0x0472,
    0x043d,  0x040a,  0x03d8,  0x03a9,  0x037b,  0x034f,  0x0325,  0x02fd,
    0x02d6,  0x02b1,  0x028d,  0x026b,  0x024a,  0x022b,  0x020d,  0x01f0,
    0x01d5,  0x01bb,  0x01a2,  0x018b,  0x0174,  0x015e,  0x014a,  0x0136,
    0x0124,  0x0112,  0x0101,  0x00f2,  0x00e2,  0x00d4,  0x00c7,  0x00ba,
    0x00ae,  0x00a2,  0x0097,  0x008d,  0x0084,  0x007b,  0x0072,  0x006a,
    0x0062,  0x005b,  0x0055,  0x004e,  0x0048,  0x0043,  0x003e,  0x0039,
    0x0034,  0x0030,  0x002c,  0x0029,  0x0025,  0x0022,  0x001f,  0x001c,
    0x001a,  0x0018,  0x0016,  0x0014,  0x0012,  0x0010,  0x000e,  0x000d,
    0x000c,  0x000b,  0x0009,  0x0008,  0x0008,  0x0007,  0x0006,  0x0005,
    0x0005,  0x0004,  0x0004,  0x0003,  0x0003,  0x0002,  0x0002,  0x0002,
    0x0002,  0x0001,  0x0001,  0x0001,  0x0001,  0x0001,  0x0001,  0x0000,
    0x0000,  0x0000,  0x0000,  0x0000,  0x0000,  0x0000,  0x0000,  0x0000
};
