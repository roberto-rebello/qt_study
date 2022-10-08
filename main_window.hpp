#include <QMainWindow>

#include <QPushButton>

class MainWindow :public QMainWindow {

    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

    private slots:
        void on_clicked(bool checked);
        void disable_on_click();

        void on_title_change(QString title);

    private:
        void mousePressEvent(QMouseEvent *event);
        void mouseDoubleClickEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);

        void contextMenuEvent(QContextMenuEvent *e);

        QPushButton *m_button;
};