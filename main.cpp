#include <QApplication>

#include "main_window.hpp"
#include "widget_demo.hpp"
#include "layout_demo.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // MainWindow window;
    WidgetDemo window;

    window.resize(150, 150);
    window.show();
    return app.exec();
}