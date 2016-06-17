#ifndef BST_H
#define BST_H
#include<iostream>
#include<algorithm>
#include<cstddef>


template<typename Type>
class Bst
{
	private:
		Type* _tree;
		size_t _size;
		size_t _max;
	public:
		Bst();	//
	    ~Bst();
	    void insert(Type&& val);
	    void insert(const Type& val);
	    int find(Type&& val); //zvajzni bolean
	    int find(const Type& val); //boolean
	    void remove(const Type& x);
	    size_t size();
	   	bool empty();
	   	void destroy();
	   	void reallocate();
	    
};

template<typename Type>
bool Bst<Type>::empty()
{
	return(_size==0);
}

template<typename Type>
void Bst<Type>::destroy()
{
	if(!empty())
	{
		std::cout<<"Tree empty!"<<std::endl;
	}
	else
	{
		delete [] _tree;
		_tree=nullptr;
		_max=0;
		_size=0;
	}
}

template<typename Type>
size_t Bst<Type>::size()
{
	return _size;
}

template<typename Type>
void Bst<Type>::reallocate()
{
	int t[_max];
	for(int i=1 ; i<=_size ; i++)
	t[i]=_tree[i];
	delete [] _tree;
	_max=_max*1.5;
	_tree=new Type[_max];
	for(int i=1 ; i<=_size ; i++)
	_tree[i]=t[i];
	_size++;
	
}

template<typename Type>
Bst<Type>::Bst()
{
	_max=50;
	_size=0;
	_tree=nullptr;
	std::cout<<"Pozvan konstruktor!"<<std::endl;
}


template<typename Type>
Bst<Type>::~Bst()
{
	std::cout<<"Pozvan destruktor"<<std::endl;
	
	destroy();
}

template<typename Type>
void Bst<Type>::insert(const Type& val)
{
	_size++;
	if(empty())
	{
		_tree[1]=val;
	}
	else
	{
		if(_size>=_max)
		reallocate();
		if(val>_tree[_size])
		_tree[2*_size+1]=val;
		else
		_tree[2*_size]=val;
	}
	
	
}

template<typename Type>
void Bst<Type>::insert(Type&& val)
{
	_size++;
	if(empty())
	{
		_tree[1]=val;
	}
	else
	{
		if(_size>=_max)
		reallocate();
		if(val>_tree[_size])
		_tree[2*_size+1]=std::move(val);
		else
		_tree[2*_size]=std::move(val);
	}
}

template<typename Type>
int Bst<Type>::find(const Type& val)
{
	int i=1;
	while(i<_max)
	{
		if(val!=_tree[i])
		{
			if(val<_tree[i])
			i=2*i;
			else
			i=2*i+1;
		}
		else
		return i;
	}
}

template<typename Type>
int Bst<Type>::find(Type&& val)
{
	int i=1;
	while(i<_max)
	{
		if(val<_tree[i])
		i=2*i;
		else
		i=2*i+1;
	}
}

template<typename Type>
void Bst<Type>::remove(const Type& val)
{
	int ind = find(val);
	if(ind<_max)
	delete _tree[ind];
}

#endif
