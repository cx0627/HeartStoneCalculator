//
// Created by sugar on 2022/8/28.
//

#ifndef HEARTSTONECALCULATOR_PLAYCARDCHECKUP_H
#define HEARTSTONECALCULATOR_PLAYCARDCHECKUP_H

#include "../card/Card.h"
#include "../card/Property.h"
#include "../util/util.h"

class PlayCardCheckUp
{
public:
    bool PreCheckUp(Card* card, Property* property)
    {
        if (!PreAttendantNumCheckUp(card, property)) {
            return false;
        }
        if (PreCostCheckUp(card, property) > property->getLastCost()) {
            return false;
        }
        if (!PreTargetCheckUp(card, property)) {
            return false;
        }
        return true;
    }

    //检查是否有合法目标
    bool PreTargetCheckUp(Card* card, Property* property)
    {
        if (card->getTargetType() == TargetType::NotTarget)
            return true;
        if (card->getTargetType() == TargetType::CanSpecifyTarget)
            return true;
        if (card->getTargetType() == TargetType::CanSpecifyFriendlyTarget)
            return true;
        if (card->getTargetType() == TargetType::MustSpecifyFriendlyTarget && property->getAttendantNum() == 0)
            return false;
        if (card->getTargetType() == TargetType::SpecialTarget)
        {
            if (card->getNextLegalTarget(0, property) != -1)
                return true;
            else
                return false;
        }
        return true;
    }

    //费用预估计 用于检测是否有足够的费用打出
    //TODO
    int PreCostCheckUp(Card* card, Property* property)
    {
        int tmpCost = card->getCost();

        tmpCost -= property->getFirstCardReduceCost();

        if (dynamic_cast<ComboCard*>(card) != nullptr)
        {
            tmpCost -= property->getFirstComboCardReduceCost();
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

        tmpCost -= property->getFirstCardReduceCost();
        property->setFirstCardReduceCost(property->getSecondCardReduceCost());
        property->setSecondCardReduceCost(0);

        if (dynamic_cast<ComboCard*>(card) != nullptr)
        {
            tmpCost -= property->getFirstComboCardReduceCost();
            property->setFirstComboCardReduceCost(0);
        }

        return max(0, tmpCost);
    }
};

namespace CheckUp{
    PlayCardCheckUp defaultPlayCardCheckUp;
}

#endif //HEARTSTONECALCULATOR_PLAYCARDCHECKUP_H
