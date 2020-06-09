#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waypoint.h"
#include "enemy.h"
#include "bullet.h"
#include "plistreader.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QMessageBox>
#include <QTimer>
#include <QXmlStreamReader>
#include <QtDebug>
#include <QMovie>
#include <QLabel>

static const int TowerCost = 300;

MainWindow::MainWindow(QWidget *parent)//构造函数，以主界面为基础
	: QMainWindow(parent)
    , ui(new Ui::MainWindow)//绘画
    , m_waves(0)//波数
    , m_playerHp(5)//血量
    , m_playrGold(1000)//初始金币
    , m_gameEnded(false)//是否失败
    , m_gameWin(false)//是否获胜
{
	ui->setupUi(this);

    preLoadWavesInfo();//
    loadTowerPositions();//
    addWayPoints();//增加位移点数
    this->setFixedSize(900,600);
	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));//地图随着时间的变换而改变
    timer->start(30);//

	// 设置300ms后游戏启动
	QTimer::singleShot(300, this, SLOT(gameStart()));
}

MainWindow::~MainWindow()//析构函数
{
	delete ui;
}

void MainWindow::loadTowerPositions()
{
    //读取文件中的炮塔位置信息，可以不用深究，但是可以修改位置【可改】

    //这里可以改变炮塔的位置，文件是html格式
    QFile file(":/config/TowersPosition.plist");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "TowerDefense", "Cannot Open TowersPosition.plist");
        return;
    }

    PListReader reader;
    reader.read(&file);

    QList<QVariant> array = reader.data();
    foreach (QVariant dict, array)
    {
        QMap<QString, QVariant> point = dict.toMap();
        int x = point.value("x").toInt();
        int y = point.value("y").toInt();
        m_towerPositionsList.push_back(QPoint(x, y));
    }

    file.close();
}

void MainWindow::paintEvent(QPaintEvent *)//主窗口的绘画功能
{
    if (m_gameEnded || m_gameWin)
    {
        QString text = m_gameEnded ? "YOU LOST!!!" : "YOU WIN!!!";//用字代替结束！！！！！！！！可以改为图片！！！！！！！！！
        QPainter painter(this);//设置针对主窗口的画家
        painter.setPen(QPen(Qt::red));//画家用画笔画画
        painter.drawText(rect(), Qt::AlignCenter, text);//画家写字
        return;
    }

    QPixmap cachePix(":/image/background.jpg");
    QPainter cachePainter(this);//画家对着背景绘画
    cachePainter.drawPixmap(0,0,900,600,cachePix);
    foreach (const TowerPosition &towerPos, m_towerPositionsList)//foreach遍历
        towerPos.draw(&cachePainter);

    foreach (const Tower *tower, m_towersList)
        tower->draw(&cachePainter);


    foreach (const Enemy *enemy, m_enemyList)
        enemy->draw(&cachePainter);

    foreach (const Bullet *bullet, m_bulletList)
        bullet->draw(&cachePainter);

    drawWave(&cachePainter);//画波数
    drawHP(&cachePainter);//画所剩生命值
    drawPlayerGold(&cachePainter);//画现有金钱

    //画背景图片

}

void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标功能
{
	QPoint pressPos = event->pos();
	auto it = m_towerPositionsList.begin();
	while (it != m_towerPositionsList.end())
	{
		if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower())
		{
			m_playrGold -= TowerCost;
			it->setHasTower();
			Tower *tower = new Tower(it->centerPos(), this);
			m_towersList.push_back(tower);
			update();
			break;
		}

		++it;
	}
}

bool MainWindow::canBuyTower() const//判断是否可以买防御塔
{
	if (m_playrGold >= TowerCost)
		return true;
	return false;
}

void MainWindow::drawWave(QPainter *painter)//画波数
{
	painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(400, 5, 100, 25), QString("WAVE : %1").arg(m_waves + 1));
}

void MainWindow::drawHP(QPainter *painter)//画现有生命值
{
	painter->setPen(QPen(Qt::red));
	painter->drawText(QRect(30, 5, 100, 25), QString("HP : %1").arg(m_playerHp));
}

void MainWindow::drawPlayerGold(QPainter *painter)//画现有金钱
{
	painter->setPen(QPen(Qt::red));
	painter->drawText(QRect(200, 5, 200, 25), QString("GOLD : %1").arg(m_playrGold));
}

void MainWindow::doGameOver()//结束
{
	if (!m_gameEnded)
	{
		m_gameEnded = true;
		// 此处应该切换场景到结束场景
		// 暂时以打印替代,见paintEvent处理
	}
}

void MainWindow::awardGold(int gold)//杀怪物得到金钱
{
	m_playrGold += gold;
	update();
}


void MainWindow::addWayPoints()//增加目标点
{
    WayPoint *wayPoint1 = new WayPoint(QPoint(890, 283));
	m_wayPointsList.push_back(wayPoint1);

    WayPoint *wayPoint2 = new WayPoint(QPoint(600, 283));
	m_wayPointsList.push_back(wayPoint2);
	wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3 = new WayPoint(QPoint(600, 180));
	m_wayPointsList.push_back(wayPoint3);
	wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4 = new WayPoint(QPoint(450, 180));
	m_wayPointsList.push_back(wayPoint4);
	wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5 = new WayPoint(QPoint(450, 340));
	m_wayPointsList.push_back(wayPoint5);
	wayPoint5->setNextWayPoint(wayPoint4);

    WayPoint *wayPoint6 = new WayPoint(QPoint(10, 340));
	m_wayPointsList.push_back(wayPoint6);
	wayPoint6->setNextWayPoint(wayPoint5);
}

void MainWindow::getHpDamage(int damage/* = 1*/)//受到伤害
{
	m_playerHp -= damage;
	if (m_playerHp <= 0)
		doGameOver();
}

void MainWindow::removedEnemy(Enemy *enemy)//什么时候移除敌人
{
	Q_ASSERT(enemy);

	m_enemyList.removeOne(enemy);
	delete enemy;

	if (m_enemyList.empty())
	{
		++m_waves;
        if (!loadWave())//判断何时胜利
		{
			m_gameWin = true;
			// 游戏胜利转到游戏胜利场景
			// 这里暂时以打印处理
		}
	}
}

void MainWindow::removedBullet(Bullet *bullet)//判断什么时候移除子弹
{
	Q_ASSERT(bullet);

	m_bulletList.removeOne(bullet);
	delete bullet;
}

void MainWindow::addBullet(Bullet *bullet)//什么时候增加子弹
{
	Q_ASSERT(bullet);

	m_bulletList.push_back(bullet);
}

void MainWindow::updateMap()//更新地图，保持实时更新
{
	foreach (Enemy *enemy, m_enemyList)
		enemy->move();
	foreach (Tower *tower, m_towersList)
		tower->checkEnemyInRange();
	update();
}

void MainWindow::preLoadWavesInfo()
{
    QFile file(":/config/Waves.plist");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "TowerDefense", "Cannot Open TowersPosition.plist");
        return;
    }

    PListReader reader;
    reader.read(&file);

    // 获取波数信息
    m_wavesInfo = reader.data();

    file.close();
}

bool MainWindow::loadWave()
{
    if (m_waves >= m_wavesInfo.size())
        return false;

    WayPoint *startWayPoint = m_wayPointsList.back();
    QList<QVariant> curWavesInfo = m_wavesInfo[m_waves].toList();

    for (int i = 0; i < curWavesInfo.size(); ++i)
    {
        QMap<QString, QVariant> dict = curWavesInfo[i].toMap();
        int spawnTime = dict.value("spawnTime").toInt();

        Enemy *enemy = new Enemy(startWayPoint, this);
        m_enemyList.push_back(enemy);
        QTimer::singleShot(spawnTime, enemy, SLOT(doActivate()));
    }

    return true;
}

QList<Enemy *> MainWindow::enemyList() const
{
    return m_enemyList;
}

void MainWindow::gameStart()
{
    loadWave();
}
