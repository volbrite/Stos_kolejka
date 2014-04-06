#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "stos.h"

using namespace std;

/**
  * Odpowiada za wczytanie nazwy pliku
  * PRE:
  *     - wymaga przekazania do niej nazwy pod postacia zmiennej 'string'
  *
  * POST:
  *     - zwraca nazwe dokumentu podana przez uzytkownika
  */
string WCZYTAJ_NAZWE(string nazwa)
{
    cout << "** Wczytaj plik (podaj sciezke):" << endl <<
            "*= ";
    cin >> nazwa;

    nazwa = nazwa.c_str();

    system("clear");
    return nazwa;
}

int* OtworzPlik( string nazwaPliku)
{
    int liczba_elementow;

    ifstream plik;
    plik.open( nazwaPliku.c_str() );
    do
    {
        if( !plik.good() )
        {
            system("clear");
            cout << "** PLIK NIE ZOSTAL ODNALEZIONY LUB ZOSTAL ZAPISANY W ZLYM FORMACIE" << endl;
            cout << "** WPROWADZ NAZWE PONOWNIE" << endl;
            nazwaPliku = WCZYTAJ_NAZWE(nazwaPliku);
            plik.open( nazwaPliku.c_str() );
        }
        if( plik.good() )
        {
            plik >> liczba_elementow;                   /// Pobranie liczby elementow
            int* tablica = new int [liczba_elementow];  /// Zainicjowanie tablicy dynamicznej
            tablica[0] = liczba_elementow;             /// Przypisanie l. elementow jako pierwszy element tabeli
            for (int i = 1; i <= liczba_elementow; i++)
                plik >> tablica[i];                     /// wczytanie danych do kolejnych komórek tabeli
            return tablica;
        }
    } while (plik.good() == true);

    return 0;
}

string INT_na_String(int numer)
{
   stringstream ss;
   ss << numer;
   return ss.str();
}

/**
  * @brief Zapis danych do pliku.
  *
  * Zapisuje dane wynikowe do pliku CSV
  *
  * PRE:
  *     - wymaga przekazania tabeli z zsumowanym czasem wykonania zadanej ilosci powtorzen, tabeli na ktorej dzialal
  *       algorytm, nazwy wyjsciowej (domylsnie 'WYNIKI.csv') oraz zadanej ilosci powtorzen
  *
  * POST:
  *     - Zapisuje do pliku wyniki dzialania programu
  */
void ZAPIS_CZASOW_DO_PLIKU(long double TABELA_CZASOW[4][101],long double TABELA_CZASOW_SUMA[4],
                           string nazwaWy,
                           int ilosc_losowan,
                           int rozmiar)
{
    for (int z = 0 ; z < 3 ; z++)
    {
        string nazwa = INT_na_String(rozmiar) + "_" + nazwaWy + "_" + INT_na_String(z) + ".csv";

        cout << "** Czasy zostana zapisane do pliku: " << nazwa << endl;

        fstream plik( nazwa.c_str(), ios::out );
        plik.setf(ios::fixed);                          /// Poprawne wyswietlanie czasu w programie
        if(plik.good() == true )
        {
            plik << "* CZAS Calkowity: " << setprecision(5) << TABELA_CZASOW_SUMA[z] << endl;
            plik << "* ILOSC Losowan:  " << ilosc_losowan << endl;
            plik << "* ROZMIAR:        " << rozmiar << endl << endl;
            for (int x = 0; x < ilosc_losowan ; x++)
                plik << rozmiar << ";" << setprecision(5) << TABELA_CZASOW[z][x] << endl;

            plik.close();
        }
        else
            cout << "* BLAD! NIE MOZNA UTWORZYC PLIKU!" << endl << endl;
    }
    cout << "* Zapis zakonczony poprawnie." << endl << endl;
}

long double OBLICZ_CZAS(timeval start, timeval koniec)
{
    long double czas_wykonania, sekundy, usekundy;

    sekundy  = koniec.tv_sec  - start.tv_sec;       /// Obliczenie sekund za pomoca funkcji biblioteki "sys/time.h"
    usekundy  = koniec.tv_usec  - start.tv_usec;    /// Obliczenie milisekund

    czas_wykonania = ((sekundy) + usekundy/1000000.0);        /// Obliczenie czasu wykonania

    return czas_wykonania;
}



