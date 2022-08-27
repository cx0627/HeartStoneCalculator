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

class Card
{
private:
    string name;
    vector<Handle> handlerList;

public:
    string getName()
    {
        return name;
    }

    int addHandle(Handle handle)
    {
        handlerList.push_back(handle);
        return handlerList.size();
    }

    int getHandleListLen()
    {
        return handlerList.size();
    }

    void ClearHandleList()
    {
        handlerList.clear();
    }
};

#endif //HEARTSTONECALCULATOR_Card_H