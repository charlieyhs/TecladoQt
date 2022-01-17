#ifndef DUPUSHBUTTON_H
#define DUPUSHBUTTON_H

#include <QPushButton>

class DuPushButton : public QPushButton
{
    Q_OBJECT
public:
    DuPushButton(QWidget *parent = nullptr);
signals:
    void keyPressed(DuPushButton *);
};

#endif // DUPUSHBUTTON_H
