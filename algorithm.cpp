#include "algorithm.h"

//default constructor
algorithm::algorithm(graphics_graph *graph, QWidget *mes, vector<QTimer*> timers)
{
    m_graphic_graph = graph;
    m_message = mes;
    m_timers = timers;
    m_counter = 0;
}

//destructor
algorithm::~algorithm()
{
    m_counter = 0;
    delete m_graphic_graph;
    delete m_message;
    for (size_t i = 0; i < m_timers.size(); ++i)
        delete m_timers[i];
}

//starts algorithm demonstration
void algorithm::run()
{
    m_timers[0]->start(5000);
}


