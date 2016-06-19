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
    int pretragaKorisnikaJMBG(std::string x);
    int pretragaKorisnika2(std::string x,std::string y);
    int pretragaKorisnika(std::string x); // pretraga
		void dodajKorisnika(Korisnik x);	// gotovo
		
		int iznajmiFilm(listaFilmova& x,std::string jmbg); //gotovo
		int vratiFilm(listaFilmova& x,std::string jmbg); //gotovo
		void azuriranjeKorisnika(std::string x);//izrada
		void prikazStanja(); //ispisuje sve relevantne podatke za biblioteku
		void Blacklist();	//gotovo
		bool empty();	//gotov
		size_t brojClanova();	// gotov
		void sortDatum();//
		void sortAlfa();//
    ListaNizom<Korisnik>& getBaza(){return this->_database;}
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
  int uslov=pretragaKorisnika2(x.getOsoba().getIme(),x.getOsoba().getJMBG());
  
	if(uslov==-1)
	{
	_database.dodajNaKraj(x);
	_size++;
	}
	
	else
	{
  

		std::cout<<"Vec postoji korisnik sa istim podacima"<<std::endl;
	}
}

int ListaKorisnika::pretragaKorisnikaJMBG(std::string x){
  int trind=-1;
  for(int i=0;i<_database.velicina();i++){
    if(_database.dohvatiEl(i).getOsoba().getJMBG()==x){
      trind=i;
    }
  }
  
  return trind;
}

int ListaKorisnika::pretragaKorisnika2(std::string x,std::string y){
  int trind=-1;
  for(int i=0;i<_database.velicina();i++){
    if(_database.dohvatiEl(i).getOsoba().getIme()==x && _database.dohvatiEl(i).getOsoba().getJMBG()==y)
      trind=i;
  }
  return trind;
}

int ListaKorisnika::pretragaKorisnika(std::string x)
{
	int trind=-1;
	for(int i=0;i<_database.velicina();i++)
	{
		
		if(_database.dohvatiEl(i).getOsoba().getIme()==x || _database.dohvatiEl(i).getOsoba().getPrezime()==x)
		trind=i;
		
		
	}
	return trind;
}

void ListaKorisnika::obrisiKorisnika(std::string x)
{
	int t=pretragaKorisnikaJMBG(x);
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
	
	if(pretragaKorisnika(novi.getOsoba().getIme())==-1&& pretragaKorisnikaJMBG(novi.getOsoba().getJMBG())==-1)
	dodajKorisnika(novi);
	else
	std::cout<<"Korisnik vec postoji u bazi podataka"<<std::endl;
}

int ListaKorisnika::iznajmiFilm(listaFilmova& x,std::string jmbg)
{   
    int uslov=pretragaKorisnikaJMBG(jmbg);
	  int ser;
		x.print();
		std::cout<<"Unesite serijski broj filma: "<<std::endl;
		cin.clear();
		cin>>ser;
		int t=x.pretraziSer(ser);
    if(t!=-1){
      
			x.getFilmovi().dohvatiEl(t).setBrKopija(x.getFilmovi().dohvatiEl(t).getBrKopija()-1);

		
			_database.dohvatiEl(uslov).setBrPF(_database.dohvatiEl(uslov).getBrPF()+1);
			std::cout<<"Uspjesno obavljena transakcija! Uzivajte !"<<std::endl;
      return ser;
		}
    else 
      cout<<"Unos nije validan!"<<endl;
    return -1;
	}
	


int ListaKorisnika::vratiFilm(listaFilmova& x,std::string jmbg)
{
	
	std::cout<<"Unesite serijski broj filma kojeg vracate:"<<std::endl;
	int ser;
	cin>>ser;
	int pom=x.pretraziSer(ser);
	if(pom==-1)
	{
		std::cout<<"Greska ! Film nije u bazi podataka!"<<std::endl;
    ser=-1;
	}
	else
	{
		x.getFilmovi().dohvatiEl(pom).setBrKopija(x.getFilmovi().dohvatiEl(pom).getBrKopija()+1);
		int in=pretragaKorisnikaJMBG(jmbg);
    _database.dohvatiEl(in).setBrPF(_database.dohvatiEl(in).getBrPF()-1);
		std::cout<<"Film je vracen!"<<std::endl;
		
		
	}
	return ser;
}

//void ListaKorisnika::prikazStanja()
//{
//	std::cout<<_database<<std::endl;
//	std::cout<<"Ukupno "<<brojClanova()<<" korisnika"<<std::endl;
//}


void ListaKorisnika::azuriranjeKorisnika(std::string x)
{
	int in=pretragaKorisnikaJMBG(x);
  if(in==-1){
    cout<<"Korisnik nije pronadjen!"<<endl;
    return ;
  }
	std::cout<<"Koji aspekt zelite azurirati?"<<std::endl;
  std::cout<<"1.Ime"<<endl;
  std::cout<<"2.Prezime"<<endl;
  std::cout<<"3.Datum"<<endl;
 	int izbor;
	std::string g;
	int j;
	cin>>izbor;
	switch (izbor)
	{
		case 3:
      std::cout<<"Unesite datum u formatu: dan mjesec godina "<<endl;
      cin.clear();
      std::cin>>j;
				_database.dohvatiEl(in).getDatum().setDan(j);
        std::cin.clear();
        std::cin>>j;
				_database.dohvatiEl(in).getDatum().setMjesec(j);
        std::cin.clear();
        std::cin>>j;
				_database.dohvatiEl(in).getDatum().setGodina(j);
				break;
		case 1:
			cout<<"Unesite ime: ";
			cin>>g;
			_database.dohvatiEl(in).getOsoba().setIme(g);
			break;
		case 2:
      std::cin>>g;
			_database.dohvatiEl(in).getOsoba().setPrezime(g);
		  break;
		default:
			std::cout<<"Opcija nije validna!"<<std::endl;
      break;
			
			
				
		
	}
}


void ListaKorisnika::sortDatum()
{
	for(int i=0;i<_database.velicina();i++)
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
	for(int i=0;i<_database.velicina();i++)
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
