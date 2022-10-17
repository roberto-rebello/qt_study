#include "main_window.hpp"

#include <QVBoxLayout>

#include "power_bar.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          m_container(new QWidget(this))
{
    setWindowTitle("Custom Widget");

    QVBoxLayout *layout = new QVBoxLayout();
    m_container->setLayout(layout);
    setCentralWidget(m_container);

    PowerBar *powerBar = new PowerBar();
    layout->addWidget(powerBar);
}

MainWindow::~MainWindow()
{
    delete m_container;
}