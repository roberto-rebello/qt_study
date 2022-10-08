#include "widget_demo.hpp"

#include <iostream>


WidgetDemo::WidgetDemo(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Widgets Demo");

    QVBoxLayout *grid = new QVBoxLayout();

    // QCheckBox Demo
    CheckBox = new QCheckBox(this);
    CheckBox->setText("This is a checkbox");
    CheckBox->setCheckState(Qt::Checked); // Qt::Unchecked == 0 , Qt::PartiallyChecked == 1, Qt::Checked == 2
    CheckBox->setTristate(true);
    connect(CheckBox, SIGNAL(stateChanged(int)), this, SLOT(checkbox_show_state(int)));

    // QComboBox Demo
    ComboBox = new QComboBox(this);
    ComboBox->addItem("Option One");
    ComboBox->addItem("Option Two");
    ComboBox->addItem("Option Three");
    // ComboBox->setCurrentIndex(-1);
    // ComboBox->setCurrentText("Option Three");
    connect(ComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(combobox_index_changed(int)));
    connect(ComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(combobox_text_changed(QString)));

    // QDateEdit Demo
    DateEdit = new QDateEdit(this);

    // QDateTimeEdit Demo
    DateTimeEdit = new QDateTimeEdit(this);

    // QDial Demo
    Dial = new QDial(this);
    Dial->setRange(-10, 100);
    Dial->setSingleStep(0.5);
    connect(Dial, SIGNAL(valueChanged(int)), this, SLOT(dial_value_changed(int)));
    connect(Dial, SIGNAL(sliderMoved(int)), this, SLOT(dial_moved(int)));
    connect(Dial, SIGNAL(sliderPressed()), this, SLOT(dial_pressed()));
    connect(Dial, SIGNAL(sliderReleased()), this, SLOT(dial_released()));

    // QDoubleSpinBox Demo
    DoubleSpinBox = new QDoubleSpinBox(this);
    DoubleSpinBox->setMinimum(-3);
    DoubleSpinBox->setMaximum(10);
    // DoubleSpinBox->setRange(-3, 10);
    DoubleSpinBox->setPrefix("$");
    DoubleSpinBox->setSuffix("c");
    DoubleSpinBox->setSingleStep(0.5);
    connect(DoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(doubleSpinBox_value_changed(double)));
    connect(DoubleSpinBox, SIGNAL(textChanged(QString)), this, SLOT(doubleSpinBox_text_changed(QString)));  // Qt >= 5.14

    // QFontComboBox Demo
    FontComboBox = new QFontComboBox(this);

    // QLCDNumber Demo
    LCDNumber = new QLCDNumber(this);

    // QLabel Demo
    Label = new QLabel(this);
    Label->setText("Hello");
    QFont labelFont = Label->font();
    labelFont.setPointSize(30);
    Label->setFont(labelFont);
    Label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    // QLineEdit Demo
    LineEdit = new QLineEdit(this);
    LineEdit->setMaxLength(14);
    LineEdit->setPlaceholderText("Enter your text");
    // LineEdit->setInputMask("000.000.000-00;_");
    // LineEdit->setReadOnly(true);
    connect(LineEdit, SIGNAL(returnPressed()), this, SLOT(lineEdit_pressed()));
    connect(LineEdit, SIGNAL(selectionChanged()), this, SLOT(lineEdit_selection_changed()));
    connect(LineEdit, SIGNAL(textChanged(QString)), this, SLOT(lineEdit_text_changed(QString)));
    connect(LineEdit, SIGNAL(textEdited(QString)), this, SLOT(lineEdit_text_edited(QString)));

    // QProgressBar Demo
    ProgressBar = new QProgressBar(this);

    // QPushButton Demo
    PushButton = new QPushButton(this);

    // QRadioButton Demo
    RadioButton = new QRadioButton(this);

    // QSlider Demo
    // Slider = new QSlider(Qt::Orientation::Vertical, this);   // Default
    Slider = new QSlider(Qt::Orientation::Horizontal, this);
    Slider->setMinimum(-3);
    Slider->setMaximum(30);
    // Slider->setRange(-3, 30);
    Slider->setSingleStep(3);
    connect(Slider, SIGNAL(valueChanged(int)), this, SLOT(slider_value_changed(int)));
    connect(Slider, SIGNAL(sliderMoved(int)), this, SLOT(slider_moved(int)));
    connect(Slider, SIGNAL(sliderPressed()), this, SLOT(slider_pressed()));
    connect(Slider, SIGNAL(sliderReleased()), this, SLOT(slider_released()));

    // QSpinBox Demo
    SpinBox = new QSpinBox(this);
    SpinBox->setMinimum(-3);
    SpinBox->setMaximum(10);
    // SpinBox->setRange(-3, 10);
    SpinBox->setPrefix("$");
    SpinBox->setSuffix("c");
    SpinBox->setSingleStep(1);
    connect(SpinBox, SIGNAL(valueChanged(int)), this, SLOT(spinBox_value_changed(int)));
    connect(SpinBox, SIGNAL(textChanged(QString)), this, SLOT(spinBox_text_changed(QString)));  // Qt >= 5.14

    // QTimeEdit Demo
    TimeEdit = new QTimeEdit(this);


    std::vector<QWidget*> widgets {
            CheckBox,
            ComboBox,
            DateEdit,
            DateTimeEdit,
            Dial,
            DoubleSpinBox,
            FontComboBox,
            LCDNumber,
            Label,
            LineEdit,
            ProgressBar,
            PushButton,
            RadioButton,
            Slider,
            SpinBox,
            TimeEdit,
    };

    for (QWidget* widget : widgets) {
        grid->addWidget(widget);
    }

    QWidget *container = new QWidget(this);
    container->setLayout(grid);

    setCentralWidget(container);

}

void WidgetDemo::checkbox_show_state(int state) {
    if (state == Qt::Unchecked) {
        std::cout << "Check Box State: Unchecked (" << state << ")" << std::endl;
    } else if (state == Qt::PartiallyChecked) {
        std::cout << "Check Box State: PartiallyChecked (" << state << ")" << std::endl;
    } else if (state == Qt::Checked) {
        std::cout << "Check Box State: Checked (" << state << ")" << std::endl;
    }
}

void WidgetDemo::combobox_index_changed(int index) {
    std::cout << "ComboBox index changed to " << index << std::endl;
}

void WidgetDemo::combobox_text_changed(QString text) {
    std::cout << "ComboBox text changed to " << text.toStdString() << std::endl;
}

void WidgetDemo::lineEdit_pressed() {
    std::cout << "LineEdit pressed" << std::endl;
    LineEdit->setText("BOOM!");
}

void WidgetDemo::lineEdit_selection_changed() {
    std::cout << "LineEdit selection changed" << std::endl;
}

void WidgetDemo::lineEdit_text_changed(QString text) {
    std::cout << "LineEdit text changed to: " << text.toStdString() << std::endl;
}

void WidgetDemo::lineEdit_text_edited(QString text) {
    std::cout << "LineEdit text edited to: " << text.toStdString() << std::endl;
}

void WidgetDemo::spinBox_value_changed(int value) {
    std::cout << "SpinBox value changed to: " << value << std::endl;
}

void WidgetDemo::spinBox_text_changed(QString text) {
    std::cout << "SpinBox text changed to: " << text.toStdString() << std::endl;
}

void WidgetDemo::doubleSpinBox_value_changed(double value) {
    std::cout << "DoubleSpinBox value changed to: " << value << std::endl;
}

void WidgetDemo::doubleSpinBox_text_changed(QString text) {
    std::cout << "DoubleSpinBox text changed to: " << text.toStdString() << std::endl;
}

void WidgetDemo::slider_value_changed(int value) {
    std::cout << "Slider value changed to: " << value << std::endl;
}

void WidgetDemo::slider_moved(int position) {
    std::cout << "Slider moved to:" << position << std::endl;
}

void WidgetDemo::slider_pressed() {
    std::cout << "Slider pressed" << std::endl;
}

void WidgetDemo::slider_released() {
    std::cout << "Slider released" << std::endl;
}

void WidgetDemo::dial_value_changed(int value) {
    std::cout << "Dial value changed to: " << value << std::endl;
}

void WidgetDemo::dial_moved(int position) {
    std::cout << "Dial moved to:" << position << std::endl;
}

void WidgetDemo::dial_pressed() {
    std::cout << "Dial pressed" << std::endl;
}

void WidgetDemo::dial_released() {
    std::cout << "Dial released" << std::endl;
}
