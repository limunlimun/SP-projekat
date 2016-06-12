#ifndef _LISTAFILMOVA_H
#define _LISTAFILMOVA_H

#include "film.h"

class listaFilmova{
  private:
    ListaNizom<Film> filmovi;
  public:
    listaFilmova()=default;
    ~listaFilmova()=default;

    void print();
    void pretrazi(Film f);
    void pregledFilma(std::string naziv);
    void posudiFilm(Film f);
    void vratiFilm(Film f);
    void dodajFilm(Film f);
    void ukloniFilm(Film f);
    void azurirajFilm();

};


void listaFilmova::print(){
 for(int i=0;i<filmovi.velicina();i++)
   filmovi.dohvatiEl(i).printFilm();
}

#endif
