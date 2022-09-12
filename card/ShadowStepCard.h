//
// Created by sugar on 2022/9/5.
//

#ifndef HEARTSTONECALCULATOR_SHADOWSTEPCARD_H
#define HEARTSTONECALCULATOR_SHADOWSTEPCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"
#include "../util/util.h"

class ShadowStepPlayCardHandle : public Handle
{
public:
    ShadowStepPlayCardHandle()
    {
        this->handleState = PlayCard;
    }

    void run(Property *property, int position)
    {
        Card* tmpCard = getNewCardCopy(property->getAttendant(position));
        tmpCard->setCost(max(0, tmpCard->getCost() - 2));
        property->addCard(tmpCard);
        property->deleteAttendant(position);
        RunAllHandleWith(tmpCard, AfterDeath, property);
    }
};

//暗影步
class ShadowStepCard : public MagicCard
{
public:
    ShadowStepCard()
    {
        this->targetType = TargetType::MustSpecifyFriendlyTarget;
        this->name = "ShadowStep";
        this->cost = 0;
        addHandle(new ShadowStepPlayCardHandle());
    }

    ShadowStepCard(ShadowStepCard* shadowStepCard)
    {
        this->targetType = shadowStepCard->getTargetType();
        this->name = shadowStepCard->getName();
        this->cost = shadowStepCard->getCost();
        addHandle(new ShadowStepPlayCardHandle());
    }

    Card* getCardBySelf()
    {
        return new ShadowStepCard(this);
    }

    int getRealCost()
    {
        return 0;
    }
};

#endif //HEARTSTONECALCULATOR_SHADOWSTEPCARD_H
