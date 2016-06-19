#include "admin.h"
#include "lista_filmova.h"
#include "Lista_korisnika.h"
#include "lista_historija.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <unistd.h>
using namespace std;

int ss =1000;
int poc=1;
//pomocne globalne varijable za rucno kreiranje JMBG
string pd[]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28"};
string pm[]={"01","02","03","04","05","06","07","08","09","10","11","12"};
string pg[]={"990","991","992","993","994","995","996","997","998","999"};
string pn[]={"180","185"};
string pn2[]={"070","071","072","073","074","075","076","077","078","079","080","081","082","083","084","085","086","087","088","089"};
//funkcija za rastavljanje elemenata unutar jedne liste
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
//funkcija za rastavljanje stringa na podstringove
vector<string> rastavi(string red){
  stringstream x(red);
  string novi;
  vector<string> povratni;
  while(getline(x,novi,';')) povratni.push_back(novi);
  return povratni;
}
//funkcija za kreiranje filma iz proslijedjenog reda iz file-a
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

//funkcija za kreiranje korisnika na osnovu proslijedjenog reda iz file-a
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
//funkcija za kreiranje unosa iz historije videoteke    
Historija kreirajHis(string red){
  vector<string> temp=rastavi(red);
  stringstream a(temp.at(1));
  int s;
  a>>s;
  Historija povratna(temp[0],s);
  return povratna;
}

//glavni program
int main(){
  //osnovne liste za rad u videoteci
  listaFilmova Videoteka;
  ListaKorisnika Clanovi;
  ListaHistorija UkupnaH;
  ListaHistorija TrenutnaH;
  Historija h;
  //upis clanova
  ifstream infile;
  infile.open("Arhiva.txt");
  if(infile.fail()){
    cerr<<"Greska.Terminiraj."<<endl;
    exit(1);
  }
  
  string red;
  Korisnik priv;
  string J;
  while(getline(infile,red)){
    priv=kreirajKorisnika(red);
    int dd=rand() % 28;
    int mm=rand() % 12;
    int gg=rand() % 9;
    int nn=rand() % 1;
    int nn2=rand() % 18;
    J=pd[dd]+pm[mm]+pg[gg]+pn[nn]+pn2[nn2];
    priv.getOsoba().setJMBG(J);
    Clanovi.dodajKorisnika(priv);
  }
  infile.close();

  //upis dosadasnje historije videoteke
  infile.open("ukhistorija.txt");
  if(infile.fail()){
    cerr<<"Greska.Terminiraj."<<endl;
    exit(1);
  }
  while(getline(infile,red)){
    h=kreirajHis(red);
    UkupnaH.dodajUnos(h);
  }
  infile.close();

  //upis trenutnog stanja podignutih filmova
  infile.open("trhistorija.txt");
  if(infile.fail()){
    cerr<<"Greska.Terminiraj."<<endl;
    exit(1);
  }
  while(getline(infile,red)){
    h=kreirajHis(red);
    TrenutnaH.dodajUnos(h);
  }
  infile.close();

  //upis filmova u videoteku
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

  

  //login administratora ili korisnika
  int indCl=-1;
  Admin admin;
  int menu=0;
  cout<<"Unesite korisnicko ime: ";
  string ime;
  string lozinka;
  cin>>ime;
  lozinka=getpass("Unesite password: ");
  if (admin.login(ime,lozinka)) menu=1;
  else if(Clanovi.pretragaKorisnika2(ime,lozinka)!=-1) {
    menu=2;
    indCl=Clanovi.pretragaKorisnika2(ime,lozinka);
  }
  else 
    menu=0;
  if(menu) 
    cout<<endl<<ime<<", dobrodosli u videoteku "<<Videoteka.getImeV()<<endl;
  if(menu==0) 
    cout<<"Unos nije validan. Program se terminira!"<<endl;
  if(menu==1){
  
    //interface videoteke za administratora sa svim opcijama
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
    cout<<"14. Korisnicki interface"<<endl;
    cout<<"15. Izlaz iz programa"<<endl;
    cout<<endl<<"Unesite broj odabrane opcije: ";
    cin.clear();
    cin>>odabir;
    cout<<endl<<endl;
    //pomocne varijable koje ce se koristiti prilikom neke od navedenih opcija
    string ime,prezime,jmbg;
    int ind;
    string pretrazi;
    int serijski;
    int temp=0;
    
    //implementacija opcija iz administratorskog interface-a
    switch(odabir){
      case 1 : //ispis svih filmova sa svim detaljima
               Videoteka.print();
               cout<<endl;
               break;
      case 2 : //pretraga filmova po nazivu
               cout<<"Unesite naziv filma: ";
               cin.clear();cin>>pretrazi;
               temp=Videoteka.pretrazi(pretrazi);
               cout<<"Pronadjeno je "<<temp<<" filmova."<<endl;
               break;
      case 3 : //ispisivanje svih detalja odredjenog filma
               cout<<"Unesite naziv filma: ";
               cin.clear();cin>>pretrazi;cout<<endl;
               temp=Videoteka.pregledFilma(pretrazi);
               if(!temp) cout<<"Film nije pronadjen"<<endl;
               cout<<endl;
               break;
      case 4 : //upis filma u videoteku
               Videoteka.dodajFilm();
               cout<<"Unesite serijski broj:  "<<endl;
               cin.clear();
               while(cin>>serijski){
                 if(Videoteka.pretraziSer(serijski)==-1) 
                   break;
                 else 
                   cout<<"Serijski broj u upotrebi."<<endl<<"Unesite serijski broj: ";
               } 
               Videoteka.getFilmovi().dohvatiEl(Videoteka.getFilmovi().velicina()-1).setSerijski(serijski);
               cout<<endl;
               break;
      case 5 : //brisanje filma iz videoteke
               cout<<"Unesite serijski broj filma: ";
               cin.clear();cin>>serijski;
               Videoteka.ukloniFilm(serijski);
               cout<<endl;
               break;
      case 6 : //azuriranje filma
               cout<<"Unesite serijski broj filma: ";
               cin.clear(); cin>>serijski;
               Videoteka.azurirajFilm(serijski);
               cout<<endl;
               break;
      case 7 : //pregled clanova videoteke
               cout<<endl<<"Ime i JMBG korisnika:"<<endl;
               for(int i=0;i<Clanovi.brojClanova();i++)
                 cout<<Clanovi.getBaza().dohvatiEl(i).getOsoba().getIme()<<" "<<Clanovi.getBaza().dohvatiEl(i).getOsoba().getJMBG()<<endl;
               cout<<endl;
               break;
      case 8 : //pretraga odredjenog korisnika
               cout<<"Unesite ime i jmbg korisnika: ";
               cin.clear();
               cin>>ime>>prezime;
               ind=Clanovi.pretragaKorisnika2(ime,prezime);
               if(ind==-1) 
                 cout<<"Korisnik nije pronadjen!"<<endl;
               else cout<<"Korisnik se nalazi u bazi!"<<endl;
               break;
      case 9 : //kreiranje novog korisnika i upisivanje u bazu korisnika
               Clanovi.kreirajKorisnika();
               break;
      case 10 : //brisanje korisnika iz baze clanova 
               cout<<"Unesite JMBG korisnika: ";
                cin.clear();
                cin>>jmbg;
                Clanovi.obrisiKorisnika(jmbg);
                break;
      case 11 : //azuriranje odredjenog korisnika
                cout<<"Unesite JMBG korisnika: ";
                cin.clear();
                cin>>jmbg;
                Clanovi.azuriranjeKorisnika(jmbg);
                break;
      case 12 : //pregled posudjenih filmova za korisnika
                cout<<"Unesite JMBG korisnika: ";
                cin.clear();
                cin>>jmbg;
                for(int i=0;i<TrenutnaH.getLH().velicina();i++){
                  if(TrenutnaH.getLH().dohvatiEl(i).getJM()==jmbg){
                    temp++;
                    cout<<"Serijski broj podignutog filma: "<<TrenutnaH.getLH().dohvatiEl(i).getSer()<<endl;
                }
                }
                if(temp==0) cout<<"Korisnik je vratio sve filmove."<<endl;
                break;
      case 13 : //pregled historije posudjivanja
                cout<<"Unesite JMBG korisnika: ";
                cin.clear();
                cin>>jmbg;
                for(int i=0;i<UkupnaH.getLH().velicina();i++){
                  if(UkupnaH.getLH().dohvatiEl(i).getJM()==jmbg)
                    cout<<"Serijski broj podignutog filma: "<<UkupnaH.getLH().dohvatiEl(i).getSer()<<endl;
                }
                break;
      case 14 : //dozvola korisniku za koristenje videoteke
                cout<<"Unesite ime:";
                cin.clear();
                cin>>ime;
                lozinka=getpass("Unesite JMBG");
                if(Clanovi.pretragaKorisnika2(ime,lozinka)!=-1){
                  menu=2;
                  indCl=Clanovi.pretragaKorisnika2(ime,lozinka);
                  cout<<endl<<ime<<" , dobrodosli u videoteku "<<Videoteka.getImeV()<<endl;
                }

      case 15 : //napustanje programa
                izlaz=1;
                break;
      default : cout<<"Pogresan unos. Program se terminira!"<<endl;
                izlaz=1;
                cout<<endl;
                break;
    } //kraj switch


  }//kraj while
}//kraj if(menu)

//korisnicki interface videoteke
if(menu==2){
  int izlaz=0;
  int odabir=0;
  //opcije dostupne korisniku
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
    int brojac=0;
    
    //implementacija korisnickih opcija
    switch(odabir){
      case 1 : //pregled sadrzaja videoteke
               Videoteka.print();
               cout<<endl;
               break;
      case 2 : //metod za pretragu filma
               cout<<"Unesite naziv filma: ";
               cin.clear(); cin>>pretrazi;
               temp=Videoteka.pretrazi(pretrazi);
               cout<<"Pronadjeno je "<<temp<<" filmova."<<endl;
               cout<<endl;
               break;
      case 3 : //metod za pregled filma
               cout<<"Unesite naziv filma: ";
               cin.clear(); cin>>pretrazi;
               temp=Videoteka.pregledFilma(pretrazi);
               if(!temp) cout<<"Film nije pronadjen"<<endl;
               cout<<endl;
               break;
      case 4 : //metod za posudjivanje filma
               if(Clanovi.getBaza().dohvatiEl(indCl).getBrPF()<3){
               serijski=Clanovi.iznajmiFilm(Videoteka,lozinka);
               if(serijski!=-1){
                 h.setJM(lozinka);
                 h.setSer(serijski);
               }
               UkupnaH.dodajUnos(h);
               TrenutnaH.dodajUnos(h);
               }
               break;
      case 5 : //metod za vracanje filma
               temp=Clanovi.pretragaKorisnikaJMBG(lozinka);
               if(Clanovi.getBaza().dohvatiEl(temp).getBrPF()<1){
                 cout<<"Nemate iznajmljenih filmova."<<endl;
                 break;
               }
               serijski=Clanovi.vratiFilm(Videoteka,lozinka);
               if(serijski!=-1){
                 h.setJM(lozinka);
                 h.setSer(serijski);
                 TrenutnaH.obrisiUnos(h);
               }
               break;
      case 6 : //pregled svoje historije
               for(int i=0;i<UkupnaH.getLH().velicina();i++){
                 if(UkupnaH.getLH().dohvatiEl(i).getJM()==lozinka)
                   brojac++;
               }
               cout<<"Pronadjenih unosa: "<<brojac<<endl;
               if(brojac){
                 for(int i=0;i<UkupnaH.getLH().velicina();i++){
                   if(UkupnaH.getLH().dohvatiEl(i).getJM()==lozinka)
                     cout<<"Serijski broj filma: "<<UkupnaH.getLH().dohvatiEl(i).getSer()<<endl;
                 }
               }

               break;
      case 7 : //pregled trenuno podignutih filmova
               for(int i=0;i<TrenutnaH.getLH().velicina();i++){
                 if(TrenutnaH.getLH().dohvatiEl(i).getJM()==lozinka)
                   brojac++;
               }
               cout<<"Pronadjenih unosa: "<<brojac<<endl;
               if(brojac){
                 for(int i=0;i<TrenutnaH.getLH().velicina();i++){
                   if(TrenutnaH.getLH().dohvatiEl(i).getJM()==lozinka)
                   cout<<"Serijski broj filma: "<<TrenutnaH.getLH().dohvatiEl(i).getSer()<<endl;
                 }
               }
               break;
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

//ispis svih rezultata programa u memoriju(file-ove) koji ce se koristiti u iducem pokretanjuprograma
ofstream ofileF("lista_filmova.txt");
for(int i=0;i<Videoteka.trenutnoStanje();i++)
  ofileF<<Videoteka.getFilmovi().dohvatiEl(i).pripremiIspis()<<endl;

  ofileF.close();

ofstream ofileC("Arhiva.txt");
     for(int i=0;i<Clanovi.brojClanova();i++){
      ofileC<<Clanovi.getBaza().dohvatiEl(i).ispis()<<endl;
  }
 ofileC.close();

 ofstream ofileTH("trhistorija.txt");
   for(int i=0;i<TrenutnaH.getLH().velicina();i++)
     ofileTH<<TrenutnaH.getLH().dohvatiEl(i).printUnos()<<endl;
  ofileTH.close();

 ofstream ofileUH("ukhistorija.txt");
   for(int i=0;i<UkupnaH.getLH().velicina();i++)
     ofileUH<<UkupnaH.getLH().dohvatiEl(i).printUnos()<<endl;
  ofileUH.close();

  return 0;
}
