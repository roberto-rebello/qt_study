#include "bar.hpp"

#include <QPainter>

#include <QDial>
#include <QMouseEvent>

Bar::Bar(QWidget *parent) : QWidget(parent),
                            m_numBars(10)
{
    init();
}

Bar::Bar(unsigned numBars, QWidget *parent) : QWidget(parent),
                                              m_numBars(numBars)
{
    init();
}

Bar::Bar(std::vector<QColor> colors, QWidget *parent) : QWidget(parent),
                                                        m_colors(colors)
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    m_numBars = m_colors.size();
}

void Bar::init()
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    m_colors.reserve(m_numBars);
    for (size_t i = 0; i < m_numBars; i++)
    {
        m_colors.push_back(m_default_bar_color);
    }
}

void Bar::set_background_color(QColor color)
{
    m_background_color = color;
}

void Bar::set_padding(float padding)
{
    m_padding = padding;
}

void Bar::set_bar_fill(float fill)
{
    m_bar_fill = fill;
}

void Bar::set_default_bar_color(QColor color)
{
    m_default_bar_color = color;
    m_colors.clear();
    m_colors.reserve(m_numBars);
    for (size_t i = 0; i < m_numBars; i++)
    {
        m_colors.push_back(m_default_bar_color);
    }
}

void Bar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    QBrush brush;
    brush.setColor(m_background_color);
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    QRect rect(0, 0, painter.device()->width(), painter.device()->height());

    painter.fillRect(rect, brush);

    // Get current state
    QDial *dial = parent()->findChild<QDial *>("Dial");
    float vmin = dial->minimum();
    float vmax = dial->maximum();
    float value = dial->value();
    int power = m_numBars * ((value - vmin) / (vmax - vmin));

    // Define canvas
    int padding = painter.device()->width() * m_padding;
    int canvas_height = painter.device()->height() - (padding * 2);
    int canvas_width = painter.device()->width() - (padding * 2);

    int power_bar_size = canvas_height / m_numBars;
    int power_bar_height = power_bar_size * m_bar_fill;
    int power_bar_spacer = power_bar_size * (1 - m_bar_fill) / 2;

    for (int i = 1; i <= power; i++)
    {
        QRect rect(padding,
                   padding + canvas_height - (i * power_bar_size) + power_bar_spacer,
                   canvas_width,
                   power_bar_height);
        painter.fillRect(rect, m_colors[i - 1]);
    }

    painter.end();
}

void Bar::trigger_refresh()
{
    update();
}

void Bar::mouseMoveEvent(QMouseEvent *e)
{
    calculate_clicked_value(e);
}

void Bar::mousePressEvent(QMouseEvent *e)
{
    calculate_clicked_value(e);
}

void Bar::calculate_clicked_value(QMouseEvent *e)
{
    QDial *dial = parent()->findChild<QDial *>("Dial");
    float vmin = dial->minimum();
    float vmax = dial->maximum();

    float padding = size().width() * m_padding;
    float height = size().height() - (padding * 2);
    float bar_size = height / m_numBars;

    float click_y = e->position().y() - padding - bar_size / 2;

    float bar_percent = (height - click_y) / height;
    int value = vmin + bar_percent * (vmax - vmin);

    emit(clickedValue(value));
}