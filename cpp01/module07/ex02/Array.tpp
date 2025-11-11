/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:18:57 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/11 18:52:20 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array()
{
	// this->type = new T[0];
	this->type = NULL;// e' uguale a quello sopra ma meglio
	this->_size = 0;
}

template <typename T> Array<T>::Array(unsigned int size)
{
	this->_size = size;
	this->type = new T[this->_size]; //deep copy
}

template <typename T> Array<T>::Array(const Array &obj) : type(NULL), _size(0)
{
	this->operator=(obj);
}
template <typename T> Array<T>& Array<T>::operator=(const Array &obj)
{
	if (this != &obj)
	{
		delete[] this->type;

		this -> _size = obj._size;

		this -> type = new T[this->_size];//deep cpy
		for (unsigned int i = 0; i < this->_size; i++)
			this->type[i] = obj.type[i];
	}
	return *this;
}

template <typename T> T& Array<T>::operator[](unsigned int index)
{
		if (index >= this->_size)
			throw SizeException();
		return this->type[index];
}

template <typename T> const T& Array<T>::operator[](unsigned int index) const
{
		if (index >= this->_size)
			throw SizeException();
		return this->type[index];

}

template <typename T> const char* Array<T>::SizeException::what() const throw()
{
	return "Wrong array size";
}

template <typename T> Array<T>::~Array()
{
	delete[] type;
}

template <typename T> unsigned int Array<T>::size() const
{
	return this->_size;
}
