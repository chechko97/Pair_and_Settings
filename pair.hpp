#include <iostream>

using namespace std;

template<class T>
class Pair
{
private:
	char* key;
	T value;
public:
	Pair();
	Pair(const char* key, T value);
	Pair(const Pair& other);
	Pair& operator=(const Pair& other);
	~Pair();
	char* getKey() const;
	T getValue() const;
	void setValue(T value);

};

template<class T>
inline Pair<T>::Pair()
{
	key = nullptr;
	value = 0;
}

template<class T>
inline Pair<T>::Pair(const char * key, T value) : key(nullptr)
{
	this->key = new char[strlen(key) + 1];
	strcpy_s(this->key, strlen(key) + 1, key);
	this->value = value;
}

template<class T>
inline Pair<T>::Pair(const Pair & other)
{
	this->key = new char[strlen(other.key) + 1];
	strcpy_s(this->key, strlen(other.key) + 1, other.key);
	this->value = other.value;
}

template<class T>
Pair<T> & Pair<T>::operator=(const Pair<T>& other)
{
	if (this != &other)
	{
		delete[] this->key;
		this->key = new char[strlen(other.key) + 1];
		strcpy_s(this->key, strlen(other.key) + 1, other.key);
		this->value = other.value;
	}
	return *this;
}

template<class T>
Pair<T>::~Pair()
{
	delete[] key;
}

template<class T>
char * Pair<T>::getKey() const
{
	return key;
}

template<class T>
T Pair<T>::getValue() const
{
	return value;
}

template<class T>
void Pair<T>::setValue(T value)
{
	this->value = value;
}
