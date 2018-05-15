#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include <QTimer>
#include <map>
#include<QPixmap>
#include<QPaintEvent>
#include <iostream>

using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    //init game world
    _game.initWorld("C:\\Users\\34701\\Desktop\\ynbb.txt");//TODO 应该是输入有效的地图文件

    //以下是对时钟的初始化
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(randomMove()));//timeoutslot()为自定义槽
        //时钟事件与randomMove函数绑定
    timer->start(100);
    timer->setInterval(1000);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        //设置随机数种子
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    QPixmap ii;
    ii.load("C:\\Users\\34701\\Pictures\\timg.jpg");
    pa->drawPixmap(0,0,2000,1000,ii);
    this->_game.show(pa);
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_Left)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_Right)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_Up)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_Down)
    {
         this->_game.handlePlayerMove(2,1);
    }
    else if(e->key() == Qt::Key_A)
    {
        this->_game.handleMonsterMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handleMonsterMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handleMonsterMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handleMonsterMove(2,1);
    }
    else if(e->key()==Qt::Key_R)
    {
        this->_game._player._exist=true;
    }
    this->repaint();
}

/*void MW1::randomMove(){
    int d = 1 + rand()%4;
    this->_game.handlePlayerMove1(d,1);
    this->repaint();
}*/

