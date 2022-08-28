//
// Created by sugar on 2022/9/4.
//

#ifndef HEARTSTONECALCULATOR_COINCARD_H
#define HEARTSTONECALCULATOR_COINCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"

inline int min(int a, int b)
{
    return a < b ? a : b;
}

class CoinPlayCardHandle : public Handle
{
public:
    CoinPlayCardHandle()
    {
        this->handleState = PlayCard;
    }

    void run(Property *property, int position)
    {
        property->setLastCost(min(property->getLastCost() + 1, DEFAULT_MAX_COST));
    }
};

//硬币
class CoinCard : public MagicCard
{
public:
    CoinCard()
    {
        this->targetType = TargetType::NotTarget;
        this->name = "Coin";
        this->cost = 0;
        addHandle(new CoinPlayCardHandle());
    }

    CoinCard(CoinCard* coinCard)
    {
        this->targetType = coinCard->getTargetType();
        this->name = coinCard->getName();
        this->cost = coinCard->getCost();
        addHandle(new CoinPlayCardHandle());
    }

    Card* getCardBySelf()
    {
        return new CoinCard(this);
    }
};

#endif //HEARTSTONECALCULATOR_COINCARD_H
