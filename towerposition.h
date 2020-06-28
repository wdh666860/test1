#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include "tower.h"

class QPainter;

class TowerPosition
{
public:
    TowerPosition(QPoint pos, const QPixmap &sprite = QPixmap(":/image/open_spot.png"));
    void setHasTower(bool hasTower = true);
    void setHasnotTower(bool hasnotTower = false);
    bool hasTower() const;
    const QPoint centerPos() const;
    bool containPoint(const QPoint &pos) const;

    void draw(QPainter *painter) const;

    Tower*       m_tower;
private:
    //几包含3个信息：坐标点、尺寸大小、图片信息

    bool		m_hasTower;
    QPoint		m_pos;
    QPixmap		m_sprite;
    static const QSize ms_fixedSize; //QSize保存二维数据，这里应该指炮塔位置的长和宽
};

#endif // TOWERPOSITION_H
