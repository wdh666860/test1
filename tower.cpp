#include "tower.h"
#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
Tower::Tower(QPoint pos, QString name) : QObject(0),pixmap(name)
{
    _pos=pos;
}
void Tower::draw(QPainter *painter)
{
    painter->drawPixmap(_pos,pixmap);
}
