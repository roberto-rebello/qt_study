#include "layout_demo.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QPushButton>

#include <QTabWidget>

// Color
Color::Color(std::string color, QWidget *parent) : QWidget(parent) {
    
    QPalette palette = this->palette();
    palette.setColor(QPalette::ColorRole::Window, QColor(QString(color.c_str())));

    setAutoFillBackground(true);
    setPalette(palette);
}

// LayoutDemo
LayoutDemo::LayoutDemo(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Layout Demo");
    
    // Main Layout
    QGridLayout *layout = new QGridLayout();
    layout->setSpacing(50);

    // Vertical Layout
    QVBoxLayout *vertical_layout = new QVBoxLayout();
    vertical_layout->addWidget(new Color("red"));
    vertical_layout->addWidget(new Color("green"));
    vertical_layout->addWidget(new Color("blue"));
    vertical_layout->addWidget(new Color("yellow"));
    layout->addLayout(vertical_layout, 0, 0);

    // Vertical Layout
    QHBoxLayout *horizontal_layout = new QHBoxLayout();
    horizontal_layout->addWidget(new Color("red"));
    horizontal_layout->addWidget(new Color("green"));
    horizontal_layout->addWidget(new Color("blue"));
    horizontal_layout->addWidget(new Color("yellow"));
    layout->addLayout(horizontal_layout, 0, 1);

    // Grid Layout
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(new Color("red"), 0, 0);
    grid->addWidget(new Color("green"), 0, 1);
    grid->addWidget(new Color("blue"), 1, 0);
    grid->addWidget(new Color("yellow"), 1, 1);
    layout->addLayout(grid, 1, 0);


    QWidget *container = new QWidget();
    container->setLayout(layout);
    setCentralWidget(container);


    // Stacked Layout
    QWidget *stacked_widget = new QWidget();

    m_stacked_layout = new QStackedLayout();
    m_stacked_layout->addWidget(new Color("red"));
    m_stacked_layout->addWidget(new Color("green"));
    m_stacked_layout->addWidget(new Color("blue"));
    m_stacked_layout->addWidget(new Color("yellow"));

    QVBoxLayout *page = new QVBoxLayout();
    QHBoxLayout *buttons = new QHBoxLayout();

    page->addLayout(buttons);
    page->addLayout(m_stacked_layout);

    QPushButton *red = new QPushButton("Red", stacked_widget);
    connect(red, SIGNAL(pressed()), this, SLOT(set_stacked_red()));
    buttons->addWidget(red);

    QPushButton *green = new QPushButton("Green", stacked_widget);
    connect(green, SIGNAL(pressed()), this, SLOT(set_stacked_green()));
    buttons->addWidget(green);

    QPushButton *blue = new QPushButton("Blue", stacked_widget);
    connect(blue, SIGNAL(pressed()), this, SLOT(set_stacked_blue()));
    buttons->addWidget(blue);

    QPushButton *yellow = new QPushButton("Yellow", stacked_widget);
    connect(yellow, SIGNAL(pressed()), this, SLOT(set_stacked_yellow()));
    buttons->addWidget(yellow);

    stacked_widget->setWindowTitle("Stacked Layout Demo");
    stacked_widget->setLayout(page);
    stacked_widget->show();


    // Tab Widget Demo
    QTabWidget *stacked = new QTabWidget();
    stacked->setWindowTitle("TabWidget Demo");
    stacked->setTabPosition(QTabWidget::North);
    stacked->setMovable(true);
    stacked->addTab(new Color("red"), "Red");
    stacked->addTab(new Color("green"), "Green");
    stacked->addTab(new Color("blue"), "Blue");
    stacked->addTab(new Color("yellow"), "Yellow");
    stacked->show();

}

void LayoutDemo::set_stacked_red() {
    m_stacked_layout->setCurrentIndex(0);
}

void LayoutDemo::set_stacked_green() {
    m_stacked_layout->setCurrentIndex(1);
}

void LayoutDemo::set_stacked_blue() {
    m_stacked_layout->setCurrentIndex(2);
}

void LayoutDemo::set_stacked_yellow() {
    m_stacked_layout->setCurrentIndex(3);
}


