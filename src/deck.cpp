#include "deck.h"

#include <iostream>
#include <algorithm>
#include <random> 


template <typename T>
Deck<T>::Deck()
{
    std::cout << "The Deck is empty" << std::endl;
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

// Not sure how to shuffle the list, but the std::vector can be shuffled easier
template <typename T>
void Deck<T>::shuffle(int seed) 
{
    // Convert list to vector
    std::vector<T> temp(m_deck.begin(), m_deck.end());

    std::default_random_engine engine(seed);

    // Shuffle the vector
    std::shuffle(temp.begin(), temp.end(), engine);

    //clear and add in place to the private list
    m_deck.clear();
    m_deck.insert(m_deck.end(), temp.begin(), temp.end());
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
    std::cout << "Deck content:" << std::endl;
    for (const auto& elem : m_deck) {
        std::cout << elem << std::endl;
    }
    std::cout << std::endl;
}


// Explicit instantiation for the Deck<int> type
template class Deck<int>;

template class Deck<std::string>;