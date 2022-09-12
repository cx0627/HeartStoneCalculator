//
// Created by sugar on 2022/9/6.
//

#ifndef HEARTSTONECALCULATOR_MAILBOXDANCERCARD_H
#define HEARTSTONECALCULATOR_MAILBOXDANCERCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"
#include "CoinCard.h"

class MailboxDancerBattlecryHandle : public Handle
{
public:
    MailboxDancerBattlecryHandle()
    {
        this->handleState = Battlecry;
    }

    void run(Property *property, int position)
    {
        property->addCard(new CoinCard());
    }
};

//邮箱舞者
class MailboxDancerCard : public AttendantCard, BattlecryCard
{
public:
    MailboxDancerCard()
    {
        this->targetType = TargetType::NotTarget;
        this->name = "MailboxDancer";
        this->cost = 2;
        this->attack = 3;
        this->health = 2;
        addHandle(new MailboxDancerBattlecryHandle());
    }

    MailboxDancerCard(MailboxDancerCard* mailboxDancerCard)
    {
        this->targetType = mailboxDancerCard->getTargetType();
        this->name = mailboxDancerCard->getName();
        this->cost = mailboxDancerCard->getCost();
        this->attack = mailboxDancerCard->getAttack();
        this->health = mailboxDancerCard->getHealth();
        addHandle(new MailboxDancerBattlecryHandle());
    }

    Card* getCardBySelf()
    {
        return new MailboxDancerCard(this);
    }

    int getRealCost()
    {
        return 2;
    }
};

#endif //HEARTSTONECALCULATOR_MAILBOXDANCERCARD_H
