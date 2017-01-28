#ifndef LOGICAL_EDGE_H
#define LOGICAL_EDGE_H

/*implements graph edge
 * as mathematical objrct*/

class logical_edge
{
    public:
        logical_edge(int f = -1,int t = -1,int w = -1);
        logical_edge(const logical_edge&);
        int get_from()const;
        int get_to()const;
        bool operator < (logical_edge &e)const;
        //inner functional class for edges compare
        class compare
        {
            public:
                bool operator()(logical_edge a, logical_edge b)
                {
                    return b < a;
                }
        };
    private:
        int m_from;         //source vertex
        int m_to;           //destination vertex
        int m_weight;       //weight
};

#endif // LOGICAL_EDGE_H
