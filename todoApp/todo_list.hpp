#include <QMainWindow>

class TodoList : public QMainWindow
{

    Q_OBJECT

private:
    /* data */
public:
    TodoList(QWidget *parent = nullptr);
    ~TodoList();
};
