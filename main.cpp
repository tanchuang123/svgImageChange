#include "SvgChangeForm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SvgChangeForm w;
    w.show();

    return a.exec();
}
