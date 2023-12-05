#include "aoc2023/day3.hpp"
#include <adizzle/string.hpp>
#include <algorithm>
#include <cmath>
#include <ranges>

namespace aoc2023::day3 {

namespace rv = std::ranges::views;

auto parse(std::string_view line) -> std::vector<number> {
    size_t index     = 0;
    auto current_num = std::string();
    auto nums        = std::vector<number>();
    while(index < line.size()) {
        if(std::isdigit(line.at(index)) != 0) {
            while(index < line.size() && std::isdigit(line.at(index)) != 0) {
                current_num += line.at(index++);
            }

            auto num = number{
                .value  = std::stoull(current_num),
                .start  = index - current_num.size(),
                .length = current_num.size(),
            };

            nums.emplace_back(num);

            current_num.clear();
        }

        ++index;
    }

    return nums;
}

auto solve(std::string_view input) -> std::uint64_t {
    std::uint64_t sum = 0;
    // Split input into a vector of strings (effectively a matrix)
    auto lines = adizzle::split(input, '\n');

    // Parse each string for numbers.
    for(size_t i = 0; i < lines.size(); ++i) {
        // Record number start position and number end position.
        auto nums = parse(lines.at(i));

        // Search surrounding positions for a symbols
        for(const auto& num: nums) {
            auto search_space = std::string();

            size_t search_row_start = i == 0 ? 0 : i - 1;
            size_t search_row_end   = i == lines.size() - 1 ? i : i + 1;

            // Calculate search space
            for(size_t j = search_row_start; j <= search_row_end; ++j) {

                size_t start  = num.start == 0 ? 0 : num.start - 1;
                size_t length = num.start == 0 ? num.length + 1 : num.length + 2;

                if(start + length >= lines.at(j).size()) {
                    length = lines.at(j).size() - start;
                }

                search_space += lines.at(j).substr(start, length);
            }

            // Add number to sum if symbol found, else move on
            auto x = search_space | rv::filter([](auto c) { return (c != '.' && std::isdigit(c) == 0); });
            if(!x.empty()) {
                sum += num.value;
            }
        }
    }

    return sum;
}

} // namespace aoc2023::day3