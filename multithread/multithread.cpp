#include "multithread.hpp"
#include "worker.hpp"

#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <iostream>

#include <QPushButton>
#include <QVBoxLayout>

MultiThread::MultiThread(QWidget *parent) : QMainWindow(parent),
                                            m_counter(0),
                                            m_label(new QLabel("Start", this)),
                                            m_timer(new QTimer()),
                                            m_threadPool(new QThreadPool(this))
{
    setWindowTitle("MultiThread Demo");

    std::cout << "Multithreading with maximum " << m_threadPool->maxThreadCount() << " threads" << std::endl;

    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *container = new QWidget(this);
    container->setLayout(layout);

    setCentralWidget(container);

    QPushButton *button = new QPushButton("DANGER!", this);
    connect(button, SIGNAL(pressed()), this, SLOT(oh_no()));

    layout->addWidget(m_label);
    layout->addWidget(button);

    m_timer->setInterval(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(recurring_timer()));
    m_timer->start();
}

MultiThread::~MultiThread()
{
}

void MultiThread::oh_no()
{
    Worker *worker = new Worker();
    m_threadPool->start(worker);
}

void MultiThread::recurring_timer()
{
    m_counter++;

    std::string newText("Counter: " + std::to_string(m_counter));
    m_label->setText(newText.c_str());
}