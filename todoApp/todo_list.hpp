#include <QMainWindow>

#include "todo_model.hpp"

#include <QListView>
#include <QLineEdit>

class TodoList : public QMainWindow
{

    Q_OBJECT

public:
    TodoList(QWidget *parent = nullptr);

private:
    TodoModel *m_model;
    QListView *m_todoView;
    QLineEdit *m_todoEdit;

private slots:
    void add_btn();
    void delete_btn();
    void complete_btn();
};
