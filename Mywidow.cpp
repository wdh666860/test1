#include "Mywidow.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include "mybutton.h"

Mywidow::Mywidow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(900,650);
}
void Mywidow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix(":/final.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

