#ifndef TOWER_H
#define TOWER_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include "bullet.h"

class QPainter;
class Enemy;
class MainWindow;
class QTimer;

class Tower : public QObject
{
	Q_OBJECT
public:
    Tower(QPoint pos, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/tower1_1.png"));
	~Tower();

	void draw(QPainter *painter) const;
	void checkEnemyInRange();
	void targetKilled();
	void attackEnemy();
	void chooseEnemyForAttack(Enemy *enemy);
	void removeBullet();
	void damageEnemy();
	void lostSightOfEnemy();
    virtual int gettowertype();
    virtual int getlevel();
    Bullet       *bullet;
private slots://槽函数，对不同类的塔有不同的武器子弹，所以先在此用虚函数

    virtual void shootWeapon();

    protected:
	bool			m_attacking;
    int				m_attackRange;
    int				m_damage;
    int				m_fireRate;
	qreal			m_rotationSprite;

	Enemy *			m_chooseEnemy;
	MainWindow *	m_game;
	QTimer *		m_fireRateTimer;

	const QPoint	m_pos;
	const QPixmap	m_sprite;

	static const QSize ms_fixedSize;
};
class Tower1 : public Tower
{
    Q_OBJECT
public:
    Tower1(QPoint pos, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/tower1_1.png"));
    ~Tower1();
    virtual int gettowertype();
    virtual int getlevel();
protected slots:
    virtual void shootWeapon();

};
class Tower1_2 : public Tower1
{
    Q_OBJECT
public:
    Tower1_2(QPoint pos, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/tower1_2.png"));
    ~Tower1_2();
    virtual int gettowertype();
    virtual int getlevel();
protected slots:
    virtual void shootWeapon();
};



class Tower2 : public Tower
{
    Q_OBJECT
public:
    Tower2(QPoint pos, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/tower2_1.png"));
    ~Tower2();
    virtual int gettowertype();
    virtual int getlevel();
protected slots:
   virtual void shootWeapon();

};

class Tower2_2 : public Tower2
{
    Q_OBJECT
public:
    Tower2_2(QPoint pos, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/tower2_2.png"));
    ~Tower2_2();
    virtual int gettowertype();
    virtual int getlevel();
protected slots:
   virtual void shootWeapon();

};


#endif // TOWER_H
