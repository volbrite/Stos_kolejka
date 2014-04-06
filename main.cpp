/**
    * @brief Program LAB1 - Algorytm Mnozenia
    *
    * Program wczytuje dane z pliku, mnozy x2, nastepnie sprawdza
    * poprawnosc wykonanego dzialania (rowniez z pliku) i zapisuje
    * wynik do *.CSV
    *
    * @author Michal Bizon
    * @date 03.03.14
    * @version 1.0.0
    * @copyright GPL
    *
*/

/** Sprawozdanie - raport z wypełnienia stosu N = {10,100,1000,10 000}
        wykres
    podwajamy wielkosc tablicy gdy przekroczymy jej ilosc elementow
    zmniejszamy jej wielkosc o polowe, gdy mamy 1/4 elementow

    zaimplementowac stos przy uzyciu tablic i listy
    IMPL. Tablicowa
        - Wersja powiekszajaca o +1
        - Wersja podwajajaca
**/
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>
#include <string>

#include "stos.h"
#include "lista.h"
#include "interfejs.h"
#include "funkcje.h"

using namespace std;


int main()
{
    /**
     * @brief Inicjalizacja zmiennych

     Zmienne:
      - TABELA - przechowuje tabele wczytana z pliku (dynamicznie alokowana)
      - Zamknij, Debug - do sterowania programem oraz ewentualnego wypisywania na ekran
      - iloscElemTabeli - ilosc elementow pobrana z pliku
      - ilosc_losowan - ilosc powtorzen kazdego przypisania
     */

    string nazwaWe = "dane_2k.csv", nazwaWy = "WYNIKI";
    char opcja;
    int* TABELA;
    bool Zamknij = false, Debug = false;
    int ilosc_losowan = 20;
    int iloscElemTabeli;

    struct timeval start, koniec;   /// Inicjacja zmiennych do obliczenia czasu
    cout.setf(ios::fixed);          /// Poprawne wyswietlanie czasu w programie




    WYPISZ_WSTEP();
    cin.get();

    cout << "WCZYTAJ DANE WEJSCIOWE" << endl;
    nazwaWe = WCZYTAJ_NAZWE(nazwaWe);
      TABELA = OtworzPlik(nazwaWe);           /// Przypisanie tabeli zwracanej z funkcji do TABELA
    cout << endl;

    iloscElemTabeli = TABELA[0];          /// iloscElemTabeli - uzyta tylko do wyswietlania ilosci danych pobranych z pliku


    while (Zamknij != true)
    {
        WYPISZ_PARAMETRY(ilosc_losowan, iloscElemTabeli, Debug);
        WYPISZ_MENU();
        cin >> opcja;
//        opcja = 's';
        switch (opcja)
        {

        /** @brief OPCJA O - Wczytanie danych wejsciowych ponownie */
        case 'o':
        case 'O':
            {
                system("clear");
                cout << "WCZYTAJ DANE WEJSCIOWE" << endl;
                nazwaWe = WCZYTAJ_NAZWE(nazwaWe);
                delete[] TABELA;

                TABELA = OtworzPlik(nazwaWe);
                iloscElemTabeli = TABELA[0];          /// iloscElemTabeli - uzyta tylko do wyswietlania ilosci danych pobranych z pliku
                system("clear");
                break;
            }

            /** @brief OPCJA D - wlaczenie trybu DEBUG - czyli wyswietlanie kazdego przypisania na ekranie */
        case 'd':
        case 'D':
            {
                system("clear");
                Debug = true;
                system("clear");
                break;
            }
            /** @brief OPCJA Z - Zmiana ilosci powtorzen przypisania tej samej tabeli (dla uzyskania bardziej realnych czasow */
        case 'z':
        case 'Z':
            {
                system("clear");
                cout << "Wprowadz nowa ilosc powtorzen:" << endl;
                cin >> ilosc_losowan;
                system("clear");
                break;
            }
        /** @brief OPCJA S - Symulacja */
        case 'S':
        case 's':
            {
                system("clear");

                cout << "*  ROZPOCZYNAM SYMULACJE:  *" << endl <<
                        "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

                STOS Wczytany_ONE, Wczytany_DOUBLE;         ///Inicjacja Obiektów klasy STOS
                Lista Wczytany_THREE;                       ///Inicjacja listy jednokierunkowej

                if (Debug == true)
                    ilosc_losowan = 1;
                long double TABELA_CZASOW[4][101], TABELA_CZAS_SUMA[4] = {0};    /// Zainicjowane dopiero w tym miejscu ze wzgledu na 'ilosc_losowan', ktora moze zostac zmieniona przez uzytkownika

                cout << "* PRZYPISANIE:  Zwiekszanie o 1 rozmiaru stosu *" << endl;
                for (int n = 0; n<ilosc_losowan ; n++)      /// Petla glowna symulacji.
                {
                    gettimeofday(&start, NULL);             /// Zapisuje do zmiennej 'start' czas przed rozpoczeciem wykonania algorytmu
                        Wczytany_ONE.Przypisanie_do_stosu_ONE(TABELA, Debug);
                    gettimeofday(&koniec, NULL);

                    TABELA_CZAS_SUMA[0] += OBLICZ_CZAS(start, koniec);          /// Suma czasow wykonania calej symulacji - dla danego przypadku
                    TABELA_CZASOW[0][n] = OBLICZ_CZAS(start, koniec);            /// Tabela czasow poszczegolnych przypisan

                    Wczytany_ONE.DESTRUCT();
                }

                cout << "* Czas tej operacji to: " << setprecision(9) << TABELA_CZAS_SUMA[0] << " [s]" << endl;
                cout << "* Sredni czas wykonania jednego mnozenia: " << setprecision(9) << TABELA_CZAS_SUMA[0]/ilosc_losowan << " [s]" << endl << endl;

                cout << "* PRZYPISANIE:  Zwiekszanie x2 rozmiaru stosu *" << endl;
                for (int n = 0; n<ilosc_losowan ; n++)      /// Petla glowna symulacji.
                {
                    gettimeofday(&start, NULL);
                        Wczytany_DOUBLE.Przypisanie_do_stosu_DOUBLE(TABELA, Debug);
                    gettimeofday(&koniec, NULL);

                    TABELA_CZAS_SUMA[1] += OBLICZ_CZAS(start, koniec);
                    TABELA_CZASOW[1][n] = OBLICZ_CZAS(start, koniec);
                    Wczytany_DOUBLE.DESTRUCT();
                }
                cout << "* Czas tej operacji to: " << setprecision(9) << TABELA_CZAS_SUMA[1] << " [s]" << endl;
                cout << "* Sredni czas wykonania jednego mnozenia: " << setprecision(9) << TABELA_CZAS_SUMA[1]/ilosc_losowan << " [s]" << endl << endl;



                cout << "* PRZYPISANIE:  Wczytanie do listy jednokierunkowej *" << endl;
                for (int n = 0; n<ilosc_losowan ; n++)      /// Petla glowna symulacji
                {
                    gettimeofday(&start, NULL);
                        Wczytany_THREE.Przypisz_do_Listy(TABELA, Debug);
                    gettimeofday(&koniec, NULL);

                    TABELA_CZAS_SUMA[2] += OBLICZ_CZAS(start, koniec);
                    TABELA_CZASOW[2][n] = OBLICZ_CZAS(start, koniec);

                    if (Debug == true)
                        Wczytany_THREE.Wyswietl_Liste();
                    Wczytany_THREE.DESTRUCT();
                }
                cout << "* Czas tej operacji to: " << setprecision(9) << TABELA_CZAS_SUMA[2] << " [s]" << endl;
                cout << "* Sredni czas wykonania jednego mnozenia: " << setprecision(9) << TABELA_CZAS_SUMA[2]/ilosc_losowan << " [s]" << endl << endl;


                /// Zapisanie wynikow do pliku
                if (Debug == false)
                    ZAPIS_CZASOW_DO_PLIKU(TABELA_CZASOW,TABELA_CZAS_SUMA,nazwaWy,ilosc_losowan,iloscElemTabeli);

                /// Oczyszczanie - działa tylko w ten sposób...
                Wczytany_ONE.~STOS();
                Wczytany_DOUBLE.~STOS();
                Wczytany_THREE.~Lista();
                for (int x = 0 ; x < 3 ; x++)
                    for (int y = 0 ; y < 100 ; y++)
                        TABELA_CZASOW[x][y] = TABELA_CZAS_SUMA[x] = 0;

                cin.get(); system("clear");
                Zamknij = true;
                break;
            }
        /** @brief OPCJA E - Exit - Wyjscie */
        case 'E':
        case 'e':
            {
                Zamknij = true;
                break;
            }

        default:
            {
                system("clear");
                cout << "|------------------------|" << endl <<
                        "| NIEZNANA OPCJA POGRAMU |" << endl <<
                        "|------------------------|" << endl << endl;
                cin.get();
                system("clear");
                break;
            }
        }
    }
    delete[] TABELA; ///Kasowanie tabeli
    return 0;
}

