#ifndef PLANSZA_H
#define PLANSZA_H

#include <QDialog>
#include <QMessageBox>
#include <QtGui>

#include "ui_plansza.h"


struct Ruch
{
    int ruch;
    bool czy_wyg() { return (ruch == 10 || ruch == -10); }
    bool czy_rem() { return ruch==20; }
    inline Ruch(int r) : ruch(r) {}
    inline operator int() const { return ruch; }
};

class Engine
{
    char pole[9];
    char compsymbol; //na razie kółko, póki nie napiszemy buttona przekazujacego te informacje
    char usersymbol; //na razie krzyzyk, poki nie bedzie buttona do wyboru symbolu
    int minmax (char);
    int wygrana();
    bool remis();
    public:
        Ruch usermove (int);  //zwraca ruch lub powiadomienie o zakonczeniu gry
        Engine() { for (int i=0; i<9; i++) pole[i]=' '; compsymbol = 'O'; }
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

#endif
