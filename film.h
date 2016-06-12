#ifndef _FILM_H
#define _FILM_H
#include <iomanip>

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
    int serijski;//jedinstveni kljuc ukoliko postoji vise filmova sa istim imenom
  public:
    Film()=default;
    Film(std::string naziv,std::string opis,Osoba rez,ListaNizom<Osoba> lp,ListaNizom<Osoba> ls,ListaNizom<Osoba> lg,std::string komp,unsigned int godizd,unsigned int brkop,int ser):_naziv(naziv),_opis(opis),_reziser(rez),lista_producenata(lp),lista_scenarista(ls),lista_glumaca(lg),prod_komp(komp),god_izdavanja(godizd),broj_kopija(brkop),serijski(ser){};
    ~Film()=default;
    Film(Film &f){
      _naziv=f._naziv;
      _opis=f._opis;
      _reziser=f._reziser;
      lista_producenata=f.lista_producenata;
      lista_scenarista=f.lista_scenarista;
      lista_glumaca=f.lista_glumaca;
      prod_komp=f.prod_komp;
      god_izdavanja=f.god_izdavanja;
      broj_kopija=f.broj_kopija;
      serijski=f.serijski;
    }
   
    std::string getNaziv(){return _naziv;}
    std::string getOpis(){return _opis;}
    Osoba getOsoba(){return _reziser;}
    ListaNizom<Osoba> getProducenti(){return lista_producenata;}
    ListaNizom<Osoba> getScenaristi(){return lista_scenarista;}
    ListaNizom<Osoba> getGlumci(){return lista_glumaca;}
    std::string getKompanija(){return prod_komp;}
    unsigned int getGodIzdavanja(){return god_izdavanja;}
    unsigned int getBrKopija(){return broj_kopija;}
    int getSerijski(){return serijski;}

    void setNaziv(std::string x){_naziv=x;}
    void setOpis(std::string x){_opis=x;}
    //nedostaje reziser i setovanje listi
    //potrebno u klasu osoba dodati konstruktos Osoba(Osoba)
    void setKompanija(std::string x){prod_komp=x;}
    void setGodIzd(int x){god_izdavanja=x;}
    void setBrKopija(int x){broj_kopija=x;}
    void setSerijski(int x){serijski=x;}
	void operator=(const Film& x)
	{
		this->_naziv=x._naziv;
		this->lista_glumaca=x.lista_glumaca;
		this->lista_producenata=x.lista_producenata;
		this->lista_scenarista=x.lista_scenarista;
		this->god_izdavanja=x.god_izdavanja;
		this->broj_kopija=x.broj_kopija;
		this->prod_komp=x.prod_komp;
		this->_opis=x._opis;
		this->_reziser=x._reziser;
	}
	
	void operator=(Film&& x)
	{
		this->_naziv=std::move(x._naziv);
		this->lista_glumaca=std::move(x.lista_glumaca);
		this->lista_producenata=std::move(x.lista_producenata);
		this->lista_scenarista=std::move(x.lista_scenarista);
		this->god_izdavanja=std::move(x.god_izdavanja);
		this->broj_kopija=std::move(x.broj_kopija);
		this->prod_komp=std::move(x.prod_komp);
		this->_opis=std::move(x._opis);
		this->_reziser=std::move(x._reziser);
	}
    void printFilm(){
      cout<<setw(4);
      cout<<"Naziv: "<<_naziv<<endl;
      cout<<setw(4);
      cout<<"Opis: "<<_opis<<endl;
      cout<<setw(4); 
      cout<<"Reziser: "; _reziser.printOsoba(); cout<<endl;
      cout<<setw(4); 
      cout<<"Producenti: ";
      for(int i=0;i<lista_producenata.velicina();i++){
        lista_producenata.dohvatiEl(i).printOsoba();
        cout<<" ";} cout<<endl;
      cout<<setw(4);
      cout<<"Scenaristi: ";
      for(int i=0;i<lista_scenarista.velicina();i++){
        lista_scenarista.dohvatiEl(i).printOsoba();
        cout<<" ";} cout<<endl;
      cout<<setw(4);
      cout<<"Glumci: ";
      for(int i=0;i<lista_glumaca.velicina();i++){
        lista_glumaca.dohvatiEl(i).printOsoba();
      cout<<" ";} cout<<endl;
      cout<<setw(4);
      cout<<"Produkcijska kompanija: "<<prod_komp<<endl;
      cout<<setw(4);
      cout<<"Godina izdavanja: "<<god_izdavanja<<endl;
      cout<<setw(4);
      cout<<"Broj kopija: "<<broj_kopija<<endl;
      cout<<setw(4);
      cout<<"Serijski broj: "<<serijski<<endl;
}

};

#endif
