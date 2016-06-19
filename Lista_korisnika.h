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
		void obrisiKorisnika(std::string x); // gotov
		int pretragaKorisnika(std::string x); // pretraga
		void dodajKorisnika(Korisnik x);	// gotovo
		
		void iznajmiFilm(listaFilmova x); //gotovo
		void vratiFilm(listaFilmova x); //gotovo
		void azuriranjeKorisnika(std::string x);//izrada
		void prikazStanja(); //ispisuje sve relevantne podatke za biblioteku
		void Blacklist();	//gotovo
		bool empty();	//gotov
		size_t brojClanova();	// gotov
		void sortDatum();//
		void sortAlfa();//
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
	for(int i=0;i<_database.maxVelicina()-1;i++)
	{
		
		if(_database.dohvatiEl(i).getOsoba().getIme()==x || _database.dohvatiEl(i).getOsoba().getPrezime()==x)
		trind=i;
		
		
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
		std::cout<<"Film je vracen!"<<std::cout;
		
		
	}
	
}

void ListaKorisnika::prikazStanja()
{
	std::cout<<_database<<std::endl;
	std::cout<<"Ukupno "<<brojClanova()<<" korisnika"<<std::endl;
}


void ListaKorisnika::azuriranjeKorisnika(std::string x)
{
	int in=pretragaKorisnika(x);
	std::cout<<"Koji aspekt zelite azurirati?"<<std::endl;
	std::cout<<"1.Datum\n2.Ime\3.Prezime\4.Broj posudjenih filmova"<<std::endl;
	int izbor;
	std::string g;
	int j;
	cin>>izbor;
	switch (izbor)
	{
		case 1:
				
				cin>>j;
				_database.dohvatiEl(in).getDatum().setDan(j);
				cin>>j;
				_database.dohvatiEl(in).getDatum().setMjesec(j);
				cin>>j;
				_database.dohvatiEl(in).getDatum().setGodina(j);
				break;
		case 2:
			
			cin>>g;
			_database.dohvatiEl(in).getOsoba().setIme(g);
			break;
		case 3:
			
			cin>>g;
			_database.dohvatiEl(in).getOsoba().setPrezime(g);
		case 4:
			cin>>j;
			_database.dohvatiEl(in).getOsoba().setPrezime(g);
		default:
			std::cout<<"Opcija nije validna!"<<std::endl;
			
			
				
		
	}
}


void ListaKorisnika::sortDatum()
{
	for(int i=0;i<_database.maxVelicina()-1;i++)
	{
		if(_database.dohvatiEl(i)>_database.dohvatiEl(i+1))
		std::swap(_database.dohvatiEl(i),_database.dohvatiEl(i+1));
		for (int j=i;j<_database.maxVelicina()-1;j++)
		{
			if(_database.dohvatiEl(j)>_database.dohvatiEl(j+1))
		std::swap(_database.dohvatiEl(j),_database.dohvatiEl(j+1));
		}
	}
}

//u oba slucaja implementiran insertion algoritam , mada bi quicksort bio puno bolji

void ListaKorisnika::sortAlfa()
{
	for(int i=0;i<_database.maxVelicina()-1;i++)
	{
		if(_database.dohvatiEl(i).getOsoba()>_database.dohvatiEl(i+1).getOsoba())
		std::swap(_database.dohvatiEl(i),_database.dohvatiEl(i+1));
		for (int j=i;j<_database.maxVelicina()-1;j++)
		{
			if(_database.dohvatiEl(j).getOsoba()>_database.dohvatiEl(j+1).getOsoba())
		std::swap(_database.dohvatiEl(j),_database.dohvatiEl(j+1));
		}
	}
}




#endif
