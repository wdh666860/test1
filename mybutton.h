#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>


class Mybutton : public QPushButton
{
    Q_OBJECT
public:
    Mybutton(QString p);

signals:

};

#endif // MYBUTTON_H
