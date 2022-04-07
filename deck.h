#ifndef DECK_H  //include guard
#define DECK_H
#include <vector>
#include <stack>

#include "card.h"

class Deck {
protected:
    //vectors have O(1) random access
    std::vector<Card*> deck;  //heterogeneous dynamic container of polymorphic Card object pointers (allocated separately on the heap)
    //stacks have O(1) insertion and deletion making it ideal for drawing a card LIFO
    std::stack<Card*> stack;
    int noOfCards = 52;  //limit to 52-card deck of cards

public:
    Deck();
    ~Deck();

    void shuffle();
    Card* draw();
    void printDeck();
};

#endif
