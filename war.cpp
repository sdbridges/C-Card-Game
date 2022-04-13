#include <iostream>

#include "war.h"

War::War() {  //constructor

}

War::~War() {  //destructor

}

void War::play() {
    Deck deck;  //create a deck
    deck.shuffle();  //shuffle the deck

    //Deal 26 shuffled cards to player
    for (int i = 0; i < 26; i++) {
        Card* card = deck.draw();
        this->player1hand.push(card);
    }

    //Deal 26 shuffled cards to computer
    for (int i = 26; i < 52; i++) {
        Card* card = deck.draw();
        this->computerhand.push(card);
    }

//    while (!player1hand.empty()) {
//        std::cout << this->player1hand.front()->print() <<  std::endl;
//        player1hand.pop();
//    }
//
//
//    std::cout << "\n" << std::endl;
//    while (!computerhand.empty()) {
//        std::cout << this->computerhand.front()->print() << std::endl;
//        computerhand.pop();
//    }


    std::string playerName;
    std::cout << "Welcome to War !!  Enter your name to begin first round: ";
    std::cin >> playerName;

    std::cout << "Hello, " << playerName << ".  Welcome to round 1 !!"  << std::endl;

        while ((!player1hand.empty()) && (!computerhand.empty())) {
            std::cout << std::endl;
            std::cout << "You play: " << player1hand.front()->print() << std::endl;
            std::cout << "Computer plays: " << computerhand.front()->print() << std::endl;


            // if players card is greater than computer's card put into bottom of players deck
            if (player1hand.front()->getValue() > computerhand.front()->getValue()) {
                std::cout << "*You win the round !!*" << std::endl;
                player1hand.push(computerhand.front());
                player1hand.push(player1hand.front());
                player1hand.pop();
                computerhand.pop();
                std::cout << player1hand.size() << std::endl;
                std::cout << computerhand.size() << std::endl;
                std::string keepGoing;
                std::cout << std::endl;
                std::cout << "Enter c to continue or any other key to forfeit\n";;
                std::cin >> keepGoing;
                if (keepGoing == "c") {
                    continue;
                } else {
                    break;
                }
                // if computers card is greater than the players card put into bottom of computers deck
            } else if (computerhand.front()->getValue() > player1hand.front()->getValue()) {
                std::cout << "*Computer wins the round !!*" << std::endl;
                computerhand.push(player1hand.front());
                computerhand.push(computerhand.front());
                player1hand.pop();
                computerhand.pop();
                std::cout << player1hand.size() << std::endl;
                std::cout << computerhand.size() << std::endl;
                std::string keepGoing;
                std::cout << std::endl;
                std::cout << "Enter c to continue or any other key to forfeit\n";;
                std::cin >> keepGoing;
                if (keepGoing == "c") {
                    continue;
                } else {
                    break;
                }
                //card values are equal
            } else {
                    //Cards are the same suit and value
                    std::cout << "It is war, winner gets all 6 cards!!!!" << std::endl;
                    tempstack.push(player1hand.front());  //the original cards that are equal
                    tempstack.push(computerhand.front());
                    player1hand.pop();
                    computerhand.pop();
                    tempstack.push(player1hand.front());  //player's face down down card
                    tempstack.push(computerhand.front()); //computer's face down card
                    player1hand.pop();
                    computerhand.pop();
                    //Re-init comparison checks
                    // Compare face up card values
                    if (player1hand.front()->getValue() > computerhand.front()->getValue()) {
                        std::cout << "*You win the round !!*" << std::endl;
                        tempstack.push(computerhand.front());  //face up cards
                        tempstack.push(player1hand.front());
                        player1hand.pop();
                        computerhand.pop();
                        //add other 4 cards to bottom of players hand
                        while (!tempstack.empty()) {
                            player1hand.push(tempstack.top());
                            tempstack.pop();
                        }
                        std::cout << player1hand.size() << std::endl;
                        std::cout << computerhand.size() << std::endl;
                        std::string keepGoing;
                        std::cout << std::endl;
                        std::cout << "Enter c to continue or any other key to forfeit\n";;
                        std::cin >> keepGoing;
                        if (keepGoing == "c") {
                            continue;
                        } else {
                            break;
                        }
                        std::cout << player1hand.size() << std::endl;
                        std::cout << computerhand.size() << std::endl;
                    } else if (computerhand.front()->getValue() > player1hand.front()->getValue()) {
                        std::cout << "*Computer wins the round !!*" << std::endl;
                        tempstack.push(player1hand.front()); //face up cards
                        tempstack.push(computerhand.front());
                        player1hand.pop();
                        computerhand.pop();
                        //add other 4 cards to bottom of computers hand
                        while (!tempstack.empty()) {
                            computerhand.push(tempstack.top());
                            tempstack.pop();
                        }
                        std::cout << player1hand.size() << std::endl;
                        std::cout << computerhand.size() << std::endl;
                        std::string keepGoing;
                        std::cout << std::endl;
                        std::cout << "Enter c to continue or any other key to forfeit\n";;
                        std::cin >> keepGoing;
                        if (keepGoing == "c") {
                            continue;
                        } else {
                            break;
                        }
                    } else {
                       std::cout << " It is war again winner, gets all 10 cards!!!!"  << std::endl;
                        player1hand.pop();
                        computerhand.pop();
                        tempstack.push(player1hand.front());  //player's face down down card
                        tempstack.push(computerhand.front()); //computer's face down card
                        player1hand.pop();
                        computerhand.pop();
                        //Re-init comparison checks
                        // Compare face up card values
                        if (player1hand.front()->getValue() > computerhand.front()->getValue()) {
                            std::cout << "*You win the round !!*" << std::endl;
                            tempstack.push(computerhand.front());  //face up cards
                            tempstack.push(player1hand.front());
                            player1hand.pop();
                            computerhand.pop();
                            //add other 4 cards to bottom of players hand
                            while (!tempstack.empty()) {
                                player1hand.push(tempstack.top());
                                tempstack.pop();
                            }
                            std::cout << player1hand.size() << std::endl;
                            std::cout << computerhand.size() << std::endl;
                            std::string keepGoing;
                            std::cout << std::endl;
                            std::cout << "Enter c to continue or any other key to forfeit\n";;
                            std::cin >> keepGoing;
                            if (keepGoing == "c") {
                                continue;
                            } else {
                                break;
                            }
                            std::cout << player1hand.size() << std::endl;
                            std::cout << computerhand.size() << std::endl;
                        } else if (computerhand.front()->getValue() > player1hand.front()->getValue()) {
                            std::cout << "*Computer wins the round !!*" << std::endl;
                            tempstack.push(player1hand.front()); //face up cards
                            tempstack.push(computerhand.front());
                            player1hand.pop();
                            computerhand.pop();
                            //add other 4 cards to bottom of computers hand
                            while (!tempstack.empty()) {
                                computerhand.push(tempstack.top());
                                tempstack.pop();
                            }
                            std::cout << player1hand.size() << std::endl;
                            std::cout << computerhand.size() << std::endl;
                            std::string keepGoing;
                            std::cout << std::endl;
                            std::cout << "Enter c to continue or any other key to forfeit\n";;
                            std::cin >> keepGoing;
                            if (keepGoing == "c") {
                                continue;
                            } else {
                                break;
                            }
                        } else {
                            std::cout << " It is war again, winner gets all 14 cards !!!!"  << std::endl;
                            player1hand.pop();
                            computerhand.pop();
                            tempstack.push(player1hand.front());  //player's face down down card
                            tempstack.push(computerhand.front()); //computer's face down card
                            player1hand.pop();
                            computerhand.pop();
                            //Re-init comparison checks
                            // Compare face up card values
                            if (player1hand.front()->getValue() > computerhand.front()->getValue()) {
                                std::cout << "*You win the round !!*" << std::endl;
                                tempstack.push(computerhand.front());  //face up cards
                                tempstack.push(player1hand.front());
                                player1hand.pop();
                                computerhand.pop();
                                //add other 4 cards to bottom of players hand
                                while (!tempstack.empty()) {
                                    player1hand.push(tempstack.top());
                                    tempstack.pop();
                                }
                                std::cout << player1hand.size() << std::endl;
                                std::cout << computerhand.size() << std::endl;
                                std::string keepGoing;
                                std::cout << std::endl;
                                std::cout << "Enter c to continue or any other key to forfeit\n";;
                                std::cin >> keepGoing;
                                if (keepGoing == "c") {
                                    continue;
                                } else {
                                    break;
                                }
                                std::cout << player1hand.size() << std::endl;
                                std::cout << computerhand.size() << std::endl;
                            } else if (computerhand.front()->getValue() > player1hand.front()->getValue()) {
                                std::cout << "*Computer wins the round !!*" << std::endl;
                                tempstack.push(player1hand.front()); //face up cards
                                tempstack.push(computerhand.front());
                                player1hand.pop();
                                computerhand.pop();
                                //add other 4 cards to bottom of computers hand
                                while (!tempstack.empty()) {
                                    computerhand.push(tempstack.top());
                                    tempstack.pop();
                                }
                                std::cout << player1hand.size() << std::endl;
                                std::cout << computerhand.size() << std::endl;
                                std::string keepGoing;
                                std::cout << std::endl;
                                std::cout << "Enter c to continue or any other key to forfeit\n";;
                                std::cin >> keepGoing;
                                if (keepGoing == "c") {
                                    continue;
                                } else {
                                    break;
                                }
                            } else {
                                std::cout << " It is war again winner gets all 18 cards!!!!"  << std::endl;
                                player1hand.pop();
                                computerhand.pop();
                                tempstack.push(player1hand.front());  //player's face down down card
                                tempstack.push(computerhand.front()); //computer's face down card
                                player1hand.pop();
                                computerhand.pop();
                                //Re-init comparison checks
                                // Compare face up card values
                                if (player1hand.front()->getValue() > computerhand.front()->getValue()) {
                                    std::cout << "*You win the round !!*" << std::endl;
                                    tempstack.push(computerhand.front());  //face up cards
                                    tempstack.push(player1hand.front());
                                    player1hand.pop();
                                    computerhand.pop();
                                    //add other 4 cards to bottom of players hand
                                    while (!tempstack.empty()) {
                                        player1hand.push(tempstack.top());
                                        tempstack.pop();
                                    }
                                    std::cout << player1hand.size() << std::endl;
                                    std::cout << computerhand.size() << std::endl;
                                    std::string keepGoing;
                                    std::cout << std::endl;
                                    std::cout << "Enter c to continue or any other key to forfeit\n";;
                                    std::cin >> keepGoing;
                                    if (keepGoing == "c") {
                                        continue;
                                    } else {
                                        break;
                                    }
                                    std::cout << player1hand.size() << std::endl;
                                    std::cout << computerhand.size() << std::endl;
                                } else if (computerhand.front()->getValue() > player1hand.front()->getValue()) {
                                    std::cout << "*Computer wins the round !!*" << std::endl;
                                    tempstack.push(player1hand.front()); //face up cards
                                    tempstack.push(computerhand.front());
                                    player1hand.pop();
                                    computerhand.pop();
                                    //add other 4 cards to bottom of computers hand
                                    while (!tempstack.empty()) {
                                        computerhand.push(tempstack.top());
                                        tempstack.pop();
                                    }
                                    std::cout << player1hand.size() << std::endl;
                                    std::cout << computerhand.size() << std::endl;
                                    std::string keepGoing;
                                    std::cout << std::endl;
                                    std::cout << "Enter c to continue or any other key to forfeit\n";;
                                    std::cin >> keepGoing;
                                    if (keepGoing == "c") {
                                        continue;
                                    } else {
                                        break;
                                    }
                                } else {
                                    std::cout << " It is war again winner gets all 22 cards!!!!"  << std::endl;
                                    player1hand.pop();
                                    computerhand.pop();
                                    tempstack.push(player1hand.front());  //player's face down down card
                                    tempstack.push(computerhand.front()); //computer's face down card
                                    player1hand.pop();
                                    computerhand.pop();
                                    //Re-init comparison checks
                                    // Compare face up card values
                                    if (player1hand.front()->getValue() > computerhand.front()->getValue()) {
                                        std::cout << "*You win the round !!*" << std::endl;
                                        tempstack.push(computerhand.front());  //face up cards
                                        tempstack.push(player1hand.front());
                                        player1hand.pop();
                                        computerhand.pop();
                                        //add other 4 cards to bottom of players hand
                                        while (!tempstack.empty()) {
                                            player1hand.push(tempstack.top());
                                            tempstack.pop();
                                        }
                                        std::cout << player1hand.size() << std::endl;
                                        std::cout << computerhand.size() << std::endl;
                                        std::string keepGoing;
                                        std::cout << std::endl;
                                        std::cout << "Enter c to continue or any other key to forfeit\n";;
                                        std::cin >> keepGoing;
                                        if (keepGoing == "c") {
                                            continue;
                                        } else {
                                            break;
                                        }
                                        std::cout << player1hand.size() << std::endl;
                                        std::cout << computerhand.size() << std::endl;
                                    } else if (computerhand.front()->getValue() > player1hand.front()->getValue()) {
                                        std::cout << "*Computer wins the round !!*" << std::endl;
                                        tempstack.push(player1hand.front()); //face up cards
                                        tempstack.push(computerhand.front());
                                        player1hand.pop();
                                        computerhand.pop();
                                        //add other 4 cards to bottom of computers hand
                                        while (!tempstack.empty()) {
                                            computerhand.push(tempstack.top());
                                            tempstack.pop();
                                        }
                                        std::cout << player1hand.size() << std::endl;
                                        std::cout << computerhand.size() << std::endl;
                                        std::string keepGoing;
                                        std::cout << std::endl;
                                        std::cout << "Enter c to continue or any other key to forfeit\n";;
                                        std::cin >> keepGoing;
                                        if (keepGoing == "c") {
                                            continue;
                                        } else {
                                            break;
                                        }
                                    } else {
                                        std::cout << " It is war again, winner gets all 26 cards!!!!"  << std::endl;
                                        player1hand.pop();
                                        computerhand.pop();
                                        tempstack.push(player1hand.front());  //player's face down down card
                                        tempstack.push(computerhand.front()); //computer's face down card
                                        player1hand.pop();
                                        computerhand.pop();
                                        //Re-init comparison checks
                                        // Compare face up card values
                                        if (player1hand.front()->getValue() > computerhand.front()->getValue()) {
                                            std::cout << "*You win the round !!*" << std::endl;
                                            tempstack.push(computerhand.front());  //face up cards
                                            tempstack.push(player1hand.front());
                                            player1hand.pop();
                                            computerhand.pop();
                                            //add other 4 cards to bottom of players hand
                                            while (!tempstack.empty()) {
                                                player1hand.push(tempstack.top());
                                                tempstack.pop();
                                            }
                                            std::cout << player1hand.size() << std::endl;
                                            std::cout << computerhand.size() << std::endl;
                                            std::string keepGoing;
                                            std::cout << std::endl;
                                            std::cout << "Enter c to continue or any other key to forfeit\n";;
                                            std::cin >> keepGoing;
                                            if (keepGoing == "c") {
                                                continue;
                                            } else {
                                                break;
                                            }
                                            std::cout << player1hand.size() << std::endl;
                                            std::cout << computerhand.size() << std::endl;
                                        } else if (computerhand.front()->getValue() > player1hand.front()->getValue()) {
                                            std::cout << "*Computer wins the round !!*" << std::endl;
                                            tempstack.push(player1hand.front()); //face up cards
                                            tempstack.push(computerhand.front());
                                            player1hand.pop();
                                            computerhand.pop();
                                            //add other 4 cards to bottom of computers hand
                                            while (!tempstack.empty()) {
                                                computerhand.push(tempstack.top());
                                                tempstack.pop();
                                            }
                                            std::cout << player1hand.size() << std::endl;
                                            std::cout << computerhand.size() << std::endl;
                                            std::string keepGoing;
                                            std::cout << std::endl;
                                            std::cout << "Enter c to continue or any other key to forfeit\n";;
                                            std::cin >> keepGoing;
                                            if (keepGoing == "c") {
                                                continue;
                                            } else {
                                                break;
                                            }
                                        } else {
                                            std::cout << " No more cards, you should play the lottery!!"  << std::endl;
                                            std::cout << "Now make a rock, paper, scissors AI to break the tie!!"  << std::endl;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
            }
        }


    winner();


}

void War::winner() {
    std::cout << "You have " << player1hand.size() << " cards left." << std::endl;
    std::cout << "Computer has " << computerhand.size() << " cards left." << std::endl;

    if (computerhand.size() > player1hand.size()) {
        std::cout << "\nComputer wins the game" << std::endl;
    } else if (player1hand.size() > computerhand.size()){
        std::cout << "\nYou win the game !!" << std::endl;
    } else {
        std::cout << "\nGame is a tie" << std::endl;
    }
}