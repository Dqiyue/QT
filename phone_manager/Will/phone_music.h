#ifndef PHONE_MUSIC_H
#define PHONE_MUSIC_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QSignalMapper>
#include <QToolButton>
#include <QFile>
#include <QDir>
#include <QSlider>
#include <QPushButton>
#include <QDebug>
#include <QMediaPlayer>
#include <QAbstractItemView>
#include <QListView>
#include <QGraphicsDropShadowEffect>
#include <QMediaMetaData>
#include <QTime>
#include <QMessageBox>
#include <QProcess>
#include <QScrollArea>
#include <QThread>
#include <QSizeGrip>
#include "playlistmodel.h"
#include "Common.h"

class QModelIndex;



class Phone_Music : public QWidget
{
    Q_OBJECT
public:
    explicit Phone_Music(QWidget *parent = 0);
    ~Phone_Music();

    QMediaPlayer::State state() const;
    int volume() const;
    bool isMuted() const;

public:
    int song_number;
    void pause_the_music_play();
    void turn_next_page();

signals:

    void changeVolume(int volume);
    void changeMuting(bool muting);
    void changeRate(qreal rate);
    void play();
    void pause();
    void update_song_number(int song_number);




public slots:
    void play_and_pause_clicked();

    void setState(QMediaPlayer::State state);
    void setVolume(int volume);
    void setMuted(bool muted);

    void playMusic(QString songName);

    void change_to_play_mode_one();
    void change_to_play_mode_two();
    void change_to_play_mode_three();
    void delete_song(QString index);
    void output_song(QString index);


//    void preSong();
//    void nextSong();

private slots:
//    void playClicked();
    void muteClicked();
    void next_song_clicked();
    void input_music();

    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);
    void metaDataChanged();

    void previousClicked();

    void seek(int seconds);
    void jump(const QModelIndex &index);
    void playlistPositionChanged(int);

    void statusChanged(QMediaPlayer::MediaStatus status);
    void bufferingProgress(int progress);
//    void videoAvailableChanged(bool available);

    void displayErrorMessage();


    bool addToPlaylist(QFileInfo fileInfo);
    void out_pro_fin(int ec);
    void in_pro_fin(int ec);



private:
    void init_music_list();
    void init_bottom_widget();
    void clearLayout(QLayout* layout);

    void setTrackInfo(const QString &info);
    void setStatusInfo(const QString &info);
    void handleCursor(QMediaPlayer::MediaStatus status);
    void updateDurationInfo(qint64 currentInfo);
    void update_music_list();

private:

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QAbstractItemView *playlistView;
    PlaylistModel *playlistModel;
    QWidget *music_list_widget;

    QSlider *slider;
    QSlider *music_volumes_slider;
    QWidget *bottom_music_show;
    QVBoxLayout *music_list_layout;
    QProcess *in;
    QProcess *out;

    QList<QPushButton*> btnlist;
    QList<QPushButton*> btnlist_del;
    QList<QPushButton*> btnlist_out;
    QList<QFileInfo> music_fileInfo_list;
    QLabel *main_label;
    QLabel *music_label;
    QLabel *bottom_label;
    QLabel *message_label;
    QVBoxLayout *main_layout;
    QVBoxLayout *bottom_layout;
    QHBoxLayout *play_control_layout;
    QPushButton *play_and_pause;
    QPushButton *next_song;
    QPushButton *pre_song;
    QPushButton *song_flush;
    QPushButton *play_mode_one;
    QPushButton *play_mode_two;
    QPushButton *play_mode_three;
    QPushButton *muted_button;
    QPushButton *input_button;
    QHBoxLayout *play_mode_layout;
    QHBoxLayout *duration_layout;
    QHBoxLayout *music_label_layout;
    QScrollArea *scroll_area;

    QLabel *duration_played;
    QLabel *labelDuration;
    QString trackInfo;
    QString statusInfo;
    qint64 duration;
    QMediaPlayer::State playerState;
    bool is_muted;
    int pre_song_index;
    bool is_played;
    int current_song;

};

#endif // PHONE_MUSIC_H
