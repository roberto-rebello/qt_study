#include "main_window.hpp"

#include <QApplication>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMouseEvent>
#include <QPointF>
#include <QMenu>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("MainWindow Demo");

    QWidget *container = new QWidget(this);
    QGridLayout *grid = new QGridLayout();

    // Quit Button
    QPushButton *quit_button = new QPushButton("Quit", this);
    connect(quit_button, SIGNAL(clicked()), qApp, SLOT(quit()));
    grid->addWidget(quit_button, 2, 2);

    // Push Button
    m_button = new QPushButton("Click me!", this);
    m_button->setMaximumSize(QSize(300, 300));
    m_button->setCheckable(true);
    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(on_clicked(bool)));
    connect(m_button, SIGNAL(clicked()), this, SLOT(disable_on_click()));
    grid->addWidget(m_button, 2, 0);

    // Line Edit
    QLineEdit *lineEdit = new QLineEdit();
    grid->addWidget(lineEdit, 0, 0, 1, 3);

    // Label
    QLabel *label = new QLabel();
    label->setStyleSheet("border: 1px solid black;");
    grid->addWidget(label, 1, 0, 1, 3);
    connect(lineEdit, SIGNAL(textChanged(QString)), label, SLOT(setText(QString)));

    // Window signals
    connect(this, SIGNAL(windowTitleChanged(QString)), this, SLOT(on_title_change(QString)));

    // Container
    container->setLayout(grid);
    setCentralWidget(container);
}

void MainWindow::on_clicked(bool checked)
{
    std::cout << "Clicked" << std::endl;
    std::cout << "Checked: " << (checked ? "Yes" : "No") << std::endl;
}

void MainWindow::disable_on_click()
{
    setWindowTitle("My Oneshot App");

    m_button->setEnabled(false);
    m_button->setText("Clicked!");
}

void MainWindow::on_title_change(QString title)
{
    std::cout << "Title chenged to: " << title.toStdString() << std::endl;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    std::cout << e->button() << " Click Event" << std::endl;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    std::cout << e->button() << " Double click Event" << std::endl;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    std::cout << e->button() << " Release Event" << std::endl;
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    QPointF point = e->position();
    std::cout << "Move Event"
              << " (" << point.x() << "," << point.y() << ")" << std::endl;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu *contex = new QMenu(this);
    contex->addAction(new QAction("Teste 1", this));
    contex->addAction(new QAction("Teste 2", this));
    contex->addAction(new QAction("Teste 3", this));
    contex->addAction(new QAction("Teste 4", this));
    contex->exec(e->globalPos());
}