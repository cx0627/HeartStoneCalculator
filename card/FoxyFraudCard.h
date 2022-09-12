//
// Created by sugar on 2022/9/4.
//

#ifndef HEARTSTONECALCULATOR_FOXYFRAUDCARD_H
#define HEARTSTONECALCULATOR_FOXYFRAUDCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"

class FoxyFraudBattlecryHandle : public Handle
{
public:
    FoxyFraudBattlecryHandle()
    {
        this->handleState = Battlecry;
    }

    void run(Property *property, int position)
    {
        property->setFirstComboCardReduceCost(property->getFirstComboCardReduceCost() + 2);
    }
};

//老千
class FoxyFraudCard : public BattlecryCard, AttendantCard
{
public:
    FoxyFraudCard()
    {
        this->targetType = TargetType::NotTarget;
        this->name = "FoxyFraud";
        this->cost = 2;
        this->health = 3;
        this->attack = 2;
        addHandle(new FoxyFraudBattlecryHandle());
    }

    FoxyFraudCard(FoxyFraudCard* foxyFraudCard)
    {
        this->targetType = foxyFraudCard->getTargetType();
        this->name = foxyFraudCard->getName();
        this->cost = foxyFraudCard->getCost();
        this->attack = foxyFraudCard->getAttack();
        this-> health = foxyFraudCard->getHealth();
        addHandle(new FoxyFraudBattlecryHandle());
    }

    Card* getCardBySelf()
    {
        return new FoxyFraudCard(this);
    }

    int getRealCost()
    {
        return 2;
    }
};

#endif //HEARTSTONECALCULATOR_FOXYFRAUDCARD_H
