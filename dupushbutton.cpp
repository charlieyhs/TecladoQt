#include "dupushbutton.h"


DuPushButton::DuPushButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, &DuPushButton::clicked, [&](){
       emit keyPressed(this) ;
    });
}
