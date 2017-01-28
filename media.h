#ifndef MEDIA_H
#define MEDIA_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSlider>
#include <QPushButton>
#include <QWidget>
#include "const.h"

//implements music attributes
class Media : public QWidget
{
    Q_OBJECT
    public:
        explicit Media(QWidget* = 0, QString = NULL, qreal = 0, qreal = 0);
        ~Media();
    private:
        QMediaPlayer *m_player;
        QPushButton *m_sound_button;
        QSlider *m_volume_controller;
        QTimer *m_timer;
    private slots:
        void media_slot();
};

#endif // MEDIA_H
