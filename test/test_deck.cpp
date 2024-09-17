#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include "deck.h"


TEST_CASE("Test int")
{
    Deck<int> deck;

    deck.add(34);

    auto elem = deck.top();

    REQUIRE(elem == 34);

}

TEST_CASE("Test string")
{
    Deck<std::string> deck;

    deck.add("Asso di bastoni");
    deck.add("Quattro di coppe");

    REQUIRE(deck.top() == "Asso di bastoni");
    REQUIRE(deck.bottom() == "Quattro di coppe");

}