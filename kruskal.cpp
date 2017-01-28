#include "kruskal.h"

//default constructor
Kruskal::Kruskal(graphics_graph *graph, QWidget *mes, vector<QTimer*> timers) : algorithm(graph, mes, timers)
{
    m_edges=vector<logical_edge>(m);
    for (int i = 0; i < m; ++i)
        m_edges[i]=logical_edge(for_edges[i].first.first, for_edges[i].first.second, for_edges[i].second);
    stable_sort(m_edges.begin(), m_edges.end(), logical_edge::compare());
}

//creates forest(disjoint sets)
void Kruskal::step1()
{
    int i;
    m_sets_union = DSU(n);
    for (i = 0; i < n; ++i)
        m_sets_union.make_set(i);
    m_counter = 0;
    m_it = m_edges.rbegin();
    for (i = 0; i < n; ++i)
    {
        m_graphic_graph->m_vertices[i]->set_color(_GREEN);
        m_graphic_graph->m_MST_vertices[i]=new graphics_vertex(QPointF((m_graphic_graph->m_scene_width * for_MST_vertices[i].first)
                                                      /percent,
                                                      (m_graphic_graph->m_scene_height * for_MST_vertices[i].second)
                                                      /percent),
                                                      (m_graphic_graph->m_scene_width * for_radius) / percent, (int)i, _GREEN);
        m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_vertices[i]);
    }
    m_graphic_graph->m_parent_scene->update();
    m_timers[0]->stop();
    m_timers[1]->start(5000);
}

//consider edge:source and destination vertices
void Kruskal::step2()
{
    if (m_sets_union.get_sets_num() == 1)
    {
        m_timers[1]->stop();
        m_message->show();
    }
    else
    {
        logical_edge e = *m_it;
        m_graphic_graph->m_edges[m_graphic_graph->logical_to_graphics(e)]->set_color(_YELLOW);
        m_timers[1]->stop();
        m_timers[2]->start(5000);
    }
    m_graphic_graph->m_parent_scene->update();
}

//unites disjoint sets:vertices through connecting edg
void Kruskal::step3()
{
    int from,to;
    logical_edge e = *m_it;
    ++m_it;
    from = e.get_from();
    to = e.get_to();
    if (m_sets_union.union_sets(from, to))
    {
        m_graphic_graph->m_MST_edges[m_counter]=new graphics_edge(*m_graphic_graph->m_MST_vertices[from],
                                                                  *m_graphic_graph->m_MST_vertices[to], false);
        m_graphic_graph->m_MST_edges[m_counter]->set_color(_GREEN);
        m_graphic_graph->m_edges[m_graphic_graph->logical_to_graphics(e)]->set_color(_GREEN);
        m_graphic_graph->m_parent_scene->removeItem(m_graphic_graph->m_MST_vertices[from]);
        m_graphic_graph->m_parent_scene->removeItem(m_graphic_graph->m_MST_vertices[to]);
        m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_edges[m_counter]);
        m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_vertices[from]);
        m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_vertices[to]);
        ++m_counter;
    }
    else m_graphic_graph->m_edges[m_graphic_graph->logical_to_graphics(e)]->set_color(_BLACK);
    m_timers[2]->stop();
    m_timers[1]->start(5000);
    m_graphic_graph->m_parent_scene->update();
}

