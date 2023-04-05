#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "config.h"
#include <QTimer>
#include <QPixmap>
#include "map.h"
#include "heroplane.h"
#include "enemyplane.h"
#include "bullet.h"
#include "bomb.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void initScene();
    void playGame();
    void updatePosition();
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void collisionDetection();
    void updatepoint();
    QTimer m_Timer;
    map m_map;
    HeroPlane m_hero;
    Bullet temp_bullet;
    void enemyToScene();
    EnemyPlane m_enemys[ENEMY_NUM];
    int m_recorder;
    Bomb m_bombs[BOMB_NUM];
    int point;
private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
