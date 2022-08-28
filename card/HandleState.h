//
// Created by sugar on 2022/8/28.
//

#ifndef HEARTSTONECALCULATOR_HANDLESTATE_H
#define HEARTSTONECALCULATOR_HANDLESTATE_H

enum HandleState
{
    //打出卡牌
    PlayCard,
    //战吼
    Battlecry,
    //死亡，指这张卡退场时，触发在亡语之后
    Death
};

#endif //HEARTSTONECALCULATOR_HANDLESTATE_H
