#include "custom_dialog.hpp"

#include <QVBoxLayout>
#include <QLabel>

CustomDialog::CustomDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Custom Dialog");

    QDialogButtonBox::StandardButtons btns = QDialogButtonBox::Cancel | QDialogButtonBox::Ok;

    m_buttonBox = new QDialogButtonBox(btns, this);
    connect(m_buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(m_buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QLabel *label = new QLabel("Something happend, is that OK?");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(m_buttonBox);

    setLayout(layout);
}