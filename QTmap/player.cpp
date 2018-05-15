#include "player.h"
#include "rpgobj.h"
#include "world.h"
//direction =1,2,3,4 for 上下左右
void Player::move(int direction, int steps){
    switch (direction){
        case 1:
            this->_pos_y -= steps;
            if(_pos_y>17||_pos_y<0) this->_pos_y += steps;
            if(_pos_y==2&&_pos_x==4) this->_pos_y += steps;
            if(_pos_y==5&&_pos_x==6) this->_pos_y += steps;
            if(_pos_y==11&&_pos_x==20) this->_pos_y += steps;
            if(_pos_y==11&&_pos_x==21) this->_pos_y += steps;
            /*if(_pos_y==7&&_pos_x==6)  _fruite._exist=false;
            if(_pos_y==_monster._pos_y&&_pos_x==_monster._pos_x)  _player._exist=false;*/
            break;
        case 2:
            this->_pos_y += steps;
            if(_pos_y>17||_pos_y<0) this->_pos_y -= steps;
            //if (pp.canCover()==0) this->_pos_y-=steps;
            if(_pos_y==2&&_pos_x==4) this->_pos_y -= steps;
            if(_pos_y==4&&_pos_x==6) this->_pos_y -= steps;
            if(_pos_y==10&&_pos_x==20) this->_pos_y -= steps;
            if(_pos_y==10&&_pos_x==21) this->_pos_y -= steps;
            /*if(_pos_y==7&&_pos_x==6)  _fruite._exist=false;
            if(_pos_y==_monster._pos_y&&_pos_x==_monster._pos_x)  _player._exist=false;*/
            break;
        case 3:
            this->_pos_x -= steps;
            if(_pos_x>24||_pos_x<0) this->_pos_x +=steps;
            //if (pp.canCover()==0) this->_pos_x+=steps;
            if(_pos_y==5&&_pos_x==6) this->_pos_x +=steps;
            if(_pos_y==4&&_pos_x==6) this->_pos_x +=steps;
            if(_pos_y==2&&_pos_x==4) this->_pos_x +=steps;
            if(_pos_y==11&&_pos_x==21) this->_pos_x +=steps;
            if(_pos_y==10&&_pos_x==21) this->_pos_x +=steps;
            /*if(_pos_y==7&&_pos_x==6)  _fruite._exist=false;
            if(_pos_y==_monster._pos_y&&_pos_x==_monster._pos_x)  _player._exist=false;*/
            break;
        case 4:
            this->_pos_x += steps;
            if(_pos_x>24||_pos_x<0) this->_pos_x-=steps;
            //if (pp.canCover()==0) this->_pos_x-=steps;
            if(_pos_y==4&&_pos_x==6) this->_pos_x -=steps;
            if(_pos_y==5&&_pos_x==6) this->_pos_x -=steps;
            if(_pos_y==2&&_pos_x==4) this->_pos_x -=steps;
            if(_pos_y==11&&_pos_x==20) this->_pos_x -=steps;
            if(_pos_y==10&&_pos_x==20) this->_pos_x -=steps;
            /*if(_pos_y==7&&_pos_x==6)  _fruite._exist=false;
            if(_pos_y==_monster._pos_y&&_pos_x==_monster._pos_x)  _player._exist=false;*/
            break;
    }
}
/*void World::handlePlayerMove(int direction, int steps){
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
*/
