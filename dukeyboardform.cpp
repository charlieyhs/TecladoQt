#include "dukeyboardform.h"
#include "ui_dukeyboardform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "dupushbutton.h"

DuKeyboardForm::DuKeyboardForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DuKeyboardForm)
{
    ui->setupUi(this);
    auto vbox = new QVBoxLayout;
    vbox->addLayout(loadKeys('A','M'));
    vbox->addLayout(loadKeys('N','Z'));
    setLayout(vbox);

}

DuKeyboardForm::~DuKeyboardForm()
{
    delete ui;
}

QHBoxLayout *DuKeyboardForm::loadKeys(char x, char y)
{
    auto hbox = new QHBoxLayout;
    for(char ix = x; ix <=y; ix++){
        auto key = new DuPushButton(this);
        key->setText(QString("%1").arg(ix));
        hbox->addWidget(key);

        connect(key, &DuPushButton::keyPressed, [&](DuPushButton *key){
           emit keyPressed(key->text());
        });

    }
    return hbox;
}
