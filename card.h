#ifndef CARD_H  //include guard
#define CARD_H

class Card

{
public:
    enum Suit { club, diamond, heart, spade };
    enum Value{ two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

protected:
    Suit suit;  //instance variables
    Value value;

public:
    Card(Suit suit, Value value); //constructor for Card class instantiation
    ~Card(); //destructor

public:
    void printCard ();
    bool sameSuit(Card compare);
    int compareValue(Card compare);
    int getValue();
    int getSuit();
};

#endif