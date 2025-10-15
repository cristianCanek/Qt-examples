#include "widget.h"
#include "ui_widget.h"

#include <QSettings>
#include <QPushButton>
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Initialize colors list

    for( int i = 0; i < 9; i++ )
    {
        m_color_list.append( Qt::black );
    }

    on_pushButtonLoadSettings_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonOne_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 0 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 0 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonOne->setStyleSheet( css );
    }
}


void Widget::on_pushButtonTwo_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 1 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 1 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonTwo->setStyleSheet( css );
    }
}


void Widget::on_pushButtonThree_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 2 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 2 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonThree->setStyleSheet( css );
    }
}


void Widget::on_pushButtonFour_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 3 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 3 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonFour->setStyleSheet( css );
    }
}


void Widget::on_pushButtonFive_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 4 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 4 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonFive->setStyleSheet( css );
    }
}


void Widget::on_pushButtonSix_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 5 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 5 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonSix->setStyleSheet( css );
    }
}


void Widget::on_pushButtonSeven_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 6 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 6 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonSeven->setStyleSheet( css );
    }
}


void Widget::on_pushButtonEight_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 7 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 7 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonEight->setStyleSheet( css );
    }
}


void Widget::on_pushButtonNine_clicked()
{
    QColor color = QColorDialog::getColor( m_color_list[ 8 ], this, "Choose Background Color" );

    if( color.isValid() ) {
        // Save the color in the list in memory
        m_color_list[ 8 ] = color;

        // Set background color to the button
        QString css = QString( "background-color : %1" ).arg( color.name() );
        ui->pushButtonNine->setStyleSheet( css );
    }
}


void Widget::on_pushButtonSaveSettings_clicked()
{
    save_color( "button1", m_color_list[ 0 ] );
    save_color( "button2", m_color_list[ 1 ] );
    save_color( "button3", m_color_list[ 2 ] );
    save_color( "button4", m_color_list[ 3 ] );
    save_color( "button5", m_color_list[ 4 ] );
    save_color( "button6", m_color_list[ 5 ] );
    save_color( "button7", m_color_list[ 6 ] );
    save_color( "button8", m_color_list[ 7 ] );
    save_color( "button9", m_color_list[ 8 ] );
}


void Widget::on_pushButtonLoadSettings_clicked()
{
    set_loaded_color( "button1", 0, ui->pushButtonOne   );
    set_loaded_color( "button2", 1, ui->pushButtonTwo   );
    set_loaded_color( "button3", 2, ui->pushButtonThree );
    set_loaded_color( "button4", 3, ui->pushButtonFour  );
    set_loaded_color( "button5", 4, ui->pushButtonFive  );
    set_loaded_color( "button6", 5, ui->pushButtonSix   );
    set_loaded_color( "button7", 6, ui->pushButtonSeven );
    set_loaded_color( "button8", 7, ui->pushButtonEight );
    set_loaded_color( "button9", 8, ui->pushButtonNine  );
}

void Widget::save_color( QString key, QColor color )
{
    int red   = color.red();
    int green = color.green();
    int blue  = color.blue();

    QSettings settings( "Blikoon", "SettingsDemo" );

    settings.beginGroup( "ButtonColor" );

    settings.setValue( key + "r", red   );
    settings.setValue( key + "g", green );
    settings.setValue( key + "b", blue  );

    settings.endGroup();
}

QColor Widget::load_color( QString key )
{
    int red;
    int green;
    int blue;

    QSettings settings( "Blikoon", "SettingsDemo" );

    settings.beginGroup( "ButtonColor" );

    red   = settings.value( key + "r", QVariant( 0 ) ).toInt();
    green = settings.value( key + "g", QVariant( 0 ) ).toInt();
    blue  = settings.value( key + "b", QVariant( 0 ) ).toInt();

    settings.endGroup();

    return QColor( red, green, blue );
}

void Widget::set_loaded_color( QString key, int index, QPushButton * button )
{
    QColor color = load_color( key );
    m_color_list[ index ] = color;
    QString css = QString( "background-color : %1" ).arg( color.name() );
    button->setStyleSheet( css );
}
