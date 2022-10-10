#include <QDialog>

#include <QDialogButtonBox>

class CustomDialog : public QDialog
{

    Q_OBJECT

public:
    CustomDialog(QWidget *parent = nullptr);

private:
    QDialogButtonBox *m_buttonBox;
};