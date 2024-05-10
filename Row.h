	#pragma once
	#include "Exception.cpp"
	template<class U>
	class Array; // Forward declaration of Array class

	template <class T>
	class Array2D;


	template <class T>

	class Row {
	public:
		Row(Array2D<T>& in_array, int row);

		T& operator[](int col);

	private:
		int m_row = 0;
		Array2D<T>& m_array2d;

	};


	template<class T>
	inline Row<T>::Row(Array2D<T>& in_array, int row) : m_array2d(in_array), m_row(row) {}

	template<class T>
	inline T& Row<T>::operator[](const int col)
	{
		if (col > m_array2d.getColumn() || col < 0) {
			Exception negLength;
			std::string msg = "Error: out of bounds low";
			negLength.setMessage(msg);
			throw negLength;
		}
		return m_array2d.select(m_row, col);

	}
