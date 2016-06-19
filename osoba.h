#ifndef _OSOBA_H
#define _OSOBA_H

#include <string>
#include <iostream>
//klasa sa osnovnim clanovima koji opisuju osobu
class Osoba{
	private: 
	std::string _ime;
	std::string _prezime;
  std::string _jmbg="0"; //za glumce,producente i scenariste ovo polje ce imati vrijednost 0
	
	public:
	//osnoni kontruktori
	Osoba()=default;
	
  Osoba(std::string ime,std::string prezime):_ime(ime),_prezime(prezime){};

	Osoba(std::string ime,std::string prezime,std::string jmbg):_ime(ime),_prezime(prezime),_jmbg(jmbg){};
	
	~Osoba()=default;
  	
	Osoba(Osoba &o){_ime=o._ime;_prezime=o._prezime;}
	
	Osoba(const Osoba & o){
  _ime=o._ime;
  _prezime=o._prezime;
  _jmbg=o._jmbg;
	}
  //osnovni operatori
	void operator=(const Osoba & o){
  _ime=o._ime;
  _prezime=o._prezime;
  _jmbg=o._jmbg;
	}
	void operator=(Osoba&& o)
	{
	
  _ime=std::move(o._ime);
  _prezime=std::move(o._prezime);
  _jmbg=std::move(o._jmbg);
	}

  //osnovni metodi za rad i interakciju sa klasom Osoba
	std::string& getIme(){return this->_ime;};
	
	std::string& getPrezime(){return this->_prezime;}
	
  std::string& getJMBG(){return this->_jmbg;}
	
	void setIme(std::string x) { this->_ime=x;	}
	
	void setPrezime(std::string x) {this->_prezime=x;	}
	
	void setJMBG(std::string x)	{this->_jmbg=x;	}
	
	void printOsoba(){
  std::cout<<_ime<<" "<<_prezime;
  }
  
  //osnovni operatori za ispis i poredjenje osoba
  std::ostream& operator<<(std::ostream& out)
  {
  	out<<this->_ime<<" "<<this->_prezime<<"\t"<<this->_jmbg<<std::endl;
    return out;
  }
  
  bool operator==(const Osoba& x)
  {
  	if(_ime==x._ime && x._prezime==_prezime && x._jmbg==_jmbg)
  	return true;
  	else 
	  return false;
  }
  
  bool operator>(const Osoba& x)
  {
  	if(_prezime>x._prezime)
  	return true;
  	else 
  	return false;
  	
  }
};

#endif
