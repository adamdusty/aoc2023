#pragma once

#include <cstdint>
#include <string_view>

namespace aoc2023 {

inline namespace d1p2 {
auto decode_calibration(std::string_view input) -> std::uint64_t;
auto sum_calibrations(std::string_view input) -> std::uint64_t;
}; // namespace d1p2

namespace d1p1 {
auto decode_calibration(std::string_view input) -> std::uint64_t;
auto sum_calibrations(std::string_view input) -> std::uint64_t;
} // namespace d1p1

} // namespace aoc2023