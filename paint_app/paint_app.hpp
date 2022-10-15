#include <QMainWindow>

#include "canvas.hpp"
#include "palette_button.hpp"

#include <QLabel>

class PaintApp : public QMainWindow
{

    Q_OBJECT

public:
    PaintApp(QWidget *parent = nullptr);

private:
    Canvas *m_canvas;
};
