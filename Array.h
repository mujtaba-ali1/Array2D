#pragma once
#include <iostream>
#include "Exception.h"
template <class T>
class Array {
private:
	T* m_array = new T [10];
	int m_length = 0;
	int m_start_index = 0;

public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array& other);
	int getStartIndex();
	void setStartIndex(int startIndex);
	int getLength();
	void setLength(int other);
	Array<T>& operator =(const Array& other);
	T& operator[](int index);

	~Array();
};

template<class T>
inline Array<T>::Array() {
	m_array = new T[10];
	m_length = 10;
	m_start_index = 0;
}

template<class T>
inline Array<T>::Array(int length, int start_index): m_array(nullptr), m_length(length), m_start_index(start_index) {
	
}

template<class T>
inline Array<T>::Array(const Array& other)
{
	m_length = other.getLength();
	m_array = new T[m_length + 1];
	m_start_index = other.getStartIndex();
	for (int curPos = 0; curPos < m_length; curPos++) {
		m_array[curPos] = other[curPos];
	}
}

template<class T>
inline int Array<T>::getStartIndex()
{
	
	return m_start_index;
}

template<class T>
inline void Array<T>::setStartIndex(int startIndex)
{
	try
	{
		if (startIndex < 0) {
			Exception negLength;
			std::string msg = "Warning: Neg Sized Array causes issues!\n";
			negLength.setMessage(msg);
			throw negLength;
		}
		m_start_index = startIndex;
	}
	catch (const Exception&) {
		throw;
	}
}

template<class T>
inline int Array<T>::getLength()
{
	return m_length;
}

template<class T>
inline void Array<T>::setLength(int other)
{
	try
	{
		if (other < 0) {
			Exception negLength;
			size_t sizeMsg = strlen("Error: Neg Sized Array not possible") + 1;
			char* msg = new char[sizeMsg];
			strcpy_s(msg, sizeMsg, "Error: Neg Sized Array not possible");
			delete[] msg;
			throw negLength;
		}
		m_length = other;
	}
	catch (const Exception&) {
		throw;
	}

	try
	{
		if (other == 0) {
			Exception negLength;
			size_t sizeMsg = strlen("Error: Zero Sized Array not possible") + 1;
			char* msg = new char[sizeMsg];
			strcpy_s(msg, sizeMsg, "Error: Zero Sized Array not possible");
			delete[] msg;
			throw negLength;
		}
		if (other < m_length)
		{
			T* temp = m_array;
			m_array = new T[other + 1];
			for (int currentPos = 0; currentPos < other; currentPos++) {
				m_array[currentPos] = temp[currentPos];
			}
			delete[] temp;
		}
		
	}
	catch (const Exception&) {
		throw;
	}
}

template<class T>
inline Array<T>& Array<T>::operator=(const Array& other)
{
	m_array = new T[other.getLength()+1];
	m_length = other.getLength();
	m_start_index = other.m_start_index;
	for (int currentPos = 0; currentPos < m_array; currentPos++) {
		m_array[currentPos] = other[currentPos];
	}
		return *this;
}

template<class T>
inline T& Array<T>::operator[](int index)
{
	try
	{
		if (index < 0) {
			Exception negLength;
			std::string msg = "Error: out of bounds low";
			negLength.setMessage(msg);
			throw negLength;
		}
		else if (index > m_length) {
			Exception negLength;
			std::string msg = "Error: out of bounds high";
			negLength.setMessage(msg);
			throw negLength;
		}
	}
	catch (const std::exception e )
	{	

	}

	return m_array[index];

}

template<class T>
inline Array<T>::~Array() {

	
	delete[] m_array;

}


