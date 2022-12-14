//
// Created by sugar on 2022/8/27.
//

#ifndef HEARTSTONECALCULATOR_HANDLE_H
#define HEARTSTONECALCULATOR_HANDLE_H

#include "Property.h"
#include "HandleState.h"

const int NO_TARGET = -1;

class Handle
{
protected:
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

    virtual void run(Property *property, int position = NO_TARGET){
        puts("error");
    }
};

#endif //HEARTSTONECALCULATOR_HANDLE_H
