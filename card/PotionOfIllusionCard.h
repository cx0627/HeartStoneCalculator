//
// Created by sugar on 2022/9/6.
//

#ifndef HEARTSTONECALCULATOR_POTIONOFILLUSIONCARD_H
#define HEARTSTONECALCULATOR_POTIONOFILLUSIONCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"
#include "../util/util.h"

class PotionOfIllusionPlayCardHandle : public Handle
{
public:
    PotionOfIllusionPlayCardHandle()
    {
        this->handleState = PlayCard;
    }

    void run(Property *property, int position)
    {
        for (int i = 0; i < property->getAttendantNum(); i++) {
            Card* tmpCard = getNewCardCopy(property->getAttendant(i));
            tmpCard->setCost(1);
            property->addCard(tmpCard);
        }
    }
};

//幻觉药水
class PotionOfIllusionCard : public MagicCard
{
public:
    PotionOfIllusionCard()
    {
        this->targetType = TargetType::NotTarget;
        this->name = "PotionOfIllusion";
        this->cost = 4;
        addHandle(new PotionOfIllusionPlayCardHandle());
    }

    PotionOfIllusionCard(PotionOfIllusionCard* potionOfIllusionCard)
    {
        this->targetType = potionOfIllusionCard->getTargetType();
        this->name = potionOfIllusionCard->getName();
        this->cost = potionOfIllusionCard->getCost();
        addHandle(new PotionOfIllusionPlayCardHandle());
    }

    Card* getCardBySelf()
    {
        return new PotionOfIllusionCard(this);
    }

    int getRealCost()
    {
        return 4;
    }
};

#endif //HEARTSTONECALCULATOR_POTIONOFILLUSIONCARD_H
