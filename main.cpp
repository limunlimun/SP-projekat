#include "admin.h"
#include "lista_filmova.h"
#include "lista.hxx"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<Osoba> rastaviOsobe(string lista){
  stringstream x(lista);
  string novi;
  string zaosobu;
  vector<Osoba> povratni;
  vector<string> pomocni;
  string ime; string prezime;
  while(getline(x,novi,',')) {
    stringstream y(novi);
    while(getline(y,zaosobu,'.')) pomocni.push_back(zaosobu);
    ime=pomocni[0]; prezime=pomocni[1];
    Osoba temp(ime,prezime);
    povratni.push_back(temp);
  }
  return povratni;
}

vector<string> rastavi(string red){
  stringstream x(red);
  string novi;
  vector<string> povratni;
  while(getline(x,novi,';')) povratni.push_back(novi);
  return povratni;
}

Film kreiraj(string red){
  vector<string> temp=rastavi(red);
  Osoba rez;
  vector<Osoba> osobe=rastaviOsobe(temp[2]);
  rez=osobe[0];
  stringstream x(temp.at(7));unsigned int godizd;x>>godizd;
  stringstream y(temp.at(8));unsigned int brkop;y>>brkop;
  stringstream z(temp.at(9));int ser;z>>ser;
  ListaNizom<Osoba> lp;
  osobe=rastaviOsobe(temp[3]);
  for(int i=0;i<temp.size();i++) lp.dodajNaKraj(osobe[i]);
  ListaNizom<Osoba> ls;
  osobe=rastaviOsobe(temp[4]);
  for(int i=0;i<temp.size();i++) ls.dodajNaKraj(osobe[i]);
  ListaNizom<Osoba> lg;
  osobe=rastaviOsobe(temp[5]);
  for(int i=0;i<temp.size();i++) lg.dodajNaKraj(osobe[i]);
  Film pom(temp[0],temp[1],rez,lp,ls,lg,temp[6],godizd,brkop,ser);
return pom;
}



int main(){
  listaFilmova Videoteka;
  ifstream infile;
  infile.open("lista_filmova.txt");
  if(infile.fail()){cerr<<"Greska.Terminiraj."<<endl;exit(1);}
  string red;
  while(getline(infile,red)){
    Videoteka.dodajFilm(kreiraj(red));
  }

  Admin admin;
  cout<<"Unesite korisnicko ime i password za administratora: ";
  string ime;
  string lozinka;
  cin>>ime>>lozinka;
  if (!admin.login(ime,lozinka)) {cout<<"Pogresan unos.Program se terminira!"<<endl;
  return 0;
}
else{
  int izlaz=0;
  int odabir=0;
  while(izlaz!=1){
    
    cout<<"Ponudjenje opcije:"<<endl;
    cout<<" 1. Pregled sadrzaja videoteke"<<endl;
    cout<<" 2. Pretraga videoteke po nazivu filma"<<endl;
    cout<<" 3. Ispis svih podataka za odabrani film"<<endl;
    cout<<" 4. Dodavanje novog filma"<<endl;
    cout<<" 5. Brisanje filma iz videoteke"<<endl;
    cout<<" 6. Azuriraj postojeci film"<<endl;
    cout<<" 7. Pregled korisnika"<<endl;
    cout<<" 8. Pretraga korisnika"<<endl;
    cout<<" 9. Dodavanje korisnika"<<endl;
    cout<<"10. Brisanje korisnika"<<endl;
    cout<<"11. Azuriranje korisnika"<<endl;
    cout<<"12. Pregled posudjenih filmova za odredjenog korisnika"<<endl;
    cout<<"13. Pregled historije posudjivanja za odredjenog korisnika"<<endl;
    cout<<"14. Izlaz iz programa"<<endl;
    cout<<endl<<"Unesite broj odabrane opcije: ";
    cin.clear();
    cin>>odabir;
    switch(odabir){
      case 1 : break;
      case 2 : break;
      case 3 : break;
      case 4 : break;
      case 5 : break;
      case 6 : break;
      case 7 : break;
      case 8 : break;
      case 9 : break;
      case 10 : break;
      case 11 : break;
      case 12 : break;
      case 13 : break;
      case 14 : izlaz=1;
                break;
      default : cout<<"Pogresan unos. Pokusajte ponovo"<<endl;
                break;
    } 


  }

}}
