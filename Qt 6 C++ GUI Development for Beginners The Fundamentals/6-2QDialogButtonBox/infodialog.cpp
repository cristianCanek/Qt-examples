#include "infodialog.h"
#include "ui_infodialog.h"

#include <QAbstractButton>
#include <QDebug>

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

const QString &InfoDialog::getPosition() const
{
    return m_position;
}

const QString &InfoDialog::getFavoriteOS() const
{
    return m_favorite_os;
}


void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton( button );

    if ( stdButton == QDialogButtonBox::Ok ) {
        accept();
        qDebug() << "OK button clicked!";
    }

    if ( stdButton == QDialogButtonBox::Save ) {
        qDebug() << "SAVE button clicked!";
    }

    if ( stdButton == QDialogButtonBox::SaveAll ) {
        qDebug() << "SAVE ALL button clicked!";
    }

    if ( stdButton == QDialogButtonBox::Open ) {
        qDebug() << "OPEN button clicked!";
    }

    if ( stdButton == QDialogButtonBox::Cancel ) {
        reject();
        qDebug() << "CANCEL button clicked!";
    }
}

