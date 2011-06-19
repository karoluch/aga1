#include <algorithm>
#include "new_version.h"
#include <algorithm>

using namespace std;

/* 1: wygrywa komputer
   -1: wygrywa gracz */
int Engine::wygrana()
{
    int result = 0;
    for (int i = 1; i<=7; i+=3)
    {
        if ((pole[i-1] == pole[i]) && (pole[i] == pole[i+1]) && pole[i]!=' ')
            pole[i] == compsymbol ? result = 1 : result = -1;
            //pole[i] == 'O' ? result = 1 : result = -1;
    }
    for (int i = 1; i<=3; i++)
    {
        if ((pole[i-1] == pole[i+2]) && (pole[i+2] == pole[i+5]) && pole[i-1]!=' ')
            //pole[i] == 'O' ? result = 1 : result = -1;
            pole[i-1] == compsymbol ? result = 1 : result = -1;
    }
    if ((pole[0] == pole[4]) && (pole[4] == pole[8]) && pole[4]!=' ')
        // pole[4] == 'O' ? result = 1 : result = -1;
        pole[4] == compsymbol ? result = 1 : result = -1;
    if ((pole[2] == pole[4]) && (pole[4] == pole[6]) && pole[4]!=' ')
        // pole[4] == 'O' ? result = 1 : result = -1;
        pole[4] == compsymbol ? result = 1 : result = -1;
    return result;
}

bool Engine::remis()
{
    for (int i = 0; i<9; i++)
    {
        if (pole[i] == ' ')
            return false;
    }
    return true;
}

/* minmax symbol zwraca wartość najlepszego ruchu po postawieniu symbolu 'symbol'
    (najlepszy w rozumieniu gracza, który się teraz rusza) */
int Engine::minmax(char symbol)
{
    int wyg = wygrana();
    if (wyg) return wyg;
    if (remis()) return 0;
    //int mmx = (symbol == compsymbol ? -1 : 1);
    int mmx = (symbol == 'O' ? -1 : 1);
    for (int i=0; i<9; i++) if (pole[i] == ' ') {
        pole[i] = symbol;
        int m = minmax(symbol == 'X' ? 'O' : 'X');
        pole[i] = ' ';

        if (symbol == compsymbol)
            mmx = std::max(mmx, m);
        else
            mmx = std::min(mmx, m);
    }
    return mmx;
}

Ruch Engine::usermove(int liczba)
{
    pole[liczba-1] = 'X';
    Ruch result;
    if(wygrana() == 1)
    {
        result.ruch = 50;
        return result;
    }
    if(wygrana() == -1)
    {
        result.ruch = -50;
        return result;
    }
    if(remis())
    {
        result.ruch = 20;
        return result;
    }
    int mmx = -1, move = -1;
    for(int i = 0; i < 9; i++) if(pole[i] == ' ')
    {
        pole[i] = compsymbol;
        int m = minmax(usersymbol);
        pole[i] = ' ';
        if(m > mmx)
        {
            mmx = m;
            move = i;
        }
    }
    pole[move] = compsymbol;
    result.ruch = move+1;
    return result;
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

/*
#define DEFOZNACZ(funkcja,slot,numer) \
void Plansza::funkcja() { \
    slot->setText("X"); \
    slot->setEnabled(false); \
    react(numer); \
}
DEFOZNACZ(oznacz1,pb1,1)
DEFOZNACZ(oznacz2,pb2,2)
DEFOZNACZ(oznacz3,pb3,3)
DEFOZNACZ(oznacz4,pb4,4)
... tak też można:) */

void Plansza::oznacz1()
{
    pb1->setText("X"); //tak naprawdę tu będziemy wpisywać usersymbol
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
    std::cerr << "user made move " << liczba << "\n";
    Ruch result;
    result = silnik.usermove(liczba);
    std::cerr << "komp odpowiada " << result.ruch << "\n";
    if (result.czy_wyg())
    {
        //msgbox = new QMessageBox(this);
        if (result.ruch == 50)
        {
            msgbox = new QMessageBox(this);
            msgbox->setText("Computer wins this game.");
            msgbox->exec();
            qApp->quit();
        }
        else if (result.ruch == -50)
        {
            msgbox = new QMessageBox(this);
            msgbox->setText("Player wins this game.");
            msgbox->exec();
            qApp->quit();
        }
        //msgbox->exec();
        //qApp->quit();
    }
    if (result.czy_rem())
    {
        msgbox = new QMessageBox(this);
        msgbox->setText("Remis in this game.");
        msgbox->exec();
        qApp->quit();
    }
    if (result.ruch)
    {
        switch (result.ruch)
        {
            case 0: pb1->setText("O"); pb1->setEnabled(false); break; //dokładniej: compsymbol
            case 1: pb2->setText("O"); pb2->setEnabled(false); break;
            case 2: pb3->setText("O"); pb3->setEnabled(false); break;
            case 3: pb4->setText("O"); pb4->setEnabled(false); break;
            case 4: pb5->setText("O"); pb5->setEnabled(false); break;
            case 5: pb6->setText("O"); pb6->setEnabled(false); break;
            case 6: pb7->setText("O"); pb7->setEnabled(false); break;
            case 7: pb8->setText("O"); pb8->setEnabled(false); break;
            case 8: pb9->setText("O"); pb9->setEnabled(false); break;
        }
    }
}
