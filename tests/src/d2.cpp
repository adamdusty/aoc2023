#include <adizzle/literals.hpp>
#include <aoc2023/day2.hpp>
#include <snitch/snitch.hpp>

#include <string>

using namespace aoc2023;

TEST_CASE("game eval") {
    auto input = std::string("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");

    auto actual = evaluate_game(input);

    CHECK(actual == 1);
}

TEST_CASE("game eval") {
    auto input = std::string("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue");

    auto actual = evaluate_game(input);

    CHECK(actual == 2);
}

TEST_CASE("game eval") {
    auto input = std::string("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red");

    auto actual = evaluate_game(input);

    CHECK(actual == 0);
}

TEST_CASE("game eval") {
    auto input = std::string("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red");

    auto actual = evaluate_game(input);

    CHECK(actual == 0);
}

TEST_CASE("game eval") {
    auto input = std::string("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green");

    auto actual = evaluate_game(input);

    CHECK(actual == 5);
}

TEST_CASE("game eval") {
    auto input = std::string("Game 18: 7 blue, 10 red, 3 green; 3 green, 1 blue; 7 red, 1 green, 7 blue; 7 blue, 4 "
                             "red, 1 green; 2 green, 1 blue, 10 red; 3 blue, 11 red, 1 green");

    auto actual = evaluate_game(input);

    CHECK(actual == 18);
}

TEST_CASE("game eval") {
    auto input = std::string("Game 100: 16 red, 3 blue; 2 red, 5 green; 9 red; 1 blue, 3 green, 10 red; 1 red, 5 blue, "
                             "3 green; 12 blue, 9 red");

    auto actual = evaluate_game(input);

    CHECK(actual == 0);
}

TEST_CASE("base case") {
    auto input = std::string(R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)");

    auto actual   = sum_game_ids(input);
    auto expected = 8;

    CHECK(actual == expected);
}

TEST_CASE("additional games") {
    auto input = std::string(R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 6: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 7: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 8: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)");

    auto actual   = sum_game_ids(input);
    auto expected = 11;

    CHECK(actual == expected);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 1: 10 red, 7 green, 3 blue; 5 blue, 3 red, 10 green; 4 blue, 14 green, 7 red; 1 red, 11 green; 6 blue, 17 green, 15 red; 18 green, 7 red, 5 blue
Game 2: 13 green, 10 red; 11 green, 1 blue, 7 red; 5 red, 12 green, 1 blue; 12 green, 6 red; 8 green, 5 red; 12 green, 1 red
Game 3: 7 green, 1 blue; 1 blue, 3 green, 1 red; 1 green, 1 blue; 2 green; 1 blue, 7 green, 2 red; 2 green
Game 4: 7 green, 11 blue; 12 blue, 7 green; 1 green, 7 blue; 5 blue, 2 green; 5 red, 9 green, 14 blue
Game 5: 2 red, 6 blue, 6 green; 2 red, 6 green; 12 blue, 5 red, 3 green; 12 green, 5 red, 8 blue; 10 blue, 5 green; 2 red, 4 green
Game 6: 8 blue, 1 red, 17 green; 7 blue; 10 green, 6 blue; 5 blue, 1 red, 11 green
Game 7: 1 blue, 2 red, 2 green; 1 blue, 3 green; 3 green, 1 red, 3 blue; 2 blue, 3 green, 1 red
Game 8: 3 green, 10 red, 15 blue; 1 green, 9 red; 9 blue, 2 green, 12 red
Game 9: 4 green, 10 blue, 13 red; 16 red, 7 blue; 14 red, 1 green, 1 blue; 14 red, 4 blue, 1 green
Game 10: 6 blue, 9 red, 3 green; 9 green, 7 blue, 9 red; 2 red, 4 blue, 6 green; 12 green, 7 blue, 5 red)"
    );

    auto actual   = sum_game_ids(input);
    auto expected = 2 + 3 + 4 + 5 + 7 + 10;

    CHECK(actual == expected);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 1: 10 red, 7 green, 3 blue; 5 blue, 3 red, 10 green; 4 blue, 14 green, 7 red; 1 red, 11 green; 6 blue, 17 green, 15 red; 18 green, 7 red, 5 blue)"
    );

    auto actual = evaluate_game(input);

    CHECK(actual == 0);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 2: 13 green, 10 red; 11 green, 1 blue, 7 red; 5 red, 12 green, 1 blue; 12 green, 6 red; 8 green, 5 red; 12 green, 1 red)"
    );

    auto actual = evaluate_game(input);

    CHECK(actual == 2);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 3: 7 green, 1 blue; 1 blue, 3 green, 1 red; 1 green, 1 blue; 2 green; 1 blue, 7 green, 2 red; 2 green)"
    );

    auto actual = evaluate_game(input);

    CHECK(actual == 3);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 4: 7 green, 11 blue; 12 blue, 7 green; 1 green, 7 blue; 5 blue, 2 green; 5 red, 9 green, 14 blue)"
    );

    auto actual = evaluate_game(input);

    CHECK(actual == 4);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 5: 2 red, 6 blue, 6 green; 2 red, 6 green; 12 blue, 5 red, 3 green; 12 green, 5 red, 8 blue; 10 blue, 5 green; 2 red, 4 green)"
    );

    auto actual = evaluate_game(input);

    CHECK(actual == 5);
}

TEST_CASE("additional games") {
    auto input = std::string(R"(Game 6: 8 blue, 1 red, 17 green; 7 blue; 10 green, 6 blue; 5 blue, 1 red, 11 green)");

    auto actual = evaluate_game(input);

    CHECK(actual == 0);
}

TEST_CASE("additional games") {
    auto input =
        std::string(R"(Game 7: 1 blue, 2 red, 2 green; 1 blue, 3 green; 3 green, 1 red, 3 blue; 2 blue, 3 green, 1 red)"
        );

    auto actual = evaluate_game(input);

    CHECK(actual == 7);
}

TEST_CASE("additional games") {
    auto input = std::string(R"(Game 8: 3 green, 10 red, 15 blue; 1 green, 9 red; 9 blue, 2 green, 12 red)");

    auto actual = evaluate_game(input);

    CHECK(actual == 0);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 9: 4 green, 10 blue, 13 red; 16 red, 7 blue; 14 red, 1 green, 1 blue; 14 red, 4 blue, 1 green)"
    );

    auto actual = evaluate_game(input);

    CHECK(actual == 0);
}

TEST_CASE("additional games") {
    auto input = std::string(
        R"(Game 10: 6 blue, 9 red, 3 green; 9 green, 7 blue, 9 red; 2 red, 4 blue, 6 green; 12 green, 7 blue, 5 red)"
    );

    auto actual = evaluate_game(input);

    CHECK(actual == 10);
}

TEST_CASE("Day 2 part 2") {
    auto input = std::string(R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)");

    auto actual   = sum_power(input);
    auto expected = std::uint64_t{2286};

    CHECK(actual == expected);
}