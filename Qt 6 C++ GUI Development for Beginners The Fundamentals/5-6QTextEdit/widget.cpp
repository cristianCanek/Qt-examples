#include "widget.h"
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    setFixedSize( 400, 400 );
}

Widget::~Widget() {}

void Widget::setupUI() {
    QFont labelFont( "Times", 10, QFont::Bold );
    QLabel *mLabel = new QLabel( "This is my text", this );
    mLabel->setFont( labelFont );
    mLabel->move( 100, 25 );

    QTextEdit *textEdit = new QTextEdit( this );
    textEdit->move( 70, 55 );

    // Text changed
    connect( textEdit, &QTextEdit::textChanged, [=](){
        qDebug() << "Text changed!";
    });

    // Copy
    QPushButton *copyButton = new QPushButton( "Copy", this );
    copyButton->setMinimumSize( 50, 25 );
    copyButton->move( 10, 250 );

    connect( copyButton, &QPushButton::clicked, [=](){
        textEdit->copy();
    });

    // Cut
    QPushButton *cutButton = new QPushButton( "Cut", this );
    cutButton->setMinimumSize( 50, 25 );
    cutButton->move( 110, 250 );

    connect( cutButton, &QPushButton::clicked, [=](){
        textEdit->cut();
    });

    // Paste
    QPushButton *pasteButton = new QPushButton( "Paste", this );
    pasteButton->setMinimumSize( 50, 25 );
    pasteButton->move( 210, 250 );

    connect( pasteButton, &QPushButton::clicked, [=](){
        textEdit->paste();
    });

    // Undo
    QPushButton *undoButton = new QPushButton( "Undo", this );
    undoButton->setMinimumSize( 50, 25 );
    undoButton->move( 10, 280 );

    connect( undoButton, &QPushButton::clicked, [=](){
        textEdit->undo();
    });

    // Redo
    QPushButton *redoButton = new QPushButton( "Redo", this );
    redoButton->setMinimumSize( 50, 25 );
    redoButton->move( 110, 280 );

    connect( redoButton, &QPushButton::clicked, [=](){
        textEdit->redo();
    });

    // Set plain text to the text edit
    QPushButton *plaintTextButton = new QPushButton( "Plain text", this );
    plaintTextButton->setMinimumSize( 100, 25 );
    plaintTextButton->move( 10, 310 );

    connect( plaintTextButton, &QPushButton::clicked, [=](){
        textEdit->setPlainText( "This is plain text" );
    });

    // Set html text to the text edit
    QPushButton *htmlButton = new QPushButton( "HTML", this );
    htmlButton->setMinimumSize( 100, 25 );
    htmlButton->move( 120, 310 );

    connect( htmlButton, &QPushButton::clicked, [=](){
        textEdit->setHtml( "<h1> This is HTML text </h1>" );
    });

    // Grab plain text from the text edit
    QPushButton *grabTextButton = new QPushButton( "Grab text", this );
    grabTextButton->setMinimumSize( 100, 25 );
    grabTextButton->move( 10, 340 );

    connect( grabTextButton, &QPushButton::clicked, [=](){
        qDebug() << "This is the plain text from the text edit: " << textEdit->toPlainText();
    });

    // Grab html text from the text edit
    QPushButton *grabHtmlButton = new QPushButton( "Grab HTML", this );
    grabHtmlButton->setMinimumSize( 100, 25 );
    grabHtmlButton->move( 120, 340 );

    connect( grabHtmlButton, &QPushButton::clicked, [=](){
        qDebug() << "This is the HTML text from the text edit: " << textEdit->toHtml();
    });
}
