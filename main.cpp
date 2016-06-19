#include "admin.h"
#include "lista_filmova.h"
#include "Lista_korisnika.h"
//#include "lista.hxx"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int ss =1000;
int poc=1;

vector<Osoba> rastaviOsobe(string lista){
  stringstream x(lista);
  string novi;
  string zaosobu;
  vector<Osoba> povratni;
  string ime; string prezime;
  while(getline(x,novi,',')) {
    stringstream y(novi);
    vector<string> pomocni;
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
  stringstream x(temp.at(7));
  unsigned int godizd;
  x>>godizd;
  stringstream y(temp.at(8));
  unsigned int brkop;
  y>>brkop;
  stringstream z(temp.at(9));
  unsigned int ser; 
  z>>ser;
    
  ListaNizom<Osoba> lp;
  osobe=rastaviOsobe(temp[3]);
  for(int i=0;i<osobe.size();i++) lp.dodajNaKraj(osobe[i]);
  
  ListaNizom<Osoba> ls;
  osobe=rastaviOsobe(temp[4]);
  for(int i=0;i<osobe.size();i++) ls.dodajNaKraj(osobe[i]);
  ListaNizom<Osoba> lg;
  osobe=rastaviOsobe(temp[5]);
  for(int i=0;i<osobe.size();i++) lg.dodajNaKraj(osobe[i]);
  Film pom(temp[0],temp[1],rez,lp,ls,lg,temp[6],godizd,brkop,ser);
return pom;
}


Korisnik kreirajKorisnika(string red){
  vector<string> temp=rastavi(red);
  Osoba o(temp[1],temp[0],temp[2]);
  stringstream x(temp.at(3));
  stringstream y(temp.at(4));
  stringstream z(temp.at(5));
  stringstream w(temp.at(6));
  int dan,mj,god,br;
  x>>dan;
  y>>mj;
  z>>god;
  w>>br;
  Datum d(dan,mj,god);
  Korisnik povratni(o,d,br);
  return povratni;
}
    
int main(){
  listaFilmova Videoteka;
  ListaKorisnika Clanovi;
  
  ifstream infile;
  infile.open("Arhiva.txt");
  if(infile.fail()){
    cerr<<"Greska.Terminiraj."<<endl;
    exit(1);
  }
  string red;
  Korisnik priv;
  while(getline(infile,red)){
    priv=kreirajKorisnika(red);
    Clanovi.dodajKorisnika(priv);
  }
  infile.close();

  
  infile.open("lista_filmova.txt");
  if(infile.fail()){
    cerr<<"Greska.Terminiraj."<<endl;
    exit(1);
  }

  Film temp;

  while(getline(infile,red)){
    temp=kreiraj(red);
    temp.setSerijski(++poc);
    Videoteka.dodajFilm(temp);
    }
  for(int i=0;i<Videoteka.trenutnoStanje();i++){
    
    Videoteka.getFilmovi().dohvatiEl(i).setSerijski(ss++);
    
  }


  Admin admin;
  int menu=0;
  cout<<"Unesite korisnicko ime i password: ";
  string ime;
  string lozinka;
  cin>>ime>>lozinka;
  if (admin.login(ime,lozinka)) menu=1;
  //else if - odraditi pretragu korisnika po imenu i lozinci
  //te postaviti menu na 2
  //else - ako nijedan unos nije zadocoljen terminirati program
  if(menu) 
    cout<<endl<<ime<<", dobrodosli u videoteku "<<Videoteka.getImeV()<<endl;
  if(menu==0) 
    cout<<"Unos nije validan. Program se terminira!"<<endl;
  if(menu==1){
  int izlaz=0;
  int odabir=0;
  while(izlaz!=1){
    cout<<endl<<endl;
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
    cout<<endl<<endl;
    //pomocne varijable koje ce se koristiti prilikom neke od navedenih opcija
    string ime,prezime,jmbg;
    int ind;
    string pretrazi;
    int serijski;
    int temp;

    switch(odabir){
      case 1 : Videoteka.print();
               cout<<endl;
               break;
      case 2 : cout<<"Unesite naziv filma: ";
               cin.clear();cin>>pretrazi;
               temp=Videoteka.pretrazi(pretrazi);
               cout<<"Pronadjeno je "<<temp<<" filmova."<<endl;
               break;
      case 3 : cout<<"Unesite naziv filma: ";
               cin.clear();cin>>pretrazi;cout<<endl;
               temp=Videoteka.pregledFilma(pretrazi);
               if(!temp) cout<<"Film nije pronadjen"<<endl;
               cout<<endl;
               break;
      case 4 : Videoteka.dodajFilm();
               
               cout<<endl;
               break;
      case 5 : cout<<"Unesite serijski broj filma: ";
               cin.clear();cin>>serijski;
               Videoteka.ukloniFilm(serijski);
               cout<<endl;
               break;
      case 6 : cout<<"Unesite serijski broj filma: ";
               cin.clear(); cin>>serijski;
               Videoteka.azurirajFilm(serijski);
               cout<<endl;
               break;
      case 7 : cout<<"Unesite ime i prezime korisnika: ";
               cin.clear();
               cin>>ime>>prezime;
               ind=Clanovi.pretragaKorisnika2(ime,prezime);
               if(ind==-1)
                 cout<<"Korisnike nije pronadjen!"<<endl;
               else
                 cout<<prezime<<" "<<ime<<" "<<Clanovi.getBaza().dohvatiEl(ind).getOsoba().getJMBG()<<endl;

               break;
      case 8 : cout<<"Unesite ime i prezime korisnika: ";
               cin.clear();
               cin>>ime>>prezime;
               ind=Clanovi.pretragaKorisnika2(ime,prezime);
               if(ind==-1) 
                 cout<<"Korisnik nije pronadjen!"<<endl;
               else cout<<"Korisnik se nalazi u bazi!"<<endl;
               break;
      case 9 : Clanovi.kreirajKorisnika();
               break;
      case 10 : cout<<"Unesite JMBG korisnika: ";
                cin.clear();
                cin>>jmbg;
                Clanovi.obrisiKorisnika(jmbg);
                break;
      case 11 : break;
      case 12 : break;
      case 13 : break;
      case 14 : izlaz=1;
                break;
      default : cout<<"Pogresan unos. Program se terminira!"<<endl;
                izlaz=1;
                cout<<endl;
                break;
    } //kraj switch


  }//kraj while
}//kraj if(menu)

if(menu==2){
  int izlaz=0;
  int odabir=0;
  while(izlaz!=1){
    cout<<endl<<endl;
    cout<<"Ponudjene opcije: "<<endl;
    cout<<"1. Pregled sadrzaja videoteke"<<endl;
    cout<<"2. Pretraga po nazivu filma"<<endl;
    cout<<"3. Ispis svih podataka za odabrani film"<<endl;
    cout<<"4. Posudi film"<<endl;
    cout<<"5. Vrati film"<<endl;
    cout<<"6. Pregled svoje historije posudjivanja filmova"<<endl;
    cout<<"7. Pregled trenutne liste posudjenih filmova"<<endl;
    cout<<"8. Izlaz iz programa"<<endl;
    cout<<endl<<"Unesite broj odabrane opcije: ";
    cin.clear();
    cin>>odabir;
    //pomocne varijable
    string pretrazi;
    int temp;
    int serijski;

    switch(odabir){
      case 1 : Videoteka.print();
               cout<<endl;
               break;
      case 2 : cout<<"Unesite naziv filma: ";
               cin.clear(); cin>>pretrazi;
               temp=Videoteka.pretrazi(pretrazi);
               cout<<"Pronadjeno je "<<temp<<" filmova."<<endl;
               cout<<endl;
               break;
      case 3 : cout<<"Unesite naziv filma: ";
               cin.clear(); cin>>pretrazi;
               temp=Videoteka.pregledFilma(pretrazi);
               if(!temp) cout<<"Film nije pronadjen"<<endl;
               cout<<endl;
               break;
      case 4 : //metod za posudjivanje filma
               break;
      case 5 : //metod za vracanje filma
               break;
      case 6 : break;
      case 7 : break;
      case 8 : cout<<"Dodjite nam opet :)"<<endl;
               izlaz=1;
               cout<<endl;
               break;
      default : cout<<"Unos nije validan. Program se terminira"<<endl;
                izlaz=1;
                break;
      
    }//kraj switch

  }//kraj while
}//kraj if


ofstream ofile("lista_filmova.txt");
for(int i=0;i<Videoteka.trenutnoStanje();i++)
  ofile<<Videoteka.getFilmovi().dohvatiEl(i).pripremiIspis()<<endl;

  ofile.close();

ofstream izlazni("Arhiva.txt");
     for(int i=0;i<Clanovi.brojClanova();i++){
      izlazni<<Clanovi.getBaza().dohvatiEl(i).ispis()<<endl;
  }
 izlazni.close();

  return 0;
}
