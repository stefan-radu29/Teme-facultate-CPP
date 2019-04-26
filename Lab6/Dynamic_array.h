#pragma once
#include <stdexcept>

template <typename T>
class Dynamic_vector
{
private:

	T* elements;
	int size;
	int capacity;

public:

	Dynamic_vector(int capacity = 50);

	Dynamic_vector(const Dynamic_vector& other_vector);

	~Dynamic_vector();

	void add(const T& new_element);

	void remove(const T& element);

	T& operator[](int position) const;

	int get_size() const;

private:

	void resize(double resize_factor = 2);

};

template <typename T>
Dynamic_vector<T>::Dynamic_vector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new T[capacity];
}

template <typename T>
Dynamic_vector<T>::Dynamic_vector(const Dynamic_vector& other_vector)
{
	this->size = other_vector.size;
	this->capacity = other_vector.capacity;
	this->elements = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = other_vector.elements[i];
	}
}

template <typename T>
Dynamic_vector<T>::~Dynamic_vector()
{
	delete[] this->elements;
}

template <typename T>
void Dynamic_vector<T>::add(const T& new_element)
{
	if (this->size == this->capacity)
	{
		this->resize();
	}

	this->elements[this->size] = new_element;
	this->size++;
}

template <typename T>
void Dynamic_vector<T>::remove(const T& new_element)
{
	int index, index2;

	for (index = 0; index < this->size; index++)
	{
		if (this->elements[index] == new_element)
		{
			
			if (this->size == 1)
			{
				this->elements[index] = this->elements[index + 1];
			}
			for (index2 = index; index2 < this->size - 1; index2++)
			{
				this->elements[index2] = this->elements[index2 + 1];
			}
			this->size = this->size - 1;
		}
	}
}

template <typename T>
T& Dynamic_vector<T>::operator[](int position) const
{
	if (position < 0 || position >= this->size)
	{
		throw std::out_of_range("invalid position");
	}
	
	return this->elements[position];
}

template <typename T>
int Dynamic_vector<T>::get_size() const
{
	return this->size;
}

template <typename T>
void Dynamic_vector<T>::resize(double resize_factor)
{
	this->capacity = (int)this->capacity * resize_factor;
	
	T* elements = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		elements[i] = this->elements[i];
	}

	delete[] this->elements;

	this->elements = elements;
}