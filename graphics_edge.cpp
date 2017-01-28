#include "graphics_edge.h"

//default constructor
graphics_edge::graphics_edge(graphics_vertex &a, graphics_vertex &b, bool m, int w, QPointF p, int c)
{
    m_from = a.get_center();
    m_to = b.get_center();
    m_membership = m;
    m_weight = w;
    m_for_weight_text = p;
    m_color = c;
    m_for_font_size = a.get_radius();
}

void graphics_edge::set_color(int c)
{
    m_color = c;
}

int graphics_edge::get_color() const
{
    return m_color;
}

//paints edge as line
void graphics_edge::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QFont font("Sans", m_for_font_size, QFont::Normal);
    QPen pen;
    pen.setWidthF(m_for_font_size / _eight);
    if (m_color == _BLACK)
        pen.setColor(Qt::black);
    else if (m_color == _YELLOW)
        pen.setColor(Qt::yellow);
    else if (m_color == _GREEN)
        pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawLine(m_from, m_to);
    if (m_membership)
    {
        painter->setFont(font);
        painter->drawText(m_for_weight_text, QString::number(m_weight));
    }
}

QRectF graphics_edge::boundingRect()const
{
    return QRectF(real_zero, real_zero, real_zero, real_zero);
}

