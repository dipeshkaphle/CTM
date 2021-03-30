#pragma once

#include <cassert>
#include <cmath>
#include <concepts>
#include <numeric>
#include <stdexcept>
#include <type_traits>

// ===============================================================
// ===============================================================
// ===============================================================
//
// Concepts used
//
template <typename T> concept Integral = std::integral<T>;

template <typename T> concept UnsignedIntegral = std::unsigned_integral<T>;

template <typename T> concept SignedIntegral = std::signed_integral<T>;

template <typename T> concept FloatingPoint = std::floating_point<T>;

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;
