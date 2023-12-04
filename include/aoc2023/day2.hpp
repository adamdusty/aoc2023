#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace aoc2023 {

struct draw {
    std::uint64_t red{0};
    std::uint64_t green{0};
    std::uint64_t blue{0};
};

struct game {
    std::uint64_t id;
    std::vector<draw> draws;
};

auto evaluate_game(std::string data) -> std::uint64_t;
auto sum_game_ids(std::string data) -> std::uint64_t;

} // namespace aoc2023