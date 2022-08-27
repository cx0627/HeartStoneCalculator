//
// Created by sugar on 2022/8/27.
//

#ifndef HEARTSTONECALCULATOR_HANDLE_H
#define HEARTSTONECALCULATOR_HANDLE_H

#include "Property.h"

const int NO_OBJECT = -1;

enum HandleState
{
    PlayCard,//打出卡牌
    Battlecry//战吼
};

class Handle
{
private:
    HandleState handleState;

public:
    Handle(){
        handleState = PlayCard;
    }

    Handle(HandleState handleState){
        this->handleState = handleState;
    }

    HandleState getHandleState() const {
        return handleState;
    }

    void run(Property *property)
    {
        run(property, NO_OBJECT);
    }

    virtual void run(Property *property, int position = NO_OBJECT);
};

#endif //HEARTSTONECALCULATOR_HANDLE_H
