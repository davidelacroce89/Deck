#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include "deck.h"


TEST_CASE("Test int")
{
    Deck<int> deck;

    deck.add(34);
    deck.add(76);
    deck.printDeck();

    REQUIRE(deck.top() == 34);

    REQUIRE(deck.bottom() == 76);

    //draw comes from the top and it removed the element
    REQUIRE(deck.draw() == 34);

    deck.printDeck();

    REQUIRE(deck.bottom() == deck.top());

}

TEST_CASE("Test string")
{
    Deck<std::string> deck;

    deck.add("Asso di bastoni");
    deck.add("Quattro di coppe");
    deck.printDeck();

    REQUIRE(deck.top() == "Asso di bastoni");
    REQUIRE(deck.bottom() == "Quattro di coppe");

}

TEST_CASE("Test shuffle")
{
    Deck<int> deck;

    deck.add(23424);
    deck.add(-234323);
    deck.add(-23);
    deck.add(0);
    deck.printDeck();

    deck.shuffle();

    deck.printDeck();

    deck.shuffle(2312);

    deck.printDeck();

}

