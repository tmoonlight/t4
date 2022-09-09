#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>       // std::numeric_limits
#include <new>
#include <utility>

namespace t4 {

// types

using byte_t = std::uint8_t;

template <std::size_t N>
struct uint;

template <> struct uint<8 > { using type = std::uint8_t ; };
template <> struct uint<16> { using type = std::uint16_t; };
template <> struct uint<32> { using type = std::uint32_t; };
template <> struct uint<64> { using type = std::uint64_t; };

template <std::size_t N>
using uint_t = typename uint<N>::type;

// constants

enum : std::uint32_t {
    invalid_value   = (std::numeric_limits<std::uint32_t>::max)(),
    default_timeout = 100, // ms
};

enum : std::size_t {
    data_length     = 64,
    large_msg_limit = data_length,
    large_msg_align = 1024,
    large_msg_cache = 32,
};

enum class UI_DEF { // multiplicity of the relationship
    x11,
    wayland
};

}