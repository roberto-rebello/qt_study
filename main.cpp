#include <QApplication>

#include "main_window.hpp"
#include "widget_demo.hpp"
#include "layout_demo.hpp"
#include "toolbar_demo.hpp"
#include "dialog_demo.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    MainWindow window;
    window.resize(150, 150);
    window.show();

    WidgetDemo widget;
    widget.resize(150, 150);
    widget.show();

    LayoutDemo layout;
    layout.resize(150, 150);
    layout.show();

    ToolbarDemo toolbar;
    toolbar.resize(150, 150);
    toolbar.show();

    DialogDemo dialog;
    dialog.resize(150, 150);
    dialog.show();

    return app.exec();
}