#include "widget.h"
#include "ui_widget.h"
#include "dukeyboardform.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mKeyboard = new DuKeyboardForm(this);

    ui->lineEdit->setClearButtonEnabled(true);
    ui->scrollArea->setWidget(mKeyboard);

    connect(mKeyboard, &DuKeyboardForm::keyPressed,[&](const QString &key){
       const int pos = ui->lineEdit->cursorPosition();
       auto text = ui->lineEdit->text();
       text.insert(pos, key);
       ui->lineEdit->setText(text);
       ui->lineEdit->setCursorPosition(pos + 1);
    });
}

Widget::~Widget()
{
    delete ui;
}

