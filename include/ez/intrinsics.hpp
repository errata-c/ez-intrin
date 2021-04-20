#pragma once
#include <cinttypes>

namespace ez {
	static_assert(sizeof(char) == sizeof(int8_t), "Size mismatch");
	static_assert(sizeof(short) == sizeof(int16_t), "Size mismatch");
	static_assert(sizeof(int) == sizeof(int32_t), "Size mismatch");
	static_assert(sizeof(long long) == sizeof(int64_t), "Size mismatch");

	inline uint16_t byteswap_u16(uint16_t val);
	inline uint32_t byteswap_u32(uint32_t val);
	inline uint64_t byteswap_u64(uint64_t val);

	inline uint16_t popcount_u16(uint16_t val);
	inline uint32_t popcount_u32(uint32_t val);
	inline uint64_t popcount_u64(uint64_t val);

	inline uint8_t bittest_i32(const long& val, long index);
	inline uint8_t bittest_i64(const long long& val, long long index);
}