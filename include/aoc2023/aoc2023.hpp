#pragma once

#include <cstdint>
#include <string_view>

namespace aoc2023 {

auto decode_calibration(std::string_view input) -> std::uint64_t;
auto sum_calibrations(std::string_view input) -> std::uint64_t;

} // namespace aoc2023