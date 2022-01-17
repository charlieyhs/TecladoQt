#ifndef DUKEYBOARDFORM_H
#define DUKEYBOARDFORM_H

#include <QWidget>

namespace Ui {
class DuKeyboardForm;
}

class QHBoxLayout;

class DuKeyboardForm : public QWidget
{
    Q_OBJECT

public:
    explicit DuKeyboardForm(QWidget *parent = nullptr);
    ~DuKeyboardForm();
signals:
    void keyPressed(const QString &);
private:
    QHBoxLayout *loadKeys(char x, char y);
    Ui::DuKeyboardForm *ui;
};

#endif // DUKEYBOARDFORM_H
