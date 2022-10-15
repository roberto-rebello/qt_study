#include <QApplication>

#include "paint_app.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    PaintApp window;
    window.show();

    return app.exec();
}