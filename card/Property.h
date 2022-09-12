//
// Created by sugar on 2022/8/27.
//

#ifndef HEARTSTONECALCULATOR_PROPERTY_H
#define HEARTSTONECALCULATOR_PROPERTY_H

#include "Card.h"
#include "HandleState.h"
#include "Handle.h"

//默认场上怪上限
const int DEFAULT_ATTENDANTS_NUM = 7;
//默认手牌上限
const int DEFAULT_CARDS_NUM = 10;
//默认费用上限
const int DEFAULT_MAX_COST = 10;


class Card;
Card* getNewCardCopy(Card* card);

class Property
{
private:
    //是否双倍连击
    int doubleComboNumber = 0;
    //下一张连击牌减费
    int firstComboCardReduceCost = 0;
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
    //当前打出牌的数量
    int playCardNum = 0;
    //是否双倍战吼
    int doubleBattlecryNumber = 0;
    //造成的伤害
    int damage = 0;
    //下一张牌减费
    int firstCardReduceCost = 0;
    //下下一张牌减费
    int secondCardReduceCost = 0;

public:

    Property()
    {
        for (int i = 0; i < DEFAULT_CARDS_NUM; i++) {
            this->cards[i] = nullptr;
        }
        for (int i = 0; i < DEFAULT_ATTENDANTS_NUM; i++) {
            this->attendants[i] = nullptr;
        }
    }

    Property(Property* property)
    {
        this->doubleComboNumber = property->doubleComboNumber;
        this->doubleBattlecryNumber = property->doubleBattlecryNumber;
        this->firstComboCardReduceCost = property->firstComboCardReduceCost;
        this->firstCardReduceCost = property->firstCardReduceCost;
        this->secondCardReduceCost = property->secondCardReduceCost;
        this->lastCost = property->lastCost;
        this->cardNum = property->cardNum;
        this->attendantNum = property->attendantNum;
        this->playCardNum = property->playCardNum;
        this->damage = property->damage;
        for (int i = 0; i < DEFAULT_CARDS_NUM; i++) {
            this->cards[i] = getNewCardCopy(property->cards[i]);
        }
        for (int i = 0; i < DEFAULT_ATTENDANTS_NUM; i++) {
            this->attendants[i] = getNewCardCopy(property->attendants[i]);
        }
    }

    int getDamage() const {
        return damage;
    }

    void setDamage(int damage) {
        Property::damage = damage;
    }

    int getFirstCardReduceCost() const {
        return firstCardReduceCost;
    }

    void setFirstCardReduceCost(int firstCardReduceCost) {
        Property::firstCardReduceCost = firstCardReduceCost;
    }

    int getSecondCardReduceCost() const {
        return secondCardReduceCost;
    }

    void setSecondCardReduceCost(int secondCardReduceCost) {
        Property::secondCardReduceCost = secondCardReduceCost;
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
        if(cardNum < DEFAULT_CARDS_NUM)
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

    int getDoubleBattlecryNumber()
    {
        return doubleBattlecryNumber;
    }

    void setDoubleBattlecryNumber(int doubleBattlecryNumber)
    {
        this->doubleBattlecryNumber = doubleBattlecryNumber;
    }

    void addAttendant(Card *card)
    {
        attendants[attendantNum++] = card;
    }

    void deleteAttendant(Card *card)
    {
        for (int i = 0; i < attendantNum; i++) {
            if (attendants[i] == card) {
                deleteAttendant(i);
                return;
            }
        }
    }

    Card* deleteAttendant(int position)
    {
        if (position >= attendantNum || position < 0)
            return nullptr;
        Card* tmpCard = attendants[position];
        for (int i = position; i < attendantNum - 1; i++) {
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

    int getFirstComboCardReduceCost()
    {
        return firstComboCardReduceCost;
    }

    void setFirstComboCardReduceCost(int firstComboCardReduceCost)
    {
        Property::firstComboCardReduceCost = firstComboCardReduceCost;
    }

    int getDoubleComboNumber()
    {
        return doubleComboNumber;
    }

    void setDoubleComboNumber(int doubleComboNumber)
    {
        Property::doubleComboNumber = doubleComboNumber;
    }

    int getLastCost()
    {
        return lastCost;
    }

    void setLastCost(int lastCost)
    {
        this->lastCost = lastCost;
    }

    int getPlayCardNum()
    {
        return playCardNum;
    }

    void setPlayCardNum(int playCardNum)
    {
        this->playCardNum = playCardNum;
    }

    static Property* createProperty(Property* property)
    {
        Property* aProperty= new Property(property);
        aProperty->setPlayCardNum(aProperty->getPlayCardNum() + 1);
        return aProperty;
    }
};

#endif //HEARTSTONECALCULATOR_PROPERTY_H
