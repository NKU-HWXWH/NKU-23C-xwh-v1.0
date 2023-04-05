#include "bullet.h"
#include "config.h"
Bullet::Bullet()
{
    m_Bullet.load(BULLET_PATH);
    m_X = GAME_WIDTH*0.5 - m_Bullet.width()*0.5;
    m_Y = GAME_HEIGHT;
    m_Free = true;
    m_Speed = BULLET_SPEED;
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);

}

void Bullet::updatePosition()
{
    if(m_Free)
    {
    return;
    }
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    if(m_Y <= -m_Rect.height())
    {
    m_Free = true;
    }
}
