#include "graphics_graph.h"

//default constructor
graphics_graph::graphics_graph(QGraphicsScene *scene, qreal width, qreal height, qreal scene_width, qreal scene_height)
{
    size_t i;
    m_scene_width = scene_width;
    m_scene_height = scene_height;
    m_parent_scene = scene;
    m_vertices = vector<graphics_vertex*>(n);
    m_edges = vector<graphics_edge*>(m);
    for (i = 0;i < n; ++i)
         m_vertices[i]=new graphics_vertex(QPointF((m_scene_width * for_vertices[i].first) / percent,
                                                   (m_scene_height * for_vertices[i].second) / percent),
                                                   (m_scene_width * for_radius) / percent, (int)i);
    for (i = 0; i < m; ++i)
    {
        m_edges[i]=new graphics_edge(*m_vertices[for_edges[i].first.first],
                                     *m_vertices[for_edges[i].first.second], true, for_edges[i].second,
                             QPointF(width * (for_edges_weights[i].first)  /percent,
                                    (height * for_edges_weights[i].second) / percent));
        m_parent_scene->addItem(m_edges[i]);
    }
    for (i = 0;i < n; ++i)
        m_parent_scene->addItem(m_vertices[i]);

    m_MST_vertices=vector<graphics_vertex*>(n);
    m_MST_edges=vector<graphics_edge*>(n - 1);
}

//destructor
graphics_graph::~graphics_graph()
{
    int i;
    delete m_parent_scene;
    for (i = 0; i < m; ++i)
    {
        if (i < n)
        {
            delete m_vertices[i];
            delete m_MST_vertices[i];
            if (i < n-1)
                delete m_MST_edges[i];
        }
        delete m_edges[i];
    }
}

//restores graph and MST on the scene
void graphics_graph::restore()
{
    for (int i = 0; i < m; ++i)
    {
        if (i < n)
        {
            this->m_vertices[i]->set_color(_BLACK);
            if (this->m_MST_vertices[i]!=NULL && this->m_MST_vertices[i]->isActive())
                m_parent_scene->removeItem(this->m_MST_vertices[i]);
            if (i < n - 1 && this->m_MST_edges[i] != NULL && this->m_MST_edges[i]->isActive())
                m_parent_scene->removeItem(this->m_MST_edges[i]);
        }
        this->m_edges[i]->set_color(_BLACK);
    }
    m_parent_scene->update();
}

//maps logical edges into graphic
int graphics_graph::logical_to_graphics(logical_edge e)
{
    int f=e.get_from(),t=e.get_to(),answer = -1;
    if ((f == 0 && t == 6) || (f == 6 && t == 0))
        answer = 0;
    else if ((f == 0 && t == 1) || (f == 1 && t == 0))
        answer = 1;
    else if ((f == 0 && t == 2) || (f == 2 && t == 0))
        answer = 2;
    else if ((f == 0 && t == 5) || (f == 5 && t == 0))
        answer = 3;
    else if ((f == 0 && t == 7) || (f == 7 && t == 0))
        answer = 4;
    else if ((f == 1 && t == 7) || (f == 7 && t == 1))
        answer = 5;
    else if ((f == 3 && t == 4) || (f == 4 && t == 3))
        answer = 6;
    else if ((f == 3 && t == 5) || (f == 5 && t == 3))
        answer = 7;
    else if ((f == 4 && t == 7) || (f == 7 && t == 4))
        answer = 8;
    else if ((f == 4 && t == 5) || (f == 5 && t == 4))
        answer = 9;
    else if ((f == 4 && t == 6) || (f == 6 && t == 4))
        answer = 10;
    else if ((f == 6 && t == 7) || (f == 7 && t == 6))
        answer = 11;
    return answer;
}

