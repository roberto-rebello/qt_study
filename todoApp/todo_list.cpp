#include "todo_list.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QListView>
#include <QPushButton>
#include <QLineEdit>

TodoList::TodoList(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Todo");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *container = new QWidget(this);
    container->setLayout(mainLayout);
    setCentralWidget(container);

    QListView *todoList = new QListView(this);
    mainLayout->addWidget(todoList);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *deleteBtn = new QPushButton("Delete", this);
    QPushButton *completeBtn = new QPushButton("Complete", this);
    buttonLayout->addWidget(deleteBtn);
    buttonLayout->addWidget(completeBtn);
    mainLayout->addLayout(buttonLayout);

    QLineEdit *newTodo = new QLineEdit(this);
    mainLayout->addWidget(newTodo);

    QPushButton *addTodoBtn = new QPushButton("Add Todo", this);
    mainLayout->addWidget(addTodoBtn);
}

TodoList::~TodoList()
{
}