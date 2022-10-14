#include <QApplication>

#include "process.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    Process window;
    window.resize(400, 500);
    window.show();

    return app.exec();
}