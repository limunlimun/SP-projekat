#include <iostream>
#include <stdexcept>

using namespace std; 
template<typename T>
class ListaNizom;

template<typename T>
std::ostream& operator<<(std::ostream&, const ListaNizom<T>&);

template<typename T>
class ListaNizom
{
protected:
	T* elementi; 
	int vel;  
	int maxVel; 
public:
	ListaNizom(int n = 100); 
	ListaNizom(const ListaNizom<T>& lista); 
	const ListaNizom<T>& operator=(const ListaNizom<T>&); 
	bool prazna() const;
	bool puna() const;
	int velicina() const { return vel; } 
	int maxVelicina() const { return maxVel; } 
	void print() const; 
	bool jednaki(int lokacija, const T& obj) const;  
	ListaNizom<T>&  dodajNaLokaciju(int lokacija, const T& objdodaj);
	ListaNizom<T>&  dodajNaKraj(const T& objdodaj); 
	ListaNizom<T>&  ukloniSaLokacije(int lokacija); 
	ListaNizom<T>&  zamijeniNaLokaciji(int lokacija, const T& objNovi); 
	int trazi(const T& obj);
	ListaNizom<T>&  dodaj(const T& obj);
	ListaNizom<T>&  ukloni(const T& obj); 
	T& dohvatiEl(int lokacija); 
	~ListaNizom(void) { delete [] elementi; } 
	
	friend ostream& operator<< <>(ostream & izlaz, const ListaNizom<T>& lista);

};


template<typename T>
ostream& operator<<(ostream & izlaz, const ListaNizom<T>& lista)
{ 	       
    for(auto i = 0; i<lista.vel; i++)
        izlaz<<lista.elementi[i]<<" ";
    return izlaz;
}


template<typename T>
ListaNizom<T>::ListaNizom(int n)
{
    n<0 ?  maxVel  = 100 : maxVel = n; 
    vel = 0; 
    elementi = new T[maxVel];
}


template<typename T>
ListaNizom<T>::ListaNizom(const ListaNizom<T>& lista)
{
	maxVel = lista.maxVelicina(); 
	vel = lista.velicina(); 
	elementi = new T[maxVel]; 
	for (int i = 0; i<vel; i++)
		elementi[i] = lista.elementi[i];
}

template<typename T>
const ListaNizom<T>& ListaNizom<T>::operator=(const ListaNizom<T>& drugaLista)
{
	if (this!=&drugaLista) 
	{
		delete [] elementi; 
		maxVel = drugaLista.maxVelicina(); 
		vel = drugaLista.velicina(); 
		elementi = new T[maxVel]; 
		for (int i= 0; i<vel; i++)
			elementi[i] = drugaLista.elementi[i];
	}
	return *this; 
}


template<typename T>
bool ListaNizom<T>::prazna() const
{
	return (vel == 0);
}


template<typename T>
bool ListaNizom<T>::puna() const
{
	return (vel == maxVel);
}


template<typename T>
void ListaNizom<T>::print() const
{
	for (int i = 0; i<vel; i++)
		cout << elementi[i] << " ";
	cout << endl; 
}



template<typename T>
bool ListaNizom<T>::jednaki(int lokacija, const T& obj) const
{
	return (elementi[lokacija]==obj); 
}

template<typename T> 
ListaNizom<T>& ListaNizom<T>::dodajNaLokaciju(int lokacija, const T& objdodaj)
{
	if (lokacija<0 || lokacija > maxVel)
		throw out_of_range("Niste unijeli dozvoljeni indeks.");
	else 
	{
		if (puna())
			throw string("Lista je puna. Nije moguce dodajovati jos jedan element. ");
		else 
		{
			for (int i = vel; i>lokacija; i--) 
				elementi[i] = elementi[i-1]; 
			elementi[lokacija] = objdodaj; 
			vel++;
		} 
	}
	return *this;
}


template<typename T> 
ListaNizom<T>& ListaNizom<T>::dodajNaKraj(const T& objdodaj)
{
	if (puna())
		throw string("Lista je puna. Nije moguce dodajovati jos jedan element. ");
	else 
	    elementi[vel++] = objdodaj;	
	   
	return *this;	
	
}

template<typename T> 
ListaNizom<T>& ListaNizom<T>::ukloniSaLokacije(int lokacija)
{
	if (lokacija<0 || lokacija >= vel)
		throw out_of_range("Niste unijeli dozvoljeni indeks.");
	else 
	{
		for (int i = lokacija; i<vel - 1; i++)
			elementi[i] = elementi[i+1];
		vel--; 
		
	}
	
	return *this;
}


template<typename T> 
ListaNizom<T>& ListaNizom<T>::zamijeniNaLokaciji(int lokacija, const T& objNovi)
{
	
	if (lokacija<0 || lokacija >= vel)
		throw out_of_range("Niste unijeli dozvoljeni indeks.");
	else 
	{
		elementi[lokacija] = objNovi; 
	}
	
	return *this;
}


template<typename T> 
int ListaNizom<T>::trazi(const T& obj)
{
	for (int i = 0; i<vel; i++)
	{
		if (elementi[i]==obj)
			return i; 
	}
	return -1; 
}


template<typename T> 
ListaNizom<T>& ListaNizom<T>::dodaj(const T& obj)
{
	if (trazi(obj)==-1)
	{
		dodajNaKraj(obj);
	}
	return *this;
}

template<typename T> 
ListaNizom<T>& ListaNizom<T>::ukloni(const T& obj)
{
    auto loc = trazi(obj);
	if (loc!=-1) 
	{
	   ukloniSaLokacije(loc);
	}
	return *this;
}


template<typename T> 
T& ListaNizom<T>::dohvatiEl(int lokacija) 
{
	if (lokacija<0 || lokacija >= vel)
		throw out_of_range("Niste unijeli dozvoljeni indeks.");
	else 
		return elementi[lokacija];
}
