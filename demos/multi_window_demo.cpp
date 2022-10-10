#include "multi_window_demo.hpp"

#include <iostream>

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MultiWindowDemo::MultiWindowDemo(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("MultiWindow Demo");

    QWidget *container = new QWidget(this);
    setCentralWidget(container);

    QVBoxLayout *layout = new QVBoxLayout();
    container->setLayout(layout);

    QPushButton *button = new QPushButton("Push for new window");
    connect(button, SIGNAL(pressed()), this, SLOT(show_new_window()));
    layout->addWidget(button);
}

MultiWindowDemo::~MultiWindowDemo()
{
    std::cout << "Deconstructing MultiWindowDemo" << std::endl;
    delete m_child_window;
}

void MultiWindowDemo::show_new_window()
{
    if (m_child_window == nullptr)
    {
        std::cout << "Creating new window" << std::endl;
        m_child_window = new AnotherWindow();
        m_child_window->show();
    }
    else
    {
        if (m_child_window->close())
        {
            std::cout << "Window closed" << std::endl;
            delete m_child_window;
            m_child_window = nullptr;
        }
        else
        {
            std::cout << "Window not closed" << std::endl;
        }
    }
}

void MultiWindowDemo::closeEvent(QCloseEvent *e)
{
    m_child_window->close();
    QMainWindow::close();
}

AnotherWindow::AnotherWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("New Window");

    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    QLabel *label = new QLabel("I'm a new window!", this);
    QFont font = label->font();
    font.setPixelSize(20);
    font.setBold(true);
    label->setFont(font);
    layout->addWidget(label);
}

AnotherWindow::~AnotherWindow()
{
    std::cout << "Deconstructing AnotherWindow" << std::endl;
}