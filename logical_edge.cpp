#include "logical_edge.h"

//default constructor
logical_edge::logical_edge(int f, int t, int  w)
{
    m_from = f;
    m_to = t;
    m_weight = w;
}

//copy constructor
logical_edge::logical_edge(const logical_edge & L)
{
    m_from = L.m_from;
    m_to = L.m_to;
    m_weight = L.m_weight;
}

bool logical_edge::operator<(logical_edge &e) const
{
    return m_weight < e.m_weight;
}

int logical_edge::get_from() const
{
    return m_from;
}

int logical_edge::get_to() const
{
    return m_to;
}
