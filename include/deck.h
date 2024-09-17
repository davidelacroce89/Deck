#ifndef DECK_H
#define DECK_H

#include <list>

// Template class Deck declaration
template <typename T>
class Deck 
{
public:
    Deck();

    // Returns the “top” value of the deck
    T top();

    //Returns the “bottom” value of the deck
    T bottom();

    // Draw (remove and return) an element from the top of the deck
    T draw();

    // Insert an element at the back of the deck
    void add(const T& element);

    // Shuffle the deck
    void shuffle();


    // Check if the deck is empty
    bool isEmpty() const;

    // Print the deck contents (for debugging purposes)
    void printDeck() const;

private:

    //List allows easy insertion in between, otherwise a std::vector is easier...
    std::list<T> m_deck;  // std::list used as the underlying container
};

#endif // DECK_H
