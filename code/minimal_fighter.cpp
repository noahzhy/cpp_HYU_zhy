#include <iostream>
#include "minimal_fighter.h"
using namespace std;

MinimalFighter::MinimalFighter()
{
    this->mHp = 0;
    this->mPower = 0;
}

MinimalFighter::MinimalFighter(int _hp, int _power)
{
    this->mHp = _hp;
    this->mPower = _power;
}

int MinimalFighter::hp() const {
    return this->mHp;
}

int MinimalFighter::power()const {
    return this->mPower;
}

FighterStatus MinimalFighter::status()const {
    return this->mStatus;
}

void MinimalFighter::setHp(int _hp) {
    this->mHp = _hp;
    if (this->mHp <= 0) {this->mStatus = Dead;}
}
void MinimalFighter::hit(MinimalFighter *_enemy) {
    setHp (hp() - 1);
    _enemy-> setHp(_enemy->hp() - 1);
}

void MinimalFighter::attack(MinimalFighter *_target) {
    _target->setHp(_target->hp() - power());
    mPower = power() - 3;
}

void MinimalFighter::fight(MinimalFighter *_enemy) {
    while (hp() > 0 && _enemy->hp() > 0) {
        hit(_enemy);
    }
}

