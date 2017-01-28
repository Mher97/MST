#include "media.h"

Media::Media(QWidget *parent, QString path, qreal width, qreal height)
{
    QMediaPlaylist *list = new QMediaPlaylist(parent);
    list->addMedia(QUrl::fromLocalFile(path + for_paths[0] + for_paths[1]));
    m_player = new QMediaPlayer(parent);
    m_player->setPlaylist(list);
    m_player->setVolume(15);
    m_player->play();
    m_sound_button = new QPushButton(parent);
    m_sound_button->setGeometry((int)(width * for_sound[0].first / percent), (int)(height * for_sound[0].second / percent),
                                (int)(width * for_sound[1].first / percent), (int)(width * for_sound[1].second / percent));
    m_sound_button->setIcon(QIcon(path + for_paths[0] + for_paths[2]));
    m_sound_button->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    m_volume_controller = new QSlider(Qt::Vertical, parent);
    m_volume_controller->setGeometry((int)(width * for_sound[2].first / percent),(int)(height * for_sound[2].second / percent),
                    (int)(width * for_sound[3].first / percent), (int)(height * for_sound[3].second / percent));
    m_volume_controller->setValue(15);
    m_volume_controller->setRange(0, 100);
    m_volume_controller->hide();
    m_timer = new QTimer(this);
    connect(m_sound_button, SIGNAL(clicked()), this, SLOT(media_slot()));
    connect(m_volume_controller, SIGNAL(valueChanged(int)), m_player, SLOT(setVolume(int)));
    connect(m_timer, SIGNAL(timeout()), m_player, SLOT(play()));
    m_timer->start(150000);

}

Media::~Media()
{
    delete m_sound_button;
    delete m_volume_controller;
    delete m_player;
    delete m_timer;
}

void Media::media_slot()
{
    if (m_volume_controller->isHidden())
        m_volume_controller->show();
    else m_volume_controller->hide();
}

