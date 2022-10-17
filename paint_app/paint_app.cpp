#include "paint_app.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

PaintApp::PaintApp(QWidget *parent) : QMainWindow(parent),
                                      m_canvas(new Canvas())
{
    setWindowTitle("Paint App");

    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *container = new QWidget(this);
    container->setLayout(layout);
    setCentralWidget(container);

    layout->addWidget(m_canvas);

    std::vector<std::string> colors = {
        "#000000",
        "#141923",
        "#414168",
        "#3a7fa7",
        "#35e3e3",
        "#8fd970",
        "#5ebb49",
        "#458352",
        "#dcd37b",
        "#fffee5",
        "#ffd035",
        "#cc9245",
        "#a15c3e",
        "#a42f3b",
        "#f45b7a",
        "#c24998",
        "#81588d",
        "#bcb0c2",
        "#ffffff",
    };

    QHBoxLayout *colorPalette = new QHBoxLayout();
    for (std::string color : colors)
    {
        PaletteButton *paletteButton = new PaletteButton(color);
        connect(paletteButton, &QPushButton::pressed, this, [this, color]()
                { m_canvas->setPenColor(QColor(color.c_str())); });
        colorPalette->addWidget(paletteButton);
    }

    layout->addLayout(colorPalette);
}