#include <QApplication>

#include "painter.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    Painter window;
    window.resize(400, 500);
    window.show();

    return app.exec();
}