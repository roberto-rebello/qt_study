#include "bar.hpp"

#include <QPainter>

#include <QDial>

Bar::Bar(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

void Bar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    QBrush brush;
    brush.setColor(Qt::GlobalColor::black);
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    QRect rect(0, 0, painter.device()->width(), painter.device()->height());

    painter.fillRect(rect, brush);

    // Get current state
    QDial *dial = parent()->findChild<QDial *>("Dial");
    int vmin = dial->minimum();
    int vmax = dial->maximum();
    int value = dial->value();

    painter.setPen(QPen(Qt::GlobalColor::red));
    painter.setFont(QFont("Timer", 18));

    painter.drawText(25, 25, (std::to_string(vmin) + "-->" + std::to_string(value) + "<--" + std::to_string(vmax)).c_str());

    painter.end();
}

void Bar::trigger_refresh()
{
    update();
}