#include "todo_list.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>

TodoList::TodoList(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Todo");

    m_model = new TodoModel(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *container = new QWidget(this);
    container->setLayout(mainLayout);
    setCentralWidget(container);

    m_todoView = new QListView(this);
    m_todoView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection); // Default ?
    m_todoView->setModel(m_model);
    mainLayout->addWidget(m_todoView);

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
    QString text = m_todoEdit->text();
    m_todoEdit->setText("");

    m_model->add_todo(text);
    emit(m_model->layoutChanged());
}

void TodoList::delete_btn()
{
    QModelIndexList indexes = m_todoView->selectionModel()->selectedIndexes();

    if (!indexes.empty())
    {
        QModelIndex index = indexes.at(0); // SingleSelection so only one index selected
        m_model->delete_todo(index.row());
        emit(m_model->layoutChanged());
        m_todoView->clearSelection();
    }
}

void TodoList::complete_btn()
{
    QModelIndexList indexes = m_todoView->selectionModel()->selectedIndexes();

    if (!indexes.empty())
    {
        QModelIndex index = indexes.at(0); // SingleSelection so only one index selected
        m_model->complete_todo(index.row());
        emit(m_model->layoutChanged());
    }
}
