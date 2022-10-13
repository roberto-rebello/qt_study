#include <QApplication>

#include "multithread.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    MultiThread window;
    window.resize(400, 500);
    window.show();

    return app.exec();
}