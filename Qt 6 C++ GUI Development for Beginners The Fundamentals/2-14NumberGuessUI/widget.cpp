#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Set up the seed
    std::srand( std::time( nullptr ) );

    // Generate ( 1 - 10 )
    secret_number = std::rand() % 10 + 1;

    // Disable the Start Over button
    ui->startOverButton->setDisabled( true );

    // Clear the text label
    ui->messageLabel->setText( "" );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    guess_number = ui->numberSpinBox->value();

    qDebug() << "User guessed> " << QString::number( guess_number );

    // Check if the user guessed right
    if ( guess_number == secret_number ) {
        ui->messageLabel->setText( "Congratulations! The number is: " + QString::number( guess_number ) );

        // Button housekeeping
        ui->guessButton->setDisabled( true );
        ui->startOverButton->setDisabled( false );
    }
    else {
        if ( secret_number < guess_number ) {
            ui->messageLabel->setText( "The number is lower than that!" );
        }
        if ( secret_number > guess_number ) {
            ui->messageLabel->setText( "The number is higher than that!" );
        }
    }
}

void Widget::on_startOverButton_clicked()
{
    // Enable the Guess button
    ui->guessButton->setDisabled( false );

    // Disable the Start Over button
    ui->startOverButton->setDisabled( true );

    // Put the spinbox back to 1
    ui->numberSpinBox->setValue( 1 );

    // Regenerate the random number
    secret_number = std::rand() % 10 + 1;

    // Clear the message label
    ui->messageLabel->setText( "" );
}

