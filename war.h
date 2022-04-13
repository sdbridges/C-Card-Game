#ifndef UNTITLED2_WAR_H
#define UNTITLED2_WAR_H

#include <queue>
#include <stack>

#include "deck.h"

#define CARDS 26

class War {
public:
    War();
    ~War();

public:
    void play();
    void winner();
    void gameOver();  //create function for new version (more modularized)

protected:
    std::queue<Card*> computerhand;
    std::queue<Card*> player1hand;
    std::stack<Card*> tempstack;
};


#endif
