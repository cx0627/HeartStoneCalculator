//
// Created by sugar on 2022/8/28.
//

#ifndef HEARTSTONECALCULATOR_CALCULATOR_H
#define HEARTSTONECALCULATOR_CALCULATOR_H

#include "../card/Card.h"
#include "../card/Property.h"

using CheckUp::defaultPlayCardCheckUp;
//using namespace std;
using std::cout;
using std::endl;

class Calculator
{
private:
    string cardsName[55];
    int maxDamage = 0;
    int cnt = 0;

//    void RunAllHandleWith(Card* card, HandleState handleState, Property* property, int target = NO_TARGET)
//    {
//        RunAllHandleWith(card, handleState, property, target);
//    }

    void print(Property* property)
    {
        for (int i = 0; i < property->getPlayCardNum(); i++)
            cout << cardsName[i] << "----->";
        cout << endl;
    }

    void printAttendant(Property* property)
    {
        for (int i = 0; i < property->getCardNum(); i++) {
            cout << property->getCard(i)->getName() << "---";
        }
        cout << endl << property->getLastCost() << endl;
    }

    /*!
     *
     * @param property 当前环境
     */
    void work(Property* property)
    {
//        if (property->getPlayCardNum() > 5)
//            return;
        if (property->getDamage() > maxDamage) {
            maxDamage = property->getDamage();
            print(property);
            cout << maxDamage << endl;
        }
//        cnt ++;
//        if (cnt >= 10000000) {
//            if (cnt == 10000000)
//                cout << "NO" << endl;
//            return;
//        }
//        print(property);
//        cout << property->getDamage() << endl;
        int cardNum = property->getCardNum();
//        if (property->getCardNum() == 1 && property->getCard(0)->getName().compare("FoxyFraud") == 0
//            && property->getPlayCardNum() == 16 && property->getDamage() == 14
//            && cardsName[15].compare("ShadowStep(FoxyFraud)(0)") == 0) {
//            cnt = 0;
//        }
        for (int position = 0; position < cardNum; position++) {
            if (property->getCard(position)->getTargetType() == TargetType::NotTarget
                || (property->getCard(position)->getTargetType() == TargetType::CanSpecifyFriendlyTarget
                && property->getAttendantNum() == 0))
            {
                if (!defaultPlayCardCheckUp.PreCheckUp(property->getCard(position), property)) {
                    continue;
                }
                else {
                    Property *tmpProperty = Property::createProperty(property);
                    cardsName[tmpProperty->getPlayCardNum() - 1] = tmpProperty->getCard(position)->getName();
//                    cardsName[tmpProperty->getPlayCardNum()] = tmpProperty->getCard(position)->getName();
//                    cout << property->getPlayCardNum() << ":" <<  property->getCard(position)->getName() <<std::endl;
                    Card* tmpCard = tmpProperty->getCard(position);
                    tmpProperty->deleteCard(position);
                    int cost = PlayCardWith(tmpCard, tmpProperty);
                    cardsName[tmpProperty->getPlayCardNum() - 1] = cardsName[tmpProperty->getPlayCardNum() - 1] + "(" + std::to_string(cost) + ")";
                    work(tmpProperty);
                }
            }
            if(property->getCard(position)->getTargetType() == TargetType::MustSpecifyFriendlyTarget
               || (property->getCard(position)->getTargetType() == TargetType::CanSpecifyFriendlyTarget
                   && property->getAttendantNum() != 0))
            {
                if (!defaultPlayCardCheckUp.PreCheckUp(property->getCard(position), property)) {
                    continue;
                }
                int attendantNum = property->getAttendantNum();
                for (int target = 0; target < attendantNum; target++) {
                    Property *tmpProperty = Property::createProperty(property);
                    cardsName[tmpProperty->getPlayCardNum() - 1] = tmpProperty->getCard(position)->getName() + "(" + tmpProperty->getAttendant(target)->getName() + ")";
                    Card* tmpCard = tmpProperty->getCard(position);
                    tmpProperty->deleteCard(position);
                    int cost = PlayCardWith(tmpCard, tmpProperty, target);
                    cardsName[tmpProperty->getPlayCardNum() - 1] = cardsName[tmpProperty->getPlayCardNum() - 1] + "(" + std::to_string(cost) + ")";
                    work(tmpProperty);
                }

            }
            if(property->getCard(position)->getTargetType() == TargetType::SpecialTarget)
            {
                if (!defaultPlayCardCheckUp.PreCheckUp(property->getCard(position), property)) {
                    continue;
                }
                int target = 0;
                while ((target = property->getCard(position)->getNextLegalTarget(target, property)) != -1)
                {
                    Property *tmpProperty = Property::createProperty(property);
                    cardsName[tmpProperty->getPlayCardNum() - 1] = tmpProperty->getCard(position)->getName() + "(" + tmpProperty->getAttendant(target)->getName() + ")";
                    Card* tmpCard = tmpProperty->getCard(position);
                    tmpProperty->deleteCard(position);
                    int cost = PlayCardWith(tmpCard, tmpProperty, target);
                    cardsName[tmpProperty->getPlayCardNum() - 1] = cardsName[tmpProperty->getPlayCardNum() - 1] + "(" + std::to_string(cost) + ")";
                    work(tmpProperty);
                    target++;
                }
            }
        }
    }

public:

    //模拟一张牌打出的过程
    //TODO
    int PlayCardWith(Card* card, Property* property, int target = NO_TARGET)
    {
        int cost = defaultPlayCardCheckUp.CostCount(card, property);
        property->setLastCost(property->getLastCost() - cost);
        RunAllHandleWith(card, PlayCard, property, target);
        RunAllHandleWith(card, AfterPlayCard, property, target);
        if (property->getDoubleBattlecryNumber() > 0)
            RunAllHandleWith(card, Battlecry, property, target);
        RunAllHandleWith(card, Battlecry, property, target);
        if (property->getPlayCardNum() > 1) {
            if (property->getDoubleComboNumber() > 0)
                RunAllHandleWith(card, Combo, property, target);
            RunAllHandleWith(card, Combo, property, target);
        }
        if (dynamic_cast<AttendantCard*>(card) != nullptr) {
            Card* tmpCard = getNewCardCopy(card);
//            tmpCard->addHandle(new AttendantDeathHandle(tmpCard));
            tmpCard->setCost(tmpCard->getRealCost());
            property->addAttendant(tmpCard);
        }

        return cost;
    }

    void init()
    {
        maxDamage = 0;
        for (int i = 0; i < 55; i++)
        {
            cardsName[i] = string("");
        }
    }

    //计算斩杀
    void CalculateLethal(Property* property)
    {
        printAttendant(property);
        work(property);
    }
};

#endif //HEARTSTONECALCULATOR_CALCULATOR_H
