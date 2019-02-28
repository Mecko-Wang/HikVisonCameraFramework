#ifndef DIALOGPROGRESS_H
#define DIALOGPROGRESS_H

#include <QDialog>

namespace Ui {
class DialogProgress;
}

class DialogProgress : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProgress(QWidget *parent = 0);
    ~DialogProgress();

private:
    Ui::DialogProgress *ui;
};

#endif // DIALOGPROGRESS_H
