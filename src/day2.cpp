#include "aoc2023/day2.hpp"

#include <adizzle/string.hpp>
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

auto parse_number(std::string_view data) {
    auto res     = std::string();
    size_t index = 0;

    while(index < data.size() && std::isspace(data.at(index)) != 0) {
        ++index;
    }

    while(index < data.size() && std::isdigit(data.at(index)) != 0) {
        res += data.at(index++);
    }

    return std::stoull(res);
}

auto parse_color(std::string_view data) {
    auto res     = std::string();
    size_t index = 0;

    while(index < data.size() && std::isspace(data.at(index)) != 0) {
        ++index;
    }
    while(index < data.size() && std::isalpha(data.at(index)) != 0) {
        res += data.at(index++);
    }

    return res;
}

auto game_power(std::string_view data) -> std::uint64_t {
    auto game  = adizzle::split(data, ':').at(1);
    auto draws = adizzle::split(game, ';');

    std::uint64_t max_red   = 0;
    std::uint64_t max_green = 0;
    std::uint64_t max_blue  = 0;

    for(const auto& draw: draws) {
        auto entries = adizzle::split(draw, ',');
        for(const auto& entry: entries) {
            auto trimmed = adizzle::trim(entry);
            auto split   = adizzle::split(trimmed, ' ');
            auto num     = std::stoull(split.at(0));
            auto color   = split.at(1);

            switch(color.at(0)) {
            case 'r':
                max_red = std::max(max_red, num);
                break;
            case 'g':
                max_green = std::max(max_green, num);
                break;
            case 'b':
                max_blue = std::max(max_blue, num);
                break;
            }
        }
    }

    return max_red * max_green * max_blue;
}

auto sum_power(std::string_view data) -> std::uint64_t {
    auto pow =
        data | rv::split('\n') | rv::transform([](auto x) { return game_power(std::string(x.begin(), x.end())); });

    return std::reduce(pow.begin(), pow.end());
}

} // namespace aoc2023