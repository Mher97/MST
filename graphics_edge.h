#ifndef GRAPHICS_EDGE_H
#define GRAPHICS_EDGE_H

#include "graphics_vertex.h"

/*Represents graph edge as
 * a 2-D graphic object
 * through line*/

class graphics_edge : public QGraphicsItem
{
    public:
        graphics_edge(graphics_vertex&, graphics_vertex&, bool = true, int = 0, QPointF=QPointF(real_zero, real_zero), int = _BLACK);
        void set_color(int);
        int get_color()const;
    private:
        QPointF m_from;             //center of source 2-D vertex
        QPointF m_to;               //destination of destination vertex
        bool m_membership;          //graph edge or MST edge
        int m_weight;               //weight
        QPointF m_for_weight_text;  //weight text location
        int m_color;                //edge color
        qreal m_for_font_size;      //weight text font
    protected:
        void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
        QRectF boundingRect()const;
};

#endif // GRAPHICS_EDGE_H
