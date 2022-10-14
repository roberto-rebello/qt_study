#include <QMainWindow>

#include <QPushButton>
#include <QPlainTextEdit>
#include <QProcess>
#include <QProgressBar>

class Process : public QMainWindow
{

    Q_OBJECT

public:
    Process(QWidget *parent = nullptr);

private:
    QPushButton *m_button;
    QPlainTextEdit *m_text;
    QProcess *m_process;
    QProgressBar *m_progressBar;

    void message(std::string message);
    uint8_t simple_percent_parser(std::string output);

private slots:
    void start_process();
    void cleanup();
    void handle_stdout();
    void handle_stderror();
    void handle_state(QProcess::ProcessState state);
};
