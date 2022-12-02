#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
                    m_numOfCards(numOfCards), m_gameStatus(GameStatus::MidGame), m_player(playerName),
                                m_currCardIndex(FIRST_INDEX)
{
    Card* temp = new Card[numOfCards];
    for(int i = 0; i < numOfCards; i++){
        temp[i] = cardsArray[i];
    }
    this->m_deck = temp;
}

Mtmchkin::~Mtmchkin() {
    delete []m_deck;
}

void Mtmchkin::playNextCard() {
    m_deck[m_currCardIndex].printInfo();
    m_deck[m_currCardIndex].applyEncounter(m_player);
    m_player.printInfo();
    m_currCardIndex++;
    if(m_currCardIndex == m_numOfCards) {
        m_currCardIndex = FIRST_INDEX;
    }

    if(m_player.getLevel() == MAX_LEVEL) { // should write Player::MAX_LEVEL?
        m_gameStatus = GameStatus::Win;
    }
    if(m_player.isKnockedOut()) {
        m_gameStatus = GameStatus::Loss;
    }
}

bool Mtmchkin::isOver() const {
    return(m_gameStatus != GameStatus::MidGame);
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_gameStatus;
}