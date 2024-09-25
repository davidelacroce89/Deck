#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include <iostream>
#include "deck.h"

TEST_CASE("Test Container requirements")
{
    Deck<int> deck;

    REQUIRE(deck.empty());
    REQUIRE(deck.size() == 0);

    deck.add(-24);
    REQUIRE(!deck.empty());
    REQUIRE(deck.size() == 1);

    deck.add(7344346);
    REQUIRE(!deck.empty());
    REQUIRE(deck.size() == 2);

    //test operator []
    REQUIRE(deck[deck.size()-1] == 7344346);

    //test iterator change by reference
    std::cout << "List and modify with constant" << std::endl;
    for (auto &elem: deck)
    {
        std::cout << "Before: " << elem << std::endl;
        elem+=345345345;
    }

    std::cout << "List as const reference" << std::endl;
    for (auto const &elem: deck)
    {
        std::cout << "After: " << elem << std::endl;
    }

    std::cout << "Max size: " << deck.max_size() << std::endl;

}

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

