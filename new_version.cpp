#include "new_version.h"

int Engine::wygrana()
{
    int result = 0;
    for (int i = 1; i<=7; i+=3)
    {
        if ((pole[i-1] == pole[i]) && (pole[i] == pole[i+1]))
            pole[i] == compsymbol ? result = 1 : result = -1; //rezultat równy 1 to wygrana komputera, -1: wygrana człeka
    }
    for (int i = 1; i<=3; i++)
    {
        if ((pole[i-1] == pole[i+2]) && (pole[i+2] == pole[i+5]))
            pole[i] == compsymbol ? result = 1 : result = -1;
    }
    if ((pole[0] == pole[4]) && (pole[4] == pole[8]))
        pole[4] == compsymbol ? result = 1 : result = -1;
    if ((pole[2] == pole[4]) && (pole[4] == pole[6]))
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

int Engine::minmax(char symbol)
{
    int m;
    int mmx = -10;
    for(int i = 1; i <= 9; i++)
        if(pole[i] == ' ')
        {
            pole[i] = symbol;
            m = minmax(symbol);
            pole[i] = ' ';
            if(((symbol == 'O') && (m < mmx)) || ((symbol == 'X') && (m > mmx))) mmx = m;
        }
    return mmx;    
}

Ruch Engine::usermove(int liczba)
{
    pole[liczba-1] = usersymbol;
    Ruch result;
    if(wygrana() == 1)
    {
        result.ruch = 10;
        return result;
    }
    if(wygrana() == -1)
    {
        result.ruch = -10;
        return result;
    }
    if(remis())
    {
        result.ruch = 20;
        return result;
    }
    
    int move, i, m, mmx;
    mmx = -10;
    for(i = 1; i <= 9; i++)
    {
        if(pole[i] == ' ')
        {
            pole[i] = compsymbol;
            m = minmax(compsymbol);
            pole[i] = ' ';
            if(m > mmx)
            {
                mmx = m; 
                move = i;
            }
        }
    }
    result.ruch = move;
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
    Ruch result;
    result = silnik.usermove(liczba);
    if (result.czy_wyg())
    {
        msgbox = new QMessageBox(this);
        if (result.ruch == 10)
            msgbox->setText("Computer wins this game.");
        else if (result.ruch == -10)
            msgbox->setText("Player wins this game.");
        msgbox->exec();
        qApp->quit();
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
            case 0: { pb1->setText("O"); pb1->setEnabled(false); } //dokładniej: compsymbol
            case 1: { pb2->setText("O"); pb2->setEnabled(false); }
            case 2: { pb3->setText("O"); pb3->setEnabled(false); }
            case 3: { pb4->setText("O"); pb4->setEnabled(false); }
            case 4: { pb5->setText("O"); pb5->setEnabled(false); }
            case 5: { pb6->setText("O"); pb6->setEnabled(false); }
            case 6: { pb7->setText("O"); pb7->setEnabled(false); }
            case 7: { pb8->setText("O"); pb8->setEnabled(false); }
            case 8: { pb9->setText("O"); pb9->setEnabled(false); }
        }
    }
}