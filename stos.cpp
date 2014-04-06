#include <cstdlib>
#include <cassert>
#include "stos.h"

using namespace std;

STOS::STOS()
    : aktualny_element(0),
      aktualny_rozmiar (inicjalizacja)
{
    tablica_elementow = new int[inicjalizacja];

    if (tablica_elementow == NULL)
        cout << "* BLAD ALOKACJI PAMIECI!" << endl << endl;
}

STOS::~STOS()
{}

void STOS::DESTRUCT()
{
    for (int x = 0 ; x == aktualny_element ; x++)
        delete &tablica_elementow;

    ilosc_elementow = 0;
    aktualny_element = 0;
    aktualny_rozmiar = inicjalizacja;
}

void STOS::pushOne(int wczytana)
{
    assert( aktualny_element <= aktualny_rozmiar);

    if (aktualny_element == aktualny_rozmiar)
        powiekszOne();

    tablica_elementow[aktualny_element] = wczytana;
    ++aktualny_element;
}

void STOS::pushDouble(int wczytana)
{
    assert( aktualny_element <= aktualny_rozmiar);

    if (aktualny_element == aktualny_rozmiar)
        powiekszDouble();

    tablica_elementow[aktualny_element] = wczytana;
    ++aktualny_element;
}

void STOS::powiekszOne()
{
    int* tablica_pomocnicza = new int[aktualny_rozmiar+1];

    for (int x = 0 ; x < aktualny_rozmiar ; x++)
        tablica_pomocnicza[x] = tablica_elementow[x];

    aktualny_rozmiar++;

    tablica_elementow = tablica_pomocnicza;
    delete[] tablica_pomocnicza;
}


void STOS::powiekszDouble()
{
    int* tablica_pomocnicza = new int[2*aktualny_rozmiar];

    for (int x = 0 ; x < aktualny_element ; x++)
        tablica_pomocnicza[x] = tablica_elementow[x];

    aktualny_rozmiar = 2*aktualny_rozmiar;
    tablica_elementow = tablica_pomocnicza;
    delete[] tablica_pomocnicza;
}

void STOS::Przypisanie_do_stosu_ONE(int* TABELA, bool Debug)
{
    this->zapiszIloscElementow(TABELA[0]);
    for (int x = 1; x <= ilosc_elementow ; x++)
    {
        pushOne(TABELA[x]);
        if(Debug == true)
        {
            DEBUG();
            cin.get();
        }
    }
}

void STOS::Przypisanie_do_stosu_DOUBLE(int* TABELA, bool Debug)
{
    this->zapiszIloscElementow(TABELA[0]);
    for (int x = 1; x <= ilosc_elementow ; x++)
    {
        pushDouble(TABELA[x]);
        if(Debug == true)
        {
            DEBUG();
            cin.get();
        }
    }
}

int STOS::TOP() const
{
    assert (aktualny_element > 0);
    return tablica_elementow[aktualny_element-1];
}

void STOS::zapiszIloscElementow(int ilosc)
{
    this->ilosc_elementow = ilosc;
}

void STOS::DEBUG()
{
    cout << "*  ILOSC_ELEMENTOW: " << setprecision(5) << this->ilosc_elementow << endl <<
            "*  AKTUALNY_ELEMENT: " << setprecision(5) << this->aktualny_element << endl <<
            "*  AKTUALNY_ROZMIAR: "<< setprecision(5) << this->aktualny_rozmiar << endl <<
            "*  TOP: "<< setprecision(4) << this->TOP() << endl;
}

int STOS::pobierzIloscElementow()
{
    int temp = this->ilosc_elementow;
    return temp;
}

int STOS::pobierzElement(int element)
{
    int temp = this->tablica_elementow[element];
    return temp;
}
