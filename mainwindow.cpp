#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include "mybutton.h"
#include "Mywidow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900,650);
    Mybutton *b1=new Mybutton(":/easy.jpg");
    Mybutton *b2=new Mybutton(":/hard.jpg");
    b1->setParent(this);
    b2->setParent(this);
    b1 ->move(175,290);
    b2->move(600,290);
    Mywidow * play1 = new Mywidow();
    Mywidow * play2 = new Mywidow();
    connect(b1,&QPushButton::clicked,this,[=](){
        this->close();
        play1->show();
    });
   connect(b2,&QPushButton::clicked,this,[=](){
        this->close();
        play2->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap(":/Title.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}

