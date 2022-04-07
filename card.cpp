#include <iostream>
#include <string>

#include "card.h"

Card::Card(Suit suit, Value value) {
    this ->suit = suit; //dereference pointer to current instance
    this ->value = value;
}

Card::~Card() {

}

void Card::printCard() {
    std::string output;

    switch (this->value) {
        case Value::two:
            output += "Two of ";
            break;
        case Value::three:
            output += "Three of ";
            break;
        case Value::four:
            output += "Four of ";
            break;
        case Value::five:
            output += "Five of ";
            break;
        case Value::six:
            output += "Six of ";
            break;
        case Value::seven:
            output += "Seven of ";
            break;
        case Value::eight:
            output += "Eight of ";
            break;
        case Value::nine:
            output += "Nine of ";
            break;
        case Value::ten:
            output += "Ten of ";
            break;
        case Value::jack:
            output += "Jack of ";
            break;
        case Value::queen:
            output += "Queen of ";
            break;
        case Value::king:
            output += "King of ";
            break;
        case Value::ace:
            output += "Ace of ";
            break;
    }

    switch (this->suit) {
        case Suit::club:
            output += "Clubs";
            break;
        case Suit::diamond:
            output += "Diamonds";
            break;
        case Suit::heart:
            output += "Hearts";
            break;
        case Suit::spade:
            output += "Spades";
            break;
    }

    std::cout << output << std::endl;
}

bool Card::sameSuit(Card compare) {
    if (this -> suit == compare.suit) {
        return true;
    }
    return false;
}

int Card::compareValue(Card compare) {
    if (this->value < compare.value) {
        return -1;
    }
    if (this->value > compare.value) {
        return 1;
    }

    return 0;
}

int Card::getValue()  {
    return value;
}

int Card::getSuit() {
    return suit;
}