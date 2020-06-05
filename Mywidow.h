#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include "tower.h"
#include <QList>

class Mywidow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mywidow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void set_tower();
private:
    QList<Tower*>tower_list;
signals:

};

#endif // PLAYGROUND_H
