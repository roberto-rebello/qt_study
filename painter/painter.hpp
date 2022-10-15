#include <QMainWindow>

#include <QLabel>

class Painter : public QMainWindow
{

    Q_OBJECT

public:
    Painter(QWidget *parent = nullptr);

private:
    QLabel *m_label;

    void draw_point();
    void draw_line();
    void draw_rect();
    void draw_ellipse();
    void draw_text();
};
