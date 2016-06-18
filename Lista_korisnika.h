#ifndef _BIBLIOTEKA_H
#define _BIBLIOTEKA_H
#include<iostream>
#include"Bst.h"
#include"lista.hxx"
#include"korisnik.h"
#include <string>
#include<fstream>

//arhiviranje samo jos nije gotovo

class ListaKorisnika
{
	private :
		ListaNizom<Korisnik> _database;
		long _size;
	public:
		ListaKorisnika();	//
		~ListaKorisnika();	//
		void dodajKorisnika( Korisnik x); // Dodavanje novog korisnika
		long brojClanova ();		// administrator
		void izbrisiKorisnika(std::string x); //admin
		void iznajmljivanjeFilma(std::string film); //admin dodjeljuje film korisniku, mora pristupiti i listi filmova
		void arhiviranje(); //upisivanje u txt fajl
		void prikazStanja(); //Prikazuje sve korisnike
		void KreiranjeKorisnika();	//
		int pretragaKorisnika(std::string x); //
		void Blacklist(); //	//
};

ListaKorisnika::ListaKorisnika()
{
	_size=0;
	
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
	_database.dodaj(x);
	_size++;
	}
	
	else
	{
		std::cout<<"Vec postoji korisnik sa istim podacima"<<std::endl;
	}
}

long ListaKorisnika::brojClanova()
{
	return _size;
}

void ListaKorisnika::izbrisiKorisnika(std::string x)
{
	
	_database.ukloniSaLokacije(pretragaKorisnika(x));
	_size--;
}

void ListaKorisnika::prikazStanja()
{
	std::cout<<_database<<std::endl;
	std::cout<<"Ukupno "<<brojClanova()<<" korisnika"<<std::endl;
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

void ListaKorisnika::iznajmljivanjeFilma(std::string korisnik)
{
		//Metod treba da pristupi i listi filmova da bi smanjio broj kopija a zadatom korisniku povecao broj posudjenih za 1
		int i=pretragaKorisnika(korisnik);
		int d=_database.dohvatiEl(i).getBrPF();
		if(d>=3)
		std::cout<<"Korisnik dostigao limit! Vratite film pa onda mozete podici jos jedan."<<std::endl;
		else
		_database.dohvatiEl(i).setBrPF(d+1);
		
}

void ListaKorisnika::Blacklist()
{
	for (int i=0;i<_database.maxVelicina();i++)
	{
		if(_database.dohvatiEl(i).getBrPF()>=3)
		cout<<i<<endl;
	}
}

void ListaKorisnika::KreiranjeKorisnika()
{
	std::string pom;
	Korisnik novi;
	std::cout<<"Unesite ime vaseg korisnika"<<std::endl;
	cin>>pom;
	novi.getOsoba().setIme(pom);
	cin.clear();
	
	std::cout<<"Unesite prezime vaseg korisnika"<<std::endl;
	cin>>pom;
	novi.getOsoba().setPrezime(pom);
	cin.clear();
	
	int j;
	std::cout<<"Unesite maticni broj vaseg korisnika"<<std::endl;
	cin>>j;
	novi.getOsoba().setJMBG(j);
	cin.clear();
	
		
	std::cout<<"Unesite danasnji datum uclanjenja vaseg korisnika"<<std::endl;
	cin>>j;
	novi.getDatum().setDan(j);
	cin>>j;
	novi.getDatum().setMjesec(j);
	cin>>j;
	novi.getDatum().setGodina(j);
	
	
}

void ListaKorisnika::arhiviranje()
{
	//metod treba da upisuje sve date korisnike u txt fajl
	fstream fajl;
	fajl.open("arhiva.txt");
	
}

#endif
