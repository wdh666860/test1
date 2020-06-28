#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include "mainwindow.h"
#include "bullet.h"

class WayPoint;
class QPainter;
class MainWindow;
class Tower;
class Bullet;
class Bullet2;

class Enemy : public QObject
{
	Q_OBJECT
public:
    Enemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/enemy1.png"));
	~Enemy();

	void draw(QPainter *painter) const;
	void move();
    void getDamage(int damage , Bullet *bullet);
    void getSlow();
	void getRemoved();
	void getAttacked(Tower *attacker);
	void gotLostSight(Tower *attacker);
    void increase();
	QPoint pos() const;
    int     enemykind;
public slots:
    virtual void doActivate();//接到指示后开始移动，同样的，再后期中对不同种类的敌人，移动的速度可以不一样

protected:
    
	bool			m_active;
	int				m_maxHp;
	int				m_currentHp;
	qreal			m_walkingSpeed;
	qreal			m_rotationSprite;

	QPoint			m_pos;
	WayPoint *		m_destinationWayPoint;
	MainWindow *	m_game;
	QList<Tower *>	m_attackedTowersList;

	const QPixmap	m_sprite;
	static const QSize ms_fixedSize;
};
class Enemy1:public Enemy{
    Q_OBJECT
public:
    Enemy1(WayPoint *startWayPoint,MainWindow *game, const QPixmap &sprite = QPixmap(":/image/enemy 3_1.png"));
};

class Enemy2:public Enemy{
    Q_OBJECT
public:
    Enemy2(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/enemy 3_2.png"));
};
class Enemyboss:public Enemy{
    Q_OBJECT
public:
    Enemyboss(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/enemy 3_3.png"));
};

#endif // ENEMY_H
