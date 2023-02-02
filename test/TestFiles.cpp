#include <boost/test/unit_test.hpp>

#include "filesystem"

BOOST_AUTO_TEST_SUITE(AnimalsTests)

    BOOST_AUTO_TEST_CASE(testNormalCat_OneDay_ExpectedCost) {
        BOOST_REQUIRE(std::filesystem::exists("Rook.png"));
        BOOST_REQUIRE(std::filesystem::exists("Queen.png"));
        BOOST_REQUIRE(std::filesystem::exists("Pawn.png"));
        BOOST_REQUIRE(std::filesystem::exists("Knight.png"));
        BOOST_REQUIRE(std::filesystem::exists("Bishop.png"));
        BOOST_REQUIRE(std::filesystem::exists("King.png"));

        BOOST_REQUIRE(std::filesystem::exists("RookB.png"));
        BOOST_REQUIRE(std::filesystem::exists("QueenB.png"));
        BOOST_REQUIRE(std::filesystem::exists("PawnB.png"));
        BOOST_REQUIRE(std::filesystem::exists("KnightB.png"));
        BOOST_REQUIRE(std::filesystem::exists("BishopB.png"));
        BOOST_REQUIRE(std::filesystem::exists("KingB.png"));

        BOOST_REQUIRE(std::filesystem::exists("basic_input.txt"));
        BOOST_REQUIRE(std::filesystem::exists("save.txt"));

    }


BOOST_AUTO_TEST_SUITE_END()
