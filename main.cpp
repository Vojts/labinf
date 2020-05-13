#include <iostream>
#include <baza.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <cctype> //Pobieram biblioteki
using namespace std;

void ile(int &n){ //Tworze funckje, ktora bedzie obslugiwala ile osob uzytkownik chce wprowadzic
    cout << "Ile osob chcesz wprowadzic?" << endl; //wyswietlam na ekranie tekst (nie bede wiecej opisywal cout'ow)
    cin >> n; //pobieram od uzytkownika liczbe ile chce podac osob
};

int main()
{
    int n; //deklaruje zmienna do okreslenia ile osob chce uzytkownik wprowadzic
    int znak; //Zmienna potrzebna do obs³ugi switcha
    ile(n); //Wywoluje funkcje ile
    class baza *dane= new baza[n];
    do //petla, ktora bedzie sie wykonywac, dopoki uzytkownik nie zakonczy programu
    {
    cout << "-----MENU----- " << endl; //Opis menu
    cout << "1. Wprowadz dane" << endl;
    cout << "2. zapisz dane na dysk" << endl;
    cout << "3. Pobierz dane z dysku" << endl;
    cout << "4. Wyswietl dane" << endl;
    cout << "5. Koniec" << endl;
    cout << "\n" << endl;
    cout << "Wprowadz liczbe z menu: " << endl;
    cin >> znak; //uzytkownik wprowadza ktora opcje chce wykonac
    cout << "\n" << endl;
    switch(znak) //funkcja switch do obslugi przypadkow, ktore chce uzytkownik wykonac
    {
    case 1:
        dane->wprowadz(n, dane); //wykonuje metode wprowadz z klasy
        break;
    case 2:
        dane->zapis(n, dane);//wykonuje metode zapis z klasy
        break;
    case 3:
        dane->pobierz(dane); //wykonuje metode pobierz z klasy
        break;
    case 4:
        dane->wyswietl(n, dane); //wykonuje metode wyswietl z klasy
        break;
    case 5:
        cout << "Czyszczenie pamieci" << endl;
        cout << "\n" << endl;
        cout << "Wylaczam program." << endl;
        delete [] dane; //Czyszcze pamiec, ktora wczesniej zaalokowalem za pomoca new
        break;
    }
    }while(znak != 5); //petla trwa, dopoki znak nie bedzie sie rownal 5
    return 0;
}
