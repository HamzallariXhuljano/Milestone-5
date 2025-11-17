/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:15:00 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/15 17:55:39 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>

class Span
{
	private:
		unsigned int max_n;
		std::vector<int> v;
	public:
		Span();
		Span(unsigned int);
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();
		void addNumber(const int);
		template <typename T> void addMultNum(T, T);
		int shortestSpan();
		int longestSpan();
		// int gen();
		class SizeException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class StoredException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
#include "Span.tpp"
#endif
