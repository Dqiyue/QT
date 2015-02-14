#include "phone_music.h"
#include <QMediaPlaylist>

Phone_Music::Phone_Music(QWidget *parent) :
    QWidget(parent)
    , slider(0)
    , play_and_pause(0)
{
    main_label = new QLabel();
    main_layout = new QVBoxLayout();
    music_list_layout = new QVBoxLayout();
    bottom_music_show = new QWidget();
    pre_song = new QPushButton();
    next_song = new QPushButton();
    scroll_area = new QScrollArea(this);
    input_button = new QPushButton("Import");
    play_and_pause = new QPushButton;
    music_volumes_slider = new QSlider(Qt::Horizontal);
    bottom_layout = new QVBoxLayout();
    play_control_layout = new QHBoxLayout();
    bottom_label = new QLabel();
    music_label = new QLabel();
    message_label = new QLabel();
    play_mode_one = new QPushButton;
    play_mode_two = new QPushButton;
    play_mode_three = new QPushButton;
    play_mode_layout = new QHBoxLayout();
    music_label_layout = new QHBoxLayout();
    music_list_widget = new QWidget();
    muted_button = new QPushButton();
    is_muted = false;
       in = new QProcess();//new a process to exec the script
          out = new QProcess();//new a process to exec the script
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist();
    player->setPlaylist(playlist);
    playlistModel = new PlaylistModel(this);
    playlistModel->setPlaylist(playlist);
    is_played = false;
//    playlistView = new QListView(this);
//    playlistView->setModel(playlistModel);
//    playlistView->setCurrentIndex(playlistModel->index(playlist->currentIndex(), 0));


    duration_played = new QLabel();
    slider = new QSlider(Qt::Horizontal);
    labelDuration = new QLabel();
    duration_layout = new QHBoxLayout();
//    scroll_area->resize(290,2200);
    scroll_area->setWidgetResizable(true);
    music_list_widget->setLayout(music_list_layout);
    music_list_widget->setFixedWidth(280);
    scroll_area->setWidget(music_list_widget);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll_area->setFixedWidth(290);
    scroll_area->setFixedHeight(200);
    scroll_area->setFrameStyle(QFrame::NoFrame);
 //----------------------------------------------------player--------------------------------



//    connect(playlistView, SIGNAL(activated(QModelIndex)), this, SLOT(jump(QModelIndex)));
    connect(player, SIGNAL(durationChanged(qint64)),this, SLOT(durationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this,SLOT(positionChanged(qint64)));
    connect(player, SIGNAL(metaDataChanged()), this,SLOT(metaDataChanged()));
    connect(playlist, SIGNAL(currentIndexChanged(int)),this ,SLOT(playlistPositionChanged(int)));
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this, SLOT(statusChanged(QMediaPlayer::MediaStatus)));
    connect(player, SIGNAL(bufferStatusChanged(int)), this, SLOT(bufferingProgress(int)));
//    connect(player, SIGNAL(videoAvailableChanged(bool)), this, SLOT(videoAvailableChanged(bool)));
    connect(player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(displayErrorMessage()));

    this->setState(player->state());
    this->setVolume(player->volume());
    this->setMuted(this->isMuted());

    playlistView = new QListView();
    playlistView->setModel(playlistModel);
    playlistView->setCurrentIndex(playlistModel->index(playlist->currentIndex(), 0));

    connect(playlistView, SIGNAL(activated(QModelIndex)), this, SLOT(jump(QModelIndex)));


    slider->setRange(0, player->duration() / 1000);

    connect(slider, SIGNAL(sliderMoved(int)), this, SLOT(seek(int)));



 //------------
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(setState(QMediaPlayer::State)));
    connect(player, SIGNAL(volumeChanged(int)), this, SLOT(setVolume(int)));
    connect(player, SIGNAL(mutedChanged(bool)), this, SLOT(setMuted(bool)));



    if (!player->isAvailable()) {
        QMessageBox::warning(this, tr("Service not available"),
                             tr("The QMediaPlayer object does not have a valid service.\n"\
                                "Please check the media service plugins are installed."));
        pre_song->setDisabled(true);
        next_song->setDisabled(true);
        play_and_pause->setDisabled(true);
        music_volumes_slider->setDisabled(true);
        play_mode_one->setDisabled(true);
        play_mode_two->setDisabled(true);
          muted_button->setDisabled(true);
          slider->setDisabled(true);
        playlistView->setEnabled(false);

    }
    metaDataChanged();


 //----------------------------------------------------------------------------
    qDebug() << "this is 1";

    this->init_music_list();
    this->init_bottom_widget();

    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText, QColor(255, 181, 0));

    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(46, 139, 87));



    connect(this,SIGNAL(play()),player,SLOT(play()));
    connect(this,SIGNAL(pause()),player,SLOT(pause()));
    connect(this,SIGNAL(changeMuting(bool)),player,SLOT(setMuted(bool)));
    music_label->setText("Local Music");
    music_label->setFont(QFont(URW_P_FONT,13,50,false));
    music_label->setPalette(text_palette);
    message_label->setFont(QFont(PURISA,10,50,true));
    input_button->setFont(QFont(URW_P_FONT,13,50,false));
    input_button->setFlat(true);
    input_button->setPalette(button_text_palette);
    main_label->setText("Music");
    main_label->setFont(QFont(SIMPLE_FONT,16,50,false));

    music_label_layout->addWidget(music_label);
    music_label_layout->addWidget(input_button);
    music_label_layout->addWidget(message_label);

    connect(input_button,SIGNAL(clicked()),this,SLOT(input_music()));

    main_layout->addWidget(main_label,0,Qt::AlignTop|Qt::AlignHCenter);
    main_layout->addSpacing(20);
    main_layout->addLayout(music_label_layout);
//    main_layout->addStretch();
    main_layout->addSpacing(10);
//    main_layout->addLayout(music_list_layout);
    main_layout->addWidget(scroll_area);
//    main_layout->addWidget(playlistView);
    main_layout->addStretch();
    main_layout->addWidget(bottom_music_show);
    main_layout->addSpacing(20);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0,0,0,0);
//    scroll_area->show();
    setLayout(main_layout);
}

Phone_Music::~Phone_Music()
{

}


void Phone_Music::init_music_list()
{

    qDebug() << "this is two";
    QStringList song_name_list;
    QStringList btnlist_info;
    qint64 size = 0;
    song_number = 0;
    QString path;
    path = LOCAL_MUSIC_DIR;

    QDir dir(path);
    if(dir.exists()){
        foreach(QFileInfo fileInfo,dir.entryInfoList(QDir::Files)){
            if(fileInfo.isFile()){
                if(addToPlaylist(fileInfo)){
                    song_number++;
                    size = fileInfo.size();
                    char unit = 'B';
                     if(size >= 1024)
                     {
                         size /= 1024;
                         if(size < 1024)
                             unit = 'K';
                         else {
                             size /= 1024;
                             unit = 'M';
                         }
                     }
                    song_name_list.append(fileInfo.fileName());
                    music_fileInfo_list.append(fileInfo);
                    if(fileInfo.fileName().length()>10){
                        btnlist_info.append(QString::number(song_number,10)+".  "+fileInfo.fileName().mid(0,10)+".."+"    "+QString::number(size,10)+unit);
                    }
                    else
                    {
                        btnlist_info.append(QString::number(song_number,10)+".  "+fileInfo.fileName()+"    "+QString::number(size,10)+unit);
                    }
                        qDebug() << fileInfo.fileName();
                }
            }
         }
    }

    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(0,100,0));

//    music_list_layout->addWidget(music_label,0,Qt::AlignHCenter);
    QSignalMapper *signal_mapper = new QSignalMapper(this);
    QSignalMapper *signal_mapper_del = new QSignalMapper(this);
    QSignalMapper *signal_mapper_out = new QSignalMapper(this);
//    QWidgetList *list = new QWidgetList();
//    QSizeGrip *gr=new QSizeGrip(list);//用来重设widget的size


    for(int i=0; i<song_name_list.size(); i++)
    {

        QPushButton *button = new QPushButton(btnlist_info.at(i));
        QPushButton *del_btn = new QPushButton();
        QPushButton *output_btn = new QPushButton();
        QHBoxLayout *list_layout = new QHBoxLayout();
        del_btn->setIcon(QIcon(":/picture/player/delete4"));
        del_btn->setFlat(true);
        del_btn->setIconSize(QSize(16,16));
        del_btn->setToolTip("Delete this song");
        output_btn->setIcon(QIcon(":/picture/player/out3"));
        output_btn->setFlat(true);
        output_btn->setIconSize(QSize(16,16));
        output_btn->setToolTip("Output the song into phone");
        button->setFlat(true);
        button->setPalette(button_text_palette);
        button->setFont(QFont(URW_P_FONT,10,QFont::Bold,true));
        button->setToolTip(song_name_list.at(i));
        btnlist.append(button);
        btnlist_del.append(del_btn);
        btnlist_out.append(output_btn);

        list_layout->addWidget(button);
        list_layout->addWidget(output_btn);
        list_layout->addWidget(del_btn);

//        widget->setLayout(list_layout);
        qDebug()<<song_name_list.at(i);

        connect(del_btn, SIGNAL(clicked()), signal_mapper_del, SLOT(map()));
        connect(output_btn, SIGNAL(clicked()), signal_mapper_out, SLOT(map()));
        connect(button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(button, QString::number(i, 10));
        signal_mapper_del->setMapping(del_btn, QString::number(i, 10));
        signal_mapper_out->setMapping(output_btn, QString::number(i, 10));

        music_list_layout->addLayout(list_layout);

    }

//    scroll_area->setLayout(music_list_layout);
//    scroll_area->setWidget(music_list_widget);
//    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(playMusic(QString)));
    connect(signal_mapper_del, SIGNAL(mapped(QString)), this, SLOT(delete_song(QString)));
    connect(signal_mapper_out, SIGNAL(mapped(QString)), this, SLOT(output_song(QString)));

}

void Phone_Music::init_bottom_widget()
{

    qDebug()<<"this is 3";

    bottom_label->setText("Play Music");
    bottom_label->setFont(QFont(URW_P_FONT,12,QFont::Bold,false));
    pre_song->setIcon(QIcon(":/picture/player/pre"));
    next_song->setIcon(QIcon(":/picture/player/next"));
    play_and_pause->setIcon(QIcon(":/picture/player/play"));
    play_mode_one->setIcon(QIcon(":/picture/player/mode_one"));
    play_mode_two->setIcon(QIcon(":/picture/player/mode_two"));
    play_mode_three->setIcon(QIcon(":/picture/player/mode_three"));
    play_mode_one->setFlat(true);
    play_mode_two->setFlat(true);
    play_mode_three->setFlat(true);
    pre_song->setFlat(true);
    next_song->setFlat(true);
    play_and_pause->setFlat(true);

    muted_button->setFlat(true);
    music_volumes_slider->setRange(0, 100);


    playlist->setPlaybackMode(QMediaPlaylist::Sequential);
    play_mode_one->setIconSize(QSize(24,24));

    if(is_muted){
        muted_button->setIcon(QIcon(":/picture/player/volume_muted"));
    }
    else{
        if(volume() == 0)
            muted_button->setIcon(QIcon(":/picture/player/volume_empty"));
        else if(volume()<=25){
               muted_button->setIcon(QIcon(":/picture/player/volume_low"));
        }
        else if(volume()<=75){
            muted_button->setIcon(QIcon(":/picture/player/volume_medium"));
        }
        else {
            muted_button->setIcon(QIcon(":/picture/player/volume_high"));
        }
    }

    connect(play_and_pause, SIGNAL(clicked()), this, SLOT(play_and_pause_clicked()));
    connect(next_song, SIGNAL(clicked()), this, SLOT(next_song_clicked()));
    connect(pre_song, SIGNAL(clicked()), this,SLOT(previousClicked()));
    connect(music_volumes_slider, SIGNAL(sliderMoved(int)), player, SLOT(setVolume(int)));
    connect(muted_button, SIGNAL(clicked()), this, SLOT(muteClicked()));
    connect(play_mode_one,SIGNAL(clicked()),this,SLOT(change_to_play_mode_one()));
    connect(play_mode_two,SIGNAL(clicked()),this,SLOT(change_to_play_mode_two()));
    connect(play_mode_three,SIGNAL(clicked()),this,SLOT(change_to_play_mode_three()));


    duration_layout->addWidget(duration_played);
    duration_layout->addWidget(slider);
    duration_layout->addWidget(labelDuration);
    play_control_layout->addWidget(pre_song);
    play_control_layout->addWidget(play_and_pause);
    play_control_layout->addWidget(next_song);
    play_mode_layout->addWidget(muted_button);
    play_mode_layout->addWidget(music_volumes_slider);
    play_mode_layout->addWidget(play_mode_three);
    play_mode_layout->addWidget(play_mode_one);
    play_mode_layout->addWidget(play_mode_two);
    bottom_layout->addWidget(bottom_label,0,Qt::AlignHCenter);
    bottom_layout->addLayout(play_control_layout);
    bottom_layout->addLayout(duration_layout);
    bottom_layout->addLayout(play_mode_layout);
    bottom_music_show->setLayout(bottom_layout);

}



void Phone_Music::delete_song(QString index)
{
    bool ok;
    qDebug() << "this is delete_song index is "+index;

    int current = index.toInt(&ok,10);
    qDebug()<< music_fileInfo_list.at(current).absoluteFilePath();
    QFile file(music_fileInfo_list.at(current).absoluteFilePath());
    file.remove();
        file.close();
    update_music_list();


}


void Phone_Music::input_music()
{

//    in = new QProcess();//new a process to exec the script
    message_label->setText("正在导入..");
    input_button->setDisabled(true);
    QString string = "adb pull /sdcard/media/音乐 ./local_music/";
    in->start(string);
    connect(in,SIGNAL(finished(int)),this,SLOT(in_pro_fin(int)));


}
void Phone_Music::in_pro_fin(int ec)
{
            int s = song_number;
    if(!ec){
        in->close();//关闭外部程序
//        delete in;
//        in = 0;

        update_music_list();
        message_label->setText("导入成功 导入"+QString::number(song_number-s,10)+"首歌");
        input_button->setDisabled(false);
    }
    else{
        in->close();//关闭外部程序
//        delete in;
//        in = 0;
          update_music_list();
        message_label->setText("导入终止 导入"+QString::number(song_number-s,10)+"首歌");
         input_button->setDisabled(false);
    }
}

void Phone_Music::output_song(QString index)
{
    bool ok;
    int current = index.toInt(&ok,10);
    QString file = music_fileInfo_list.at(current).absoluteFilePath();
    qDebug()<<file;
    message_label->setText("正在导出到手机..");
//    out = new QProcess();//new a process to exec the script
    QString string = "adb push "+file+" /sdcard/media/音乐";
    out->start(string);//run get_phone_info.sh
//    out->start("adb shell");


    connect(out,SIGNAL(finished(int)),this,SLOT(out_pro_fin(int)));

}


void Phone_Music::out_pro_fin(int ec)
{
    if(!ec){
                out->close();//关闭外部程序
//                delete out;
//                out = 0;
                message_label->setText("成功导出");
    }
    else{
        out->close();//关闭外部程序
//        delete out;
//                out = 0;
//                update_music_list();
        message_label->setText("导出失败");
    }
}

void Phone_Music::update_music_list()
{


    qDebug() << "update music list";
    QStringList song_name_list;
    QStringList btnlist_info;
    qint64 size = 0;
    song_number = 0;
    QString path;
    path = LOCAL_MUSIC_DIR;
    playlist->clear();
    music_fileInfo_list.clear();
    btnlist.clear();
    btnlist_del.clear();
    btnlist_out.clear();
    clearLayout(music_list_layout);
//    music_label = new QLabel();
//    music_label->setText("Local Music");
//    music_label->setFont(QFont(SIMPLE_FONT,10,QFont::Bold,false));

    QDir dir(path);
    if(dir.exists()){
        foreach(QFileInfo fileInfo,dir.entryInfoList(QDir::Files)){
            if(fileInfo.isFile()){
                if(addToPlaylist(fileInfo)){
                    song_number++;
                    size = fileInfo.size();
                    char unit = 'B';
                     if(size >= 1024)
                     {
                         size /= 1024;
                         if(size < 1024)
                             unit = 'K';
                         else {
                             size /= 1024;
                             unit = 'M';
                         }
                     }
                    song_name_list.append(fileInfo.fileName());
                    music_fileInfo_list.append(fileInfo);
                    if(fileInfo.fileName().length()>10){
                        btnlist_info.append(QString::number(song_number,10)+".  "+fileInfo.fileName().mid(0,10)+".."+"    "+QString::number(size,10)+unit);
                    }
                    else
                    {
                        btnlist_info.append(QString::number(song_number,10)+".  "+fileInfo.fileName()+"    "+QString::number(size,10)+unit);
                    }
                        qDebug() << fileInfo.fileName();
                }
            }
         }
    }

    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(0,100,0));
    qDebug()<<"music_label: "+music_label->text();
//    music_list_layout->addWidget(music_label,0,Qt::AlignHCenter);
    QSignalMapper *signal_mapper = new QSignalMapper(this);
    QSignalMapper *signal_mapper_del = new QSignalMapper(this);
    QSignalMapper *signal_mapper_out = new QSignalMapper(this);
    for(int i=0; i<song_name_list.size(); i++)
    {

        QPushButton *button = new QPushButton(btnlist_info.at(i));
        QPushButton *del_btn = new QPushButton();
        QPushButton *output_btn = new QPushButton();
        QHBoxLayout *list_layout = new QHBoxLayout();
        del_btn->setIcon(QIcon(":/picture/player/delete4"));
        del_btn->setFlat(true);
        del_btn->setIconSize(QSize(16,16));
        del_btn->setToolTip("Delete this song");
        output_btn->setIcon(QIcon(":/picture/player/out3"));
        output_btn->setFlat(true);
        output_btn->setIconSize(QSize(16,16));
        output_btn->setToolTip("Output the song into phone");
        button->setFlat(true);
        button->setPalette(button_text_palette);
        button->setFont(QFont(URW_P_FONT,10,QFont::Bold,true));
        button->setToolTip(song_name_list.at(i));
        btnlist.append(button);
        btnlist_del.append(del_btn);
        btnlist_out.append(output_btn);

        list_layout->addWidget(button);
        list_layout->addWidget(output_btn);
        list_layout->addWidget(del_btn);


        qDebug()<<song_name_list.at(i);

        connect(del_btn, SIGNAL(clicked()), signal_mapper_del, SLOT(map()));
        connect(output_btn, SIGNAL(clicked()), signal_mapper_out, SLOT(map()));
        connect(button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(button, QString::number(i, 10));
        signal_mapper_del->setMapping(del_btn, QString::number(i, 10));
        signal_mapper_out->setMapping(output_btn, QString::number(i, 10));

        music_list_layout->addLayout(list_layout);

    }
//    scroll_area->setLayout(music_list_layout);
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(playMusic(QString)));
    connect(signal_mapper_del, SIGNAL(mapped(QString)), this, SLOT(delete_song(QString)));
    connect(signal_mapper_out, SIGNAL(mapped(QString)), this, SLOT(output_song(QString)));

    emit update_song_number(song_number);
}


//void Phone_Music::turn_next_page()
//{
//    update_music_list(current_song);

//}

void Phone_Music::clearLayout(QLayout* layout)
{
    qDebug() << "clear layout";
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (QWidget* widget = item->widget())
                delete widget;

        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout);
        delete item;
    }
}

void Phone_Music::playMusic(QString current)
{

//    if (index.isValid()) {
    bool ok;
    int current_index = current.toInt(&ok, 10);
        playlist->setCurrentIndex(current_index);
        player->play();
//    }

}


QMediaPlayer::State Phone_Music::state() const
{
    return playerState;
}

bool Phone_Music::addToPlaylist(QFileInfo fileInfo)
{
            QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            if (fileInfo.suffix().toLower() == QLatin1String("m3u")) {
                return false;
            } else{
                playlist->addMedia(url);
            return true;
        }


}

void Phone_Music::durationChanged(qint64 duration)
{
    this->duration = duration/1000;
    slider->setMaximum(duration / 1000);
}

void Phone_Music::positionChanged(qint64 progress)
{
    if (!slider->isSliderDown()) {
        slider->setValue(progress / 1000);
    }
    updateDurationInfo(progress / 1000);
}

void Phone_Music::metaDataChanged()
{
    if (player->isMetaDataAvailable()) {
        setTrackInfo(QString("%1 - %2")
                .arg(player->metaData(QMediaMetaData::AlbumArtist).toString())
                .arg(player->metaData(QMediaMetaData::Title).toString()));

        }

}



void Phone_Music::play_and_pause_clicked()
{
    switch (player->state()) {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        emit play();play_and_pause->setIcon(QIcon(":/picture/player/pause"));
        break;
    case QMediaPlayer::PlayingState:
        emit pause();play_and_pause->setIcon(QIcon(":/picture/player/play"));
        break;
    }
}

void Phone_Music::pause_the_music_play()
{
    emit pause();play_and_pause->setIcon(QIcon(":/picture/player/play"));
}

int Phone_Music::volume() const
{
    return music_volumes_slider ? music_volumes_slider->value() : 0;
}

void Phone_Music::setVolume(int volume)
{
    if (music_volumes_slider)
        music_volumes_slider->setValue(volume);
    if(is_muted){
        muted_button->setIcon(QIcon(":/picture/player/volume_muted"));
    }
    else{
        if(volume == 0)
            muted_button->setIcon(QIcon(":/picture/player/volume_empty"));
        else if(volume<=25){
               muted_button->setIcon(QIcon(":/picture/player/volume_low"));
        }
        else if(volume<=75){
            muted_button->setIcon(QIcon(":/picture/player/volume_medium"));
        }
        else {
            muted_button->setIcon(QIcon(":/picture/player/volume_high"));
        }
    }
}

bool Phone_Music::isMuted() const
{
    return is_muted;
}

void Phone_Music::muteClicked()
{
    emit changeMuting(!is_muted);
}

void Phone_Music::previousClicked()
{
    // Go to previous track if we are within the first 5 seconds of playback
    // Otherwise, seek to the beginning.
    if(player->position() <= 5000)
        if(playlist->currentIndex()>0)
            playlist->previous();
        else{
            playlist->setCurrentIndex(2);
        }
    else
        player->setPosition(0);
}

void Phone_Music::next_song_clicked()
{
    if(playlist->currentIndex()<song_number-1){
        playlist->next();
    }
    else{
        playlist->setCurrentIndex(0);
        player->play();
    }
}

void Phone_Music::jump(const QModelIndex &index)
{
    if (index.isValid()) {
        playlist->setCurrentIndex(index.row());
        player->play();
    }
}

void Phone_Music::playlistPositionChanged(int currentItem)
{
    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(0,0,0));
    QPalette button_text_palette_pre = palette();
    button_text_palette_pre.setColor(QPalette::ButtonText, QColor(0,100,0));
    if(is_played){
        btnlist.at(pre_song_index)->setPalette(button_text_palette_pre);
    }
    playlistView->setCurrentIndex(playlistModel->index(currentItem, 0));
    btnlist.at(currentItem)->setPalette(button_text_palette);
    pre_song_index = currentItem;
    is_played = true;
}

void Phone_Music::seek(int seconds)
{
    player->setPosition(seconds * 1000);
}

void Phone_Music::setMuted(bool muted)
{
    if (muted != is_muted) {
        is_muted = muted;

        if(is_muted){
            muted_button->setIcon(QIcon(":/picture/player/volume_muted"));
        }
        else{
            if(volume() == 0)
                muted_button->setIcon(QIcon(":/picture/player/volume_empty"));
            else if(volume()<=25){
                   muted_button->setIcon(QIcon(":/picture/player/volume_low"));
            }
            else if(volume()<=75){
                muted_button->setIcon(QIcon(":/picture/player/volume_medium"));
            }
            else {
                muted_button->setIcon(QIcon(":/picture/player/volume_high"));
            }


        }
    }
}

void Phone_Music::change_to_play_mode_one()
{
    playlist->setPlaybackMode(QMediaPlaylist::Sequential);
    play_mode_two->setIconSize(QSize(16,16));
    play_mode_one->setIconSize(QSize(24,24));
    play_mode_three->setIconSize(QSize(16,16));

}

void Phone_Music::change_to_play_mode_two()
{

    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    play_mode_two->setIconSize(QSize(24,24));
    play_mode_one->setIconSize(QSize(16,16));
    play_mode_three->setIconSize(QSize(16,16));
}

void Phone_Music::change_to_play_mode_three()
{

    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    play_mode_two->setIconSize(QSize(16,16));
    play_mode_one->setIconSize(QSize(16,16));
    play_mode_three->setIconSize(QSize(24,24));
}

void Phone_Music::statusChanged(QMediaPlayer::MediaStatus status)
{
    handleCursor(status);

    // handle status message
    switch (status) {
    case QMediaPlayer::UnknownMediaStatus:
    case QMediaPlayer::NoMedia:
    case QMediaPlayer::LoadedMedia:
    case QMediaPlayer::BufferingMedia:
    case QMediaPlayer::BufferedMedia:
        setStatusInfo(QString());
        break;
    case QMediaPlayer::LoadingMedia:
        setStatusInfo(tr("Loading..."));
        break;
    case QMediaPlayer::StalledMedia:
        setStatusInfo(tr("Media Stalled"));
        break;
    case QMediaPlayer::EndOfMedia:
        break;
    case QMediaPlayer::InvalidMedia:
        displayErrorMessage();
        break;
    }
}

void Phone_Music::handleCursor(QMediaPlayer::MediaStatus status)
{
#ifndef QT_NO_CURSOR
    if (status == QMediaPlayer::LoadingMedia ||
        status == QMediaPlayer::BufferingMedia ||
        status == QMediaPlayer::StalledMedia)
        setCursor(QCursor(Qt::BusyCursor));
    else
        unsetCursor();
#endif
}

void Phone_Music::bufferingProgress(int progress)
{
    setStatusInfo(tr("Buffering %4%").arg(progress));
}


void Phone_Music::setTrackInfo(const QString &info)
{
    trackInfo = info;
    if (!statusInfo.isEmpty())
        bottom_label->setText(QString("%1 | %2").arg(trackInfo).arg(statusInfo));
    else
        bottom_label->setText(trackInfo);
}

void Phone_Music::setStatusInfo(const QString &info)
{
    statusInfo = info;
    if (!statusInfo.isEmpty())
        bottom_label->setText(QString("%1 | %2").arg(trackInfo).arg(statusInfo));
    else
        bottom_label->setText(trackInfo);
}

void Phone_Music::displayErrorMessage()
{
    setStatusInfo(player->errorString());
}

void Phone_Music::updateDurationInfo(qint64 currentInfo)
{
    QString tStr1,tStr2;
    if (currentInfo || duration) {
        QTime currentTime((currentInfo/3600)%60, (currentInfo/60)%60, currentInfo%60, (currentInfo*1000)%1000);
        QTime totalTime((duration/3600)%60, (duration/60)%60, duration%60, (duration*1000)%1000);
        QString format = "mm:ss";
        if (duration > 3600)
            format = "hh:mm:ss";
        tStr1 = currentTime.toString(format);
        tStr2 = totalTime.toString(format);
    }
    duration_played->setText(tStr1);
    labelDuration->setText(tStr2);
}

void Phone_Music::setState(QMediaPlayer::State state)
{
    if (state != playerState) {
        playerState = state;

        switch (state) {
        case QMediaPlayer::StoppedState:
        play_and_pause->setIcon(QIcon(":/picture/player/play"));
            break;
        case QMediaPlayer::PlayingState:
          play_and_pause->setIcon(QIcon(":/picture/player/pause"));
            break;
        case QMediaPlayer::PausedState:
            play_and_pause->setIcon(QIcon(":/picture/player/play"));
            break;
        }
    }
}


