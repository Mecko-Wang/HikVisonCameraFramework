#include "dialogprogress.h"
#include "ui_dialogprogress.h"

DialogProgress::DialogProgress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProgress)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

DialogProgress::~DialogProgress()
{
    delete ui;
}
