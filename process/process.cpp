#include "process.hpp"

#include <QVBoxLayout>

#include <regex>

Process::Process(QWidget *parent) : QMainWindow(parent),
                                    m_button(new QPushButton(this)),
                                    m_text(new QPlainTextEdit(this)),
                                    m_process(nullptr),
                                    m_progressBar(new QProgressBar(this))
{
    setWindowTitle("Process Demo");

    QVBoxLayout *layout = new QVBoxLayout();

    QWidget *container = new QWidget(this);
    container->setLayout(layout);
    setCentralWidget(container);

    m_text->setReadOnly(true);
    layout->addWidget(m_text);

    m_progressBar->setRange(0, 100);
    layout->addWidget(m_progressBar);

    m_button->setText("Execute");
    connect(m_button, SIGNAL(pressed()), this, SLOT(start_process()));
    layout->addWidget(m_button);
}

void Process::message(std::string message)
{
    m_text->appendPlainText(QString(message.c_str()));
}

void Process::start_process()
{
    if (m_process == nullptr)
    {
        message("Process started");
        m_process = new QProcess(this);
        connect(m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(handle_stdout()));
        connect(m_process, SIGNAL(readyReadStandardError()), this, SLOT(handle_stderror()));
        connect(m_process, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(handle_state(QProcess::ProcessState)));
        connect(m_process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(cleanup()));
        m_process->start("python3", {"dummy_script.py"});
    }
}

void Process::handle_stdout()
{
    QByteArray data = m_process->readAllStandardOutput();
    message(data.toStdString());
}

void Process::handle_stderror()
{
    QByteArray error = m_process->readAllStandardError();
    message(error.toStdString());

    uint16_t progress = simple_percent_parser(error.toStdString());
    if (progress > 0)
    {
        m_progressBar->setValue(progress);
    }
}

void Process::handle_state(QProcess::ProcessState state)
{
    std::vector<std::string> states{"Not Runnig", "Starting", "Running"};
    message("State changed to: " + states[state]);
}

void Process::cleanup()
{
    message("Processed Finished");
    delete m_process;
    m_process = nullptr;
}

uint8_t Process::simple_percent_parser(std::string output)
{
    std::smatch percent;
    std::regex rgx("[0-9]+\%");
    if (std::regex_search(output, percent, rgx))
    {
        return std::stoi(percent[0]);
    }
    return 0;
}