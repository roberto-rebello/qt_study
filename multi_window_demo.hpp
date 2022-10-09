#include <QMainWindow>

class MultiWindowDemo : public QMainWindow
{

    Q_OBJECT

public:
    MultiWindowDemo(QWidget *parent = nullptr);
    ~MultiWindowDemo();

private slots:
    void show_new_window();

private:
    void closeEvent(QCloseEvent *e);

    QWidget *m_child_window = nullptr;
};

class AnotherWindow : public QWidget
{

    Q_OBJECT

public:
    AnotherWindow(QWidget *parent = nullptr);
    ~AnotherWindow();
};