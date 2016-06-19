#ifndef _DATUM_H
#define _DATUM_H
#include<iostream>

class Datum{
  private:
    //osnovna konstrukcija datuma
    int _dan;
    int _mjesec;
    int _godina;
  public:
    //konstruktori
    Datum()=default;
    Datum(int d,int m,int g):_dan(d),_mjesec(m),_godina(g){};
    ~Datum()=default;

    //osnovni metodi za rad sa datumima
    int getDan(){return _dan;}
    int getMjesec(){return _mjesec;}
    int getGodina(){return _godina;}
    
    void setDan(int j){this->_dan=j;}
	void setMjesec(int j){this->_mjesec=j;}
    void setGodina(int j){this->_godina=j;}
    
    //operatori za poredjenje datuma
    bool operator>(const Datum& x)
    {
    	if(this->_godina>x._godina)
    	{
    		return true;
		}
		else if(this->_godina==x._godina && this->_mjesec>x._mjesec)
		{
			return true;
		}
		else if(this->_godina==x._godina && this->_mjesec==x._mjesec && this->_dan>x._dan)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool operator<(const Datum& x)
    {
    	if(this->_godina<x._godina)
    	{
    		return true;
		}
		else if(this->_godina==x._godina && this->_mjesec<x._mjesec)
		{
			return true;
		}
		else if(this->_godina==x._godina && this->_mjesec==x._mjesec && this->_dan<x._dan)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool operator==(const Datum& x)
	{
		if(_dan==x._dan && _mjesec==x._mjesec && _godina==x._godina)
		return true;
		else 
		return false;
	}
	
};

#endif
