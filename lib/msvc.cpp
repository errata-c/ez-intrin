#include <ez/intrinsics.hpp>

#include "intrin.h"
#include "immintrin.h"
#include <stdlib.h>

#include <type_traits>

namespace ez {
	// Reverse the endianess
	inline uint16_t byteswap_u16(uint16_t val) {
		return _byteswap_ushort(val);
	}
	// Reverse the endianess
	inline uint32_t byteswap_u32(uint32_t val) {
		return _byteswap_ulong(val);
	}
	// Reverse the endianess
	inline uint64_t byteswap_u64(uint64_t val) {
		return _byteswap_uint64(val);
	}

	// Count the ones in a binary value
	inline uint16_t popcount_u16(uint16_t val) {
		return __popcnt16(val);
	}
	// Count the ones in a binary value
	inline uint32_t popcount_u32(uint32_t val) {
		return __popcnt(val);
	}
	// Count the ones in a binary value
	inline uint64_t popcount_u64(uint64_t val) {
		return __popcnt64(val);
	}

	// returns non-zero if bit at index is one
	inline uint8_t bittest_i32(const long& val, long index) {
		return _bittest(&val, index);
	}
	// returns non-zero if bit at index is one
	inline uint8_t bittest_i64(const int64_t & val, int64_t index) {
		return _bittest64(&val, index);
	}
	
	// performs an addition with a carry-in and returns the carry-out
	inline uint8_t addcarry_u16(uint8_t cin, uint16_t a, uint16_t b, uint16_t & out) {
		return _addcarry_u16(cin, a, b, &out);
	}
	// performs an addition with a carry-in and returns the carry-out
	inline uint8_t addcarry_u32(uint8_t cin, uint32_t a, uint32_t b, uint32_t & out) {
		return _addcarry_u32(cin, a, b, &out);
	}
	// performs an addition with a carry-in and returns the carry-out
	inline uint8_t addcarry_u64(uint8_t cin, uint64_t a, uint64_t b, uint64_t & out) {
		return _addcarry_u64(cin, a, b, &out);
	}
	
	// sets index to position of least significant bit set to one, if return value is non-zero
	inline uint8_t lsb_index_u32(unsigned long val, unsigned long & index) {
		return _BitScanForward(&index, val);
	}
	// sets index to position of least significant bit set to one, if return value is non-zero
	inline uint8_t lsb_index_u64(unsigned long val, uint64_t & index) {
		return _BitScanForward64(&index, val);
	}
	
	// sets index to position of most significant bit set to one, if return value is non-zero
	inline uint8_t msb_index_u32(unsigned long val, unsigned long & index) {
		return _BitScanReverse(&index, val);
	}
	// sets index to position of most significant bit set to one, if return value is non-zero
	inline uint8_t msb_index_u64(unsigned uint64_t val, unsigned long & index) {
		return _BitScanReverse64(&index, val);
	}
	
	
	
	// Loads from big endian to the machine endianess. If machine is already big endian this is a no-op.
	inline int16_t load_be_i16(const int16_t & val) {
		return _loadbe_i16(&val);
	}
	// Loads from big endian to the machine endianess. If machine is already big endian this is a no-op.
	inline int16_t load_be_i32(const int16_t & val) {
		return _loadbe_i32(&val);
	}
	// Loads from big endian to the machine endianess. If machine is already big endian this is a no-op.
	inline int16_t load_be_i64(const int16_t & val) {
		return _loadbe_i64(&val);
	}
	
	// Loads from big endian to the machine endianess. If machine is already big endian this is a no-op.
	inline uint16_t load_be_u16(const uint16_t & val) {
		return _loadbe_u16(&val);
	}
	// Loads from big endian to the machine endianess. If machine is already big endian this is a no-op.
	inline uint32_t load_be_u32(const uint32_t & val) {
		return _loadbe_u32(&val);
	}
	// Loads from big endian to the machine endianess. If machine is already big endian this is a no-op.
	inline uint64_t load_be_u64(const uint64_t & val) {
		return _loadbe_u64(&val);
	}
	
	
	
	// Loads from little endian to the machine endianess. If machine is already little endian this is a no-op.
	inline int16_t load_le_i16(const int16_t & val) {
		return val;
	}
	// Loads from little endian to the machine endianess. If machine is already little endian this is a no-op.
	inline int32_t load_le_i32(const int32_t & val) {
		return val;
	}
	// Loads from little endian to the machine endianess. If machine is already little endian this is a no-op.
	inline int64_t load_le_i64(const int64_t & val) {
		return val;
	}
	
	// Loads from little endian to the machine endianess. If machine is already little endian this is a no-op.
	inline uint16_t load_le_u16(const uint16_t & val) {
		return val;
	}
	// Loads from little endian to the machine endianess. If machine is already little endian this is a no-op.
	inline uint32_t load_le_u32(const uint32_t & val) {
		return val;
	}
	// Loads from little endian to the machine endianess. If machine is already little endian this is a no-op.
	inline uint64_t load_le_u64(const uint64_t & val) {
		return val;
	}



	inline uint8_t rotl_u8(uint8_t val, uint8_t shift) {
		return _rotl8(val, shift);
	}
	inline uint16_t rotl_u16(uint16_t val, uint16_t shift) {
		return _rotl16(val, shift);
	}
	inline uint32_t rotl_u32(uint32_t val, int shift) {
		return _lrotl(reinterpret_cast<unsigned long>(val), shift);
	}
	inline uint64_t rotl_u64(uint64_t val, int shift) {
		return _rotl64(val, shift);
	}
	
	
	inline uint8_t rotr_u8(uint8_t val, uint8_t shift) {
		return _rotr8(val, shift);
	}
	inline uint16_t rotr_u16(uint16_t val, uint16_t shift) {
		return _rotr16(val, shift);
	}
	inline uint32_t rotr_u32(uint32_t val, int shift) {
		return _lrotr(reinterpret_cast<unsigned long>(val), shift);
	}
	inline uint64_t rotr_u64(uint64_t val, int shift) {
		return _rotr64(val, shift);
	}
	
};