#include <string>

#include <QMainWindow>

#include <QPalette>
#include <QColor>

#include <QStackedLayout>

class Color : public QWidget
{

    Q_OBJECT

public:
    Color(std::string color, QWidget *parent = nullptr);

private:
};

class LayoutDemo : public QMainWindow
{

    Q_OBJECT

public:
    LayoutDemo(QWidget *parent = nullptr);

private:
    QStackedLayout *m_stacked_layout;

private slots:
    void set_stacked_red();
    void set_stacked_green();
    void set_stacked_blue();
    void set_stacked_yellow();
};