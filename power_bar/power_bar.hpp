#include <QWidget>

#include "bar.hpp"
#include <QDial>

class PowerBar : public QWidget
{

    Q_OBJECT

public:
    PowerBar(QWidget *parent = nullptr);
    PowerBar(unsigned numBars, QWidget *parent = nullptr);
    PowerBar(std::vector<QColor> colors, QWidget *parent = nullptr);

    ~PowerBar();

    void set_background_color(QColor color);
    void set_padding(float padding);
    void set_bar_fill(float fill);
    void set_default_bar_color(QColor color);

private:
    Bar *m_bar;
    QDial *m_dial;

    void init_powerbar();
};
