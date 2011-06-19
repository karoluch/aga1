#include <algorithm>
#include "new_version.h"

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
    }
    for (int i = 1; i<=3; i++)
    {
        if ((pole[i-1] == pole[i+2]) && (pole[i+2] == pole[i+5]) && pole[i+2]!=' ')
            pole[i+2] == compsymbol ? result = 1 : result = -1;
    }
    if ((pole[0] == pole[4]) && (pole[4] == pole[8]) && pole[4]!=' ')
        pole[4] == compsymbol ? result = 1 : result = -1;
    if ((pole[2] == pole[4]) && (pole[4] == pole[6]) && pole[4]!=' ')
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
    int mmx = (symbol == compsymbol ? -1 : 1);
    for (int i=0; i<9; i++) if (pole[i] == ' ') 
    {
        pole[i] = symbol;
        int m = minmax(symbol == 'X' ? 'O' : 'X'); // te znaczki tez zamienic na compsymbol i usersymbol?
        pole[i] = ' ';

        if (symbol == compsymbol)
            mmx = max(mmx, m);
        else
            mmx = min(mmx, m);
    }
    return mmx;
}

Ruch Engine::usermove(int liczba)
{
    pole[liczba-1] = usersymbol;
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
    pole[move+1] = compsymbol;
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
    pb1->setText(usersymbol);
    pb1->setEnabled(false);
    react(1);
}

void Plansza::oznacz2()
{
    pb2->setText(usersymbol);
    pb2->setEnabled(false);
    react(2);
}

void Plansza::oznacz3()
{
    pb3->setText(usersymbol);
    pb3->setEnabled(false);
    react(3);
}

void Plansza::oznacz4()
{
    pb4->setText(usersymbol);
    pb4->setEnabled(false);
    react(4);
}

void Plansza::oznacz5()
{
    pb5->setText(usersymbol);
    pb5->setEnabled(false);
    react(5);
}

void Plansza::oznacz6()
{
    pb6->setText(usersymbol);
    pb6->setEnabled(false);
    react(6);
}

void Plansza::oznacz7()
{
    pb7->setText(usersymbol);
    pb7->setEnabled(false);
    react(7);
}

void Plansza::oznacz8()
{
    pb8->setText(usersymbol);
    pb8->setEnabled(false);
    react(8);
}

void Plansza::oznacz9()
{
    pb9->setText(usersymbol);
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
    }
    if (result.czy_rem())
    {
        msgbox = new QMessageBox(this);
        msgbox->setText("Remis in this game.");
        msgbox->exec();
        qApp->quit();
    }
    //if (result.ruch)
    //{
        switch (result.ruch)
        {
            case 0: pb1->setText(compsymbol); pb1->setEnabled(false); break;
            case 1: pb2->setText(compsymbol); pb2->setEnabled(false); break;
            case 2: pb3->setText(compsymbol); pb3->setEnabled(false); break;
            case 3: pb4->setText(compsymbol); pb4->setEnabled(false); break;
            case 4: pb5->setText(compsymbol); pb5->setEnabled(false); break;
            case 5: pb6->setText(compsymbol); pb6->setEnabled(false); break;
            case 6: pb7->setText(compsymbol); pb7->setEnabled(false); break;
            case 7: pb8->setText(compsymbol); pb8->setEnabled(false); break;
            case 8: pb9->setText(compsymbol); pb9->setEnabled(false); break;
        }
    //}
}
