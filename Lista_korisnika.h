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
			ListaNizom<Korisnik> _data;
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
		
		
		void blacklist();	//
		bool empty();	//gotov
		size_t brojKorisnika();	// gotov
};

ListaKorisnika::ListaKorisnika()
{
	_size=0;
}

bool ListaKorisnika::empty()
{
	return (_size==0);
}

size_t ListaKorisnika::brojKorisnika()
{
	return _size;
}

ListaKorisnika::~ListaKorisnika()
{
	_data.~ListaNizom();
	_size=0;
}

void ListaKorisnika::dodajKorisnika(Korisnik x)
{
	_data.dodajNaKraj(x);
	_size++;
}

int ListaKorisnika::pretragaKorisnika(std::string x)
{
	int j=-1;
	Korisnik pom; 	
	for (int i=0;i<_data.maxVelicina();i++)
	{
		pom=_data.dohvatiEl(i);
		if(pom.getOsoba().getIme()==x || pom.getOsoba().getPrezime()==x)
		j=i;
	}
	return j;
}

void ListaKorisnika::obrisiKorisnika(std::string x)
{
	int t=pretragaKorisnika(x);
	if(t != -1)
	_data.ukloniSaLokacije(t);
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
		_data.dohvatiEl(uslov).setBrPF(_data.dohvatiEl(uslov).getBrPF()+1);
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
	
}
#endif
