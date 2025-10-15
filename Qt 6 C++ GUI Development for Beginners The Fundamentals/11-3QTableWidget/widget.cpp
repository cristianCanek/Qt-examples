#include "widget.h"
#include "ui_widget.h"

#include <QTableWidget>

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

void Widget::on_pushButtonListItems_clicked()
{
    for ( size_t i{}; i< ui->tableWidget->rowCount(); i++ ) {
        for ( size_t j{}; j < ui->tableWidget->columnCount(); j++ ) {
            // Attention: If you call item() on a pair of indexes where no item has been set, you get
            //            nullptr. Hence the if check below.
            //            See documentation for QTableWidget::item()

            auto item_ptr = ui->tableWidget->item( i, j );

            if ( item_ptr ) {
                QVariant data = item_ptr->data( Qt::DisplayRole );
                qDebug() << data.toString();
            }
            else {
                qDebug() << "No data!";
            }
        }
    }
}


void Widget::on_pushButtonSetItems_clicked()
{
    // Expand tableWidget to create a new row/column
    ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
    ui->tableWidget->insertColumn( ui->tableWidget->columnCount() );

    // Add the item in the tableWidget
    QTableWidgetItem * newItem = new QTableWidgetItem( "I'm a new item" );
    ui->tableWidget->setItem( ui->tableWidget->rowCount() - 1, ui->tableWidget->columnCount() - 1, newItem );
}
