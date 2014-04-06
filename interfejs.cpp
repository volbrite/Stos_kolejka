#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

void WYPISZ_WSTEP()
{
    cout << "*********************************************" << endl <<
            "|        Mnozenie i zliczanie czasu         |" << endl <<
            "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|" << endl <<
            "|   Autor: Bizon Michal  |  Indeks: 195251  |" << endl <<
            "| ----------------------------------------- |" << endl <<
            "|       ALGORYTM: wczytywanie do stosu      |" << endl <<
            "| ----------------------------------------- |" << endl <<
            "|___________________________________________|" << endl << endl;
}


void WYPISZ_MENU()
{
    cout << "|------------------------" << endl <<
            "| Opcje programu (opcje wyboru sa dostepne):" << endl <<
            "|  (o) - wczytaj dane z pliku" << endl <<
            "|  (d) - TRYB DEBUG" << endl <<
            "|  (z) - Wybierz ilosc powtorzen wykonania algorytmu" << endl <<
            "|  (Q) - Wybierz sposob implementacji stosu" << endl <<
            "|  (E) - Wyjscie" << endl <<
            "|------------------------" << endl <<
            "|  (S) - Start symulacji" << endl <<
            "|------------------------" << endl << endl;
}

void WYPISZ_PARAMETRY(int ilosc_powtorzen,
                      int ilosc_elementow,
                      bool Debug)
{
        cout << "* Parametry programu:  " << endl <<
                "*  - Ilosc powtorzen:  " << ilosc_powtorzen << endl <<
                "*  - Rozmiar tablicy:  " << ilosc_elementow << endl;
        if (Debug == true)
            cout << "*  - Tryb debugowania: TAK" << endl;
        else
            cout << "*  - Tryb debugowania: NIE" << endl;
        //cout << "*  - Nazwa pliku wejsciowego: " << Nazwa_pliku_wejsciowego << endl;
}



