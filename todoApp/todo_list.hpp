#include <QMainWindow>

#include "todo_model.hpp"

#include <QLineEdit>

class TodoList : public QMainWindow
{

    Q_OBJECT

public:
    TodoList(QWidget *parent = nullptr);

private:
    TodoModel *m_model;
    QLineEdit *m_todoEdit;

private slots:
    void add_btn();
    void delete_btn();
    void complete_btn();
};
