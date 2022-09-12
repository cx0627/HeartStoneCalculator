//
// Created by sugar on 2022/9/4.
//

#ifndef HEARTSTONECALCULATOR_SCABBSCUTTERBUTTERCARD_H
#define HEARTSTONECALCULATOR_SCABBSCUTTERBUTTERCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"

class ScabbsCutterbutterComboHandle : public Handle
{
public:
    ScabbsCutterbutterComboHandle()
    {
        this->handleState = Combo;
    }

    void run(Property *property, int position)
    {
        property->setFirstCardReduceCost(property->getFirstCardReduceCost() + 3);
        property->setSecondCardReduceCost(property->getSecondCardReduceCost() + 3);
    }
};

//刀油
class ScabbsCutterbutterCard : public ComboCard, AttendantCard
{
public:
    ScabbsCutterbutterCard()
    {
        this->targetType = TargetType::NotTarget;
        this->name = "ScabbsCutterbutter";
        this->cost = 4;
        this->health = 3;
        this->attack = 3;
        addHandle(new ScabbsCutterbutterComboHandle());
    }

    ScabbsCutterbutterCard(ScabbsCutterbutterCard* scabbsCutterbutterCard)
    {
        this->targetType = scabbsCutterbutterCard->getTargetType();
        this->name = scabbsCutterbutterCard->getName();
        this->cost = scabbsCutterbutterCard->getCost();
        this->attack = scabbsCutterbutterCard->getAttack();
        this-> health = scabbsCutterbutterCard->getHealth();
        addHandle(new ScabbsCutterbutterComboHandle());
    }

    Card* getCardBySelf()
    {
        return new ScabbsCutterbutterCard(this);
    }

    int getRealCost()
    {
        return 4;
    }
};

#endif //HEARTSTONECALCULATOR_SCABBSCUTTERBUTTERCARD_H
