#include "mybutton.h"
#include <QPixmap>

Mybutton::Mybutton(QString p):QPushButton(0)
{
    QPixmap pix(p);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:Opx}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
