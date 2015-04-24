#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>

template<typename T>
class Array
{
public:
	//constructors
	Array();
	Array(T* rhs, int size);
	Array(int size);
	//Array(const Array<T>& rhs);

	//destructor
	~Array();

	//operators overloading
	Array<T>& operator=(const Array<T>& rhs);
	T& operator[](int pos);

	//operations with array
	//Add(T* data); - implement later!!
	int Size();
	void Print();
	//void Resize(int size);
private:
	void Destroy();

private:
	int mSize;
	T* mData;
};
/*
template<typename T>
void Array<T>::Resize(int size)
{

}
*/
template<typename T>
Array<T>::Array(T* rhs, int size)
{
	mSize = size;
	mData = new T[size];
	for (int i = 0; i < size; i++)
	{
		mData[i] = rhs[i];
	}
}

template<typename T>
Array<T>::Array<T>()
{
	mSize = 0;
	mData = 0;
}

template<typename T>
Array<T>::Array<T>(int size)
{
	mSize = size;
	mData = new T[size];
}
/*
template<typename T>
Array<T>::Array<T>(const Array<T>& rhs)
{
	mSize = rhs->mSize;
	for (int i = 0; i < mSize; i++)
	{
		T* mData[i] = new T();
		mData[i] = rhs->mData[i];
	}
}
*/
template<typename T>
void Array<T>::Destroy()
{
	for (int i = 0; i < mSize; i++)
	{
		delete[] mData;
		mData = 0;
	}
	mSize = 0;
}

template<typename T>
Array<T>::~Array<T>()
{
	Destroy();
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this == &rhs) return *this;

	Destroy();
	mSize = rhs->mSize;
	for (int i = 0; i < rhs->mSize; i++)
	{
		T* mData[i] = new T();
		mData[i] = rhs->mData[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](int i)
{
	return mData[i];
}

template<typename T>
int Array<T>::Size()
{
	return mSize;
}

template<typename T>
void Array<T>::Print()
{
	for (int i = 0; i < mSize; i++)
	{
		//std::cout << mSize << std::endl;
		std::cout << i + 1 << ": " << mData[i] << ";" << std::endl;
	}
}

#endif