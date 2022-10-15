#include "painter.hpp"

#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPushButton>

Painter::Painter(QWidget *parent) : QMainWindow(parent),
                                    m_label(new QLabel())
{
    setWindowTitle("Pixelmap Demo");

    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *container = new QWidget(this);
    container->setLayout(layout);

    setCentralWidget(container);

    QPixmap canvas(400, 300);
    canvas.fill();

    m_label->setPixmap(canvas);
    layout->addWidget(m_label);

    draw_point();
    draw_line();
    draw_rect();
    draw_ellipse();
    draw_text();
}

void Painter::draw_point()
{
    QPixmap device = m_label->pixmap();

    QPainter painter(&device);
    for (int size = 40; size > 0; size--)
    {
        painter.setPen(QPen(Qt::GlobalColor::red, size));
        painter.drawPoint(200, 150 + size);
    }
    painter.end();

    m_label->setPixmap(device);
}

void Painter::draw_line()
{
    QPixmap device = m_label->pixmap();

    QPainter painter(&device);
    painter.setPen(QPen(Qt::GlobalColor::blue, 15, Qt::PenStyle::DashLine));
    painter.drawLine(10, 10, 300, 200);
    painter.end();

    m_label->setPixmap(device);
}

void Painter::draw_rect()
{
    QPixmap device = m_label->pixmap();

    QPainter painter(&device);
    painter.setPen(QPen(Qt::GlobalColor::green, 5));
    painter.drawRect(10, 10, 300, 200);
    painter.setPen(QPen(Qt::GlobalColor::gray, 2));
    painter.setBrush(QBrush(Qt::yellow, Qt::BrushStyle::Dense2Pattern));
    painter.drawRects(QList({QRect(200, 20, 50, 50),
                             QRect(205, 25, 50, 50),
                             QRect(210, 30, 50, 50),
                             QRect(215, 35, 50, 50),
                             QRect(220, 40, 50, 50)}));

    painter.setPen(QPen(Qt::GlobalColor::darkRed, 3, Qt::PenStyle::SolidLine));
    painter.setBrush(QBrush());
    painter.drawRoundedRect(20, 100, 100, 100, 20, 20);
    painter.end();

    m_label->setPixmap(device);
}

void Painter::draw_ellipse()
{
    QPixmap device = m_label->pixmap();

    QPainter painter(&device);
    painter.setPen(QPen(QColor(204, 0, 0), 1));
    painter.drawEllipse(10, 10, 100, 100);
    painter.drawEllipse(10, 10, 150, 200);
    painter.drawEllipse(10, 10, 200, 300);
    painter.drawLine(10, 10, 300, 200);
    painter.end();

    m_label->setPixmap(device);
}

void Painter::draw_text()
{
    QPixmap device = m_label->pixmap();

    QPainter painter(&device);
    painter.setPen(QPen(Qt::GlobalColor::black, 3, Qt::PenStyle::DotLine));
    QFont font;
    font.setFamily("Times");
    font.setBold(true);
    font.setPointSize(40);
    painter.setFont(font);
    painter.drawText(150, 250, "Hello, Qt");
    painter.end();

    m_label->setPixmap(device);
}