//
// Created by sugar on 2022/8/28.
//

#ifndef HEARTSTONECALCULATOR_PLAYCARDCHECKUP_H
#define HEARTSTONECALCULATOR_PLAYCARDCHECKUP_H

#include "../card/Card.h"
#include "../card/Property.h"

inline int max(int a, int b)
{
    return a > b ? a : b;
}

class PlayCardCheckUp
{
public:
    bool PreCheckUp(Card* card, Property* property)
    {
        if(!PreAttendantNumCheckUp(card, property)) {
            return false;
        }
        if(PreCostCheckUp(card, property) > property->getLastCost()) {
            return false;
        }
        return true;
    }

    //费用预估计 用于检测是否有足够的费用打出
    //TODO
    int PreCostCheckUp(Card* card, Property* property)
    {
        int tmpCost = card->getCost();
        if (dynamic_cast<HitCard*>(card) != nullptr)
        {
            tmpCost -= property->getFirstHitCardReduceCost();
        }
        return max(0, tmpCost);
    }

    //随从格子预估计 用于检测是否有足够的格子打出
    //TODO
    bool PreAttendantNumCheckUp(Card* card, Property* property)
    {
        if (dynamic_cast<AttendantCard*>(card) != nullptr) {
            if(property->getAttendantNum() <= 6) {
                return true;
            }
            else {
                return false;
            }
        }
        return true;
    }

    //费用计算 用于计算打出时消耗的费用
    //TODO
    int CostCount(Card* card, Property* property)
    {
        int tmpCost = card->getCost();
        if (dynamic_cast<HitCard*>(card) != nullptr)
        {
            tmpCost -= property->getFirstHitCardReduceCost();
            property->setFirstHitCardReduceCost(0);
        }
        property->setLastCost(property->getLastCost() - max(0, tmpCost));
        return max(0, tmpCost);
    }
};

namespace CheckUp{
    PlayCardCheckUp defaultPlayCardCheckUp;
}

#endif //HEARTSTONECALCULATOR_PLAYCARDCHECKUP_H
