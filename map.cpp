#include "map.h"
#include "config.h"
map::map()
{
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;
    m_scroll_speed = MAP_SCROLL_SPEED;
}
void map::mapPosition()
{
    m_map1_posY += MAP_SCROLL_SPEED;
    if(m_map1_posY >= 0)
{
    m_map1_posY =-GAME_HEIGHT;
}
    m_map2_posY += MAP_SCROLL_SPEED;
    if(m_map2_posY >= GAME_HEIGHT )
{
    m_map2_posY =0;
}
}
