#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSettings>
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "glog/logging.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void writeParam();

private slots:
    void on_pb_save_param_clicked();
    void dispParam();

    void on_pb_clear_pic_clicked();

private:
    Ui::Dialog *ui;

signals:
    void clearHistoryPicture();
    void updateParam();
};

#endif // DIALOG_H
