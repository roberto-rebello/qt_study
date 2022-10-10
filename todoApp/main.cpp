#include <QApplication>

#include "todo_list.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    TodoList window;
    window.resize(400, 500);
    window.show();

    return app.exec();
}