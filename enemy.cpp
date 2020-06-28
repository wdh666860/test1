#include "enemy.h"
#include "waypoint.h"
#include "tower.h"
#include "utility.h"
#include "mainwindow.h"
#include "audioplayer.h"
#include "bullet.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QMatrix>
#include <QVector2D>
#include <QtMath>

class MainWindow;
static const int Health_Bar_Width = 20;
const QSize Enemy::ms_fixedSize(40, 40);
Enemy::Enemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/enemy3_1.png")*/)
	: QObject(0)
	, m_active(false)
	, m_maxHp(40)
	, m_currentHp(40)
	, m_walkingSpeed(1.0)
	, m_rotationSprite(0.0)
	, m_pos(startWayPoint->pos())
	, m_destinationWayPoint(startWayPoint->nextWayPoint())
	, m_game(game)
	, m_sprite(sprite)
{
}

Enemy::~Enemy()
{
	m_attackedTowersList.clear();
	m_destinationWayPoint = NULL;
	m_game = NULL;
}

void Enemy::doActivate()
{
	m_active = true;
}

void Enemy::move()
{
	if (!m_active)
		return;

	if (collisionWithCircle(m_pos, 1, m_destinationWayPoint->pos(), 1))
	{
		// 敌人抵达了一个航点
		if (m_destinationWayPoint->nextWayPoint())
		{
			// 还有下一个航点
			m_pos = m_destinationWayPoint->pos();
			m_destinationWayPoint = m_destinationWayPoint->nextWayPoint();
		}
		else
		{
			// 表示进入基地
			m_game->getHpDamage();
			m_game->removedEnemy(this);
			return;
		}
	}

	// 还在前往航点的路上
	// 目标航点的坐标
	QPoint targetPoint = m_destinationWayPoint->pos();
	// 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值

	// 向量标准化
	qreal movementSpeed = m_walkingSpeed;
	QVector2D normalized(targetPoint - m_pos);
	normalized.normalize();
	m_pos = m_pos + normalized.toPoint() * movementSpeed;
}

void Enemy::draw(QPainter *painter) const
{
	if (!m_active)
		return;

	painter->save();

    QPoint healthBarPoint = m_pos + QPoint(-Health_Bar_Width / 2+32 , -ms_fixedSize.height() / 2);
	// 绘制血条
	painter->setPen(Qt::NoPen);
	painter->setBrush(Qt::red);
	QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
	painter->drawRect(healthBarBackRect);

	painter->setBrush(Qt::green);
	QRect healthBarRect(healthBarPoint, QSize((double)m_currentHp / m_maxHp * Health_Bar_Width, 2));
	painter->drawRect(healthBarRect);

	// 绘制偏转坐标,由中心+偏移=左上
	static const QPoint offsetPoint(-ms_fixedSize.width() / 2, -ms_fixedSize.height() / 2);
	painter->translate(m_pos);
	painter->rotate(m_rotationSprite);
	// 绘制敌人
	painter->drawPixmap(offsetPoint, m_sprite);

	painter->restore();
}

void Enemy::getRemoved()
{
	if (m_attackedTowersList.empty())
		return;

	foreach (Tower *attacker, m_attackedTowersList)
		attacker->targetKilled();
	// 通知game,此敌人已经阵亡
	m_game->removedEnemy(this);
}

void Enemy::getDamage(int damage, Bullet *bullet)//敌人受伤和死亡都要有音效
{
    if(bullet->m_kind==1)
    {
            m_game->audioPlayer()->playSound(Bullet1Sound);
            m_currentHp -= damage;

            if (m_currentHp <= 0)
            {
                m_game->audioPlayer()->playSound(EnemyDestorySound);
                m_game->awardGold(200);
                getRemoved();
            }
    }
    if(bullet->m_kind==2)
    {
        m_game->audioPlayer()->playSound(Bullet2Sound);
        m_currentHp -= damage;

        if (m_currentHp <= 0)
        {
            m_game->audioPlayer()->playSound(EnemyDestorySound);
            m_game->awardGold(200);
            getRemoved();
        }
    }
}
void Enemy::getSlow()
{
    m_walkingSpeed=m_walkingSpeed-0.1;
}

void Enemy::getAttacked(Tower *attacker)
{
	m_attackedTowersList.push_back(attacker);
}

void Enemy::gotLostSight(Tower *attacker)
{
	m_attackedTowersList.removeOne(attacker);
}

QPoint Enemy::pos() const
{
	return m_pos;
}
void Enemy::increase()
{
    this->m_maxHp=m_maxHp+20*m_game->getwaves();
    this->m_currentHp=m_currentHp+20*m_game->getwaves();
    this->m_walkingSpeed=m_walkingSpeed+1*m_game->getwaves();
}
Enemy1::Enemy1(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/enemy3_1.png")*/)
    :Enemy(startWayPoint, game,sprite/* = QPixmap(":/image/enemy1.png")*/)

{    this->m_maxHp=50;
     m_currentHp=50;
     m_walkingSpeed=1.5;
      enemykind=1;

}
Enemy2::Enemy2(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/enemy3_2.png")*/)
    :Enemy(startWayPoint, game,sprite/* = QPixmap(":/image/enemy1.png")*/)

{    this->m_maxHp=70;
     m_currentHp=70;
     m_walkingSpeed=2.0;
      enemykind=2;
}
Enemyboss::Enemyboss(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/enemy3_3.png")*/)
    :Enemy(startWayPoint, game,sprite/* = QPixmap(":/image/enemy1.png")*/)

{    this->m_maxHp=100;
     m_currentHp=100;
     m_walkingSpeed=2.5;
      enemykind=3;
}
