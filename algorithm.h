#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QWidget>
#include <QTimer>
#include "graphics_graph.h"

/*MST algorithms base and abstract class*/

class algorithm
{
    public:
        algorithm(graphics_graph*, QWidget*, vector<QTimer*>);
        virtual ~algorithm();
        void run();
    protected:
        vector<QTimer*> m_timers;        //demonstration controll through timers
        graphics_graph *m_graphic_graph; //2-D graph and MST
        QWidget *m_message;              //message about work completing
        int m_counter;                   //used for algorithms
        virtual void step1() = 0;
        virtual void step2() = 0;
        virtual void step3() = 0;
};

#endif // ALGORITHM_H
