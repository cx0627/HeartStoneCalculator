//
// Created by sugar on 2022/9/3.
//

#ifndef HEARTSTONECALCULATOR_SPECTRALPILLAGERCARD_H
#define HEARTSTONECALCULATOR_SPECTRALPILLAGERCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"

class SpectralPillagerComboHandle : public Handle
{
public:
    SpectralPillagerComboHandle()
    {
        this->handleState = Combo;
    }

    void run(Property *property, int position)
    {
        property->setDamage(property->getDamage() + property->getPlayCardNum());
    }
};

//鬼灵
class SpectralPillagerCard : public ComboCard, AttendantCard
{
public:
    SpectralPillagerCard()
    {
        this->targetType = TargetType::NotTarget;
        this->name = "SpectralPillager";
        this->cost = 6;
        this->health = 5;
        this->attack = 5;
        addHandle(new SpectralPillagerComboHandle());
    }

    SpectralPillagerCard(SpectralPillagerCard* spectralPillagerCard)
    {
        this->targetType = spectralPillagerCard->getTargetType();
        this->name = spectralPillagerCard->getName();
        this->cost = spectralPillagerCard->getCost();
        this->attack = spectralPillagerCard->getAttack();
        this-> health = spectralPillagerCard->getHealth();
        addHandle(new SpectralPillagerComboHandle());
    }

    Card* getCardBySelf()
    {
        return new SpectralPillagerCard(this);
    }
};

#endif //HEARTSTONECALCULATOR_SPECTRALPILLAGERCARD_H
