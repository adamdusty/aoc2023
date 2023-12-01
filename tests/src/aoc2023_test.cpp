#include <snitch/snitch.hpp>
#include <aoc2023/aoc2023.hpp>

TEST_CASE("Test case", "[greeting]") {
    REQUIRE(aoc2023::get_version() == 1);
}