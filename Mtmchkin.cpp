#include "Mtmchkin.h"
#include <string>
#include "Player.h"

#include <iostream>
using std::string;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
                    m_numOfCards(numOfCards), m_gameStatus(GameStatus::MidGame), m_player(playerName)
{
    Card* temp = new Card[numOfCards];
    for(int i = 0; i < numOfCards; i++){
        temp[i] = cardsArray[i];
    }
    this->m_deck = temp;
}

int main() {
    
}