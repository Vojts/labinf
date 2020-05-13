#include "baza.h"
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

baza::~baza()
{
    cout << "usuwam dane, destruktor dziala" << endl;
}
baza::baza(){};
baza::baza(char *i, char *n, int telefon)
{
    strcpy(this-> imie, i);
    strcpy(this-> nazwisko, n);
    this-> telefon = telefon;
    cout << "wykonuje konstruktor" << endl;
    cout << "Imie: " << imie << "\n" << "Nazwisko: " << nazwisko << "\n" << "Telefon: " << telefon << "\n" << endl;
};
void baza::wprowadz(int &n, baza *dane){ //tworze metode wprowadz w klasie baza
    for(int i=0; i<n; i++) //petla, dzieki ktorej program pobierze od uzytkownika tyle osob, ile wprowadzil wczesniej
    {
        cout << "Imie: ";
        cin >> imie; //pobieram imie i zapisuje je w klasie. [i] okresla w ktorym miejscu klasy, jest to obslugiwane przez petle for
        cout << "Nazwisko: ";
        cin >> nazwisko;
        cout << "Telefon: ";
        cin >> telefon;
        cout << "\n" << endl;
        if(!(telefon)) //Sprawdzam, czy telefon, ktory jest intem zostal poprawnie wprowadzony (zabezpieczenie przed wysypaniem sie programu)
        {
            cout << "Telefon powinien zawierac same cyfry!" << endl;
            cin.clear(); //kasowanie flagi b³êdu strumienia
            cin.sync(); //kasowanie zbêdnych znaków z bufora
            i--; //zmniejszam licznik i, zeby ponownie wprowadzic te same dane, w ktorych wystapil blad
            cout << "Wprowadz te osobe ponownie" << endl;
        }
        baza *dane[i] = new baza(imie, nazwisko, telefon);
    }
};

void baza::wyswietl(int &n, baza *dane){ //tworze metode wyswietl w klasie baza
    cout << "Wyswietlam dane:" << endl;
    cout << "\n" << endl;
    for(int i=0; i<n; i++) //Wyswietli tyle osob, ile wprowadzil uzytkownik
        {
            cout << "Imie: " << dane[i].imie << endl;
            cout << "Nazwisko: " << dane[i].nazwisko << endl;
            cout << "Telefon: " << dane[i].telefon<< endl;
            cout << "\n" << endl;
        }
};

void baza::zapis(int &n, baza *dane){ //tworze metode zapis w klasie baza
    ofstream plik("dane.dat",ios::binary|ios::out|ios::trunc); //otwieram / tworze plik binarny jesli nie istnieje, a jesli istnieje, to czyszcze jego zawartosc
    if(plik.good() == true) //sprawdzam, czy plik zostal otwarty poprawnie
    {
        for(int i=0; i<n; i++)
        {
            plik.write(reinterpret_cast<char*>(dane+i),sizeof(baza)); //zeby moc zapisywac rozne typy danych, trzeba zastosowac reinterpet_cast. (dane+i) sluza do zapisywania kolejnych rekordow z klasy (i-ty rekord)
        }
    }
    plik.close(); //zamykam plik
};

void baza::pobierz(baza *dane){ //tworze metode pobierz w klasie baza
    ifstream plik("dane.dat",ios::binary|ios::in); //otwieram plik do odczytu
    if(plik.good() == true)
    {
        for(int i=0;;i++)
        {
            plik.read(reinterpret_cast<char*>(dane+i),sizeof(baza)); //znowu reinterpret cast, po to zeby odczytal rozne typy danych. dane+i dzialaja tak samo jak wyzej
            if(plik.eof()) //bedzie dzialac, dopoki plik sie nie skonczy
                break;
        }
    }
    plik.close(); //zamykam plik
};
