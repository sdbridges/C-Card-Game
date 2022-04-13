#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
    enum Suit{CLUB, DIAMOND, HEART, SPADE};
    enum Value{TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

public:
    Card(Suit suit, Value value);
    ~Card();

public:
    std::string print();
    bool sameSuit(Card compare);
    int compareValue(Card compare);
    int getValue();
    int getSuit();

protected:
    Suit suit;
    Value value;
};

#endif
