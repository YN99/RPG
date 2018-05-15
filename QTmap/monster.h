#ifndef MONSTER_H
#define MONSTER_H
#include "rpgobj.h"


class Monster: public RPGObj
{
public:
    Monster(){}
    ~Monster(){}
    void move_monster(int direction, int steps=1);
        //direction =1,2,3,4 for 上下左右
private:
    //为了能用coverable函数
    RPGObj pp;
};

#endif // MONSTER_H
