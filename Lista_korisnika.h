#ifndef _BIBLIOTEKA_H
#define _BIBLIOTEKA_H
#include "film.h"
#include"korisnik.h"
#include<iostream>
#include<cstddef>
template <class Type>
struct Node
{
	private:
	Type info;
	
	public:
	Node<Type> *llink;
	Node<Type> *rlink;
	
	
	Node(const Type & v) : info(v), llink(nullptr), rlink(nullptr){}
	void SetInfo(Type v) {info=v;}
	Type getInfo() {return info;}
};


class ListaKorisnika
{
	private:
		Node<Korisnik>* root;
		size_t size;
		
	
	public:
		ListaKorisnika(); // konstruktor
		~ListaKorisnika(); //destruktor
		void dodajKorisnika(Korisnik x);	// dodavanje novog filma
		void iznajmiFilm(Film x); //iznajmljuje film
		void obrisiKorisnika(); // brise ga iz liste
		Korisnik pretragaKorisnika(); //pretraga
		void blacklist();	//lista korisnika koji duguju filmove iznad granice
		bool empty();	//da li je prazna lista
		bool brojKorisnika();	// size()
};

ListaKorisnika::ListaKorisnika()
{
	root=nullptr;
	size=0;
}

bool ListaKorisnika::empty()
{
	return (size==0);
}

bool ListaKorisnika::brojKorisnika()
{
	return size;
}

void ListaKorisnika::dodajKorisnika(Korisnik x)
{
	Node<Korisnik>* novi=new Node<Korisnik>(x);
	Node<Korisnik>* pom=root;
	novi->SetInfo(x);
	if(empty())
	{
		root=novi;
	}
	else
	{
		while(pom!=nullptr)
		{
			if(novi->getInfo > pom->getInfo())
			
		}
	}
	
	size++;
}

#endif
