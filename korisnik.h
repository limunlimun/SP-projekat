#ifndef _KORISNIK_H
#define _KORISNIK_H

#include "osoba.h"
#include "datum.h"
class Korisnik{
  private:
    Osoba osoba;
    Datum datum;
  public:
    Korisnik()=default;
    Korisnik(Osoba o,Datum d):osoba(o),datum(d){};
    ~Korisnik()=default;

    Osoba getOsoba(){return osoba;}
    Datum getDatum(){return datum;}
};



#endif
