//
// Created by sugar on 2022/9/6.
//

#ifndef HEARTSTONECALCULATOR_TENWUOFTHEREDSMOKECARD_H
#define HEARTSTONECALCULATOR_TENWUOFTHEREDSMOKECARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"

class TenwuOfTheRedSmokeBattlecryHandle : public Handle
{
public:
    TenwuOfTheRedSmokeBattlecryHandle()
    {
        this->handleState = Battlecry;
    }

    void run(Property *property, int position)
    {
        if (position == -1) {
            return;
        }
        Card* tmpCard = getNewCardCopy(property->getAttendant(position));
        tmpCard->setCost(1);
        property->addCard(tmpCard);
        property->deleteAttendant(position);
        RunAllHandleWith(tmpCard, AfterDeath, property);
    }
};

//赤烟腾武
class TenwuOfTheRedSmokeCard : public AttendantCard, BattlecryCard
{
public:
    TenwuOfTheRedSmokeCard()
    {
        this->targetType = TargetType::CanSpecifyFriendlyTarget;
        this->name = "TenwuOfTheRedSmoke";
        this->cost = 2;
        this->attack = 3;
        this->health = 2;
        addHandle(new TenwuOfTheRedSmokeBattlecryHandle());
    }

    TenwuOfTheRedSmokeCard(TenwuOfTheRedSmokeCard* tenwuOfTheRedSmokeCard)
    {
        this->targetType = tenwuOfTheRedSmokeCard->getTargetType();
        this->name = tenwuOfTheRedSmokeCard->getName();
        this->cost = tenwuOfTheRedSmokeCard->getCost();
        this->attack = tenwuOfTheRedSmokeCard->getAttack();
        this->health = tenwuOfTheRedSmokeCard->getHealth();
        addHandle(new TenwuOfTheRedSmokeBattlecryHandle());
    }

    Card* getCardBySelf()
    {
        return new TenwuOfTheRedSmokeCard(this);
    }

    int getRealCost()
    {
        return 2;
    }
};

#endif //HEARTSTONECALCULATOR_TENWUOFTHEREDSMOKECARD_H
