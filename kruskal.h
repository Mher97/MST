#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "algorithm.h"
#include "dsu.h"

class Kruskal : public algorithm
{
    public:
        Kruskal(graphics_graph*, QWidget*, vector<QTimer*>);
        void step1();
        void step2();
        void step3();
    private:
        vector<logical_edge> m_edges;                   //list of edges
        vector<logical_edge>::reverse_iterator m_it;    //iterator on the list
        DSU m_sets_union;                               //DSU object
};

#endif // KRUSKAL_H
