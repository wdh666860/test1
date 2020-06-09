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
    bool hasTower() const;
    const QPoint centerPos() const;
    bool containPoint(const QPoint &pos) const;

    void draw(QPainter *painter) const;

    int         m_towerkind;
    Tower*       m_tower;

private:
    //几乎所有对象都包含3个信息：坐标点、尺寸大小、图片信息
    bool		m_hasTower;
    QPoint		m_pos; //QPoint定义点坐标，这里保存区域的左上角坐标
    QPixmap		m_sprite;

    static const QSize ms_fixedSize; //QSize保存二维数据，这里应该指炮塔位置的长和宽
};

#endif // TOWERPOSITION_H
