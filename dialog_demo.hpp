#include <QMainWindow>

class DialogDemo : public QMainWindow
{

    Q_OBJECT

public:
    DialogDemo(QWidget *parent = nullptr);

private slots:
    void basic_button_pressed();
    void custom_button_pressed();
    void message_button_pressed();
    void default_button_pressed();
    void qdialog_button_pressed();
};