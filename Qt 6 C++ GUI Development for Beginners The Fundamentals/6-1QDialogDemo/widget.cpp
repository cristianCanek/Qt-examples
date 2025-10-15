#include "widget.h"
#include "ui_widget.h"
#include "infodialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_provideInfoButton_clicked()
{
    InfoDialog *dialog = new InfoDialog( this );

    // Call the dialog to be shown in MODAL mode
    // This method blocks the parent to be modified/clickable
    //auto ret = dialog->exec();

    //if ( ret == QDialog::Accepted ) {
        //QString position = dialog->getPosition();
        //QString os = dialog->getFavoriteOS();

        //qDebug() << "Dialog accepted, position is: " << position << " and favorite OS is: " << os;
        //ui->infoLabel->setText( "Your position is: " + position + " and your favorite os is: " + os );
    //}
    //else {
        //ui->infoLabel->setText( "Dialog rejected!" );
    //}

    // Call the dialog to be shown in NON MODAL mode

    connect( dialog, &InfoDialog::accepted, [=](){
        QString position = dialog->getPosition();
        QString os = dialog->getFavoriteOS();

        qDebug() << "Dialog accepted, position is: " << position << " and favorite OS is: " << os;
        ui->infoLabel->setText( "Your position is: " + position + " and your favorite os is: " + os );
    });

    connect( dialog, &InfoDialog::rejected, [=](){
        ui->infoLabel->setText( "Dialog rejected!" );
    });

    // This method DOES NOT block the parent to be modified/clickable
    dialog->show();

    dialog->raise(); // Put the dialog on top
    dialog->activateWindow(); // Give the focus to the dialog window

}

