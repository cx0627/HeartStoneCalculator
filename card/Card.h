//
// Created by sugar on 2022/8/24.
//
#ifndef HEARTSTONECALCULATOR_Card_H
#define HEARTSTONECALCULATOR_Card_H

#include <String.h>
#include <vector>
#include "Handle.h"
using std::string;
using std::vector;

enum TargetType
{
    //不需要指定目标
    NotTarget,
    //必须要指定目标
    MustSpecifyTarget,
    //可以指定目标
    CanSpecifyTarget,
    //必须指定友方目标
    MustSpecifyFriendlyTarget,
    //可以指定友方目标
    CanSpecifyFriendlyTarget,
    //特殊的目标（需要进行合法目标的判断）
    SpecialTarget
};

class Card
{
protected:
    //卡牌名称
    string name;
    //卡牌费用
    int cost;
    //卡牌的效果列表
    vector<Handle*> handleList;
    //是否需要指定目标
    TargetType targetType;

public:
    Card()
    {
    }

    Card(string name, int cost)
    {
        this->name = name;
        this->cost = cost;
    }

    Card(Card* card)
    {
        this->name = card->name;
        this->cost = card->cost;
    }

    virtual Card* getCardBySelf()
    {
        return new Card(this);
    }

    string getName()
    {
        return name;
    }

    int getCost()
    {
        return cost;
    }

    void setCost(int cost)
    {
        this->cost = cost;
    }

    TargetType getTargetType()
    {
        return targetType;
    }

    virtual bool isLegalTarget(Card* targetCard)
    {
        //默认没有合法目标
        puts("1");
        return false;
    }

    int getNextLegalTarget(int position, Property* property)
    {
        isLegalTarget(property->getAttendant(0));
        if (position < 0 || position >= property->getAttendantNum())
            return -1;
        int p = position;
        while (p < property->getAttendantNum() && !isLegalTarget(property->getAttendant(p))) {
            p++;
        }
        if (p == property->getAttendantNum()) {
            return -1;
        }
        if (isLegalTarget(property->getAttendant(p))) {
            return p;
        }
        return -1;
    }

    int addHandle(Handle* handle)
    {
        handleList.push_back(handle);
        return handleList.size();
    }

    int getNextHandle(int position, HandleState handleState)
    {
        if (position < 0 || position >= handleList.size())
            return -1;
        int p = position;
        while (p < handleList.size() && handleList[p]->getHandleState() != handleState) {
            p++;
        }
        if (p == handleList.size()) {
            return -1;
        }
        if (handleList[p]->getHandleState() == handleState) {
            return p;
        }
        return -1;
    }

    void RunHandle(int position, Property* property, int target = NO_TARGET)
    {
        handleList[position]->run(property, target);
    }

    int getHandleListLen()
    {
        return handleList.size();
    }

    void ClearHandleList()
    {
        handleList.clear();
    }

    virtual ~Card(){
        handleList.clear();
    }
};

Card* getNewCardCopy(Card* card)
{
    if (card == nullptr)
        return nullptr;
    return card->getCardBySelf();
}

void RunAllHandleWith(Card* card, HandleState handleState, Property* property, int target = NO_TARGET)
{
    int position = 0;
    while ((position = card->getNextHandle(position, handleState)) != -1) {
        card->RunHandle(position, property, target);
        position++;
    }
}

//假卡
class FakeCard : virtual public Card
{
public:
    FakeCard()
    {
    }

    FakeCard(FakeCard* fakeCard)
    {
    }

    virtual Card* getCardBySelf()
    {
        return new FakeCard(this);
    }
};

//法术牌
class MagicCard : virtual public Card
{
public:
    MagicCard()
    {
    }

    MagicCard(MagicCard* magicCard)
    {
    }

    virtual Card* getCardBySelf()
    {
        return new MagicCard(this);
    }
};

//战吼牌
class BattlecryCard : virtual public Card
{
public:
    BattlecryCard()
    {
    }

    BattlecryCard(BattlecryCard* battlecryCard)
    {
    }

    virtual Card* getCardBySelf()
    {
        return new BattlecryCard(this);
    }
};

//连击牌
class ComboCard : virtual public Card
{
public:
    ComboCard()
    {
    }

    ComboCard(ComboCard* hitCard)
    {
    }

    virtual Card* getCardBySelf()
    {
        return new ComboCard(this);
    }
};

class AttendantCard;

class AttendantPlayCardHandle  : public Handle
{
private:
    Card* card;

public:
    AttendantPlayCardHandle()
    {
        this->handleState = PlayCard;
    }

    AttendantPlayCardHandle(Card* card)
    {
        this->card = card;
        this->handleState = PlayCard;
    }

    void run(Property *property, int position)
    {
        property->addAttendant(this->card);
    }
};

class AttendantDeathHandle  : public Handle
{
private:
    Card* card;

public:
    AttendantDeathHandle()
    {
        this->handleState = Death;
    }

    AttendantDeathHandle(Card* card)
    {
        this->card = card;
        this->handleState = Death;
    }

    void run(Property *property, int position)
    {
        property->deleteAttendant(this->card);
    }
};

void addAttendantHandle(Card* card)
{
}

//随从牌
class AttendantCard : virtual public Card
{
protected:
    int attack;
    int health;
public:

    AttendantCard(AttendantCard* attendantCard)
    {
        this->attack = attendantCard->getAttack();
        this->health = attendantCard->getHealth();
    }

    AttendantCard()
    {

    }

    int getAttack()
    {
        return attack;
    }

    int getHealth()
    {
        return health;
    }

//    virtual Card* getCardBySelf()
//    {
//        return new AttendantCard(this);
//    }
};

#endif //HEARTSTONECALCULATOR_Card_H