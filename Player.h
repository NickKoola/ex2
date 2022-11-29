#ifndef PLAYER_H
#define PLAYER_H

#include <string>
const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;
class Player{
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coins;

public:
    Player(std::string name, int maxHP, int force); 
    Player(std::string name,int maxHP): Player(name, maxHP,DEFAULT_FORCE) {};
    Player(std::string name): Player(name, DEFAULT_MAX_HP,DEFAULT_FORCE) {};

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