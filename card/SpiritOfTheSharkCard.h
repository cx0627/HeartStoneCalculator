//
// Created by sugar on 2022/8/28.
//

#ifndef HEARTSTONECALCULATOR_SPIRITOFTHESHARKCARD_H
#define HEARTSTONECALCULATOR_SPIRITOFTHESHARKCARD_H

#include "Card.h"
#include "Handle.h"
#include "Property.h"

class SpiritOfTheSharkPlayCardHandle : public Handle
{
public:
    SpiritOfTheSharkPlayCardHandle()
    {
        this->handleState = PlayCard;
    }

    void run(Property *property, int position){
        property->setDoubleHitNumber(property->getDoubleHitNumber() + 1);
//        puts("s1");
    }
};

class SpiritOfTheSharkDeathHandle : public Handle
{
public:
    SpiritOfTheSharkDeathHandle()
    {
        this->handleState = Death;
    }

    void run(Property *property, int position){
        property->setDoubleHitNumber(property->getDoubleHitNumber() - 1);
//        puts("s2");
    }
};

class SpiritOfTheShark : public AttendantCard
{
public:
    SpiritOfTheShark()
    {
        this->name = "SpiritOfTheShark";
        this->cost = 4;
        this->attack = 0;
        this-> health = 3;
        addHandle(new SpiritOfTheSharkPlayCardHandle());
        addHandle(new SpiritOfTheSharkDeathHandle());
    }
};

#endif //HEARTSTONECALCULATOR_SPIRITOFTHESHARKCARD_H
