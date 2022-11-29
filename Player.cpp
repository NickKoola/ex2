#include "Player.h"
#include "utilities.h"

#include <iostream>

using  std::string;

Player::Player(string name, int maxHP, int force)
{
    if(maxHP <= 0) {
        m_maxHP = 100;
    }
    else {
        m_maxHP = maxHP;
    }

    if(force < 0){
        m_force = 5;
    }
    else {
        m_force = force;
    }

    m_name = name; 
    m_level = 1;
    m_hp = m_maxHP;
    m_coins = 0;
}

void Player::printInfo()  // TODO
{
    printPlayerInfo(m_name.c_str(), this->m_level,
                    this->m_force, this->m_hp, this->m_coins);
}

void Player::levelUp() {
    if(m_level < 10){
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int buffAmount) {
    if(buffAmount > 0) {
        m_force += buffAmount;
    }
}

void Player::heal(int healAmount) {
    if(healAmount > 0) {
        if(m_hp + healAmount > m_maxHP) {
            m_hp = m_maxHP;
        }
        else {
            m_hp += healAmount;
        }
    }
}

void Player::damage(int damageRecieved) {
    if(damageRecieved > 0) {
        if(damageRecieved > m_hp) {
            m_hp = 0;
        }
        else {
            m_hp -= damageRecieved;
        }
    }
}

bool Player::isKnockedOut() const {
    return (m_hp == 0);
}

void Player::addCoins(int coinsRecieved) {
    if(coinsRecieved > 0) {
        m_coins += coinsRecieved;
    }
}

bool Player::pay(int price) { // what if price is negative
    if(m_coins >= price) {
        m_coins -= price;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const {
    return (m_force + m_level);
}


/*
int main() {
    string name1 = "nick";
   // Player p1 = Player(name1, 132, 3);
    //p1.printInfo();
}
*/