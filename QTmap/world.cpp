 #include "world.h"
#include "player.h"
#include "icon.h"
#include<iostream>
#include <fstream>
#include <cstring>
using namespace std;
static int ary[100][100]={0};
void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(5);
    this->_player.setPosY(5);

    /*this->_player_1.initObj("player");
    this->_player_1.setPosX(10);
    this->_player_1.setPosY(10);*/

    this->_fruite.initObj("fruit");
    this->_fruite.setPosX(6);
    this->_fruite.setPosY(8);

    this->_monster.initObj("monster");
    this->_monster.setPosX(15);
    this->_monster.setPosY(15);

    const char *p=mapFile.c_str();
    ifstream iin(p);
    string s;
    int a,b;
    while(iin){
        iin>>s;
        iin>>a>>b;
        RPGObj obj;
        obj.initObj(s);
        obj.setPosX(a);
        obj.setPosY(b);
        obj._exist=true;
        _objs.push_back(obj);
    }
    iin.close();

    /*RPGObj obj1, obj2, obj4,obj5;
    obj1.initObj("stone");
    obj1.setPosX(4);
    obj1.setPosY(3);

    obj2.initObj("stone");
    obj2.setPosX(6);
    obj2.setPosY(5);

    obj4.initObj("stone");
    obj4.setPosX(6);
    obj4.setPosY(6);

    obj5.initObj("yezitree");
    obj5.setPosX(20);
    obj5.setPosY(10);

    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    //this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);*/
}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_player.show(painter);
    //this->_player_1.show(painter);
    this->_fruite.show(painter);
    this->_monster.show(painter);
}

void World::handlePlayerMove(int direction, int steps){
    switch (direction){
        case 1:
            this->_player._pos_y -= steps;
            if(_player._pos_y==7&&_player._pos_x==6)
             _fruite._exist=false;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
             _player._exist=false;
            this->_player._pos_y += steps;
            break;
        case 2:
            this->_player._pos_y += steps;
            if(_player._pos_y==7&&_player._pos_x==6)
            _fruite._exist=false;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
            _player._exist=false;
             this->_player._pos_y -= steps;
            break;
        case 3:
            this->_player._pos_x -= steps;
            if(_player._pos_y==7&&_player._pos_x==6)
            _fruite._exist=false;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
            _player._exist=false;
            this->_player._pos_x += steps;
            break;
        case 4:
            this->_player._pos_x += steps;
            if(_player._pos_y==7&&_player._pos_x==6)
             _fruite._exist=false;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
            _player._exist=false;
            this->_player._pos_x -= steps;
            break;
    }
    this->_player.move(direction, steps);
   }
void World::handleMonsterMove(int direction, int steps){
    switch (direction){
        case 1:
            this->_monster._pos_y -= steps;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
             _player._exist=false;
            this->_monster._pos_y += steps;
            break;
        case 2:
            this->_monster._pos_y += steps;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
            _player._exist=false;
            this->_monster._pos_y -= steps;
            break;
        case 3:
            this->_monster._pos_x -= steps;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
            _player._exist=false;
            this->_monster._pos_x += steps;
            break;
        case 4:
            this->_monster._pos_x += steps;
            if(_player._pos_y==_monster._pos_y&&_player._pos_x==_monster._pos_x)
            _player._exist=false;
            this->_monster._pos_x -= steps;
            break;
    }
    this->_monster.move_monster(direction, steps);
}

/*void World::handlePlayerMove1(int direction, int steps){
    this->_player_1.move(direction, steps);
   }
*/
