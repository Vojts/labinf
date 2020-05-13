#include <iostream>

using namespace std;

class baza { //Tworze klase baza
private: //Powoduje, ze wartosci imie, nazwisko i telefon beda prywatne tj. beda dostepne tylko w obrebie swojej klasy
    char imie[10];
    char nazwisko[25];
    int telefon;
public: //Metody beda publiczne, zeby mogly byc wykonywane w programie
    baza();
    baza(char *i, char *n, int telefon);
    ~baza();
    void wprowadz(int &n, baza *dane);
    void wyswietl(int &n, baza *dane);
    void zapis(int &n, baza *dane);
    void pobierz(baza *dane);
};
