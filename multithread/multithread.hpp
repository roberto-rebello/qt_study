#include <QMainWindow>

#include <QLabel>
#include <QTimer>
#include <QThreadPool>

class MultiThread : public QMainWindow
{

    Q_OBJECT

public:
    MultiThread(QWidget *parent = nullptr);
    ~MultiThread();

private:
    uint8_t m_counter;
    QLabel *m_label;
    QTimer *m_timer;
    QThreadPool *m_threadPool;

private slots:
    void oh_no();
    void recurring_timer();
};
