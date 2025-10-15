#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QMessageBox>

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

void Widget::on_pushButtonWrite_clicked()
{
    // Save the file to disk
    QString filename = QFileDialog::getSaveFileName( this, "Save As" );

    if ( filename.isEmpty() ) {
        return;
    }

    QFile file( filename );

    // Open then file
    if ( !file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append ) ) {
        return;
    }

    QTextStream out( &file );
    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}

void Widget::on_pushButtonRead_clicked()
{
    QString fileContent;

    // Save the file to disk
    QString filename = QFileDialog::getOpenFileName( this, "Open File" );

    if ( filename.isEmpty() ) {
        return;
    }

    QFile file( filename );
    if ( !file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        return;
    }

    QTextStream in( &file );
    QString line = in.readLine();

    while ( !line.isNull() ) {
        fileContent.append( line );
        line = in.readLine();
    }

    file.close();

    ui->textEdit->clear();
    ui->textEdit->setPlainText( fileContent );
}


void Widget::on_pushButtonCopy_clicked()
{
    QString src_file_name = ui->lineEditSource->text();
    QString dest_file_name = ui->lineEditDestination->text();

    if ( src_file_name.isEmpty() || dest_file_name.isEmpty() ) {
        return;
    }

    QFile file( src_file_name );

    if ( file.copy( dest_file_name ) ) {
        QMessageBox::information( this, "Success", "Copy successful" );
    }
    else {
        QMessageBox::information( this, "Failure", "Copy Failed!" );
    }

    file.close();
}


void Widget::on_pushButtonSelectFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName( this, "Choose File" );

    if ( filename.isEmpty() ) {
        return;
    }

    ui->lineEditSource->setText( filename );
}

