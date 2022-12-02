#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "utilities.h"

const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;
const int STARTING_LEVEL = 1;
const int STARTING_COINS = 0;
const int MAX_LEVEL = 10;
class Player{
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coins;

public:
    
    Player(std::string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE); 

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player& other) = default;
    ~Player() = default; 
    Player& operator=(const Player& player) = default;

    void printInfo();
    void levelUp();
    int getLevel() const;
    void buff(int buffAmount);
    void heal(int healAmount);
    void damage(int damageRecieved);
    bool isKnockedOut() const;
    void addCoins(int coinsRecieved);
    bool pay(int price);
    int getAttackStrength() const;


};

#endif