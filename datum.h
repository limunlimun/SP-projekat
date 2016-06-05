#ifndef _DATUM_H
#define _DATUM_H

class Datum{
  private:
    int _dan;
    int _mjesec;
    int _godina;
  public:
    Datum()=default;
    Datum(int d,int m,int g):_dan(d),_mjesec(m),_godina(g){};
    ~Datum()=default;

    int getDan(){return _dan;}
    int getMjesec(){return _mjesec;}
    int getGodina(){return _godina;}
  };

#endif
