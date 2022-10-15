#include <QLabel>

#include <QPixmap>

class Canvas : public QLabel
{
public:
    Canvas(QWidget *parent = nullptr);

public slots:
    void setPenColor(QColor color);

private:
    int m_last_x = 0;
    int m_last_y = 0;
    QColor m_pen_color = Qt::GlobalColor::black;

    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
