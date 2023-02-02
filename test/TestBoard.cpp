#include <boost/test/unit_test.hpp>
#include "Pawn.h"
#include "Piece.h"


BOOST_AUTO_TEST_SUITE(BoardTest)

    BOOST_AUTO_TEST_CASE(TestFigures) {
        auto pawn = Pawn(0,0,1,"Pawn");
        auto pawn2 = Pawn(7,7,0,"Pawn");

        BOOST_REQUIRE_EQUAL(pawn.GetPosIndex(),0);
        BOOST_REQUIRE_EQUAL(pawn2.GetPosIndex(),63);
        BOOST_REQUIRE_EQUAL(pawn2.GetPieceName(),"Pawn");
        BOOST_REQUIRE_EQUAL(pawn2.GetColor(),0);

    }


BOOST_AUTO_TEST_SUITE_END()
