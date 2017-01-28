#include "dsu.h"

DSU::DSU(int n)
{
    m_union_range_size = n;
    m_union_size = 0;
    m_sets_num = 0;
    m_parent = vector<int>(m_union_range_size, -1);
    m_size = vector<int>(m_union_range_size);
    m_rank = vector<int>(m_union_range_size);
}

DSU::DSU(const DSU &U)
{
    m_parent = U.m_parent;
    m_size = U.m_size;
    m_rank = U.m_rank;
    m_union_size = U.m_union_size;
    m_sets_num = U.m_sets_num;
    m_union_range_size = U.m_union_range_size;
}

DSU& DSU::operator =(const DSU &U)
{
    m_parent = U.m_parent;
    m_size = U.m_size;
    m_rank = U.m_rank;
    m_union_size = U.m_union_size;
    m_sets_num = U.m_sets_num;
    m_union_range_size = U.m_union_range_size;
    return *this;
}

//creates single disjoint set with single element
void DSU::make_set(const int x)
{
    if (x < 0 || x >= m_union_range_size)
        throw _out_of_range();
    m_parent[x] = x;
    m_size[x] = 1;
    ++m_union_size;
    ++m_sets_num;
}

//finds element's set
int DSU::find_set(const int x)
{
    if (x < 0 || x >= m_union_range_size)
        throw _out_of_range();
    if (m_parent[x] == -1)
        throw item_is_absent();
    if (m_parent[x] == x)
        return x;
    return m_parent[x] = find_set(m_parent[x]);
}

//unites two disjoint sets
bool DSU::union_sets(int a,int b)
{
    try
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (m_rank[a] < m_rank[b])
                swap(a, b);
            m_parent[b] = a;
            m_size[a] += m_size[b];
            if (m_rank[a] == m_rank[b])
                ++m_rank[a];
            --m_sets_num;
            return true;
        }
        return false;
    }
    catch (exception &e)
    {
        cout << e.what() <<endl;
        abort();
    }
}

//returns set depth
int DSU::get_set_rank(const int x)
{
    try
    {
        return m_rank[find_set(x)];
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        abort();
    }
}

//returns set size
int DSU::get_set_size(const int x)
{
    try
    {
        return m_size[find_set(x)];
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        abort();
    }
}

int DSU::get_union_size()const
{
    return m_union_size;
}

//returns num of sets
int DSU::get_sets_num()const
{
    return m_sets_num;
}

int DSU::get_union_range_size()const
{
    return m_union_range_size;
}

