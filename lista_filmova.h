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
    int pretrazi(std::string ime,int ispis=0);
    void pregledFilma(std::string ime);
    void posudiFilm(int serial);
    void vratiFilm(int serial);
    void dodajFilm(Film f);
    void ukloniFilm(int serial);
    void azurirajFilm();

};


void listaFilmova::print(){
 for(int i=0;i<filmovi.velicina();i++)
   filmovi.dohvatiEl(i).printFilm();
}

int listaFilmova::pretrazi(std::string ime,int ispis){
  int brojac=0;
  for(int i=0;i<filmovi.velicina();i++){
    if(filmovi.dohvatiEl(i).getNaziv()==ime){
      brojac++;
      if(ispis==1) filmovi.dohvatiEl(i).printFilm();
    }
  }
  return brojac;
}

void listaFilmova::pregledFilma(std::string ime){
  if(pretrazi(ime,1)) 
    ;
}

void listaFilmova::posudiFilm(int serial){
  int provjera=0;
  for(int i=0;i<filmovi.velicina();i++)
    if(filmovi.dohvatiEl(i).getSerijski()==serial){
      provjera++;
      if(filmovi.dohvatiEl(i).getBrKopija())
        filmovi.dohvatiEl(i).setBrKopija(filmovi.dohvatiEl(i).getBrKopija()-1);
          else std::cout<<"Nema dostupnih kopija."<<endl;
    }
  if(provjera==0) std::cout<<"Film se ne nalazi u videoteci."<<endl;
  
}

void listaFilmova::vratiFilm(int serial){
  int provjera=0;
  for(int i=0;i<filmovi.velicina();i++)
    if(filmovi.dohvatiEl(i).getSerijski()==serial){
      provjera++;
      filmovi.dohvatiEl(i).setBrKopija(filmovi.dohvatiEl(i).getBrKopija()+1);
    }
  if(provjera==0) std::cout<<"Film se ne nalazi u videoteci."<<endl;
}

void listaFilmova::dodajFilm(Film f){
  for(int i=0;i<filmovi.velicina();i++)
    if(filmovi.dohvatiEl(i).getSerijski()==f.getSerijski()) {cout<<"Serijski broj je vec u upotrebi."<<endl; return;
    }

  if(filmovi.velicina()==filmovi.maxVelicina()) {cout<<"Videoteka je puna."<<endl; return;}

  filmovi.dodajNaKraj(f);}

  void listaFilmova::ukloniFilm(int serial){
    for(int i=0;i<filmovi.velicina();i++){
      if(filmovi.dohvatiEl(i).getSerijski()==serial){
        filmovi.ukloniSaLokacije(i);
        cout<<"Film je izbrisan iz videoteke."<<endl;
        return;
    }}
      cout<<"Film ne postoji u videoteci."<<endl;
  }


#endif
