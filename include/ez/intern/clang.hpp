#include <ez/intrinsics.hpp>

namespace ez {
	uint16_t byteswap_u16(uint16_t val) {
		return __builtin_bswap16(val);
	}
	uint32_t byteswap_u32(uint32_t val) {
		return __builtin_bswap32(val);
	}
	uint64_t byteswap_u64(uint64_t val) {
		return __builtin_bswap64(val);
	}

	uint16_t popcount_u16(uint16_t val) {
		return __builtin_popcount(val);
	}
	uint32_t popcount_u32(uint32_t val) {
		return __builtin_popcount(val);
	}
	uint64_t popcount_u64(uint64_t val) {
		return __builtin_popcountll(val);
	}

	uint8_t bittest_i32(const int32_t& val, int32_t index) {
		return _bittest((const long*)&val, (long)index);
	}
	uint8_t bittest_i64(const int64_t& val, int64_t index) {
		return _bittest64(&val, index);
	}
}