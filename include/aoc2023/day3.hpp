#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

namespace aoc2023::day3 {

struct number {
    std::uint64_t value;
    size_t start;
    size_t length;

    auto operator==(const number&) const -> bool = default;
};

auto parse(std::string_view line) -> std::vector<number>;
auto solve(std::string_view input) -> std::uint64_t;

} // namespace aoc2023::day3