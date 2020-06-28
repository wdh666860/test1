#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "towerposition.h"
#include "tower.h"

namespace Ui {
class MainWindow;
}

class WayPoint;
class Enemy;
class Bullet;
class AudioPlayer;

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void getHpDamage(int damage = 1);
	void removedEnemy(Enemy *enemy);
	void removedBullet(Bullet *bullet);
	void addBullet(Bullet *bullet);
	void awardGold(int gold);
    int  getwaves();//获取波数，以便于不断增强敌人
	AudioPlayer* audioPlayer() const;
	QList<Enemy *> enemyList() const;
    int             towertype;
    int             del;
    int             up;
protected:
    
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);

private slots:
	void updateMap();
	void gameStart();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
	void loadTowerPositions();
	void addWayPoints();
	bool loadWave();
	bool canBuyTower() const;
	void drawWave(QPainter *painter);
	void drawHP(QPainter *painter);
	void drawPlayerGold(QPainter *painter);
	void doGameOver();
	void preLoadWavesInfo();

protected:
	Ui::MainWindow *		ui;
	int						m_waves;
	int						m_playerHp;
	int						m_playrGold;
	bool					m_gameEnded;
	bool					m_gameWin;
	AudioPlayer *			m_audioPlayer;
	QList<QVariant>			m_wavesInfo;
	QList<TowerPosition>	m_towerPositionsList;
    QList<Tower *>			m_towersList;
	QList<WayPoint *>		m_wayPointsList;
	QList<Enemy *>			m_enemyList;
	QList<Bullet *>			m_bulletList;
};

#endif // MAINWINDOW_H
