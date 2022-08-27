//
// Created by sugar on 2022/8/27.
//

#ifndef HEARTSTONECALCULATOR_PROPERTY_H
#define HEARTSTONECALCULATOR_PROPERTY_H

#include "Card.h"

//默认场上怪上限
const int DEFAULT_ATTENDANTS_NUM = 7;
//默认手牌上限
const int DEFAULT_CARDS_NUM = 10;

class Card;

class Property
{
private:
    //是否双倍连击
    int doubleHitNumber = 0;
    //下一张连击牌减费
    int firstHitCardReduceCost = 0;
    //剩余费用
    int lastCost = 0;
    //手牌
    Card* cards[DEFAULT_CARDS_NUM];
    //手牌数量
    int cardNum = 0;
    //场上的怪
    Card* attendants[DEFAULT_ATTENDANTS_NUM];
    //手牌数量
    int attendantNum = 0;

public:
    Property()
    {

    }

    Property(Property* property)
    {
        this->doubleHitNumber = property->doubleHitNumber;
        this->firstHitCardReduceCost = property->firstHitCardReduceCost;
        for (int i = i; i < DEFAULT_CARDS_NUM; i++) {
            this->cards[i] = property->cards[i];
        }
        for (int i = i; i < DEFAULT_ATTENDANTS_NUM; i++) {
            this->attendants[i] = property->attendants[i];
        }
    }

    Card* getCard(int position)
    {
        return cards[position];
    }

    void setCard(int position, Card *card)
    {
        cards[position] = card;
    }

    void addCard(Card *card)
    {
        cards[cardNum++] = card;
    }

    Card* deleteCard(int position)
    {
        if (position >= cardNum || position < 0)
            return nullptr;
        Card* tmpCard = cards[position];
        for (int i = position; i < cardNum; i++) {
            cards[i] = cards[i + 1];
        }
        cardNum--;
        return tmpCard;
    }

    void addAttendant(int position, Card *card)
    {
        attendants[cardNum++] = card;
    }

    Card* deleteAttendant(int position)
    {
        if (position >= attendantNum || position < 0)
            return nullptr;
        Card* tmpCard = attendants[position];
        for (int i = position; i < attendantNum; i++) {
            attendants[i] = attendants[i + 1];
        }
        attendantNum--;
        return tmpCard;
    }

    Card* getAttendant(int position)
    {
        return attendants[position];
    }

    void setAttendant(int position, Card* card)
    {
        attendants[position] = card;
    }

    int getCardNum()
    {
        return cardNum;
    }

    int getAttendantNum()
    {
        return attendantNum;
    }

    int getFirstHitCardReduceCost()
    {
        return firstHitCardReduceCost;
    }

    void setFirstHitCardReduceCost(int firstHitCardReduceCost)
    {
        Property::firstHitCardReduceCost = firstHitCardReduceCost;
    }

    int getDoubleHitNumber()
    {
        return doubleHitNumber;
    }

    void setDoubleHitNumber(int doubleHitNumber)
    {
        Property::doubleHitNumber = doubleHitNumber;
    }

    int getLastCost()
    {
        return lastCost;
    }

    void setLastCost(int lastCost)
    {
        this->lastCost = lastCost;
    }

    static Property* createProperty(Property* property)
    {
        return new Property(property);
    }
};

#endif //HEARTSTONECALCULATOR_PROPERTY_H
