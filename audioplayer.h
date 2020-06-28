#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>

class QMediaPlayer;
static const QString s_curDir = "C:/Users/86181/Desktop/TowerDefenseQt/TowerDefenseQt/music";

enum SoundType
{
	TowerPlaceSound,		// 放塔时的声音
    LifeLoseSound,			// 基地费血时的声音

    Bullet1Sound,    //敌人被子弹打中的声音
    Bullet2Sound,
    EnemyDestorySound,// 敌人升天时的声音
    TowerUp,
    TowerDestroy
};

class AudioPlayer : public QObject
{
public:
    explicit AudioPlayer(QUrl backgroundMusicUrl,QObject *parent = 0);

	void startBGM();
    void stopBGM();
	void playSound(SoundType soundType);
    void playWinSound();
    void playLoseSound();
private:
	QMediaPlayer *m_backgroundMusic; // 只用来播放背景音乐
    QMediaPlayer *m_winMusic;
    QMediaPlayer *m_loseMusic;
};


#endif // AUDIOPLAYER_H
