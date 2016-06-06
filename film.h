#ifndef _FILM_H
#define _FILM_H

#include "lista.hxx"
#include "osoba.h"
#include "datum.h"

class Film{
  private:
    std::string _naziv;
    std::string _opis;
    Osoba _reziser;
    ListaNizom<Osoba> lista_producenata;
    ListaNizom<Osoba> lista_scenarista;
    ListaNizom<Osoba> lista_glumaca;
    std::string prod_komp;//produkcijska kompanija
    unsigned int god_izdavanja;//godina izdavanja
    unsigned int broj_kopija;
  public:
    Film()=default;
    Film(std::string naziv,std::string opis,Osoba rez,ListaNizom<Osoba> lp,ListaNizom<Osoba> ls,ListaNizom<Osoba> lg,std::string komp,unsigned int godizd,unsigned int brkop):_naziv(naziv),_opis(opis),_reziser(rez),lista_producenata(lp),lista_scenarista(ls),lista_glumaca(lg),prod_komp(komp),god_izdavanja(godizd),broj_kopija(brkop){};
    ~Film()=default;
   
    std::string getNaziv(){return _naziv;}
    std::string getOpis(){return _opis;}
    Osoba getOsoba(){return _reziser;}
    ListaNizom<Osoba> getProducenti(){return lista_producenata;}
    ListaNizom<Osoba> getScenaristi(){return lista_scenarista;}
    ListaNizom<Osoba> getGlumci(){return lista_glumaca;}
    std::string getKompanija(){return prod_komp;}
    unsigned int getGodIzdavanja(){return god_izdavanja;}
    unsigned int getBrKopija(){return broj_kopija;}
};

#endif
