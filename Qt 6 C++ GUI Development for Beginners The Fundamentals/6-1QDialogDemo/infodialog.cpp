#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okPushButton_clicked()
{
    QString user_position = ui->positionLineEdit->text();

    if ( !user_position.isEmpty() ) {
        m_position = user_position;

        if ( ui->windowsRadioButton->isChecked() ) {
            m_favorite_os = "Windows";
        }

        if ( ui->linuxRadioButton->isChecked() ) {
            m_favorite_os = "Linux";
        }

        if ( ui->macRadioButton->isChecked() ) {
            m_favorite_os = "Mac";
        }

        // Accept the dialog
        accept();
    }
    else {
        reject();
    }
}


void InfoDialog::on_cancelPushButton_clicked()
{
    // Reject dialog
    reject();
}

const QString &InfoDialog::getPosition() const
{
    return m_position;
}

const QString &InfoDialog::getFavoriteOS() const
{
    return m_favorite_os;
}

