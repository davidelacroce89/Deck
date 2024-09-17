#include "deck.h"

#include <iostream>



template <typename T>
Deck<T>::Deck()
{
    std::cout << "The Deck is empty";
}

template <typename T>
void Deck<T>::add(const T& element)
{
    m_deck.push_back(element);
}

// Draw (remove and return) an element from the top of the deck
template <typename T>
T Deck<T>::top() 
{
    if (isEmpty()) 
    {
        throw std::out_of_range("The deck is empty!");
    }
    return m_deck.front();  // Get the element at the front
}

// Draw (remove and return) an element from the top of the deck
template <typename T>
T Deck<T>::bottom() 
{
    if (isEmpty()) 
    {
        throw std::out_of_range("The deck is empty!");
    }
    return m_deck.back();  // Get the element at the front
}

// Shuffle the deck
template <typename T>
void Deck<T>::shuffle() 
{
    //TODO I will do it later...
}

// Draw (remove and return) an element from the top of the deck
template <typename T>
T Deck<T>::draw() 
{
    if (isEmpty()) 
    {
        throw std::out_of_range("The deck is empty!");
    }
    auto top = m_deck.front();  // Get the element at the front
    m_deck.pop_front();      // Remove the element from the front
    return top;
}

// Check if the deck is empty
template <typename T>
bool Deck<T>::isEmpty() const {
    return m_deck.empty();
}

// Print the deck contents (for debugging purposes)
template <typename T>
void Deck<T>::printDeck() const 
{
    for (const auto& card : m_deck) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}


// Explicit instantiation for the Deck<int> type
template class Deck<int>;

template class Deck<std::string>;