#ifndef PLANSZA_H
#define PLANSZA_H

#include <QDialog>
#include <QMessageBox>
#include <QtGui>

#include "ui_plansza.h"


struct Ruch
{
    int ruch;
    bool czy_wyg() { if (ruch == 10) return true; }
    bool czy_prz() { if (ruch == 20) return true; }
    bool czy_rem() { if (ruch == 30) return true; }
};

class Engine
{
    int Plansza[9];
    int minmax (int);
    public:
        Ruch usermove (int);  //zwraca ruch lub powiadomienie o zakonczeniu gry
};

class Plansza : public QDialog, public Ui_Plansza
{
    Q_OBJECT
    private:
        QMessageBox *msgbox;
        Engine silnik;
        void react(int);  //które pole od 1 do 9 sie zmienilo
    public:
        Plansza(QWidget *parent = 0);
    private slots:
        void oznacz1();  //1. ustaw napis; 2. set disabled; 3. react(int);
        void oznacz2();
        void oznacz3();
        void oznacz4();
        void oznacz5();
        void oznacz6();
        void oznacz7();
        void oznacz8();
        void oznacz9();
};

Plansza::Plansza (QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    connect(pb1, SIGNAL(clicked()), this, SLOT(oznacz1()));
    connect(pb2, SIGNAL(clicked()), this, SLOT(oznacz2()));
    connect(pb3, SIGNAL(clicked()), this, SLOT(oznacz3()));
    connect(pb4, SIGNAL(clicked()), this, SLOT(oznacz4()));
    connect(pb5, SIGNAL(clicked()), this, SLOT(oznacz5()));
    connect(pb6, SIGNAL(clicked()), this, SLOT(oznacz6()));
    connect(pb7, SIGNAL(clicked()), this, SLOT(oznacz7()));
    connect(pb8, SIGNAL(clicked()), this, SLOT(oznacz8()));
    connect(pb9, SIGNAL(clicked()), this, SLOT(oznacz9()));
}

void Plansza::oznacz1()
{
    pb1->setText("X");
    pb1->setEnabled(false);
    react(1);
}

#endif