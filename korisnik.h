#ifndef _KORISNIK_H
#define _KORISNIK_H

#include "osoba.h"
#include "datum.h"
class Korisnik{
  private:
    Osoba osoba;
    Datum datum;
    int brPosFilmova=0;
  public:
    Korisnik()=default;
    Korisnik(Osoba o,Datum d):osoba(o),datum(d){};
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
};



#endif
