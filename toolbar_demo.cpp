#include "toolbar_demo.hpp"

#include <iostream>

#include <QVBoxLayout>
#include <QLabel>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>

ToolbarDemo::ToolbarDemo(QWidget *parent) : QMainWindow(parent)
{

    setWindowTitle("Toolbar Demo");

    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *container = new QWidget(this);
    container->setLayout(layout);
    setCentralWidget(container);

    QLabel *label = new QLabel("Hello!", container);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    QToolBar *toolbar = new QToolBar("My Toolbar", this);
    toolbar->setIconSize(QSize(16, 16));
    addToolBar(toolbar);

    QAction *action = new QAction(QIcon("images/icons/bug.png"), "Action 1", this);
    action->setStatusTip("This is a demo action");
    action->setCheckable(true);
    connect(action, SIGNAL(triggered(bool)), this, SLOT(action_triggered(bool)));
    toolbar->addAction(action);

    toolbar->addSeparator();

    QLabel *label2 = new QLabel("Hey there!");
    toolbar->addWidget(label2);

    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
}

void ToolbarDemo::action_triggered(bool checked)
{
    std::cout << "Action state: " << (checked ? "Checked" : "Unchecked") << std::endl;
}
