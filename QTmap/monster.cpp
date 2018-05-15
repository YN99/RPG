#include "monster.h"
#include "rpgobj.h"
//direction =1,2,3,4 for 上下左右
void Monster::move_monster(int direction, int steps){
    switch (direction){
        case 1:
            this->_pos_y -= steps;
            if(_pos_y>17||_pos_y<0) this->_pos_y += steps;
           // if (pp.canCover()==0) this->_pos_y+=steps;
            if(_pos_y==2&&_pos_x==4) this->_pos_y += steps;
            if(_pos_y==5&&_pos_x==6) this->_pos_y += steps;
            if(_pos_y==11&&_pos_x==20) this->_pos_y += steps;
            if(_pos_y==11&&_pos_x==21) this->_pos_y += steps;
            //if(_pos_y==8&&_pos_x==6)
            break;
        case 2:
            this->_pos_y += steps;
            if(_pos_y>17||_pos_y<0) this->_pos_y -= steps;
            //if (pp.canCover()==0) this->_pos_y-=steps;
            if(_pos_y==2&&_pos_x==4) this->_pos_y -= steps;
            if(_pos_y==4&&_pos_x==6) this->_pos_y -= steps;
            if(_pos_y==10&&_pos_x==20) this->_pos_y -= steps;
            if(_pos_y==10&&_pos_x==21) this->_pos_y -= steps;
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
            break;
    }
}
