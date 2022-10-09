#include "dialog_demo.hpp"
#include "custom_dialog.hpp"

#include <iostream>

#include <QVBoxLayout>

#include <QPushButton>
#include <QDialog>
#include <QMessageBox>

DialogDemo::DialogDemo(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Dialog Demo");

    QVBoxLayout *layout = new QVBoxLayout();

    QWidget *container = new QWidget(this);
    container->setLayout(layout);
    setCentralWidget(container);

    QPushButton *basic = new QPushButton("Basic dialog");
    connect(basic, SIGNAL(pressed()), this, SLOT(basic_button_pressed()));
    layout->addWidget(basic);

    QPushButton *custom = new QPushButton("Custom dialog");
    connect(custom, SIGNAL(pressed()), this, SLOT(custom_button_pressed()));
    layout->addWidget(custom);

    QPushButton *message = new QPushButton("Message dialog");
    connect(message, SIGNAL(pressed()), this, SLOT(message_button_pressed()));
    layout->addWidget(message);

    QPushButton *default_btn = new QPushButton("MessageBox Demo");
    connect(default_btn, SIGNAL(pressed()), this, SLOT(default_button_pressed()));
    layout->addWidget(default_btn);
}

void DialogDemo::basic_button_pressed()
{
    std::cout << "BasicButton pressed" << std::endl;

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Dialog Window");
    dialog->exec();
}

void DialogDemo::custom_button_pressed()
{
    std::cout << "CustomButton pressed" << std::endl;

    CustomDialog *customDialog = new CustomDialog(this);
    if (customDialog->exec())
    {
        std::cout << "Sucess!" << std::endl;
    }
    else
    {
        std::cout << "Cancel!" << std::endl;
    }
}

void DialogDemo::message_button_pressed()
{
    std::cout << "MessageButton pressed" << std::endl;

    QMessageBox *message = new QMessageBox(this);
    message->setWindowTitle("I have a question!");
    message->setText("Is this a simple dialog?");
    message->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    message->setIcon(QMessageBox::Icon::Question);
    if (message->exec() == QMessageBox::Ok)
    {
        std::cout << "Message OK!" << std::endl;
    }
}

void DialogDemo::default_button_pressed()
{
    std::cout << "DefaultButton pressed" << std::endl;

    QMessageBox *about = new QMessageBox(this);
    about->about(this, "About MessageBox", "This is an example of a default 'About' MessageBox");

    QMessageBox *critical = new QMessageBox(this);
    critical->critical(this, "Critical MessageBox", "This is an example of a default 'Critical' MessageBox");

    QMessageBox *information = new QMessageBox(this);
    information->information(this, "Information MessageBox", "This is an example of a default 'Information' MessageBox");

    QMessageBox *question = new QMessageBox(this);
    question->question(this, "Question MessageBox", "This is an example of a default 'Question' MessageBox");

    QMessageBox *warning = new QMessageBox(this);
    warning->warning(this, "Warning MessageBox", "This is an example of a default 'Warning' MessageBox");

    QMessageBox *aboutQt = new QMessageBox(this);
    aboutQt->aboutQt(this, "AboutQt MessageBox");
}