#include <QPushButton>

class PaletteButton : public QPushButton
{

    Q_OBJECT

public:
    PaletteButton(std::string color, QWidget *parent = nullptr);

private:
    std::string m_color = "#000000";
};