#include <aoc2023/aoc2023.hpp>
#include <snitch/snitch.hpp>
#include <string>

using namespace aoc2023;

TEST_CASE("decode_calibration", "[d1p1]") {
    auto input    = std::string();
    auto expected = std::uint64_t{};
    auto actual   = std::uint64_t{};

    input    = "1abc2";
    expected = 12;
    actual   = d1p1::decode_calibration(input);
    CHECK(actual == expected);

    input    = "pqr3stu8vwx";
    expected = 38;
    actual   = d1p1::decode_calibration(input);
    CHECK(actual == expected);

    input    = "a1b2c3d4e5f";
    expected = 15;
    actual   = d1p1::decode_calibration(input);
    CHECK(actual == expected);

    input    = "treb7uchet";
    expected = 77;
    actual   = d1p1::decode_calibration(input);
    CHECK(actual == expected);
}

TEST_CASE("sum_calibrations", "[d1p1]") {
    auto input = std::string(R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)");

    std::uint64_t expected = 142;
    auto actual            = d1p1::sum_calibrations(input);

    CHECK(actual == expected);
}

TEST_CASE("decode_calibration", "[d1p2]") {
    auto input    = std::string();
    auto expected = std::uint64_t{};
    auto actual   = std::uint64_t{};

    input    = "two1nine";
    expected = 29;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);

    input    = "eightwothree";
    expected = 83;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);

    input    = "abcone2threexyz";
    expected = 13;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);

    input    = "xtwone3four";
    expected = 24;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);

    input    = "4nineeightseven2";
    expected = 42;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);

    input    = "zoneight234";
    expected = 14;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);

    input    = "7pqrstsixteen";
    expected = 76;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);

    input    = "5oneight";
    expected = 58;
    actual   = d1p2::decode_calibration(input);
    CHECK(actual == expected);
}

TEST_CASE("sum_calibrations", "[d1p2]") {
    auto input = std::string(R"(two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen)");

    std::uint64_t expected = 281;
    auto actual            = d1p2::sum_calibrations(input);

    CHECK(actual == expected);
}
