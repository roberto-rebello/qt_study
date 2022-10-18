#include "power_bar.hpp"

#include <QVBoxLayout>

PowerBar::PowerBar(QWidget *parent) : QWidget(parent),
                                      m_bar(new Bar(this)),
                                      m_dial(new QDial(this))
{
    init_powerbar();
}

PowerBar::PowerBar(unsigned numBars, QWidget *parent) : QWidget(parent),
                                                        m_bar(new Bar(numBars, this)),
                                                        m_dial(new QDial(this))
{
    init_powerbar();
}

PowerBar::PowerBar(std::vector<QColor> colors, QWidget *parent) : QWidget(parent),
                                                                  m_bar(new Bar(colors, this)),
                                                                  m_dial(new QDial(this))
{
    init_powerbar();
}

PowerBar::~PowerBar()
{
    delete m_bar;
    delete m_dial;
}

void PowerBar::init_powerbar()
{
    m_bar->setObjectName("Bar");

    m_dial->setObjectName("Dial");
    connect(m_dial, &QDial::valueChanged, m_bar, &Bar::trigger_refresh);

    QVBoxLayout *layout = new QVBoxLayout();
    setLayout(layout);

    layout->addWidget(m_bar);
    layout->addWidget(m_dial);

    setMinimumSize(250, 400);
}

void PowerBar::set_background_color(QColor color)
{
    m_bar->set_background_color(color);
}

void PowerBar::set_padding(float padding)
{
    m_bar->set_padding(padding);
}

void PowerBar::set_bar_fill(float fill)
{
    m_bar->set_bar_fill(fill);
}

void PowerBar::set_default_bar_color(QColor color)
{
    m_bar->set_default_bar_color(color);
}
