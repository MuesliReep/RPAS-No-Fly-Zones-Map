#include <QCoreApplication>

#include "program.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Program p;

    return a.exec();
}
