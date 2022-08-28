//
// Created by sugar on 2022/8/28.
//

#ifndef HEARTSTONECALCULATOR_SPIRITOFTHESHARKCARD_H
#define HEARTSTONECALCULATOR_SPIRITOFTHESHARKCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"

class SpiritOfTheSharkAfterPlayCardHandle : public Handle
{
public:
    SpiritOfTheSharkAfterPlayCardHandle()
    {
        this->handleState = AfterPlayCard;
    }

    void run(Property *property, int position)
    {
        property->setDoubleComboNumber(property->getDoubleComboNumber() + 1);
        property->setDoubleBattlecryNumber(property->getDoubleBattlecryNumber() + 1);
        return;
    }
};

class SpiritOfTheSharkAfterDeathHandle : public Handle
{
public:
    SpiritOfTheSharkAfterDeathHandle()
    {
        this->handleState = AfterDeath;
    }

    void run(Property *property, int position)
    {
        property->setDoubleComboNumber(property->getDoubleComboNumber() - 1);
        property->setDoubleBattlecryNumber(property->getDoubleBattlecryNumber() - 1);
    }
};

//鲨鱼之灵
class SpiritOfTheSharkCard : public AttendantCard
{
public:
    SpiritOfTheSharkCard()
    {
        this->targetType = TargetType::NotTarget;
        this->name = "SpiritOfTheShark";
        this->cost = 4;
        this->attack = 0;
        this-> health = 3;
        addHandle(new SpiritOfTheSharkAfterPlayCardHandle());
        addHandle(new SpiritOfTheSharkAfterDeathHandle());
    }

    SpiritOfTheSharkCard(SpiritOfTheSharkCard* spiritOfTheSharkCard)
    {
        this->targetType = spiritOfTheSharkCard->getTargetType();
        this->name = spiritOfTheSharkCard->getName();
        this->cost = spiritOfTheSharkCard->getCost();
        this->attack = spiritOfTheSharkCard->getAttack();
        this-> health = spiritOfTheSharkCard->getHealth();
        addHandle(new SpiritOfTheSharkAfterPlayCardHandle());
        addHandle(new SpiritOfTheSharkAfterDeathHandle());
    }

    Card* getCardBySelf()
    {
        return new SpiritOfTheSharkCard(this);
    }
};

#endif //HEARTSTONECALCULATOR_SPIRITOFTHESHARKCARD_H
