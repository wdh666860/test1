#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waypoint.h"
#include "enemy.h"
#include "bullet.h"
#include "audioplayer.h"
#include "plistreader.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QMessageBox>
#include <QTimer>
#include <QXmlStreamReader>
#include <QtDebug>

static const int TowerCost = 300;
static const int UpCost = 400;

MainWindow::MainWindow(QWidget *parent)//构造函数，以主界面为基础
	: QMainWindow(parent)
    , ui(new Ui::MainWindow)//绘画
    , m_waves(0)//波数
    , m_playerHp(100)//血量
    , m_playrGold(10000)//初始金币
    , m_gameEnded(false)//是否失败
    , m_gameWin(false)//是否获胜
{
	ui->setupUi(this);
    this->setFixedSize(900,600);//设置窗口的大小
    preLoadWavesInfo();
    loadTowerPositions();
    addWayPoints();//增加位移点数
    QUrl backgroundMusicUrl = QUrl::fromLocalFile(s_curDir + "/background.wav");
    m_audioPlayer = new AudioPlayer(backgroundMusicUrl,this);
	m_audioPlayer->startBGM();

	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));//地图随着时间的变换而改变
    timer->start(30);
	QTimer::singleShot(300, this, SLOT(gameStart()));
}

MainWindow::~MainWindow()//析构函数
{
	delete ui;
}

void MainWindow::loadTowerPositions()//读取防御塔的位置信息
{
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
    //应该隐藏按钮
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
    if(m_gameWin){        
    QPixmap lastback(":/image/victory.jpg");
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(),this->height(),lastback);
    }
    if(m_gameEnded)
    {
        QPixmap lastback(":/image/loss.jpg");
        QPainter painter(this);
        painter.drawPixmap(0, 0,this->width(),this->height(), lastback);
    }
    return;
    }
    QPixmap cachePix(":/image/background.jpg");
    QPainter cachePainter(this);//画家对着窗口绘画
    cachePainter.drawPixmap(0,0,this->width(),this->height(),cachePix);
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
}

void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标功能,从塔基开始遍历
{
	QPoint pressPos = event->pos();
	auto it = m_towerPositionsList.begin();
	while (it != m_towerPositionsList.end())
	{
        if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower() && towertype==1 && up==0 && del==0)
		{
			m_audioPlayer->playSound(TowerPlaceSound);
			m_playrGold -= TowerCost;
			it->setHasTower();

            it->m_tower = new Tower1(it->centerPos(), this);
            m_towersList.push_back(it->m_tower);
			update();
			break;
		}
        if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower() && towertype==2 && up==0 && del==0)
        {
            m_audioPlayer->playSound(TowerPlaceSound);
            m_playrGold -= TowerCost+200;
            it->setHasTower();

            it->m_tower = new Tower2(it->centerPos(), this);//构建的同时直接在mainwindow上作画
            m_towersList.push_back(it->m_tower);//把新构建的塔放入towerlist中储存，方便管理
            update();
            break;
        }
        //删除的鼠标事件，难点：如何删除塔
        if( it->containPoint(pressPos) && it->hasTower() && towertype==0 && up==0 && del==1)
        {
            m_towersList.removeOne(it->m_tower);
            it->setHasnotTower();
            m_bulletList.removeOne(it->m_tower->bullet);
            m_audioPlayer->playSound(TowerDestroy);
            update();
            break;
        }
        //升级的鼠标事件
        if( it->containPoint(pressPos) && it->hasTower() && towertype==0 && up==1 && del==0)
        {
             if(it->m_tower->gettowertype()==1 && it->m_tower->getlevel()==1 && m_playrGold>=UpCost)
                {
                     m_towersList.removeOne(it->m_tower);
                     it->m_tower = new Tower1_2(it->centerPos(), this);
                     m_towersList.push_back(it->m_tower);
                     m_playrGold -= UpCost;

                     update();
                }

              if(it->m_tower->gettowertype()==2 && it->m_tower->getlevel()==1 && m_playrGold>=UpCost)
                {
                    m_towersList.removeOne(it->m_tower);
                    it->m_tower = new Tower2_2(it->centerPos(), this);
                    m_towersList.push_back(it->m_tower);
                    m_playrGold -= UpCost;
                    update();

                }

            m_audioPlayer->playSound(TowerUp);
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
    painter->setPen(QPen(Qt::white));
    QFont font =painter->font();
    font.setPixelSize(30);
    painter->setFont(font);
    painter->drawText(QRect(860, 5, 300, 75), QString(" %1").arg(m_waves + 1));
}

void MainWindow::drawHP(QPainter *painter)//画现有生命值
{
    painter->setPen(QPen(Qt::white));
    painter->drawText(QRect(600, 5, 300, 75), QString("%1").arg(m_playerHp));
}

void MainWindow::drawPlayerGold(QPainter *painter)//画现有金钱
{
    painter->setPen(QPen(Qt::white));
    painter->drawText(QRect(720, 5, 300, 75), QString("%1").arg(m_playrGold));
}

void MainWindow::doGameOver()//结束
{
    if (!m_gameEnded)
    {
        m_gameEnded = true;

        m_audioPlayer->stopBGM();
        m_audioPlayer->playLoseSound();
    }
}

void MainWindow::awardGold(int gold)//杀怪物得到金钱
{
	m_playrGold += gold;
	update();
}

AudioPlayer *MainWindow::audioPlayer() const//播放音乐
{
	return m_audioPlayer;
}

void MainWindow::addWayPoints()//增加目标点
{
    WayPoint *wayPoint1 = new WayPoint(QPoint(890, 280));
	m_wayPointsList.push_back(wayPoint1);

    WayPoint *wayPoint2 = new WayPoint(QPoint(575, 280));
	m_wayPointsList.push_back(wayPoint2);
	wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3 = new WayPoint(QPoint(575, 170));
	m_wayPointsList.push_back(wayPoint3);
	wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4 = new WayPoint(QPoint(435, 170));
	m_wayPointsList.push_back(wayPoint4);
	wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5 = new WayPoint(QPoint(435, 340));
	m_wayPointsList.push_back(wayPoint5);
	wayPoint5->setNextWayPoint(wayPoint4);

    WayPoint *wayPoint6 = new WayPoint(QPoint(10, 340));
	m_wayPointsList.push_back(wayPoint6);
	wayPoint6->setNextWayPoint(wayPoint5);
}

void MainWindow::getHpDamage(int damage/* = 1*/)//受到伤害
{
	m_audioPlayer->playSound(LifeLoseSound);
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
            m_audioPlayer->stopBGM();
            m_audioPlayer->playWinSound();
			m_gameWin = true;
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

bool MainWindow::loadWave()//加载波的数量和每一波的敌人个数
{
    if (m_waves >= m_wavesInfo.size())
        return false;

    WayPoint *startWayPoint = m_wayPointsList.back();
    QList<QVariant> curWavesInfo = m_wavesInfo[m_waves].toList();

    for (int i = 0; i < curWavesInfo.size(); ++i)
    {
        QMap<QString, QVariant> dict = curWavesInfo[i].toMap();
        int spawnTime = dict.value("spawnTime").toInt();
        Enemy *enemy;//父类接收
        int j=i%3;
        switch(j){
        case 0:
            enemy = new Enemy1(startWayPoint, this);
            enemy->increase();
            break;
        case 1:
            enemy=new Enemy2(startWayPoint, this);
            enemy->increase();
            break;
        case 2:
            enemy=new Enemyboss(startWayPoint, this);
            enemy->increase();
            break;
        }
        m_enemyList.push_back(enemy);
        QTimer::singleShot(spawnTime, enemy, SLOT(doActivate()));
    }

    return true;
}



QList<Enemy *> MainWindow::enemyList() const//敌人的集合
{
	return m_enemyList;
}

void MainWindow::gameStart()//开始
{
	loadWave();
}
    int  MainWindow::getwaves()
    {
        return  m_waves;
    }


void MainWindow::on_pushButton_2_clicked()//tower2
{
    towertype=2;
    del=0;
    up=0;
}

void MainWindow::on_pushButton_clicked()//tower1
{
    towertype=1;
    del=0;
    up=0;
}

void MainWindow::on_pushButton_3_clicked()//删除
{
    del=1;
    towertype=0;
    up=0;
}

void MainWindow::on_pushButton_4_clicked()//升级
{
    del=0;
    towertype=0;
    up=1;
}

