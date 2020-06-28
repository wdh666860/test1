#include "tower.h"
#include "enemy.h"
#include "bullet.h"
#include "mainwindow.h"
#include "utility.h"
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QVector2D>
#include <QtMath>

const QSize Tower::ms_fixedSize(65, 65);

Tower::Tower(QPoint pos, MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/tower1_1.png"*/)
	: m_attacking(false)
    , m_attackRange(150)
	, m_damage(10)
	, m_fireRate(1000)
	, m_rotationSprite(0.0)
	, m_chooseEnemy(NULL)
	, m_game(game)
	, m_pos(pos)
	, m_sprite(sprite)
{
	m_fireRateTimer = new QTimer(this);
	connect(m_fireRateTimer, SIGNAL(timeout()), this, SLOT(shootWeapon()));
}

Tower::~Tower()
{
	delete m_fireRateTimer;
	m_fireRateTimer = NULL;
}

void Tower::checkEnemyInRange()
{
	if (m_chooseEnemy)
	{
		QVector2D normalized(m_chooseEnemy->pos() - m_pos);
		normalized.normalize();
		m_rotationSprite = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) - 90;
		if (!collisionWithCircle(m_pos, m_attackRange, m_chooseEnemy->pos(), 1))
			lostSightOfEnemy();
	}
	else
	{
		QList<Enemy *> enemyList = m_game->enemyList();
		foreach (Enemy *enemy, enemyList)
		{
			if (collisionWithCircle(m_pos, m_attackRange, enemy->pos(), 1))
			{
				chooseEnemyForAttack(enemy);
				break;
			}
		}
	}
}

void Tower::draw(QPainter *painter) const
{
	painter->save();
	painter->setPen(Qt::white);
	// 绘制攻击范围
	painter->drawEllipse(m_pos, m_attackRange, m_attackRange);

	// 绘制偏转坐标,由中心+偏移=左上
    static const QPoint offsetPoint(-ms_fixedSize.width() /2-5, -ms_fixedSize.height() / 2-5);
	// 绘制炮塔并选择炮塔
	painter->translate(m_pos);
	painter->rotate(m_rotationSprite);
	painter->drawPixmap(offsetPoint, m_sprite);
	painter->restore();
}
int Tower::gettowertype()
{
    return 1;
}
int Tower::getlevel()
{
    return 1;
}

void Tower::attackEnemy()
{
	m_fireRateTimer->start(m_fireRate);
}

void Tower::chooseEnemyForAttack(Enemy *enemy)
{
	m_chooseEnemy = enemy;
	attackEnemy();
	m_chooseEnemy->getAttacked(this);
}

void Tower::shootWeapon()
{
    Bullet *bullet = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game);
	bullet->move();
	m_game->addBullet(bullet);
}

void Tower::targetKilled()
{
	if (m_chooseEnemy)
		m_chooseEnemy = NULL;

	m_fireRateTimer->stop();
	m_rotationSprite = 0.0;
}

void Tower::lostSightOfEnemy()
{
	m_chooseEnemy->gotLostSight(this);
	if (m_chooseEnemy)
		m_chooseEnemy = NULL;

	m_fireRateTimer->stop();
	m_rotationSprite = 0.0;
}
Tower1::Tower1(QPoint pos, MainWindow *game, const QPixmap &sprite)
    : Tower(pos, game, sprite)
{
    m_attackRange=150;
    m_damage=10;
}
Tower1::~Tower1()
{
}
void Tower1::shootWeapon()
{
    Bullet *bullet = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game);
    bullet->move();
    m_game->addBullet(bullet);
}
int Tower1::gettowertype()
{
    return 1;
}
int Tower1::getlevel()
{
    return 1;
}

Tower1_2::Tower1_2(QPoint pos, MainWindow *game, const QPixmap &sprite)
    : Tower1(pos, game, sprite)
{
    m_attackRange=250;
    m_damage=15;
}
Tower1_2::~Tower1_2()
{
}
void Tower1_2::shootWeapon()
{
    Bullet *bullet = new Bullet(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game);
    bullet->move();
    m_game->addBullet(bullet);
}
int Tower1_2::gettowertype()
{
    return 1;
}
int Tower1_2::getlevel()
{
    return 2;
}



Tower2::Tower2(QPoint pos, MainWindow *game, const QPixmap &sprite)
    : Tower(pos, game, sprite)
{
    m_attackRange=200;
    m_damage=15;
}
Tower2::~Tower2()
{

}
void Tower2::shootWeapon()
{
    Bullet2 *bullet2 = new Bullet2(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game);
    bullet2->move();
    m_game->addBullet(bullet2);
}
int Tower2::gettowertype()
{
    return 2;
}
int Tower2::getlevel()
{
    return 1;
}




Tower2_2::Tower2_2(QPoint pos, MainWindow *game, const QPixmap &sprite)
    : Tower2(pos, game, sprite)
{
    m_attackRange=300;
    m_damage=20;
}
Tower2_2::~Tower2_2()
{

}
void Tower2_2::shootWeapon()
{
    Bullet2 *bullet2 = new Bullet2(m_pos, m_chooseEnemy->pos(), m_damage, m_chooseEnemy, m_game);
    bullet2->move();
    m_game->addBullet(bullet2);
}
int Tower2_2::gettowertype()
{
    return 2;
}
int Tower2_2::getlevel()
{
    return 2;
}


