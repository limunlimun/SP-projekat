#ifndef _OSOBA_H
#define _OSOBA_H

#include <string>
#include <iostream>
class Osoba{
	private: 
	std::string _ime;
	std::string _prezime;
  std::string _jmbg="0"; //za glumce,producente i scenariste ovo polje ce imati vrijednost 0
	
	public:
	
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

	std::string getIme(){return _ime;};
	
	std::string getPrezime(){return _prezime;}
	
  std::string getJMBG(){return _jmbg;}
	
	void setIme(std::string x) { _ime=x;	}
	
	void setPrezime(std::string x) {_prezime=x;	}
	
	void setJMBG(std::string x)	{_jmbg=x;	}
	
	void printOsoba(){
  std::cout<<_ime<<" "<<_prezime;
  }
  
  std::ostream& operator<<(std::ostream& out)
  {
  	out<<this->_ime<<" "<<this->_prezime<<"\t"<<this->_jmbg<<std::endl;
  }
  
  bool operator==(const Osoba& x)
  {
  	if(_ime==x._ime && x._prezime==_prezime && x._jmbg==_jmbg)
  	return true;
  	else 
	  return false;
  }
};

#endif
