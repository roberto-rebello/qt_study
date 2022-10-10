#include <QMainWindow>

#include <QCheckBox>
#include <QComboBox>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDial>
#include <QDoubleSpinBox>
#include <QFontComboBox>
#include <QLabel>
#include <QLCDNumber>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>
#include <QTimeEdit>
#include <QVBoxLayout>
#include <QWidget>

class WidgetDemo : public QMainWindow {

    Q_OBJECT

    public:
        WidgetDemo(QWidget *parent = nullptr);

    private slots:
        // Check Box Slots
        void checkbox_show_state(int state);

        // Combo Box Slots
        void combobox_index_changed(int index);
        void combobox_text_changed(QString text);

        // LineEdit Slots
        void lineEdit_pressed();
        void lineEdit_selection_changed();
        void lineEdit_text_changed(QString text);
        void lineEdit_text_edited(QString text);

        // SpinBox Slots
        void spinBox_value_changed(int value);
        void spinBox_text_changed(QString text);

        // DoubleSpinBox Slots
        void doubleSpinBox_value_changed(double value);
        void doubleSpinBox_text_changed(QString text);

        // Slider Slots
        void slider_value_changed(int value);
        void slider_moved(int position);
        void slider_pressed();
        void slider_released();

        // Dial Slots
        void dial_value_changed(int value);
        void dial_moved(int position);
        void dial_pressed();
        void dial_released();

    private:

    QCheckBox *CheckBox;
    QComboBox *ComboBox;
    QDateEdit *DateEdit;
    QDateTimeEdit *DateTimeEdit;
    QDial *Dial;
    QDoubleSpinBox *DoubleSpinBox;
    QFontComboBox *FontComboBox;
    QLCDNumber *LCDNumber;
    QLabel *Label;
    QLineEdit *LineEdit;
    QProgressBar *ProgressBar;
    QPushButton *PushButton;
    QRadioButton *RadioButton;
    QSlider *Slider;
    QSpinBox *SpinBox;
    QTimeEdit *TimeEdit;
};