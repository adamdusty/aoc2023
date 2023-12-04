#include "aoc2023/day2.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace rv = std::ranges::views;

namespace aoc2023 {

auto evaluate_game(std::string data) -> std::uint64_t {
    data.erase(std::remove_if(data.begin(), data.end(), [](auto c) { return std::isspace(c); }), data.end());
    auto draws = data.substr(data.find(':') + 1, data.size() - data.find(':'));

    size_t index = 0;
    while(index < draws.size()) {
        auto val = std::string();
        while(std::isdigit(draws.at(index)) != 0) {
            val += draws.at(index++);
        }

        if(val.empty()) {
            ++index;
            continue;
        }

        auto draw_num = std::stoull(val);

        if(draw_num > 14) {
            return 0;
        }

        if(draw_num > 12) {
            switch(draws.at(index)) {
            case 'r':
                return 0;
                break;
            case 'g':
                if(draw_num > 13) {
                    return 0;
                }
                break;
            case 'b':
                if(draw_num > 14) {
                    return 0;
                }
                break;
            }
        }

        ++index;
    }

    return std::stoull(data.substr(4, data.find(':')));
}

auto sum_game_ids(std::string data) -> std::uint64_t {
    auto ids = data | rv::split('\n') |
               rv::transform([](auto line) { return evaluate_game(std::string(line.begin(), line.end())); });

    return std::reduce(ids.begin(), ids.end());
}

} // namespace aoc2023