#include <QApplication>
#include <QDialog>

#include "new_version.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    Plansza *gra = new Plansza;
    gra->show();
    return app.exec();
}