#include "enemyplane.h"
#include "config.h"
EnemyPlane::EnemyPlane()
{
    m_enemy.load(ENEMY_PATH);
    m_X = 0;
    m_Y = 0;
    m_Free = true;
    m_Speed = ENEMY_SPEED;
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);
}

void EnemyPlane::updatePosition()
{
    if(m_Free)
    {
    return;
    }
    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    if(m_Y >= GAME_HEIGHT+m_Rect.height())
    {
    m_Free = true;
    }
}
