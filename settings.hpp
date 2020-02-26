#include <iostream>
#include "pair.hpp"

using namespace std;

template<class T>
class Settings
{
private:
	Pair<T> * container;
	int size;
	int capacity;
	void resize();
	void erase();
	void copy(const Settings& other);

public:
	Settings();
	Settings(const Pair<T>* container);
	Settings(const Settings& other);
	Settings& operator=(const Settings& other);
	~Settings();
	int count() const;
	void set(const char* key, T value);
	bool get(const char* key, T& value);

};

template<class T>
void Settings<T>::resize()
{
	Pair<T>* newContainer = new Pair<T>[capacity * 2];
	for (int i = 0; i < size; i++)
	{
		newContainer[i] = container[i];
	}
	erase();
	container = newContainer;
	capacity *= 2;
}

template<class T>
void Settings<T>::erase()
{
	delete[] container;
}

template<class T>
void Settings<T>::copy(const Settings & other)
{
	size = other.size;
	capacity = other.capacity;
	container = new Pair<T>[capacity];
	for (int i = 0; i < size; i++)
	{
		container[i] = other.container[i];
	}
}

template<class T>
inline Settings<T>::Settings()
{
	size = 0;
	capacity = 4;
	container = new Pair<T>[capacity];
}

template<class T>
Settings<T>::Settings(const Pair<T>* container)
{
	copy(container);
}

template<class T>
Settings<T>::Settings(const Settings & other)
{
	copy(other);
}

template<class T>
Settings<T> & Settings<T>::operator=(const Settings<T> & other)
{
	if (this != &other)
	{
		erase();
		copy(other); 
	}
	return *this;
}

template<class T>
Settings<T>::~Settings()
{
	erase();
}

template<class T>
int Settings<T>::count() const
{
	return size;
}

template<class T>
void Settings<T>::set(const char * key, T value)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(container[i].getKey(), key) == 0)
		{
			container[i].setValue(value);
			return;
		}
	}
	if (size == capacity)
	{
		resize();
	}
	Pair<T> pair(key, value);
	container[size++] = pair;
}

template<class T>
bool Settings<T>::get(const char * key, T& value)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(container[i].getKey(), key) == 0)
		{
			value = container[i].getValue();
			return true;
		}
	}
	return false;
}


