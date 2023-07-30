#include "sosGUI.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sosGUI sosGUImain;
    sosGUImain.show();
    return a.exec();
}
