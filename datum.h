#ifndef _DATUM_H
#define _DATUM_H
#include<iostream>

class Datum{
  private:
    int _dan;
    int _mjesec;
    int _godina;
  public:
    Datum()=default;
    Datum(int d,int m,int g):_dan(d),_mjesec(m),_godina(g){};
    ~Datum()=default;

    int getDan(){return _dan;}
    int getMjesec(){return _mjesec;}
    int getGodina(){return _godina;}
    
    void setDan(int j){_dan=j;}
	void setMjesec(int j){_mjesec=j;}
    void setGodina(int j){_godina=j;}
    
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
	
	friend std::ostream& operator<<(std::ostream& out,const Datum& x)
	{
		out<<x._dan<<"/"<<x._mjesec<<"/"<<x._godina<<std::endl;
	}
  };

#endif
