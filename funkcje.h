#include <string>
#include "stos.h"

#ifndef FUNKCJE_H
#define FUNKCJE_H

using namespace std;

/**
 * @brief Wczytuje nazwe pliku, a nastepnie go otwiera
 *
 * @param nazwa - przechowuje nazwe pliku - uzytkownik wprowadzajac nazwe nadpisuje stara
 * @return string - zwraca wczytana nazwe i przypisuje ja do string'a
 */
string WCZYTAJ_NAZWE(string nazwa);


/**
  * @brief Odpowiada za otworzenie pliku i obsluge bledow przy ich otwieraniu.
  *
  * \details Funkcja Otwiera plik wskazany przez uzytkownika, nastepnie wykonuje petle 'do .. while()' dopuki uzytkownik
  * nie poda nazwy / sciezki do pliku z poprawnymi danymi. Po poprawnym podaniu pliku zrodlowego funkcja wczytuje
  * do tablicy liczbe elementow z pierwszego wiersza pliku z danymi, nastepnie inicjowana jest tablica dynamiczna o
  * tejze ilosci elementow i zostaje zapelniona danymi wczytanymi z pliku. Nastepnie zwraca ta tablice.
  *
  * @param nazwaPliku - wymaga przekazania do niej nazwy / sciezki pliku pod postacia zmiennej 'string'
  *
  *
  * @return int - zwraca tablice z danymi pobranymi z pliku
  *
  */

int* OtworzPlik( string nazwaPliku);

/**
 * @brief Funkcja Konwertuje zmienna typu INT na zmienna typu String - wymagane do zapisu czasow
 *
 * @param numer - liczba typu INT, ktory ma zostac przekonwertowany
 * @return string - zwraca liczbe w zmiennej string
 */
string INT_na_String(int numer);

/**
 * @brief Zapis danych (czasow wykonywania przypisania) do plikow.
 *
 * \details Program - po skończonym przypisywaniu wszystkimi metodami (kazdy z czasow wykonania jest zapisywany do tabel)
 *  - przekazuje te dane do funkcji tworzacej osobny plik dla kazdej metody i zapisujaca podstawowe dane o przypisaniu
 *
 * @param TABELA_CZASOW[][] - przechowuje czasy wszystkich przypisan (w jednym wierszu znajduje *ilosc_losowan* czasow)
 * @param TABELA_CZASOW_SUMA[] - zsumowany czas wszystkich przypisan (dla danej metody)
 * @param nazwaWy - nazwa pliku wyjsciowego
 * @param ilosc_losowan - ilosc identycznych przypisan danej tabeli do stosu / kolejki
 * @param rozmiar - ilosc elementow
 */

void ZAPIS_CZASOW_DO_PLIKU(long double TABELA_CZASOW[4][101],
                            long double TABELA_CZASOW_SUMA[4],
                            string nazwaWy,
                            int ilosc_losowan,
                            int rozmiar);

/**
 * @brief Funkcja odpowiedzialna za obliczanie czasu wykonania algorytmów
 *
 * @param start - wlaczenie "zegarka"
 * @param koniec - wylaczenie "zegarka"
 * @return long double - zwraca czas (ilosc / dlugosc) czasu pomiedzy startem a poczatkiem
 */
long double OBLICZ_CZAS(timeval start, timeval koniec);
#endif // FUNKCJE_H
