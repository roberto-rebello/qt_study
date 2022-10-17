#include <QWidget>

#include "bar.hpp"
#include <QDial>

class PowerBar : public QWidget
{

    Q_OBJECT

public:
    PowerBar(QWidget *parent = nullptr);

private:
    Bar *m_bar;
    QDial *m_dial;
};
