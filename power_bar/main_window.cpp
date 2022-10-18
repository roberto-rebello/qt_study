#include "main_window.hpp"

#include <QHBoxLayout>

#include "power_bar.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          m_container(new QWidget(this))
{
    setWindowTitle("Custom Widget");

    QHBoxLayout *layout = new QHBoxLayout();
    m_container->setLayout(layout);
    setCentralWidget(m_container);

    PowerBar *powerBar = new PowerBar();
    layout->addWidget(powerBar);

    PowerBar *powerBar1 = new PowerBar(3);
    layout->addWidget(powerBar1);

    std::vector<QColor> colors1 = {QColor("#5e4fa2"),
                                   QColor("#3288bd"),
                                   QColor("#66c2a5"),
                                   QColor("#abdda4"),
                                   QColor("#e6f598"),
                                   QColor("#ffffbf"),
                                   QColor("#fee08b"),
                                   QColor("#fdae61"),
                                   QColor("#f46d43"),
                                   QColor("#d53e4f"),
                                   QColor("#9e0142")};
    PowerBar *powerBar2 = new PowerBar(colors1);
    layout->addWidget(powerBar2);

    std::vector<QColor> colors2 = {QColor("#a63603"),
                                   QColor("#e6550d"),
                                   QColor("#fd8d3c"),
                                   QColor("#fdae6b"),
                                   QColor("#fdd0a2"),
                                   QColor("#feedde")};
    PowerBar *powerBar3 = new PowerBar(colors2);
    layout->addWidget(powerBar3);

    PowerBar *crazyPowerBar = new PowerBar();
    crazyPowerBar->set_background_color(QColor(Qt::GlobalColor::darkRed));
    crazyPowerBar->set_bar_fill(0.3);
    crazyPowerBar->set_padding(0.3);
    crazyPowerBar->set_default_bar_color(QColor(Qt::GlobalColor::yellow));
    layout->addWidget(crazyPowerBar);
}

MainWindow::~MainWindow()
{
    delete m_container;
}