#ifndef GRAPHICS_VERTEX_H
#define GRAPHICS_VERTEX_H

#include <QGraphicsItem>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include "const.h"

/*Represents graph vertex as
 * a 2-D graphic oject through cyrcle.
 * Inherited from abstract QGraphicsitem.*/

class graphics_vertex : public QGraphicsItem
{
    public:
        graphics_vertex(QPointF = QPointF(0,0), qreal = 0, int = 0, int = _BLACK);
        void set_center(QPointF);
        void set_number(int);
        void set_color(int);
        QPointF get_center()const;
        qreal get_radius()const;
        int get_color()const;
        int get_number()const;
    private:
        QPointF m_center;       //center of cyrcle
        qreal m_radius;         //radius of cyrcle
        int m_number;           //number of vertex
        int m_color;            //color of vertex
    protected:
        void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
        QRectF boundingRect()const;
};

#endif // GRAPHICS_VERTEX_H
