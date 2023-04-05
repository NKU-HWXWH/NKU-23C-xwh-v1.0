#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QString>
#include <ui_mainscene.h>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
    playGame();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene(){
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon( GAME_ICON));
    m_Timer.setInterval(GAME_RATE);
    m_recorder = 0;
    point =0;
    srand((unsigned int)time(NULL));
}

void MainScene::playGame()
{
    m_Timer.start();
    connect(&m_Timer,&QTimer::timeout,[=](){
    enemyToScene();
    updatePosition();
    update();
    collisionDetection();
    updatepoint();
//    connect()
});
}
void MainScene::updatePosition()
{
    m_map.mapPosition();
    m_hero.shoot();
    temp_bullet.m_Free = false;
    temp_bullet.updatePosition();
    m_hero.shoot();
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
    if(!m_hero.m_bullets[i].m_Free)
    {
    m_hero.m_bullets[i].updatePosition();
    }
    }

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
    if(m_enemys[i].m_Free == false)
    {
    m_enemys[i].updatePosition();
    }
    }
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
    if(m_bombs[i].m_Free == false)
    {
    m_bombs[i].updateInfo();
    }
    }

}
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);
    painter.drawPixmap(temp_bullet.m_X,temp_bullet.m_Y,temp_bullet.m_Bullet);

    for(int i = 0 ;i < BULLET_NUM;i++)
    {
    if(!m_hero.m_bullets[i].m_Free)
    {
    painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
    }
    }

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
    if(m_enemys[i].m_Free == false)
    {
    painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
    }
    }
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
    if(m_bombs[i].m_Free == false)
    {
    painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
    }
    }

}
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_hero.m_Rect.width()*0.5;
    int y = event->y() - m_hero.m_Rect.height()*0.5;
    if(x <= 0 )
{
    x = 0;
}

    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
{
    x = GAME_WIDTH - m_hero.m_Rect.width();
}

    if(y <= 0)
{
    y = 0;
}

    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
{
    y = GAME_HEIGHT - m_hero.m_Rect.height();
}

    m_hero.setPosition(x,y);
}

void MainScene::collisionDetection()
{
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
    if(m_enemys[i].m_Free)
    {
    continue;
    }
    for(int j = 0 ; j < BULLET_NUM;j++)
    {
    if(m_hero.m_bullets[j].m_Free)
    {
    continue;
    }
    if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
    {
    m_enemys[i].m_Free = true;
    m_hero.m_bullets[j].m_Free = true;
    for(int k = 0 ; k < BOMB_NUM;k++)
    {
    if(m_bombs[k].m_Free)
    {
    m_bombs[k].m_Free = false;
    m_bombs[k].m_X = m_enemys[i].m_X;
    m_bombs[k].m_Y = m_enemys[i].m_Y;
    point++;
    break;
                 }
             }
         }

    }
}

}

void MainScene::updatepoint()
{
    QString str=QString::number(point);
    ui->ScoreBoard->setText(str);
}

void MainScene::enemyToScene()
{
    m_recorder++;
    if(m_recorder <= ENEMY_INTERVAL)
    {
    return;
    }

    m_recorder = 0;

    for(int i = 0 ; i<= ENEMY_NUM;i++)
    {
    if(m_enemys[i].m_Free)
    {
    m_enemys[i].m_Free = false;
    m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
    m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
    break;
    }
    }
}


