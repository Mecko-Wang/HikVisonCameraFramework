#include "mainwindow.h"
#include "dialogprogress.h"
#include <QApplication>
#include <QSharedMemory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedMemory shared("Motor.exe");
    if(shared.attach())
        return 0;
    shared.create(1);
    DialogProgress *progDial = new DialogProgress;
    progDial->show();
    QCoreApplication::processEvents();

    MainWindow w;
    w.setWindowIcon(QIcon("pic.ico"));
    w.initWork();
    w.show();

    delete progDial;
    progDial = NULL;

    return a.exec();
}
