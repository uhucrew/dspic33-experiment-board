#include <xc.h>
#include <dsp.h>


__prog__ fractional kaiser_window[1024] __attribute__((space(auto_psv))) = {
    0x3827,  0x385f,  0x3897,  0x38cf,  0x3907,  0x393f,  0x3977,  0x39b0,
    0x39e8,  0x3a20,  0x3a58,  0x3a90,  0x3ac8,  0x3b00,  0x3b38,  0x3b71,
    0x3ba9,  0x3be1,  0x3c19,  0x3c51,  0x3c89,  0x3cc1,  0x3cf9,  0x3d31,
    0x3d69,  0x3da1,  0x3dd9,  0x3e11,  0x3e49,  0x3e81,  0x3eb9,  0x3ef1,
    0x3f29,  0x3f61,  0x3f98,  0x3fd0,  0x4008,  0x4040,  0x4078,  0x40af,
    0x40e7,  0x411f,  0x4157,  0x418e,  0x41c6,  0x41fe,  0x4235,  0x426d,
    0x42a5,  0x42dc,  0x4314,  0x434b,  0x4383,  0x43ba,  0x43f1,  0x4429,
    0x4460,  0x4498,  0x44cf,  0x4506,  0x453d,  0x4575,  0x45ac,  0x45e3,
    0x461a,  0x4651,  0x4688,  0x46bf,  0x46f6,  0x472d,  0x4764,  0x479b,
    0x47d2,  0x4809,  0x4840,  0x4876,  0x48ad,  0x48e4,  0x491a,  0x4951,
    0x4988,  0x49be,  0x49f5,  0x4a2b,  0x4a61,  0x4a98,  0x4ace,  0x4b04,
    0x4b3b,  0x4b71,  0x4ba7,  0x4bdd,  0x4c13,  0x4c49,  0x4c7f,  0x4cb5,
    0x4ceb,  0x4d20,  0x4d56,  0x4d8c,  0x4dc2,  0x4df7,  0x4e2d,  0x4e62,
    0x4e98,  0x4ecd,  0x4f02,  0x4f38,  0x4f6d,  0x4fa2,  0x4fd7,  0x500c,
    0x5041,  0x5076,  0x50ab,  0x50e0,  0x5115,  0x514a,  0x517e,  0x51b3,
    0x51e7,  0x521c,  0x5250,  0x5285,  0x52b9,  0x52ed,  0x5321,  0x5356,
    0x538a,  0x53be,  0x53f2,  0x5425,  0x5459,  0x548d,  0x54c1,  0x54f4,
    0x5528,  0x555b,  0x558f,  0x55c2,  0x55f5,  0x5628,  0x565b,  0x568e,
    0x56c1,  0x56f4,  0x5727,  0x575a,  0x578d,  0x57bf,  0x57f2,  0x5824,
    0x5857,  0x5889,  0x58bb,  0x58ed,  0x591f,  0x5951,  0x5983,  0x59b5,
    0x59e7,  0x5a18,  0x5a4a,  0x5a7c,  0x5aad,  0x5ade,  0x5b10,  0x5b41,
    0x5b72,  0x5ba3,  0x5bd4,  0x5c05,  0x5c35,  0x5c66,  0x5c97,  0x5cc7,
    0x5cf8,  0x5d28,  0x5d58,  0x5d88,  0x5db9,  0x5de9,  0x5e18,  0x5e48,
    0x5e78,  0x5ea8,  0x5ed7,  0x5f07,  0x5f36,  0x5f65,  0x5f94,  0x5fc3,
    0x5ff2,  0x6021,  0x6050,  0x607f,  0x60ad,  0x60dc,  0x610a,  0x6139,
    0x6167,  0x6195,  0x61c3,  0x61f1,  0x621f,  0x624c,  0x627a,  0x62a7,
    0x62d5,  0x6302,  0x632f,  0x635c,  0x6389,  0x63b6,  0x63e3,  0x6410,
    0x643c,  0x6469,  0x6495,  0x64c2,  0x64ee,  0x651a,  0x6546,  0x6572,
    0x659d,  0x65c9,  0x65f5,  0x6620,  0x664b,  0x6676,  0x66a1,  0x66cc,
    0x66f7,  0x6722,  0x674d,  0x6777,  0x67a2,  0x67cc,  0x67f6,  0x6820,
    0x684a,  0x6874,  0x689e,  0x68c7,  0x68f1,  0x691a,  0x6943,  0x696d,
    0x6996,  0x69be,  0x69e7,  0x6a10,  0x6a38,  0x6a61,  0x6a89,  0x6ab1,
    0x6ad9,  0x6b01,  0x6b29,  0x6b51,  0x6b79,  0x6ba0,  0x6bc7,  0x6bef,
    0x6c16,  0x6c3d,  0x6c63,  0x6c8a,  0x6cb1,  0x6cd7,  0x6cfd,  0x6d24,
    0x6d4a,  0x6d70,  0x6d96,  0x6dbb,  0x6de1,  0x6e06,  0x6e2c,  0x6e51,
    0x6e76,  0x6e9b,  0x6ebf,  0x6ee4,  0x6f09,  0x6f2d,  0x6f51,  0x6f75,
    0x6f99,  0x6fbd,  0x6fe1,  0x7005,  0x7028,  0x704b,  0x706f,  0x7092,
    0x70b5,  0x70d7,  0x70fa,  0x711d,  0x713f,  0x7161,  0x7183,  0x71a5,
    0x71c7,  0x71e9,  0x720a,  0x722c,  0x724d,  0x726e,  0x728f,  0x72b0,
    0x72d1,  0x72f1,  0x7312,  0x7332,  0x7352,  0x7372,  0x7392,  0x73b2,
    0x73d1,  0x73f1,  0x7410,  0x742f,  0x744e,  0x746d,  0x748c,  0x74aa,
    0x74c9,  0x74e7,  0x7505,  0x7523,  0x7541,  0x755e,  0x757c,  0x7599,
    0x75b7,  0x75d4,  0x75f1,  0x760d,  0x762a,  0x7646,  0x7663,  0x767f,
    0x769b,  0x76b7,  0x76d3,  0x76ee,  0x770a,  0x7725,  0x7740,  0x775b,
    0x7776,  0x7791,  0x77ab,  0x77c5,  0x77e0,  0x77fa,  0x7814,  0x782d,
    0x7847,  0x7860,  0x787a,  0x7893,  0x78ac,  0x78c5,  0x78dd,  0x78f6,
    0x790e,  0x7926,  0x793e,  0x7956,  0x796e,  0x7985,  0x799d,  0x79b4,
    0x79cb,  0x79e2,  0x79f9,  0x7a10,  0x7a26,  0x7a3c,  0x7a52,  0x7a68,
    0x7a7e,  0x7a94,  0x7aa9,  0x7abf,  0x7ad4,  0x7ae9,  0x7afe,  0x7b12,
    0x7b27,  0x7b3b,  0x7b4f,  0x7b63,  0x7b77,  0x7b8b,  0x7b9f,  0x7bb2,
    0x7bc5,  0x7bd8,  0x7beb,  0x7bfe,  0x7c10,  0x7c23,  0x7c35,  0x7c47,
    0x7c59,  0x7c6b,  0x7c7c,  0x7c8e,  0x7c9f,  0x7cb0,  0x7cc1,  0x7cd2,
    0x7ce2,  0x7cf3,  0x7d03,  0x7d13,  0x7d23,  0x7d33,  0x7d42,  0x7d52,
    0x7d61,  0x7d70,  0x7d7f,  0x7d8e,  0x7d9c,  0x7dab,  0x7db9,  0x7dc7,
    0x7dd5,  0x7de2,  0x7df0,  0x7dfd,  0x7e0b,  0x7e18,  0x7e25,  0x7e31,
    0x7e3e,  0x7e4a,  0x7e56,  0x7e62,  0x7e6e,  0x7e7a,  0x7e85,  0x7e91,
    0x7e9c,  0x7ea7,  0x7eb2,  0x7ebc,  0x7ec7,  0x7ed1,  0x7edb,  0x7ee5,
    0x7eef,  0x7ef9,  0x7f02,  0x7f0c,  0x7f15,  0x7f1e,  0x7f26,  0x7f2f,
    0x7f37,  0x7f40,  0x7f48,  0x7f50,  0x7f57,  0x7f5f,  0x7f66,  0x7f6e,
    0x7f75,  0x7f7c,  0x7f82,  0x7f89,  0x7f8f,  0x7f95,  0x7f9b,  0x7fa1,
    0x7fa7,  0x7fac,  0x7fb2,  0x7fb7,  0x7fbc,  0x7fc0,  0x7fc5,  0x7fca,
    0x7fce,  0x7fd2,  0x7fd6,  0x7fda,  0x7fdd,  0x7fe1,  0x7fe4,  0x7fe7,
    0x7fea,  0x7fec,  0x7fef,  0x7ff1,  0x7ff3,  0x7ff5,  0x7ff7,  0x7ff9,
    0x7ffa,  0x7ffc,  0x7ffd,  0x7ffe,  0x7fff,  0x7fff,  0x7fff,  0x7fff,
    0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7fff,  0x7ffe,  0x7ffd,  0x7ffc,
    0x7ffa,  0x7ff9,  0x7ff7,  0x7ff5,  0x7ff3,  0x7ff1,  0x7fef,  0x7fec,
    0x7fea,  0x7fe7,  0x7fe4,  0x7fe1,  0x7fdd,  0x7fda,  0x7fd6,  0x7fd2,
    0x7fce,  0x7fca,  0x7fc5,  0x7fc0,  0x7fbc,  0x7fb7,  0x7fb2,  0x7fac,
    0x7fa7,  0x7fa1,  0x7f9b,  0x7f95,  0x7f8f,  0x7f89,  0x7f82,  0x7f7c,
    0x7f75,  0x7f6e,  0x7f66,  0x7f5f,  0x7f57,  0x7f50,  0x7f48,  0x7f40,
    0x7f37,  0x7f2f,  0x7f26,  0x7f1e,  0x7f15,  0x7f0c,  0x7f02,  0x7ef9,
    0x7eef,  0x7ee5,  0x7edb,  0x7ed1,  0x7ec7,  0x7ebc,  0x7eb2,  0x7ea7,
    0x7e9c,  0x7e91,  0x7e85,  0x7e7a,  0x7e6e,  0x7e62,  0x7e56,  0x7e4a,
    0x7e3e,  0x7e31,  0x7e25,  0x7e18,  0x7e0b,  0x7dfd,  0x7df0,  0x7de2,
    0x7dd5,  0x7dc7,  0x7db9,  0x7dab,  0x7d9c,  0x7d8e,  0x7d7f,  0x7d70,
    0x7d61,  0x7d52,  0x7d42,  0x7d33,  0x7d23,  0x7d13,  0x7d03,  0x7cf3,
    0x7ce2,  0x7cd2,  0x7cc1,  0x7cb0,  0x7c9f,  0x7c8e,  0x7c7c,  0x7c6b,
    0x7c59,  0x7c47,  0x7c35,  0x7c23,  0x7c10,  0x7bfe,  0x7beb,  0x7bd8,
    0x7bc5,  0x7bb2,  0x7b9f,  0x7b8b,  0x7b77,  0x7b63,  0x7b4f,  0x7b3b,
    0x7b27,  0x7b12,  0x7afe,  0x7ae9,  0x7ad4,  0x7abf,  0x7aa9,  0x7a94,
    0x7a7e,  0x7a68,  0x7a52,  0x7a3c,  0x7a26,  0x7a10,  0x79f9,  0x79e2,
    0x79cb,  0x79b4,  0x799d,  0x7985,  0x796e,  0x7956,  0x793e,  0x7926,
    0x790e,  0x78f6,  0x78dd,  0x78c5,  0x78ac,  0x7893,  0x787a,  0x7860,
    0x7847,  0x782d,  0x7814,  0x77fa,  0x77e0,  0x77c5,  0x77ab,  0x7791,
    0x7776,  0x775b,  0x7740,  0x7725,  0x770a,  0x76ee,  0x76d3,  0x76b7,
    0x769b,  0x767f,  0x7663,  0x7646,  0x762a,  0x760d,  0x75f1,  0x75d4,
    0x75b7,  0x7599,  0x757c,  0x755e,  0x7541,  0x7523,  0x7505,  0x74e7,
    0x74c9,  0x74aa,  0x748c,  0x746d,  0x744e,  0x742f,  0x7410,  0x73f1,
    0x73d1,  0x73b2,  0x7392,  0x7372,  0x7352,  0x7332,  0x7312,  0x72f1,
    0x72d1,  0x72b0,  0x728f,  0x726e,  0x724d,  0x722c,  0x720a,  0x71e9,
    0x71c7,  0x71a5,  0x7183,  0x7161,  0x713f,  0x711d,  0x70fa,  0x70d7,
    0x70b5,  0x7092,  0x706f,  0x704b,  0x7028,  0x7005,  0x6fe1,  0x6fbd,
    0x6f99,  0x6f75,  0x6f51,  0x6f2d,  0x6f09,  0x6ee4,  0x6ebf,  0x6e9b,
    0x6e76,  0x6e51,  0x6e2c,  0x6e06,  0x6de1,  0x6dbb,  0x6d96,  0x6d70,
    0x6d4a,  0x6d24,  0x6cfd,  0x6cd7,  0x6cb1,  0x6c8a,  0x6c63,  0x6c3d,
    0x6c16,  0x6bef,  0x6bc7,  0x6ba0,  0x6b79,  0x6b51,  0x6b29,  0x6b01,
    0x6ad9,  0x6ab1,  0x6a89,  0x6a61,  0x6a38,  0x6a10,  0x69e7,  0x69be,
    0x6996,  0x696d,  0x6943,  0x691a,  0x68f1,  0x68c7,  0x689e,  0x6874,
    0x684a,  0x6820,  0x67f6,  0x67cc,  0x67a2,  0x6777,  0x674d,  0x6722,
    0x66f7,  0x66cc,  0x66a1,  0x6676,  0x664b,  0x6620,  0x65f5,  0x65c9,
    0x659d,  0x6572,  0x6546,  0x651a,  0x64ee,  0x64c2,  0x6495,  0x6469,
    0x643c,  0x6410,  0x63e3,  0x63b6,  0x6389,  0x635c,  0x632f,  0x6302,
    0x62d5,  0x62a7,  0x627a,  0x624c,  0x621f,  0x61f1,  0x61c3,  0x6195,
    0x6167,  0x6139,  0x610a,  0x60dc,  0x60ad,  0x607f,  0x6050,  0x6021,
    0x5ff2,  0x5fc3,  0x5f94,  0x5f65,  0x5f36,  0x5f07,  0x5ed7,  0x5ea8,
    0x5e78,  0x5e48,  0x5e18,  0x5de9,  0x5db9,  0x5d88,  0x5d58,  0x5d28,
    0x5cf8,  0x5cc7,  0x5c97,  0x5c66,  0x5c35,  0x5c05,  0x5bd4,  0x5ba3,
    0x5b72,  0x5b41,  0x5b10,  0x5ade,  0x5aad,  0x5a7c,  0x5a4a,  0x5a18,
    0x59e7,  0x59b5,  0x5983,  0x5951,  0x591f,  0x58ed,  0x58bb,  0x5889,
    0x5857,  0x5824,  0x57f2,  0x57bf,  0x578d,  0x575a,  0x5727,  0x56f4,
    0x56c1,  0x568e,  0x565b,  0x5628,  0x55f5,  0x55c2,  0x558f,  0x555b,
    0x5528,  0x54f4,  0x54c1,  0x548d,  0x5459,  0x5425,  0x53f2,  0x53be,
    0x538a,  0x5356,  0x5321,  0x52ed,  0x52b9,  0x5285,  0x5250,  0x521c,
    0x51e7,  0x51b3,  0x517e,  0x514a,  0x5115,  0x50e0,  0x50ab,  0x5076,
    0x5041,  0x500c,  0x4fd7,  0x4fa2,  0x4f6d,  0x4f38,  0x4f02,  0x4ecd,
    0x4e98,  0x4e62,  0x4e2d,  0x4df7,  0x4dc2,  0x4d8c,  0x4d56,  0x4d20,
    0x4ceb,  0x4cb5,  0x4c7f,  0x4c49,  0x4c13,  0x4bdd,  0x4ba7,  0x4b71,
    0x4b3b,  0x4b04,  0x4ace,  0x4a98,  0x4a61,  0x4a2b,  0x49f5,  0x49be,
    0x4988,  0x4951,  0x491a,  0x48e4,  0x48ad,  0x4876,  0x4840,  0x4809,
    0x47d2,  0x479b,  0x4764,  0x472d,  0x46f6,  0x46bf,  0x4688,  0x4651,
    0x461a,  0x45e3,  0x45ac,  0x4575,  0x453d,  0x4506,  0x44cf,  0x4498,
    0x4460,  0x4429,  0x43f1,  0x43ba,  0x4383,  0x434b,  0x4314,  0x42dc,
    0x42a5,  0x426d,  0x4235,  0x41fe,  0x41c6,  0x418e,  0x4157,  0x411f,
    0x40e7,  0x40af,  0x4078,  0x4040,  0x4008,  0x3fd0,  0x3f98,  0x3f61,
    0x3f29,  0x3ef1,  0x3eb9,  0x3e81,  0x3e49,  0x3e11,  0x3dd9,  0x3da1,
    0x3d69,  0x3d31,  0x3cf9,  0x3cc1,  0x3c89,  0x3c51,  0x3c19,  0x3be1,
    0x3ba9,  0x3b71,  0x3b38,  0x3b00,  0x3ac8,  0x3a90,  0x3a58,  0x3a20,
    0x39e8,  0x39b0,  0x3977,  0x393f,  0x3907,  0x38cf,  0x3897,  0x385f
};