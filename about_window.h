#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QDesktopServices>
#include "const.h"

/*There is writen about program on this widget*/

class about_window : public QWidget
{
    Q_OBJECT
    public:
        explicit about_window(QWidget* = 0,int = 0 ,int = 0 ,QString = NULL);
        ~about_window();
    private:
        QWidget *m_parent;                          //parent widget
        int m_width;                                //widget width
        int m_height;                               //..... height
        QString m_app_path;                         //image of widget path
        QPushButton *m_back;                        //button for back main window
        QPushButton *m_more;                        //button for showing more information about algorithms
        QImage *m_background;                       //background image
        QRect boundingRect(int, int, int, int);
        void buttons_maker();
    protected:
        void paintEvent(QPaintEvent *);
    private slots:
        void back_slot();
        void more_slot();
};

#endif // ABOUT_WINDOW_H
