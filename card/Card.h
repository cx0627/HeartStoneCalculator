//
// Created by sugar on 2022/8/24.
//
#ifndef HEARTSTONECALCULATOR_Card_H
#define HEARTSTONECALCULATOR_Card_H

#include <String.h>
#include <vector>
#include "Handle.h"
using std::string;
using std::vector;

class Card
{
protected:
    string name;
    int cost;
    vector<Handle*> handlerList;

public:
    Card()
    {

    }

    Card(string name, int cost)
    {
        this->name = name;
        this->cost = cost;
    }

    string getName()
    {
        return name;
    }

    int getCost()
    {
        return cost;
    }

    virtual int addHandle(Handle* handle)
    {
        handlerList.push_back(handle);
        return handlerList.size();
    }

    int getHandleListLen()
    {
        return handlerList.size();
    }

    void ClearHandleList()
    {
        handlerList.clear();
    }

    void work()
    {
        handlerList[0]->run(new Property());
        handlerList[1]->run(new Property());
    }
};

//战吼牌
class BattlecryCard : virtual public Card
{
public:
    BattlecryCard()
    {
    }
};

//连击牌
class HitCard : virtual public Card
{
public:
    HitCard()
    {
    }

};

//随从牌
class AttendantCard : virtual public Card
{
protected:
    int attack;
    int health;
public:
    AttendantCard()
    {

    }

    int getAttack()
    {
        return attack;
    }

    int getHealth()
    {
        return health;
    }
};

#endif //HEARTSTONECALCULATOR_Card_H