#include "aoc2023/aoc2023.hpp"

#include <algorithm>
#include <cctype>
#include <numeric>
#include <ranges>
#include <vector>

namespace rv = std::ranges::views;

namespace aoc2023 {

auto decode_calibration(std::string_view input) -> std::uint64_t {
    auto digits  = input | rv::filter([](char c) { return std::isdigit(c); });
    auto num_str = std::string{};
    num_str += digits.front();
    num_str += digits.back();

    auto num = std::stoull(num_str);

    return num;
}

auto sum_calibrations(std::string_view input) -> std::uint64_t {
    auto nums = input | rv::split('\n') | rv::transform([](auto&& line) {
                    return decode_calibration(std::string_view(line.begin(), line.end()));
                });

    return std::reduce(nums.begin(), nums.end());
}

} // namespace aoc2023