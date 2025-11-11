/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:40:43 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/11 18:52:25 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T> class Array{

	private:
		T *type;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int);
		Array(const Array&);
		Array& operator=(const Array&);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index)const;
		~Array();
		unsigned int size() const;
	class SizeException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};
#include "Array.tpp"

#endif


