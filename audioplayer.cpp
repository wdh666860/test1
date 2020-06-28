#include "audioplayer.h"
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>

AudioPlayer::AudioPlayer(QUrl backgroundMusicUrl,QObject *parent)
    : QObject(parent)
    , m_backgroundMusic(NULL)
    , m_winMusic(NULL)
    , m_loseMusic(NULL)
{
    m_winMusic = new QMediaPlayer(this);
    m_winMusic->setMedia(QUrl::fromLocalFile(s_curDir + "/Win.mp3"));
    m_loseMusic = new QMediaPlayer(this);
    m_loseMusic->setMedia(QUrl::fromLocalFile(s_curDir + "/Lose.mp3"));
    if (QFile::exists(backgroundMusicUrl.toLocalFile()))
    {
        m_backgroundMusic = new QMediaPlayer(this);
        QMediaPlaylist *backgroundMusicList = new QMediaPlaylist();

        QMediaContent media(backgroundMusicUrl);
        backgroundMusicList->addMedia(media);
        backgroundMusicList->setCurrentIndex(0);
        backgroundMusicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        m_backgroundMusic->setPlaylist(backgroundMusicList);
    }
}
void AudioPlayer::startBGM()
{
	if (m_backgroundMusic)
		m_backgroundMusic->play();
}
void AudioPlayer::stopBGM(){
    m_backgroundMusic->stop();
}
void AudioPlayer::playWinSound(){
    if(m_winMusic)
        m_winMusic->play();
}

void AudioPlayer::playLoseSound(){
    if(m_loseMusic)
        m_loseMusic->play();
}
void AudioPlayer::playSound(SoundType soundType)
{
	static const QUrl mediasUrls[] =
	{
        QUrl::fromLocalFile(s_curDir + "/tower_place.mp3"),
        QUrl::fromLocalFile(s_curDir + "/loselife.wav"),
        QUrl::fromLocalFile(s_curDir + "/Bullet1.mp3"),
        QUrl::fromLocalFile(s_curDir + "/Bullet2.mp3"),
        QUrl::fromLocalFile(s_curDir + "/destroy_enemy.mp3"),
        QUrl::fromLocalFile(s_curDir + "/up.wav"),
        QUrl::fromLocalFile(s_curDir + "/destroy_tower.wav")
	};
	static QMediaPlayer player;

	if (QFile::exists(mediasUrls[soundType].toLocalFile()))
	{
		player.setMedia(mediasUrls[soundType]);
		player.play();
	}
}

