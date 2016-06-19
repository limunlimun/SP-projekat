#ifndef _KORISNIK_H
#define _KORISNIK_H
#include <sstream>
#include "osoba.h"
#include "datum.h"
// klasa za korisnike
class Korisnik{
  private:
    Osoba osoba;//korisnik treba da nasljedjuje od osobe umjesto sto ima osobu
    Datum datum;
    int brPosFilmova=0;
  public:
    //osnovni konstruktori
    Korisnik()=default;
    Korisnik(Osoba o,Datum d,int br):osoba(o),datum(d),brPosFilmova(br){};
    ~Korisnik()=default;
    //osnovne metode za rad sa korisnicima
    void setOsoba(const Osoba& x){osoba=x;	}
	void setdatum(const Datum& x){datum=x;	}
	void setBrPF(int x){brPosFilmova=x;}
   
    Osoba& getOsoba(){return this->osoba;}
    Datum& getDatum(){return this->datum;}
    int getBrPF(){return brPosFilmova;}
    //osnovni operatori za poredjenje korisnika
    bool operator>(const Korisnik& x)
    {
    	if(datum > x.datum)
    	return true;
    	else 
		return false;
	}
	bool operator<(const Korisnik& x)
    {
    	if(datum < x.datum)
    	return true;
    	else 
		return false;
	}
	
	bool operator==(const Korisnik& x)
	{
		if(datum==x.datum && osoba==x.osoba && brPosFilmova==x.brPosFilmova )
		return true;
		else 
		return false;
	}
//metod za ispisivanje u file
  std::string ispis(){
    std::string povratni;
    povratni+=osoba.getPrezime()+';'+osoba.getIme()+';';
    povratni+=osoba.getJMBG()+';';
    std::stringstream a;
    std::stringstream b;
    std::stringstream c;
    std::stringstream d;
    a<<datum.getDan();
    b<<datum.getMjesec();
    c<<datum.getGodina();
    d<<brPosFilmova;
    povratni+=a.str()+';'+b.str()+';'+c.str()+';'+d.str();
    return povratni;
    
  }
};



#endif
