// minimal_fighter.h
// Implement your minimal_fighter.cc

#ifndef __hw03__minimal_fighter__
#define __hw03__minimal_fighter__

#include <iostream>
using namespace std;

enum EFighterStatus
{
    Invalid = 0,

    Alive,
    Dead,
};
typedef enum EFighterStatus FighterStatus;

class MinimalFighter
{
private:
    int mHp;
    int mPower;
    FighterStatus mStatus;

public:
    MinimalFighter() {
        mHp = 0;
        mPower = 0;
    };
    MinimalFighter(int _hp, int _power) {
        mHp = _hp;
        mPower = _power;
    };

    int hp() const {
        return mHp;
    };
    int power() const {
        return mPower;
    };
    FighterStatus status() const {
        return mStatus;
    };

    void setHp(int _hp) {
        mHp = _hp;
        if (mHp <= 0)
        {
            mStatus = Dead;
        }
    };

    void hit(MinimalFighter *_enemy) {

        setHp (hp() - 1);
        _enemy-> setHp(_enemy->hp() - 1);

    };
    void attack(MinimalFighter *_target) {

        _target->setHp(_target->hp() - power());
        mPower = power() - 3;

    };
    void fight(MinimalFighter *_enemy) {

        while (hp() > 0 && _enemy->hp() > 0) {
            hit(_enemy);
        }


    };
};

#endif
