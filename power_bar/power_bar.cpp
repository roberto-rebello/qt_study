#include "power_bar.hpp"

#include <QVBoxLayout>

PowerBar::PowerBar(QWidget *parent) : QWidget(parent),
                                      m_bar(new Bar(this)),
                                      m_dial(new QDial(this))
{
    m_bar->setObjectName("Bar");
    m_dial->setObjectName("Dial");

    QVBoxLayout *layout = new QVBoxLayout();
    setLayout(layout);

    layout->addWidget(m_bar);
    layout->addWidget(m_dial);

    setMinimumSize(250, 400);
}