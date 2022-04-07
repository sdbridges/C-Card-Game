#include <iostream>
#include <algorithm>
#include <random>

#include "deck.h"

Deck::Deck():deck() {
    deck.reserve(noOfCards);  //buffer 52 bytes

    for (int suit = 0; suit < 4; suit++) {
        for (int value = 0; value < 13; value++) {
            Card* card = new Card(static_cast<Card::Suit>(suit), static_cast<Card::Value>(value));
            this -> deck.push_back(card);
//            std::cout << card->getValue() << "  " <<  &card[value]  << std::endl;
//            deck.push_back(new Card(static_cast<Card::Suit>(suit), static_cast<Card::Value>(value)));
        }
    }
}

void Deck::shuffle() {

    //clear the stack
    while (!stack.empty()) {
        stack.top() = NULL; //clear data
        stack.pop();  //pop node from stack
    }

    //shuffle the deck using algorithm
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));

    //repopulate stack with full deck (pointers)
    for (int i = 0; i < noOfCards; i++) {
        stack.push(deck[i]);
    }
}

Card* Deck::draw() {

    //receive a pointer to the Card on top
    int cardSuit = stack.top()->getSuit();
    int cardValue = stack.top()->getValue();
    Card* card = new Card(static_cast<Card::Suit>(cardSuit), static_cast<Card::Value>(cardValue));

    stack.top() = NULL;  //clears data on top card
    stack.pop();  //remove node
    return card;

}

void Deck::printDeck() {
    for (Card* card : deck) {
        card->printCard();
    }
}

Deck::~Deck() {
    // free the memory associated with each Card instance
    for (Card* card : deck) {
        delete card;
    }

    while (!stack.empty()) {
        stack.top() = NULL;
        stack.pop();
    }

    deck.clear();
}


