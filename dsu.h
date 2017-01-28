#ifndef DSU_H
#define DSU_H

#include <vector>
#include <iostream>
#include "dsu_exceptions.h"

/*implements Disjoint-Set-Union data structure
 * with path compression and union by rank*/

class DSU
{
    public:
        explicit DSU(int = 100);
        DSU(const DSU&);
        DSU& operator = (const DSU&);
        void make_set(const int);
        bool union_sets(int, int);
        int find_set(const int);
        int get_set_rank(const int);
        int get_set_size(const int);
        int get_union_size()const;
        int get_sets_num()const;
        int get_union_range_size()const;

    private:
        vector<int> m_parent;           //parents array
        vector<int> m_size;             //size of set
        vector<int> m_rank;             //rank of set
        int m_union_size;
        int m_sets_num;                 //num of sets
        int m_union_range_size;
};

#endif // DSU_H
