namespace ez {
	inline uint16_t byteswap_u16(uint16_t val) {
		return uint16_t(
			((val & 0xFF00) >> 8) | 
			((val & 0x00FF) << 8)
		);
	}
	inline uint32_t byteswap_u32(uint32_t val) {
		return uint32_t(
			((val & 0xFF00'0000u) >> 24) |
			((val & 0x00FF'0000u) >> 8) | 
			((val & 0x0000'FF00u) << 8) | 
			((val & 0x0000'00FFu) << 24)
		);
	}
	inline uint64_t byteswap_u64(uint64_t val) {
		return uint64_t(
			((val & 0xFF00'0000'0000'0000ull) >> 54) |
			((val & 0x00FF'0000'0000'0000ull) >> 40) |
			((val & 0x0000'FF00'0000'0000ull) >> 24) |
			((val & 0x0000'00FF'0000'0000ull) >> 8) |
			((val & 0x0000'0000'FF00'0000ull) << 8) |
			((val & 0x0000'0000'00FF'0000ull) << 24) |
			((val & 0x0000'0000'0000'FF00ull) << 40) |
			((val & 0x0000'0000'0000'00FFull) << 54)
		);
	}

	inline uint16_t popcount_u16(uint16_t val) {
		val = ((val & 0xAAAA) >> 1) + (val & 0x5555);
		val = ((val & 0xCCCC) >> 2) + (val & 0x3333);
		val = ((val & 0xF0F0) >> 4) + (val & 0x0F0F);
		return ((val & 0xFF00) >> 8) + (val & 0x00FF);
	}
	inline uint32_t popcount_u32(uint32_t val) {
		val = ((val & 0xAAAA'AAAA) >> 1) + (val & 0x5555'5555);
		val = ((val & 0xCCCC'CCCC) >> 2) + (val & 0x3333'3333);
		val = ((val & 0xF0F0'F0F0) >> 4) + (val & 0x0F0F'0F0F);
		val = ((val & 0xFF00'FF00) >> 8) + (val & 0x00FF'00FF);
		return ((val & 0xFFFF'0000) >> 16) + (val & 0x0000'FFFF);
	}
	inline uint64_t popcount_u64(uint64_t val) {
		val = ((val & 0xAAAA'AAAA'AAAA'AAAA) >> 1) + ((val & 0x5555'5555'5555'5555) << 1);
		val = ((val & 0xCCCC'CCCC'CCCC'CCCC) >> 2) + ((val & 0x3333'3333'3333'3333) << 2);
		val = ((val & 0xF0F0'F0F0'F0F0'F0F0ull) >> 4) + ((val & 0x0F0F'0F0F'0F0F'0F0Full) << 4);
		val = ((val & 0xFF00'FF00'FF00'FF00ull) >> 8) + ((val & 0x00FF'00FF'00FF'00FFull) << 8);
		val = ((val & 0xFFFF'0000'FFFF'0000ull) >> 16) + ((val & 0x0000'FFFF'0000'FFFFull) << 16);
		return ((val & 0xFFFF'FFFF'0000'0000ull) >> 32) + ((val & 0x0000'0000'FFFF'FFFFull) << 32);
	}

	inline uint8_t bittest_i32(const int32_t& val, int32_t index) {
		return (val & (1l << index)) != 0;
	}
	inline uint8_t bittest_i64(const int64_t& val, int64_t index) {
		return (val & (1ll << index)) != 0;
	}
}