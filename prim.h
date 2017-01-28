#ifndef PRIM_H
#define PRIM_H

#include "algorithm.h"
#include <queue>
#include <deque>

/*demonstrates Prim's algorithm
  on the scene.
  Inherited from abstract algorithm class*/

class Prim : public algorithm
{
    public:
        Prim(graphics_graph*, QWidget*, vector<QTimer*>);
        void restore();
        void step1();
        void step2();
        void step3();
    private:
        vector<vector<pair<int,int>>> m_graph;                                              //adjacent list
        priority_queue<logical_edge, deque<logical_edge>, logical_edge::compare> m_fringe; //fringe for priority search
        int m_current_vertex;
        void adj_list_maker();
};

#endif // PRIM_H
