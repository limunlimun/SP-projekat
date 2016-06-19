#ifndef _HISTORIJA_H
#define _HISTORIJA_H

#include <string>
#include <sstream>

class Historija{
  private:
    std::string _jm;
    int _ser;
  public:
    void setJM(std::string jm){_jm=jm;}
    void setSer(int ser){_ser=ser;}
    std::string getJM(){return _jm;}
    int getSer(){return _ser;}
    Historija()=default;
    Historija(std::string j,int s):_jm(j),_ser(s){};
    ~Historija()=default;

    std::string printUnos(){
      std::string povratni;
      std::stringstream a;
      a<<_ser;
      povratni=_jm+';'+a.str();
      return povratni;
    }
};

#endif
