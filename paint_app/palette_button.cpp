#include "palette_button.hpp"

PaletteButton::PaletteButton(std::string color, QWidget *parent) : m_color(color)
{
    setFixedSize(24, 24);
    std::string style = "background-color: " + m_color + ";";
    setStyleSheet(QString(style.c_str()));
}