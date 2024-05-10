#pragma once
#include "Row.h"
#include "Array.h"


template <class T>
class Array2D
{
public:
	//cannonicals
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D<T>& copy);
	~Array2D();
	//mutator
	Array2D<T>& operator=(const Array2D<T>& rhs);
	Row<T>& operator[](int index);
	int getRow();
	void setRow(int rows);
	int getColumn();
	void setColumn(int columns);
	T& select(int row, int column);

private:
	Array<T> m_array;
	int m_row;
	int m_col;

};
template<class T>
Array2D<T>::~Array2D() {
	;
}
template<class T>
Array2D<T>::Array2D() : m_row(0), m_col(0), m_array(new Array<T>()) {}

template<class T>
inline Array2D<T>::Array2D(int row, int col) : m_row(row), m_col(col) {}

template<class T>
inline Array2D<T>::Array2D(const Array2D& copy) : m_array(copy.m_array), m_row(copy.m_row), m_col(copy.m_col) {}






template<class T>
inline int Array2D<T>::getRow()
{
	 return m_row;
}
template<class T>
inline void Array2D<T>::setRow(int rows)
{
	m_row = rows;
}

template<class T>
inline int Array2D<T>::getColumn()
{
	return m_col;
}
template<class T>
inline void Array2D<T>::setColumn(int columns)
{
	m_col = columns;
}
template<class T>
inline T& Array2D<T>::select(int row, int column)
{
	try
	{
		if (row < 0 || row >= m_row || column < 0 || column > m_col) {
			Exception negLength;
			std::string msg = "Error: out of bounds";
			negLength.setMessage(msg);
			throw negLength;
		}
	}
	catch (const std::exception e)
	{

	}
	auto location = row * m_col + column;
	return m_array[location];
}

template<class T>
inline Array2D<T>& Array2D<T>::operator=(const Array2D& rhs)
{
	if (this != &rhs) {
		m_array = rhs.m_array;
		m_row = rhs.m_row;
		m_col = rhs.m_col;
	}
	return *this;
}

template<class T>
inline Row<T>& Array2D<T>::operator[](int index)
{
	
	try
	{
		if (index < 0 || index >= m_row) {
			Exception negLength;
			std::string msg = "Error: out of bounds";
			negLength.setMessage(msg);
			throw negLength;
		}
	}
	catch (const std::exception e)
	{

	}
	
	return Row<T>;
}



