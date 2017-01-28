#ifndef GRAPHICS_TEXT_H
#define GRAPHICS_TEXT_H

#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include "const.h"

/*object of this class texts and
 * they use on the 2-D scene.
 * Inherited from QGraphicsItem*/

class graphics_text : public QGraphicsItem
{
    public:
        graphics_text(QString, QPointF, qreal);
        QString m_text;                         //text
        QPointF m_bottom_left;
        QFont m_font;                           //text font
    protected:
        void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
        QRectF boundingRect()const;
};

#endif // GRAPHICS_TEXT_H
