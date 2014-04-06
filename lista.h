#ifndef LISTA_H
#define LISTA_H
#include <iostream>

/**
 * \struct Element - struktura przechowujaca wskaznik do nastepnego elementu a takze wartosc. Podstawowy element listy.
 */
struct Element
{
    Element *nastepny; /**< TODO */
    int wartosc; /**< TODO */
};

/**
 * \class Lista - klasa reprezentujaca liste
 *
 */
class Lista
{
private:
    Element *korzen, *ostatni; /**< TODO */
    int ilosc_elementow; /**< TODO */

public:
    /**
     * @brief Konstruktor - inicjuje korzen, ostatni (jako wskazniki na Null), a takze wartosc jako 0;
     */
    Lista();
    /**
     * @brief Destruktor - odpowiada za kasowanie listy
     */
    ~Lista();

    /**
     * @brief Zwraca aktualny rozmiar listy
     *
     * @return int - Zwraca wartosc prywatnej zmiennej *ilosc_elementow*
     */
    int rozmiar();
    /**
     * @brief Funkcja odpowiedzialna za dodawanie elementu na poczatek kolejki
     *
     * \details Element po wczytaniu do funkcji najpierw przypisuje adres korzenia jako kolejny element,
     * a nastepnie zostaje przypisany jako korzen
     *
     * @param dodawany - do funkcji przekazywany jest juz wczesniej stworzony Element (nowy obiekt zawierajacy wartosc oraz wskaznik
     * na NULL)
     */
    void push_front(Element *dodawany);
    /**
     * @brief Usuwa pierwszy element z kolejki
     *
     */
    void pop_front();

    /**
     * @brief Dodaje element na koncu kolejki - adres obiektu "dodawany" jest zapisywany jako wskaznik ostatni->nastepny
     *
     * @param dodawany - do funkcji przekazany zostaje obiekt Element, zawierajacy wartosc oraz wskaznik na nastepny obiekt = Null.
     *
     */
    void push_back(Element *dodawany);
    /**
     * @brief Usuwa ostatni element z kolejki
     *
     */
    void pop_back();

    /**
     * @brief Funkcja oczyszcza cala liste - kasuje elementy za pomoca pop_front();
     */
    void DESTRUCT();

    /**
     * @brief Do trybu DEBUG - wyswiela cala zawartosc listy
     *
     */
    void Wyswietl_Liste();

    /**
     * @brief Funkcja przypisujaca wartosci z tablicy do listy
     *
     * @param TABLICA - Zawiera ilosc elementow oraz dane wczytane z pliku tekstowego
     * @param Debug - typu bool - decyduje, czy wyswietlac wartosci czy nie
     */
    void Przypisz_do_Listy(int * TABLICA,bool Debug);
};

#endif // LISTA_H
