#ifndef GRAPHICS_GRAPH_H
#define GRAPHICS_GRAPH_H


#include <QGraphicsScene>
#include "graphics_edge.h"
#include "logical_edge.h"

class MainWindow;
class Prim;
class Kruskal;

/*collection of graphic graph items
  (edges and vertices)*/

class graphics_graph
{
    friend class Prim;
    friend class Kruskal;
    public:
        graphics_graph(QGraphicsScene* = 0, qreal = 0, qreal = 0, qreal = 0, qreal = 0);
        virtual ~graphics_graph();
        void restore();
        int logical_to_graphics(logical_edge);
    private:
        int m_scene_width;                          //2-D parent scene width
        int m_scene_height;                         //...             height
        QGraphicsScene *m_parent_scene;
        vector<graphics_vertex*> m_vertices;        //vertices of graph
        vector<graphics_edge*> m_edges;             //edges of graph
        vector<graphics_vertex*> m_MST_vertices;    //vertices of MST
        vector<graphics_edge*> m_MST_edges;         //edges of MST
};

#endif // GRAPHICS_GRAPH_H
