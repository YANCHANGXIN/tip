#include "mainwindow.h"
#include <QTextCodec>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.setWindowTitle("文本优化工具");
    w.show();
    return a.exec();
}
