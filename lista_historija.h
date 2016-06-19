#ifndef _L_HISTORIJA_H
#define _L_HISTORIJA_H

#include "historija.h"
#include "Lista_korisnika.h"
class ListaHistorija{
  private:
    ListaNizom<Historija> _lh;
  public:
    ListaHistorija()=default;
    ~ListaHistorija()=default;
    ListaNizom<Historija>& getLH(){return _lh;}
    void dodajUnos(Historija& h){
      _lh.dodajNaKraj(h);
    }
    void obrisiUnos(Historija& h){
      for(int i=0;i<_lh.velicina();i++){
        if(_lh.dohvatiEl(i).getJM()==h.getJM() && _lh.dohvatiEl(i).getSer()==h.getSer()) 
          _lh.ukloniSaLokacije(i);
        break;
      }
    }


};

#endif
