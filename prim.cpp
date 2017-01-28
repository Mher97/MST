#include "prim.h"

//default constructor
Prim::Prim(graphics_graph *graph, QWidget *mes, vector<QTimer*> timers) : algorithm(graph, mes, timers)
{
    m_current_vertex = 0;
    adj_list_maker();
}

//makes graph's adjacent list
void Prim::adj_list_maker()
{
    m_graph=vector<vector<pair<int,int>>>(n);
    for (size_t i = 0;i < m; ++i)
    {
        m_graph[for_edges[i].first.first].push_back(make_pair(for_edges[i].first.second, for_edges[i].second));
        m_graph[for_edges[i].first.second].push_back(make_pair(for_edges[i].first.first, for_edges[i].second));
    }
}

//restores algorithm
void Prim::restore()
{
    m_current_vertex = m_counter = 0;
    while(!m_fringe.empty())
        m_fringe.pop();
}

//inserts edges into fringe
void Prim::step1()
{
    if (!m_counter)
    {
        m_graphic_graph->m_vertices[m_current_vertex]->set_color(_GREEN);
        m_graphic_graph->m_MST_vertices[m_current_vertex]=new graphics_vertex(QPointF((m_graphic_graph->m_scene_width * for_MST_vertices[m_current_vertex].first)
                                                                    /percent,
                                                                    (m_graphic_graph->m_scene_height * for_MST_vertices[m_current_vertex].second)
                                                                    /percent),
                                                                    (m_graphic_graph->m_scene_width * for_radius)/percent, m_current_vertex, _GREEN);
        m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_vertices[m_current_vertex]);
    }
    ++m_counter;
    if (m_counter == n)
    {
         m_timers[0]->stop();
         m_message->show();
    }
    else
    {
        if (m_counter > 1)
            step3();
        else m_timers[2]->start(5000);
        m_timers[0]->stop();
    }
    m_graphic_graph->m_parent_scene->update();
}

//pops edges from fringe
void Prim::step2()
{
    int from,to;
    while(!m_fringe.empty())
    {
          logical_edge e = m_fringe.top();
          m_fringe.pop();
          from = e.get_from();
          to = e.get_to();
          if (m_graphic_graph->m_vertices[to]->get_color() != _GREEN)
          {
              m_graphic_graph->m_MST_vertices[to] = new graphics_vertex(QPointF((m_graphic_graph->m_scene_width * for_MST_vertices[e.get_to()].first)
                                                                  /percent,
                                                                  (m_graphic_graph->m_scene_height * for_MST_vertices[e.get_to()].second)
                                                                  /percent),
                                                                  (m_graphic_graph->m_scene_width * for_radius)/percent, to, _GREEN);
              m_graphic_graph->m_vertices[to]->set_color(_GREEN);
              m_graphic_graph->m_edges[m_graphic_graph->logical_to_graphics(e)]->set_color(_GREEN);
              m_graphic_graph->m_MST_edges[m_counter-1] = new graphics_edge(*m_graphic_graph->m_MST_vertices[from],
                                                                          *m_graphic_graph->m_MST_vertices[to],false);
              m_graphic_graph->m_MST_edges[m_counter-1]->set_color(_GREEN);
              m_graphic_graph->m_parent_scene->removeItem(m_graphic_graph->m_MST_vertices[from]);
              m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_edges[m_counter - 1]);
              m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_vertices[from]);
              m_graphic_graph->m_parent_scene->addItem(m_graphic_graph->m_MST_vertices[to]);
              for (size_t i = 0; i < m_graph[to].size(); ++i)
              {
                  if (m_graphic_graph->m_vertices[m_graph[to][i].first]->get_color() == _GREEN)
                  {
                      logical_edge helper(to, m_graph[to][i].first, m_graph[to][i].second);
                      if (m_graphic_graph->m_edges[m_graphic_graph->logical_to_graphics(helper)]->get_color() != _GREEN)
                          m_graphic_graph->m_edges[m_graphic_graph->logical_to_graphics(helper)]->set_color(_BLACK);
                  }
              }
              m_current_vertex = to;
              break;
          }
    }
    m_timers[1]->stop();
    m_timers[0]->start(5000);
    m_graphic_graph->m_parent_scene->update();
}

//step1 helper
void Prim::step3()
{
    for (size_t i = 0; i < m_graph[m_current_vertex].size(); ++i)
    {
        if (m_graphic_graph->m_vertices[m_graph[m_current_vertex][i].first]->get_color() != _GREEN)
        {
            m_graphic_graph->m_vertices[m_graph[m_current_vertex][i].first]->set_color(_YELLOW);
            logical_edge e(m_current_vertex, m_graph[m_current_vertex][i].first, m_graph[m_current_vertex][i].second);
            m_fringe.push(e);
            m_graphic_graph->m_edges[m_graphic_graph->logical_to_graphics(e)]->set_color(_YELLOW);
        }
    }
    if (m_timers[2]->isActive())
    {
        m_graphic_graph->m_parent_scene->update();
        m_timers[2]->stop();
    }
    m_timers[1]->start(5000);
}
