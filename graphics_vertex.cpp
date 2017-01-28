#include "graphics_vertex.h"

//default constructor
graphics_vertex::graphics_vertex(QPointF C, qreal r, int i, int c)
{
    m_center = C;
    m_radius = r;
    m_number = i;
    m_color = c;
    setPos(m_center.x() - m_radius, m_center.y() - m_radius);
}

void graphics_vertex::set_center(QPointF P)
{
    m_center = P;
}

void graphics_vertex::set_number(int n)
{
    m_number = n;
}

void graphics_vertex::set_color(int c)
{
    m_color = c;
}

QPointF graphics_vertex::get_center() const
{
    return m_center;
}

qreal graphics_vertex::get_radius() const
{
    return m_radius;
}

int graphics_vertex::get_color() const
{
    return m_color;
}

int graphics_vertex::get_number() const
{
    return m_number;
}

//paints vertex such as cyrcle
void graphics_vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QFont font("Sans", m_radius, QFont::Normal);
    QBrush brush(Qt::SolidPattern);
    QPen pen;
    pen.setWidthF(m_radius / _ten);
    if (m_color == _BLACK)
        brush.setColor(Qt::white);
    else if (m_color == _YELLOW)
        brush.setColor(Qt::yellow);
    else if (m_color == _GREEN)
        brush.setColor(Qt::green);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawEllipse(boundingRect());
    painter->setFont(font);
    painter->drawText(m_radius / _two, m_radius + m_radius / _two, QString::number(m_number));
}

QRectF graphics_vertex::boundingRect() const
{
    return QRectF(real_zero, real_zero, _two*m_radius, _two*m_radius);
}




