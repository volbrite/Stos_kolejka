#include "lista.h"

Lista::Lista()
{
    korzen = NULL;
    ostatni = NULL;
    ilosc_elementow = 0;
}

Lista::~Lista()
{
    Element *temp;

    while(korzen == NULL)
    {
        temp = korzen->nastepny;
        delete korzen;
        korzen = temp;
    }
}

int Lista::rozmiar()
{
    return ilosc_elementow;
}

void Lista::push_back(Element *dodawany)
{
    if(ostatni != NULL)
        ostatni->nastepny = dodawany;
    dodawany->nastepny = NULL;
    ostatni = dodawany;

    if (korzen == NULL)
        korzen = ostatni;

    ilosc_elementow++;
}

void Lista::pop_back()
{
    Element * temp;

    if (ostatni != NULL)
    {

        temp = ostatni;
        if (temp == korzen)
            korzen = ostatni = NULL;
        else
        {
            ostatni = korzen;
            while (ostatni->nastepny != temp)
                ostatni = ostatni->nastepny;

            ostatni->nastepny = NULL;
        }
    ilosc_elementow--;
    }
}

void Lista::push_front(Element *dodawany)
{
 dodawany->nastepny = korzen;
 korzen = dodawany;

 if (ostatni == NULL)
     ostatni = korzen;

 ilosc_elementow++;
}

void Lista::pop_front()
{
    Element * temp;

    if(korzen != NULL)
    {
        temp = korzen;
        korzen = korzen->nastepny;

        if (korzen == NULL)
            ostatni = NULL;
        ilosc_elementow--;

    }
}

void Lista::DESTRUCT()
{
    while (ilosc_elementow == 0)
    {
        this->pop_front();
    }
    pop_front();
}


void Lista::Wyswietl_Liste()
{
    Element *temp = new Element;
    if (korzen)
    {
        temp = korzen;

        while (temp)
        {
            std::cout << temp->wartosc << std::endl;
            temp = temp->nastepny;
        }
        std::cout << std::endl;
    }
    else std::cout << "** Lista jest PUSTA!!! **" << std::endl;
}

void Lista::Przypisz_do_Listy(int *TABLICA, bool Debug)
{
    Element * temp;
        int ilosc = TABLICA[0];
        for (int x = 1; x <= ilosc ; x++)
        {
            temp = new Element;
            temp->wartosc = TABLICA[x];

            this->push_back(temp);
        }
        //Wyswietl_Liste();
}
