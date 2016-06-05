#ifndef _OSOBA_H
#define _OSOBA_H

#include <string>

class Osoba{
private: 
std::string _ime;
std::string _prezime;
unsigned long int _jmbg;
public:
Osoba()=default;
Osoba(std::string ime,std::string prezime,unsigned long int jmbg):_ime(ime),_prezime(prezime),_jmbg(jmbg){};
~Osoba()=default;

std::string getIme(){return _ime;};
std::string getPrezime(){return _prezime;}
unsigned long int getJMBG(){return _jmbg;}
};

#endif
