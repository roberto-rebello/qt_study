#include <QWidget>

class Bar : public QWidget
{

    Q_OBJECT

public:
    Bar(QWidget *parent = nullptr);

public slots:
    void trigger_refresh();

private:
    void paintEvent(QPaintEvent *event);
};
