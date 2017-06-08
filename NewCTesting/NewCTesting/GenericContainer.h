#pragma once
template <class T> class GenericContainer
{
public:
	T lista[10];
	GenericContainer<T>() {};
	~GenericContainer() {};
	T getElement(int i)
	{
		return lista[i];
	}
	void setElement(T x ,int i)
	{
		lista[i] = x;
	}
};

