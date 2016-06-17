#ifndef _BIBLIOTEKA_H
#define _BIBLIOTEKA_H
#include<iostream>
#include "binarySearchTree.hxx"
#include"Bst.h"
#include"korisnik.h"
#include <string>
class ListaKorisnika
{
	private :
		Bst<Korisnik> _database;
		long _size;
	public:
		ListaKorisnika();
		~ListaKorisnika();
		void dodajKorisnika(const Korisnik& x);
		long brojClanova ();		// administrator
		void izbrisiKorisnika(std::string x); //admin
		void iznajmljivanjeFilma(std::string film); //admin ili korisnik
		void arhiviranje(); //upisivanje u txt fajl
};

ListaKorisnika::ListaKorisnika()
{
	_size=0;
	
}

ListaKorisnika::~ListaKorisnika()
{
	_database.destroy();
	_size=0;
}

void ListaKorisnika::dodajKorisnika(const Korisnik& x)
{
	
	_database.insert(x);
	_size++;
}

long ListaKorisnika::brojClanova()
{
	return _size;
}

void ListaKorisnika::izbrisiKorisnika(std::string x)
{
	_database.find(x);
}

#endif
