#include <QWidget>

class Bar : public QWidget
{

    Q_OBJECT

public:
    Bar(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event);
};
