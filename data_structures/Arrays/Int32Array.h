#ifndef __Int32Array_H__
#define __Int32Array_H__

#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "../../Interfaces/IPrintable.h"

template <size_t S>
class Int32Array : public IPrintable {
public:
	Int32Array(std::initializer_list<int>);
	Int32Array(int fillValue = 0);
	Int32Array(const Int32Array& other);
	Int32Array(Int32Array&& other) noexcept;
	~Int32Array();

	// IPrintable implementation
	void Print(std::ostream& os) const override;

	// members functions
	size_t Append(int value);
	void Insert(size_t index, int value);
	void Remove(size_t index);

	size_t Length() const { return _length; }
	size_t Size() const { return _size; }

	// operators
	int& operator[](size_t index) const;

private:
	int* _data;
	// stores the number of elements initialized in the array, not the size of the array itself
	size_t _size;
	// store the size of the array, which is S, the template parameter
	size_t _length;
};

template <size_t S>
Int32Array<S>::Int32Array(std::initializer_list<int> lL) 
	: _length{ S }, _size{ lL.size() }, _data{ new int[S] } {
	if (lL.size() > S) throw std::length_error("too many elements");

	std::copy(lL.begin(), lL.end(), _data);
}

template<size_t S>
Int32Array<S>::Int32Array(int fillValue)
	: _length{ S }, _size{ S }, _data{ new int[S] } {
	std::fill(_data, _data + S, fillValue);
}

template<size_t S>
Int32Array<S>::Int32Array(const Int32Array& other)
	: _length{ other._length }, _size{ other._size }, _data{ new int[other._length] } {
	std::copy(other._data, other._data + other._size, _data);
}

template<size_t S>
Int32Array<S>::Int32Array(Int32Array&& other) noexcept
	: _length{ std::move(other._length) }, _size{ std::move(other._size) }, _data{ other._data } {
	other._data = nullptr;
	other._length = 0;
	other._size = 0;
}

template <size_t S>
Int32Array<S>::~Int32Array() {
	delete[] _data;
	_data = nullptr;
}

template<size_t S>
void Int32Array<S>::Print(std::ostream& os) const
{
	os << "Int32Array of size " << _size << " and length " << _length << ": [";

	for (size_t i = 0; i < _size; ++i) {
		os << _data[i];
		if (i < _size - 1) os << ", ";
	}
	
	os << "]";
}

template<size_t S>
size_t Int32Array<S>::Append(int value)
{
	if (_size >= _length) {
		// we need to resize the array
		int* newData = new int[_length * 2];
		// copy the old data to the new array and delete the old array
		std::copy(_data, _data + _size, newData);
		delete[] _data;
		// update the pointer to the new array, length, size, and write the new value
		_data = newData;
		_data[_size] = value;
		_size++;
		_length *= 2;
	}
	else {
		_data[_size] = value;
		_size++;
	}

	// return index of the newly added element
	return _size - 1;
}

template<size_t S>
void Int32Array<S>::Insert(size_t index, int value)
{

}

template<size_t S>
void Int32Array<S>::Remove(size_t index)
{

}

template<size_t S>
int& Int32Array<S>::operator[](size_t index) const
{
	if (index >= _size) throw std::out_of_range("Index out of range");
	return _data[index];
}

#endif