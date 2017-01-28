#include "graphics_text.h"

graphics_text::graphics_text(QString S, QPointF P,qreal f)
{
    m_text = S;
    m_bottom_left = P;
    m_font = QFont("Times", f, f);
    setPos(P);
}

void graphics_text::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QPen P(Qt::blue);
    painter->setFont(m_font);
    painter->setPen(P);
    painter->drawText(m_bottom_left, m_text);
}

QRectF graphics_text::boundingRect() const
{
    return QRectF(real_zero, real_zero, real_zero, real_zero);
}
