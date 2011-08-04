#include <QtDebug>
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << "argc is " << argc;
    argc=argc-2;
    int tabnumber=1;
    while (argc>0)
    {
        qDebug() << "argc is " << argc;
        w.addTab(QString(argv[tabnumber++]));
        argc--;
    }
    w.show();

    return a.exec();
}
