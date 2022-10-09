#include "toolbar_demo.hpp"

#include <iostream>

#include <QVBoxLayout>
#include <QLabel>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>

#include <QMenuBar>

#include <QApplication>

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

    // Toolbar Demo
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

    QAction *action2 = new QAction(QIcon("images/icons/android.png"), "&Action 2", this);
    action2->setStatusTip("This is another demo action");
    action2->setCheckable(true);
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(action_triggered(bool)));
    toolbar->addAction(action2);

    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    // Menu Demo
    QMenuBar *menu = menuBar();
    QMenu *file_menu = menu->addMenu("&File");
    file_menu->addAction(action);

    QMenu *file_submenu = file_menu->addMenu("&Submenu");
    file_submenu->addAction(action2);

    file_menu->addSeparator();

    QAction *exit_action = new QAction("&Exit", this);
    exit_action->setStatusTip("Quit demo application");
    exit_action->setShortcut(QKeySequence("ctrl+q"));
    connect(exit_action, SIGNAL(triggered(bool)), qApp, SLOT(exit()));
    file_menu->addAction(exit_action);
}

void ToolbarDemo::action_triggered(bool checked)
{
    std::cout << "Action state: " << (checked ? "Checked" : "Unchecked") << std::endl;
}
