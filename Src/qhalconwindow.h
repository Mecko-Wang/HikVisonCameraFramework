#ifndef QHALCONWINDOW_H
#define QHALCONWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QScopedPointer>
#include <QMutex>

#include <HalconCpp.h>
using namespace HalconCpp;

//const int ImageHeight = 2056;
//const int ImageWidth  = 2464;


class QHalconWindow: public QWidget
{
    Q_OBJECT
public:
    QHalconWindow(QWidget *parent=NULL, long Width=100, long Height=100, long PartRow2=100, long PartCol2=100);

    HalconCpp::HWindow* GetHalconBuffer(void);


protected:
    void resizeEvent(QResizeEvent*event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    void GetPartFloat(double *row1, double *col1, double *row2, double *col2);
    void SetPartFloat(double row1, double col1, double row2, double col2);

    QWidget *initParent;
    QScopedPointer<HalconCpp::HWindow> halconBuffer;
    QPoint lastMousePos;
    double lastRow1, lastCol1, lastRow2, lastCol2;
    Hlong  row1, col1, row2, col2;

    int ImageHeight;
    int ImageWidth;
};

#endif // QHALCONWINDOW_H
