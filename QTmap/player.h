#ifndef PLAYER_H
#define PLAYER_H
#include "rpgobj.h"
//#include "world.h"
class Player: public RPGObj//,public World
{//friend class World;
public:
    Player(){}
    ~Player(){}
    void move(int direction, int steps=1);
        //direction =1,2,3,4 for 上下左右
private:
    //为了能用coverable函数
    RPGObj pp;
    //World aa;
};

#endif // PLAYER_H
