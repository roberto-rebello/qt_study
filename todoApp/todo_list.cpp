#include "todo_list.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QListView>
#include <QPushButton>

TodoList::TodoList(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Todo");

    m_model = new TodoModel(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *container = new QWidget(this);
    container->setLayout(mainLayout);
    setCentralWidget(container);

    QListView *todoView = new QListView(this);
    todoView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    todoView->setModel(m_model);
    mainLayout->addWidget(todoView);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *deleteButton = new QPushButton("Delete", this);
    connect(deleteButton, SIGNAL(pressed()), this, SLOT(delete_btn()));
    QPushButton *completeButton = new QPushButton("Complete", this);
    connect(completeButton, SIGNAL(pressed()), this, SLOT(complete_btn()));
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(completeButton);
    mainLayout->addLayout(buttonLayout);

    m_todoEdit = new QLineEdit(this);
    mainLayout->addWidget(m_todoEdit);

    QPushButton *addButton = new QPushButton("Add Todo", this);
    connect(addButton, SIGNAL(pressed()), this, SLOT(add_btn()));
    mainLayout->addWidget(addButton);
}

void TodoList::add_btn()
{
}

void TodoList::delete_btn()
{
}

void TodoList::complete_btn()
{
}
