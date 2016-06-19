#ifndef _LISTAFILMOVA_H
#define _LISTAFILMOVA_H

#include "film.h"

class listaFilmova{
  private:
    const std::string _imeV="Films and Structures";
    ListaNizom<Film> filmovi;
  public:
    listaFilmova()=default;
    ~listaFilmova()=default;
    int trenutnoStanje();
    void print();
    int pretraziSer(int serijski);
    int pretrazi(std::string ime,int ispis=0);
    int pregledFilma(std::string ime);
    void posudiFilm(int serial);
    void vratiFilm(int serial);
    void dodajFilm();
    void dodajFilm(Film f);
    void ukloniFilm(int serial);
    void azurirajFilm(int serial);

    const std::string getImeV() const {return _imeV;}
    
    ListaNizom<Film>& getFilmovi(){return this->filmovi;}
};

int listaFilmova::trenutnoStanje(){
  return filmovi.velicina();
}

Film kreirajFilm(){
  cout<<"Unesite naziv filma: ";
  std::string naziv;
  std::string temp; 
  cin.clear(); 
  while(cin>>temp){naziv+=temp+" ";}
  
  cout<<"Unesite opis filma: ";
  std::string opis; 
  cin.clear(); 
  while(cin>>temp){opis+=temp+" ";};
  
  cout<<"Unesite ime i prezime rezisera: ";
  std::string ime,prezime; 
  cin.clear(); 
  cin>>ime>>prezime;
  Osoba rez(ime,prezime);
  
  cout<<"Unesite broj producenata: ";
  int broj; 
  cin.clear(); 
  cin>>broj;
  ListaNizom<Osoba> lp;
  for(int i=0;i<broj;i++){
    cout<<"Unesite ime i prezime producenta: ";
    cin.clear(); 
    cin>>ime>>prezime;
    Osoba temp(ime,prezime); 
    lp.dodajNaKraj(temp);
  }
  
  cout<<"Unesite broj scenarista: ";
  cin.clear(); 
  cin>>broj;
  ListaNizom<Osoba> ls;
  for(int i=0;i<broj;i++){
    cout<<"Unesite ime i prezime producenta: ";
    cin.clear(); 
    cin>>ime>>prezime;
    Osoba temp(ime,prezime); 
    ls.dodajNaKraj(temp);
  }
  
  cout<<"Unesite broj glumaca: ";
  cin.clear(); 
  cin>>broj;
  ListaNizom<Osoba> lg;
  for(int i=0;i<broj;i++){
    cout<<"Unesite ime i prezime glumca: ";
    cin.clear(); 
    cin>>ime>>prezime;
    Osoba temp(ime,prezime); 
    lg.dodajNaKraj(temp);
  }

  cout<<"Unesite naziv produkcijske kompanije: ";
  std::string prkomp;  
  cin.clear(); 
  while(cin>>temp) prkomp+=temp+" ";

  cout<<"Unesite godinu izdavanja: ";
  unsigned int godizd; 
  cin.clear(); 
  cin>>godizd;

  cout<<"Unesite broj kopija: ";
  unsigned int brkop; 
  cin.clear(); 
  cin>>brkop;

  cout<<"Unesite serijski broj"<<endl;
  cout<<"NAPOMENA: ukoliko serijski broj vec postoji u videoteci, unos nece biti validan!"<<endl;
  int ser; 
  cin.clear(); 
  cin>>ser;

  Film f(naziv,opis,rez,lp,ls,lg,prkomp,godizd,brkop,ser);
  return f;
}


void listaFilmova::print(){
 for(int i=0;i<filmovi.velicina();i++){
   filmovi.dohvatiEl(i).printFilm();
   cout<<endl;
}}

int listaFilmova::pretraziSer(int serijski){
  int trind=-1;
  for(int i=0;i<filmovi.velicina();i++){
    if(filmovi.dohvatiEl(i).getSerijski()==serijski){
      trind=i;
      break;
  }
}
  return trind;
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

int listaFilmova::pregledFilma(std::string ime){
  if(pretrazi(ime,1)) return 1;
    
  else return 0;
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
  if(filmovi.velicina()==filmovi.maxVelicina()){cout<<"Videoteka je puna."<<endl;return;}
  for(int i=0;i<filmovi.velicina();i++) 
    if(filmovi.dohvatiEl(i).getSerijski()==f.getSerijski()){
      cout<<"Serijski broj je vec u upotrebi."<<endl; 
      return;}
  filmovi.dodajNaKraj(f);
}

void listaFilmova::dodajFilm(){
  if(filmovi.velicina()==filmovi.maxVelicina()){cout<< "Videoeka je puna."<<endl; return;}
  
  Film temp=kreirajFilm();

  for(int i=0;i<filmovi.velicina();i++)
    if(filmovi.dohvatiEl(i).getSerijski()==temp.getSerijski()) {cout<<"Serijski broj je vec u upotrebi."<<endl; return;
    }
  filmovi.dodajNaKraj(temp);
}

  void listaFilmova::ukloniFilm(int serial){
    for(int i=0;i<filmovi.velicina();i++){
      if(filmovi.dohvatiEl(i).getSerijski()==serial){
        filmovi.ukloniSaLokacije(i);
        cout<<"Film je izbrisan iz videoteke."<<endl;
        return;
    }}
      cout<<"Film ne postoji u videoteci."<<endl;
  }

void listaFilmova::azurirajFilm(int serial){
  int ind=-1;
  
  for(int i=0;i<filmovi.velicina();i++){
    if(filmovi.dohvatiEl(i).getSerijski()==serial) ind=i;
  }
  
  if(ind==-1) {
    cout<<"Film nije u videoteci"<<endl;
    return;
  }

  cout<<"Koju informaciju zelite azurirati: "<<endl;
  cout<<" 1. Naziv"<<endl;
  cout<<" 2. Opis"<<endl;
  cout<<" 3. Rezisera"<<endl;
  cout<<" 4. Listu producenata"<<endl;
  cout<<" 5. Listu scenarista"<<endl;
  cout<<" 6. Listu glumaca"<<endl;
  cout<<" 7. Produkcijsku kompaniju"<<endl;
  cout<<" 8. Godinu izdavanja"<<endl;
  cout<<" 9. Broj kopija"<<endl;
  cout<<"10. Serijski broj"<<endl;
  int odabir;
  int broj;
  std::string nime;
  std::string nprezime;
  Osoba nosoba;
  ListaNizom<Osoba> nova;
  std::string novi;
  cin.clear(); cin>>odabir;
  switch(odabir){
    case 1 : cout<<"Unesite novi naziv filma: ";
             cin.clear(); 
             cin>>novi;
             filmovi.dohvatiEl(ind).setNaziv(novi);
             break;
    case 2 : cout<<"Unesite novi opis filma: ";
             cin.clear(); 
             cin>>novi;
             filmovi.dohvatiEl(ind).setOpis(novi);
             break;
    case 3 : cout<<"Unesite novo ime i prezime rezisera: ";
             cin.clear();
             cin>>nime>>nprezime;
             nosoba.setIme(nime);
             nosoba.setPrezime(nprezime);
             filmovi.dohvatiEl(ind).setReziser(nosoba);
             break;
    case 4 : cout<<"Koliko clanova ima nova lista? ";
             cin.clear();
             cin>>broj;
             for(int i=0;i<broj;i++){
               cout<<"Unesite ime i prezime: ";
               cin>>nime>>nprezime;
               nosoba.setIme(nime);
               nosoba.setPrezime(nprezime);
               nova.dodajNaKraj(nosoba);
             }
             filmovi.dohvatiEl(ind).setProducenti(nova);         
             break;
    case 5 : cout<<"Koliko clanova ima nova lista?";
             cin.clear();
             cin>>broj;
             for(int i=0;i<broj;i++){
               cout<<"Unesite ime i prezime: ";
               cin>>nime>>nprezime;
               nosoba.setIme(nime);
               nosoba.setPrezime(nprezime);
               nova.dodajNaKraj(nosoba);
             }
             filmovi.dohvatiEl(ind).setScenaristi(nova);
             break;
    case 6 : cout<<"Koliko clanova ima nova lista?";
             cin.clear();
             cin>>broj;
             for(int i=0;i<broj;i++){
               cin.clear();
               cout<<"Unesite ime i prezime: ";
               cin>>nime>>nprezime;
               nosoba.setIme(nime);
               nosoba.setPrezime(nprezime);
               nova.dodajNaKraj(nosoba);
             }
             filmovi.dohvatiEl(ind).setGlumci(nova);
             break;
    case 7 : cout<<"Unesite novu produkcijsku kompaniju: ";
             cin.clear(); 
             cin>>novi;
             filmovi.dohvatiEl(ind).setKompanija(novi);
             break;
    case 8 : cout<<"Unesite godinu izdavanja: ";
             cin.clear(); 
             cin>>broj;
             filmovi.dohvatiEl(ind).setGodIzd(broj);
             break;
    case 9 : cout<<"Unesite broj kopija: ";
             cin.clear(); 
             cin>>broj;
             filmovi.dohvatiEl(ind).setBrKopija(broj);
             break;
    case 10 : cout<<"Unesite serijski broj: ";
              cin.clear(); 
              cin>>broj;
              filmovi.dohvatiEl(ind).setSerijski(broj);
              break;
  }
}

#endif
