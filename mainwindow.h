#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QLabel>
#include "graphics_edge.h"
#include "graphics_text.h"
#include "about_window.h"
#include "media.h"
#include "prim.h"
#include "kruskal.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget* = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        qreal m_width;
        qreal m_height;
        qreal m_scene_width;
        qreal m_scene_height;
        QGraphicsView *m_view;
        QGraphicsScene *m_scene;
        pair<graphics_text*, graphics_text*> m_texts;
        graphics_graph *m_graphic_graph;                //2-D vertices and edges of graph and MST
        vector<QPushButton*> m_buttons;                 //for controll
        QWidget *m_message;                             //message about completed work
        about_window *m_about;                          //widget about program
        Media *m_media;                                 //media attributes
        pair<QPushButton*, pair<int, bool> > m_pause;   //variable for pause and restart demonstration
        QString m_app_path;                             //sources path
        int m_state;                                    //program state
        Prim *m_prim;                                   //Prim's algorithm
        vector<QTimer*> m_prim_timers;                  //timers for demonstrating Prim's algo..
        Kruskal *m_kruskal;                             //Kruskal's algorithm
        vector<QTimer*> m_kruskal_timers;               //.........................Kruskal's .

        void scene_maker();
        void buttons_maker();
        void about_window_maker();
        void message_maker();

    protected:
        void paintEvent(QPaintEvent*);

    private slots:
        void message_hide();
        void pause_restart_slot();
        void new_slot();
        void about_slot();
        void Prim_starting_slot();
        void Kruskal_starting_slot();
        void Prim_considering();
        void Prim_considering_helper();
        void Prim_appending();
        void Kruskal_forest_creator();
        void Kruskal_edge_considering();
        void Kruskal_DSU();                 //disjoint set union
};

#endif // MAINWINDOW_H
