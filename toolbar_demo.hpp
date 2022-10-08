#include <QMainWindow>

class ToolbarDemo : public QMainWindow
{

    Q_OBJECT

public:
    ToolbarDemo(QWidget *parent = nullptr);

private slots:
    void action_triggered(bool checked);
};