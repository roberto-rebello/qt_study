#include <QRunnable>

class Worker : public QRunnable
{
private:
    /* data */
public:
    Worker();
    void run();
};
