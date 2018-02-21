#include "mainwindow.h"
#include <QApplication>
#include "SOIL.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    SOIL_last_result();

    return a.exec();
}
