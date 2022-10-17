#include "canvas.hpp"

#include <QPainter>
#include <QMouseEvent>

Canvas::Canvas(QWidget *parent) : QLabel(parent)
{
    QPixmap canvas(600, 600);
    canvas.fill();
    setPixmap(canvas);
}

void Canvas::setPenColor(QColor color)
{
    m_pen_color = color;
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (m_last_x == 0)
    {
        m_last_x = event->position().x();
        m_last_y = event->position().y();
        return;
    }

    QPixmap canvas = pixmap();
    QPainter painter(&canvas);
    painter.setPen(QPen(m_pen_color, 4));
    painter.drawLine(m_last_x, m_last_y, event->position().x(), event->position().y());
    painter.end();

    setPixmap(canvas);

    m_last_x = event->position().x();
    m_last_y = event->position().y();

    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    m_last_x = 0;
    m_last_y = 0;
}
