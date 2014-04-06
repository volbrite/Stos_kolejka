#ifndef STOS_H
#define STOS_H
#include <iostream>
#include <iomanip>

const int inicjalizacja = 2; /**< Poczatkowa wielkosc tablicy */

/**
 * @class Klasa reprezetujaca stos z wykozystaniem tablicy intow
 */
class STOS
{
    int * tablica_elementow; /**< TODO */

    int ilosc_elementow; /**< TODO */
    int aktualny_element; /**< TODO */
    int aktualny_rozmiar; /**< TODO */

    /**
     * @brief Funkcja powiekszajaca rozmiar tablicy elementow o jeden przy kazdym
     * przekroczeniu wielkosci tablicy
     */
    void powiekszOne();
    /**
     * @brief Funkcja powiekszajaca rozmiar tablicy elementow dwukrotnie przy kazdym
     * przekroczeniu wielkosci tablicy
     */
    void powiekszDouble();

public:
    /**
     * @brief Konstruktor - inicjalizacja zmiennych klasy
     */
    STOS();
    /**
     * @brief Destruktor - usuwanie elementow klasy
     */
    ~STOS();
    /**
     * @brief Odpowiedzialne za oczyszczanie tablicy - w celu ponownego przypisania - uzywana tyle razy, ile wystepuje powtorzen przypisania
     */
    void DESTRUCT();

    /**
     * @brief Odpowiada za wczytanie liczby typu int i przypisanie jej do tablicy - powiekszanej o 1 element przy przekroczeniu wielkosci
     *
     * @param wczytana - liczba typu int pobrana z tabeli i przypisywana do klasy
     */
    void pushOne(int wczytana);

    /**
     * @brief Odpowiada za wczytanie liczby typu int i przypisanie jej do tablicy - powiekszanej dwukrotnie przy przekroczeniu aktualnej_wielkosci
     *
     * @param wczytana - liczba typu int pobrana z tabeli i przypisywana do klasy
     */
    void pushDouble(int wczytana);

    /**
     * @brief Zwraca element, ktory jest na gorze stosu
     */
    int TOP() const;
    /**
     * @brief Przypisuje ilosc elementow pobrana z tablicy do klasy
     *
     * @param ilosc - ilosc elementow pobrana z tablicy
     */
    void zapiszIloscElementow(int ilosc);

    /**
     * @brief Pobiera ilosc elementow z klasy
     *
     * @return int - zwraca ilosc_elementow
     */
    int pobierzIloscElementow();
    /**
     * @brief Pobiera dany element stosu - przydatne na potrzeby debugowania
     *
     * @param element - numer elementu, ktory chcemy pobrac
     * @return int - wartosc elementu
     */
    int pobierzElement(int element);

    /**
     * @brief Funkcja przypisujaca wartosci z tablicy do stosu - metoda zwiekszajaca rozmiar tablicy o 1 element
     *
     * @param TABLICA - Zawiera ilosc elementow oraz dane wczytane z pliku tekstowego
     * @param Debug - typu bool - decyduje, czy wyswietlac wartosci czy nie
     */
    void Przypisanie_do_stosu_ONE(int* TABELA, bool Debug);
    /**
     * @brief Funkcja przypisujaca wartosci z tablicy do stosu - metoda zwiekszajaca rozmiar tablicy dwukrotnie
     *
     * @param TABLICA - Zawiera ilosc elementow oraz dane wczytane z pliku tekstowego
     * @param Debug - typu bool - decyduje, czy wyswietlac wartosci czy nie
     */
    void Przypisanie_do_stosu_DOUBLE(int* TABELA, bool Debug);
    /**
     * @brief Wyswietla Elementy tablicy
     */
    void DEBUG();
};

#endif // STOS_H
