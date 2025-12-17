/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:18:40 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/17 18:01:18 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


template<typename T> MutantStack<T>::MutantStack(): std::stack<T>(){}

template<typename T> MutantStack<T>::MutantStack(const MutantStack<T> &obj) : std::stack<T>(obj) {}

template<typename T> MutantStack<T>&  MutantStack<T>::operator= (const MutantStack<T> &obj)
{
	if(this != &obj)
		std::stack<T>::operator=(obj);
	return *this;
}
template<typename T> MutantStack<T>::~MutantStack(){}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::r_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::r_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::r_const_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::r_const_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}
