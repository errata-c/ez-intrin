#ifdef __AVX__
AVX
#endif
#ifdef __AVX2__
AVX2
#endif
#ifdef __AVX512BW__
AVX512
#endif
#ifdef _M_ARM
processor: ARM
#endif
#ifdef _M_ARM_ARMV7VE
processor: ARMV7
#endif
#ifdef _M_ARM_FP
armarch: _M_ARM_FP
#endif
#ifdef _M_AMD64
iw: X64
#endif
#ifdef _M_IX86
iw: X86
#endif
#ifdef __ATOM__
favor: ATOM
#endif