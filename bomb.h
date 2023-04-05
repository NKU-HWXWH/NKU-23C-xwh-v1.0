#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include <QPixmap>
#include <QVector>
class Bomb
{
public:
    Bomb();
    void updateInfo();
    public:
    QVector<QPixmap> m_pixArr;
    int m_X;
    int m_Y;
    bool m_Free;
    int m_Recoder;
    int m_index;
};

#endif // BOMB_H
