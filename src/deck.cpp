#include "deck.h"


#include <algorithm>
#include <random> 


template <typename T>
void Deck<T>::add(const T& element)
{
    m_vector.push_back(element);
}

// Draw (remove and return) an element from the top of the deck
template <typename T>
T Deck<T>::top() 
{
    if (empty()) 
    {
        throw std::out_of_range("The deck is empty!");
    }
    return m_vector.front();  // Get the element at the front
}

// Draw (remove and return) an element from the top of the deck
template <typename T>
T Deck<T>::bottom() 
{
    if (empty()) 
    {
        throw std::out_of_range("The deck is empty!");
    }
    return m_vector.back();  // Get the element at the front
}

// Not sure how to shuffle the list, but the std::vector can be shuffled easier
template <typename T>
void Deck<T>::shuffle(int seed) 
{
    // Convert list to vector
    std::vector<T> temp(m_vector.begin(), m_vector.end());

    std::default_random_engine engine(seed);

    // Shuffle the vector
    std::shuffle(temp.begin(), temp.end(), engine);

    //clear and add in place to the private list
    m_vector.clear();
    m_vector.insert(m_vector.end(), temp.begin(), temp.end());
}

// Draw (remove and return) an element from the top of the deck
template <typename T>
T Deck<T>::draw() 
{
    if (empty()) 
    {
        throw std::out_of_range("The deck is empty!");
    }
    auto top = m_vector.front();  // Get the element at the front
    m_vector.erase(m_vector.begin());      // Remove the element from the front
    return top;
}


// Print the deck contents (for debugging purposes)
template <typename T>
void Deck<T>::printDeck() const 
{
    std::cout << "Deck content:" << std::endl;
    for (const auto& elem : m_vector) {
        std::cout << elem << std::endl;
    }
    std::cout << std::endl;
}


// Explicit instantiation for the Deck<int> type
template class Deck<int>;
template class Deck<std::string>;