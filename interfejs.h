#include <cstdlib>
#include <string>

#ifndef INTERFEJS_H
#define INTERFEJS_H

using namespace std;

/**
 * @brief Funkcja wypisujaca powitanie i podstawowe informacje przy starcie programu
 *
 */
void WYPISZ_WSTEP();

/**
 * @brief Wypisuje dostepne menu opcji w programie
 *
 */
void WYPISZ_MENU();

/**
 * @brief Wypisuje parametry danego przypadku dzialania programu
 *
 * @param ilosc_powtorzen - ilosc powtorzen wykonania danego przypisania dla kazdej metody
 * @param ilosc_elementow - ilosc elementow ktore zostana przypisane
 * @param Debug - odpowiedzialne za wyswietlanie przypisywanych elementow
 */
void WYPISZ_PARAMETRY(int ilosc_powtorzen, int ilosc_elementow, bool Debug);

#endif // INTERFEJS_H
