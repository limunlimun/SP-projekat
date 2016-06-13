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
    void dodajFilm();
    void ukloniFilm(int serial);
    void azurirajFilm();

};

Film kreirajFilm(){
  cout<<"Unesite naziv filma: ";
  std::string naziv; cin.clear(); cin>>naziv;
  
  cout<<"Unesite opis filma: ";
  std::string opis; cin.clear(); cin>>opis;
  
  cout<<"Unesite ime i prezime rezisera: ";
  std::string ime,prezime; cin.clear(); cin>>ime>>prezime;
  Osoba rez(ime,prezime);
  
  cout<<"Unesite broj producenata: ";
  int broj; cin.clear(); cin>>broj;
  ListaNizom<Osoba> lp;
  for(int i=0;i<broj;i++){
    cout<<"Unesite ime i prezime producenta: ";
    cin.clear(); cin>>ime>>prezime;
    Osoba temp(ime,prezime); lp.dodajNaKraj(temp);
  }
  
  cout<<"Unesite broj scenarista: ";
  cin.clear(); cin>>broj;
  ListaNizom<Osoba> ls;
  for(int i=0;i<broj;i++){
    cout<<"Unesite ime i prezime producenta: ";
    cin.clear(); cin>>ime>>prezime;
    Osoba temp(ime,prezime); ls.dodajNaKraj(temp);
  }
  
  cout<<"Unesite broj glumaca: ";
  cin.clear(); cin>>broj;
  ListaNizom<Osoba> lg;
  for(int i=0;i<broj;i++){
    cout<<"Unesite ime i prezime glumca: ";
    cin.clear(); cin>>ime>>prezime;
    Osoba temp(ime,prezime); lg.dodajNaKraj(temp);
  }

  cout<<"Unesite naziv produkcijske kompanije: ";
  std::string prkomp;  cin.clear(); cin>>prkomp;

  cout<<"Unesite godinu izdavanja: ";
  unsigned int godizd; cin.clear(); cin>>godizd;

  cout<<"Unesite broj kopija: ";
  unsigned int brkop; cin.clear(); cin>>brkop;

  cout<<"Unesite serijski broj"<<endl;
  cout<<"NAPOMENA: ukoliko serijski broj vec postoji u videoteci, unos nece biti validan!"<<endl;
  int ser; cin.clear(); cin>>ser;

  Film f(naziv,opis,rez,lp,ls,lg,prkomp,godizd,brkop,ser);
  return f;
}


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

void listaFilmova::dodajFilm(){
  if(filmovi.velicina()==filmovi.maxVelicina()){cout<< "Videoeka je puna."<<endl; return;}
  
  Film temp=kreirajFilm();

  for(int i=0;i<filmovi.velicina();i++)
    if(filmovi.dohvatiEl(i).getSerijski()==temp.getSerijski()) {cout<<"Serijski broj je vec u upotrebi."<<endl; return;
    }
  filmovi.dodajNaKraj(temp);}

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
