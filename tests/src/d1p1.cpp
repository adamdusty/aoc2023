#include <aoc2023/aoc2023.hpp>
#include <snitch/snitch.hpp>
#include <string>

using namespace aoc2023;

TEST_CASE("decode_calibration") {
    auto input    = std::string();
    auto expected = std::uint64_t{};
    auto actual   = std::uint64_t{};

    input    = "1abc2";
    expected = 12;
    actual   = decode_calibration(input);
    CHECK(actual == expected);

    input    = "pqr3stu8vwx";
    expected = 38;
    actual   = decode_calibration(input);
    CHECK(actual == expected);

    input    = "a1b2c3d4e5f";
    expected = 15;
    actual   = decode_calibration(input);
    CHECK(actual == expected);

    input    = "treb7uchet";
    expected = 77;
    actual   = decode_calibration(input);
    CHECK(actual == expected);
}

TEST_CASE("sum_calibrations") {
    auto input = std::string(R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)");

    std::uint64_t expected = 142;
    auto actual            = sum_calibrations(input);

    CHECK(actual == expected);
}