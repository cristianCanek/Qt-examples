#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
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

void Widget::on_choosePushButton_clicked()
{
    // Get existing directory
    //QString dir = QFileDialog::getExistingDirectory( this, "Open Directory", QString(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );

    //if ( !dir.isEmpty() ) {
        //qDebug() << "Your chosen dir is: " << dir;
    //}
    //else {
        //qDebug() << "You didn't choose anything...";
    //}

    // Get a filename
    //QString filename = QFileDialog::getOpenFileName( this, QString(), QString(), "Images (*.png *.xpm *.jpg)" );

    //if ( !filename.isEmpty() ) {
        //qDebug() << "Your chosen file is: " << filename;
    //}
    //else {
        //qDebug() << "You didn't choose anything...";
    //}

    // Get a list of files
    //QStringList files = QFileDialog::getOpenFileNames( this, QString(), QString(), "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)" );

    //if ( !files.isEmpty() ) {
        //qDebug() << "Your chosen files are: ";
        //for ( auto f: files ) {
            //qDebug() << "- " << f;
        //}

        //qDebug() << "Your chosen files are: " << files;
    //}
    //else {
        //qDebug() << "You didn't choose anything...";
    //}

    // Get a name to save a file
    QString filename = QFileDialog::getSaveFileName( this, QString(), QString(), "Images (*.png *.xpm *.jpg)" );

    if ( !filename.isEmpty() ) {
        qDebug() << "Your chosen file is: " << filename;
    }
    else {
        qDebug() << "You didn't choose anything...";
    }
}

