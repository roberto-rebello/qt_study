#include "worker.hpp"

#include <iostream>
#include <unistd.h>

Worker::Worker() : QRunnable()
{
}

void Worker::run()
{
    std::cout << "Thread start" << std::endl;
    usleep(5000000);
    std::cout << "Thread end" << std::endl;
}