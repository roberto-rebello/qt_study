#include "dialog_demo.hpp"
#include "custom_dialog.hpp"

#include <iostream>
#include <unistd.h>

#include <QVBoxLayout>

#include <QPushButton>
#include <QDialog>
#include <QMessageBox>

#include <QFontDialog>
// #include <QPrintDialog>
#include <QProgressDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QFileDialog>

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

    QPushButton *dialog = new QPushButton("Ready QDialog Demo");
    connect(dialog, SIGNAL(pressed()), this, SLOT(qdialog_button_pressed()));
    layout->addWidget(dialog);
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

    QMessageBox::about(this, "About MessageBox", "This is an example of a default 'About' MessageBox");

    QMessageBox::critical(this, "Critical MessageBox", "This is an example of a default 'Critical' MessageBox");

    QMessageBox::information(this, "Information MessageBox", "This is an example of a default 'Information' MessageBox");

    QMessageBox::question(this, "Question MessageBox", "This is an example of a default 'Question' MessageBox");

    QMessageBox::warning(this, "Warning MessageBox", "This is an example of a default 'Warning' MessageBox");

    QMessageBox::aboutQt(this, "AboutQt MessageBox");
}

void DialogDemo::qdialog_button_pressed()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);

    // QPrintDialog printer(this);

    // QProgressDialog *pb = new QProgressDialog("Progressbar example", "Cancel", 0, 100, this);
    // for (uint8_t step = 0; step <= 100; step++)
    // {
    //     pb->setValue(step);
    //     usleep(250000);
    // }

    QColorDialog *color = new QColorDialog(this);
    color->exec();

    QFileDialog *file = new QFileDialog(this);
    file->exec();

    QInputDialog::getInt(this, "QInputDialog::getInt()", "Get Int");
    QInputDialog::getDouble(this, "QInputDialog::getDouble()", "Get Double");
    QInputDialog::getItem(this, "QInputDialog::getItem()", "Get Item", QStringList({"Option 1", "Option 2", "Option 3", "Option 4"}));
    QInputDialog::getText(this, "QInputDialog::getText()", "Get Text");
    QInputDialog::getMultiLineText(this, "QInputDialog::getMultiLineText()", "Get MultiLineText");
}