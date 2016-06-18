#ifndef _KORISNIK_H
#define _KORISNIK_H
#include <sstream>
#include "osoba.h"
#include "datum.h"
class Korisnik{
  private:
    Osoba osoba;
    Datum datum;
    int brPosFilmova=0;
  public:
    Korisnik()=default;
    Korisnik(Osoba o,Datum d,int br):osoba(o),datum(d),brPosFilmova(br){};
    ~Korisnik()=default;
    
    void setOsoba(const Osoba& x){osoba=x;	}
	void setdatum(const Datum& x){datum=x;	}
	void setBrPF(int x){brPosFilmova=x;}
   
    Osoba getOsoba(){return osoba;}
    Datum getDatum(){return datum;}
    int getBrPF(){return brPosFilmova;}
    
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

  std::string ispis(){
    std::string povratni;
    povratni+=osoba.getPrezime()+';'+osoba.getIme()+';';
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
