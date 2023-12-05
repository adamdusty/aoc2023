#include <aoc2023/day3.hpp>
#include <snitch/snitch.hpp>

#include <string>

using namespace aoc2023;

TEST_CASE("base case") {
    // Sum all numbers adjacent to a non-period symbol

    auto input = std::string("467..114..\n"
                             "...*......\n"
                             "..35..633.\n"
                             "......#...\n"
                             "617*......\n"
                             ".....+.58.\n"
                             "..592.....\n"
                             "......755.\n"
                             "...$.*....\n"
                             ".664.598..\n");

    auto actual = day3::solve(input);

    CHECK(actual == 4361);
}

TEST_CASE("Line parse") {
    auto input = std::string("..35...633");

    auto actual   = day3::parse(input);
    auto expected = std::vector<day3::number>{
        {.value = 35, .start = 2, .length = 2},
        {.value = 633, .start = 7, .length = 3},
    };

    CHECK(actual == expected);
}