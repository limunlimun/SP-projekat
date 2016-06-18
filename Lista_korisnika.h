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
		void obrisiKorisnika(std::string x); // 
		int pretragaKorisnika(std::string x); // pretraga
		void dodajKorisnika(Korisnik x);	// gotovo
		
		void iznajmiFilm(listaFilmova x); //gotovo
		void vratiFilm(listaFilmova x); //
		
		void prikazStanja(); //ispisuje sve relevantne podatke za biblioteku
		void Blacklist();	//gotovo
		bool empty();	//gotov
		size_t brojClanova();	// gotov
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
	if(pretragaKorisnika(x.getOsoba().getIme())!=-1 && pretragaKorisnika(x.getOsoba().getPrezime())!=-1)
	{
	_database.dodajNaKraj(x);
	_size++;
	}
	
	else
	{
		std::cout<<"Vec postoji korisnik sa istim podacima"<<std::endl;
	}
}

int ListaKorisnika::pretragaKorisnika(std::string x)
{
	int trind=-1;
	for(int i=0;i<_database.maxVelicina();i++)
	{
		
		if(_database.dohvatiEl(i).getOsoba().getIme()==x || _database.dohvatiEl(i).getOsoba().getPrezime()==x)
		trind=i;
		
		else
		{
			//implementirati binary search algoritam baziran na datumu to mogu ja implementirati sutra kad ustanem
			
		}
	}
	return trind;
}

void ListaKorisnika::obrisiKorisnika(std::string x)
{
	int t=pretragaKorisnika(x);
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
	
	if(pretragaKorisnika(novi.getOsoba().getIme())==-1&& pretragaKorisnika(novi.getOsoba().getJMBG())==-1)
	dodajKorisnika(novi);
	else
	std::cout<<"Korisnik vec postoji u bazi podataka"<<std::endl;
}

void ListaKorisnika::iznajmiFilm(listaFilmova x)
{
	std::cout<<"Unesite ime korisnika: "<<std::endl;
	std::string ime;
	cin>>ime;
	int uslov=pretragaKorisnika(ime);
	if(uslov==-1)
	std::cout<<"Niste prijavljeni u videoteku!"<<std::endl;
	
	else
	{
		x.print();
		std::cout<<"Unesite ime vaseg filma: "<<std::endl;
		cin.clear();
		cin>>ime;
		if(x.pregledFilma(ime))
		x.posudiFilm(x.pretrazi(ime,0));
		_database.dohvatiEl(uslov).setBrPF(_database.dohvatiEl(uslov).getBrPF()+1);
		std::cout<<"Uspjesno obavljena transakcija! Uzivajte !"<<std::endl;
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
		
		
	}
	
}

void ListaKorisnika::prikazStanja()
{
	std::cout<<_database<<std::endl;
	std::cout<<"Ukupno "<<brojClanova()<<" korisnika"<<std::endl;
}











#endif
