#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->setSelectionMode( QAbstractItemView::MultiSelection );

    ui->listWidget->addItem( "Item 1" );
    ui->listWidget->addItem( "Item 2" );

    QStringList listData;
    listData << "Item 3" << "Item 4" << "Item 5";
    ui->listWidget->addItems( listData );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addButton_clicked() {
    ui->listWidget->addItem( "Item added by clicking the button" );
}


void Widget::on_removeButton_clicked() {
    ui->listWidget->takeItem( ui->listWidget->currentRow() );
}


void Widget::on_selectButton_clicked() {
    // Get the list of selected items
    QList<QListWidgetItem *> list = ui->listWidget->selectedItems();

    for ( int i = 0; i < list.count(); i++ ) {
        qDebug() << "Selected item: " << list.at( i )->text() << ", row number id: " << ui->listWidget->row( list.at( i ) );
    }
}

