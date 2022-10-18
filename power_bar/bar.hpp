#include <QWidget>

class Bar : public QWidget
{

    Q_OBJECT

public:
    Bar(QWidget *parent = nullptr);
    Bar(unsigned numBars, QWidget *parent = nullptr);
    Bar(std::vector<QColor> colors, QWidget *parent = nullptr);

    void set_background_color(QColor color);

    void set_padding(float padding);

    void set_bar_fill(float fill);

    void set_default_bar_color(QColor color);

public slots:
    void trigger_refresh();

private:
    void init();

    void paintEvent(QPaintEvent *event);

    unsigned m_numBars;
    std::vector<QColor> m_colors;
    QColor m_background_color = QColor(Qt::GlobalColor::black);
    float m_padding = 0.05;
    float m_bar_fill = 0.6;
    QColor m_default_bar_color = QColor(Qt::GlobalColor::red);
};
