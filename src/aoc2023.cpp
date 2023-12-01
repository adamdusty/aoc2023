#include "aoc2023/aoc2023.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

namespace rv = std::ranges::views;

namespace aoc2023 {

auto repr_map = std::unordered_map<std::string, char>{
    {"one", '1'},
    {"two", '2'},
    {"three", '3'},
    {"four", '4'},
    {"five", '5'},
    {"six", '6'},
    {"seven", '7'},
    {"eight", '8'},
    {"nine", '9'},
};

auto first_digit(std::string_view input) -> char {
    std::string result = std::string();

    for(auto c: input) {
        if(std::isdigit(c) != 0) {
            return c;
        }
        result += c;

        for(auto& [num, dig]: repr_map) {
            if(result.find(num) != std::string::npos) {
                return dig;
            }
        }
    }

    throw std::runtime_error{"no digits"};
}

auto last_digit(std::string_view input) -> char {
    std::string result = std::string();
    auto reversed      = rv::reverse(input);

    for(auto c: reversed) {
        if(std::isdigit(c) != 0) {
            return c;
        }
        result.insert(0, 1, c);

        for(auto& [num, dig]: repr_map) {
            if(result.find(num) != std::string::npos) {
                return dig;
            }
        }
    }

    throw std::runtime_error{"no digits"};
}

inline namespace d1p2 {

auto decode_calibration(std::string_view input) -> std::uint64_t {
    auto first  = first_digit(input);
    auto last   = last_digit(input);
    auto digits = std::string{first, last};
    auto num    = std::stoull(digits);

    return num;
}

auto sum_calibrations(std::string_view input) -> std::uint64_t {
    auto nums = input | rv::split('\n') |
                rv::transform([](auto&& line) { return decode_calibration(std::string(line.begin(), line.end())); });

    return std::reduce(nums.begin(), nums.end());
}

} // namespace d1p2

namespace d1p1 {
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

} // namespace d1p1

} // namespace aoc2023