#ifndef _HISTORIJA_H
#define _HISTORIJA_H

#include <string>
#include <sstream>

//klasa pomocu koje ce se pratiti posudjivanje filmova
class Historija{
  private:
    //clanovi su jmbg korisnika i serijski broj filma kao jedinstveni podaci o korisniku i filmu
    std::string _jm;
    int _ser;
  public:
    // osnovne metode
    void setJM(std::string jm){_jm=jm;}
    void setSer(int ser){_ser=ser;}
    std::string getJM(){return _jm;}
    int getSer(){return _ser;}
    //osnovni konstruktori
    Historija()=default;
    Historija(std::string j,int s):_jm(j),_ser(s){};
    ~Historija()=default;
//metod za upis u fileove
    std::string printUnos(){
      std::string povratni;
      std::stringstream a;
      a<<_ser;
      povratni=_jm+';'+a.str();
      return povratni;
    }
};

#endif
