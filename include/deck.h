#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>

/*
 * This class is implemnting all the requirements from a Container
 * for reference https://en.cppreference.com/w/cpp/named_req/Container
 */
template <typename T>
class Deck 
{
public:

    // Required member types
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using difference_type = typename std::vector<T>::difference_type;
    using size_type = typename std::vector<T>::size_type;

    // Constructors
    Deck() = default;

    //allocate the default value for the type int is zero, string is ""
    explicit Deck(size_type n): m_vector(n)
    {
        std::cout << "The new deck has " << n << " empty elementes" << std::endl;
    }

    // Copy constructor
    Deck(const Deck& B) : m_vector(B.m_vector) {}

    // Move constructor
    Deck(Deck&& B) noexcept : m_vector(std::move(B.m_vector)) {}

    // Copy assignment operator
    Deck& operator=(const Deck& B) {
        if (this != &B) {
            m_vector = B.m_vector;
        }
        return *this;
    }

    // Move assignment operator
    Deck& operator=(Deck&& B) noexcept {
        if (this != &B) {
            m_vector = std::move(B.m_vector);
        }
        return *this;
    }

    ~Deck() {m_vector.clear();}

    // Required methods
    iterator begin() { return m_vector.begin(); }
    const_iterator begin() const { return m_vector.begin(); }

    iterator end() { return m_vector.end(); }
    const_iterator end() const { return m_vector.end(); }

    size_type size() const { return m_vector.size(); }
    size_type max_size() const { return m_vector.max_size(); }
    bool empty() const { return m_vector.empty(); }

    // Element access
    reference operator[](size_type i) { return m_vector[i]; }
    const_reference operator[](size_type i) const { return m_vector[i]; }

    // Swap function
    void swap(Deck& B) noexcept {
        std::swap(m_vector, B.m_vector);
        std::cout << "Deck swapped." << std::endl;
    }


    // Returns the “top” value of the deck
    T top();

    //Returns the “bottom” value of the deck
    T bottom();

    // Draw (remove and return) an element from the top of the deck
    T draw();

    // Insert an element at the back of the deck
    void add(const T& element);

    // Shuffle the deck
    void shuffle(int seed = 1106);

    // Print the deck contents (for debugging purposes)
    void printDeck() const;

private:

    //List would allows easy insertion in between but otherwise a std::vector is easier...
    std::vector<T> m_vector;
};

#endif // DECK_H
