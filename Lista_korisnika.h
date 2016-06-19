#ifndef _BIBLIOTEKA_H
#define _BIBLIOTEKA_H
#include "film.h"
#include"korisnik.h"
#include<iostream>
#include<cstddef>
#include"lista_filmova.h"



class ListaKorisnika
{
	private:
			ListaNizom<Korisnik> _database;
			size_t _size;
		
	
	public:
		
		ListaKorisnika(); //  gotov
		~ListaKorisnika(); // gotov
		
		void kreirajKorisnika();// gotov
		void obrisiKorisnika(std::string x,std::string y); // gotov
		int pretragaKorisnika(std::string x,std::string y); // pretraga
    int pretragaKorisnikaJMBG(std::string x,std::string y);
		void dodajKorisnika(Korisnik x);	// gotovo
		
		void iznajmiFilm(listaFilmova x); //gotovo
		void vratiFilm(listaFilmova x); //gotovo
		
		void prikazStanja(); //ispisuje sve relevantne podatke za biblioteku
		void Blacklist();	//gotovo
		bool empty();	//gotov
		size_t brojClanova();	// gotov

    ListaNizom<Korisnik>& getBaza(){return _database;}
};

ListaKorisnika::ListaKorisnika()
{
	_size=0;
}

bool ListaKorisnika::empty()
{
	return (_size==0);
}

size_t ListaKorisnika::brojClanova()
{
	return _size;
}

ListaKorisnika::~ListaKorisnika()
{
	_database.~ListaNizom();
	_size=0;
}

void ListaKorisnika::dodajKorisnika(Korisnik x)
{
 int br=0;
  for(int i=0;i<_database.velicina();i++){
    if(_database.dohvatiEl(i).getOsoba().getJMBG()==x.getOsoba().getJMBG()) 
    { cout<<"JMBG u upotrebi!"<<endl;
      br=0;
      break;
  }
    else br=1;
  }
	if(br){
	_database.dodajNaKraj(x);
	_size++;
	
}
}

int ListaKorisnika::pretragaKorisnikaJMBG(std::string x,std::string y){
  int trind=-1;
  for(int i=0;i<_database.velicina();i++){
    if(_database.dohvatiEl(i).getOsoba().getIme()==x && _database.dohvatiEl(i).getOsoba().getJMBG()==y)
      trind=i;
  }
  return trind;
}

int ListaKorisnika::pretragaKorisnika(std::string x,std::string y)
{
	int trind=-1;
	for(int i=0;i<_database.maxVelicina()-1;i++)
	{
		
		if(_database.dohvatiEl(i).getOsoba().getIme()==x && _database.dohvatiEl(i).getOsoba().getPrezime()==y)
		trind=i;
		
		else
		{
			//implementirati binary search algoritam baziran na datumu to mogu ja implementirati sutra kad ustanem
			
		}
	}
	return trind;
}

void ListaKorisnika::obrisiKorisnika(std::string x,std::string y)
{
	int t=pretragaKorisnikaJMBG(x,y);
	if(t != -1)
	_database.ukloniSaLokacije(t);
	else
	std::cout<<"Korisnik uopste nije u bazi podataka!"<<std::endl;
}

void ListaKorisnika::kreirajKorisnika()
{
	Korisnik novi;
	std::string pom;
	std::cout<<"Molimo unesite ime vaseg korisnika"<<std::endl;
	cin>>pom;
	novi.getOsoba().setIme(pom);
	cin.clear();
	
	std::cout<<"Unesite prezime vaseg korisnika"<<std::endl;
	cin>>pom;
	novi.getOsoba().setPrezime(pom);
	cin.clear();
	
	std::cout<<"Unesite prezime vaseg korisnika"<<std::endl;
	cin>>pom;
	novi.getOsoba().setJMBG(pom);
	cin.clear();
	
	int j;
	std::cout<<"Unesite datum prijavljivanja u videoteku: "<<std::endl;
	cin>>j;
	novi.setBrPF(0);
	novi.getDatum().setDan(j);
	cin.clear();
	cin>>j;
	novi.getDatum().setMjesec(j);
	cin.clear();
	cin>>j;
	novi.getDatum().setGodina(j);
	
	if(pretragaKorisnika(novi.getOsoba().getIme(),novi.getOsoba().getJMBG())==-1)
	dodajKorisnika(novi);
	else
	std::cout<<"Korisnik vec postoji u bazi podataka"<<std::endl;
}

void ListaKorisnika::iznajmiFilm(listaFilmova x)
{
	std::cout<<"Unesite ime korisnika i JMBG: "<<std::endl;
	std::string ime,jmbg;
	cin>>ime>>jmbg;
	int uslov=pretragaKorisnikaJMBG(ime,jmbg); if(uslov==-1)
	std::cout<<"Niste prijavljeni u videoteku!"<<std::endl;
	
	else
	{
		x.print();
		std::cout<<"Unesite ime vaseg filma: "<<std::endl;
		cin.clear();
		cin>>ime;
		int t=x.pretrazi(ime,0);
		if(x.pregledFilma(ime)!=0)
		{
			Film s=x.getFilmovi().dohvatiEl(t);
			s.setBrKopija(s.getBrKopija()-1);
			x.getFilmovi().zamijeniNaLokaciji(t,s);
			_database.dohvatiEl(uslov).setBrPF(_database.dohvatiEl(uslov).getBrPF()+1);
			std::cout<<"Uspjesno obavljena transakcija! Uzivajte !"<<std::endl;
		}
	}
	
}

void ListaKorisnika::vratiFilm(listaFilmova x)
{
	
	std::cout<<"Unesite ime filma kojeg vracate:"<<std::endl;
	string ime;
	cin>>ime;
	int pom=x.pretrazi(ime,1);
	if(pom!=1)
	{
		std::cout<<"Greska ! Film nije u bazi podataka!"<<std::endl;
	}
	else
	{
		Film pom1=x.getFilmovi().dohvatiEl(pom);
		pom1.setBrKopija(pom1.getBrKopija()+1);
		x.getFilmovi().zamijeniNaLokaciji(pom,pom1);
		std::cout<<"Film je vracen!"<<std::endl;
		
		
	}
	
}

//void ListaKorisnika::prikazStanja()
//{
//	std::cout<<_database<<std::endl;
//	std::cout<<"Ukupno "<<brojClanova()<<" korisnika"<<std::endl;
//}











#endif
