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
    int pole[9];
    int minmax (int);
    bool wygrana();
    bool remis();
    public:
        Ruch usermove (int);  //zwraca ruch lub powiadomienie o zakonczeniu gry
        Engine() { pole[9] = { 0,0,0,0,0,0,0,0,0 }; } //czy potrzebne? powinno sie samo wypelnic zerami
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

bool Engine::wygrana()
{
    bool result = false;
    for (int i = 1; i<=7; i+=3)
    {
        if ((pole[i-1] == pole[i]) && (pole[i] == pole[i+1]))
            result = true;
    }
    for (int i = 1; i<=3; i++)
    {
        if ((pole[i-1] == pole[i]) && (pole[i] == pole[i+1]))
            result = true;
    }
    if ((pole[0] == pole[4]) && (pole[4] == pole[8]))
        result = true;
    if ((pole[2] == pole[4]) && (pole[4] == pole[6]))
        result = true;
    return result;
}

bool Engine::remis()
{
    for (int i = 0; i<9; i++)
    {
        if (pole[i] == 0)
            return false;
    }
    return true;
}

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

void Plansza::oznacz2()
{
    pb2->setText("X");
    pb2->setEnabled(false);
    react(2);
}

void Plansza::oznacz3()
{
    pb3->setText("X");
    pb3->setEnabled(false);
    react(3);
}

void Plansza::oznacz4()
{
    pb4->setText("X");
    pb4->setEnabled(false);
    react(4);
}

void Plansza::oznacz5()
{
    pb5->setText("X");
    pb5->setEnabled(false);
    react(5);
}

void Plansza::oznacz6()
{
    pb6->setText("X");
    pb6->setEnabled(false);
    react(6);
}

void Plansza::oznacz7()
{
    pb7->setText("X");
    pb7->setEnabled(false);
    react(7);
}

void Plansza::oznacz8()
{
    pb8->setText("X");
    pb8->setEnabled(false);
    react(8);
}

void Plansza::oznacz9()
{
    pb9->setText("X");
    pb9->setEnabled(false);
    react(9);
}

void Plansza::react(int liczba)
{
    Ruch result;
    result = usermove(liczba);
    if (result.czy_wyg())
    {
        //wypisz w msgbox że wygralismy, app.exec
    }
    if (result.czy_rem())
    {
        //jak wyzej
    }
    if (result.ruch)
    {
        //case biorący odpowiedni przycisk, wpisujący tam O i robiący setDisabled
    }
}

#endif