/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:14:57 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/16 17:31:55 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_n(0), v(0)
{}

Span::Span(unsigned int max_n)
{
	this->max_n = max_n;
}

Span::Span(const Span &obj) :max_n(0), v(obj.v)
{
	this->operator=(obj);
}

Span& Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->max_n = obj.max_n;
		this->v = obj.v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(const int n)
{
	if (v.size() < this->max_n)
		v.push_back(n);
	else
		throw SizeException();
}


int Span::shortestSpan()
{
	int tmp;
	int res;
	std::vector<int> v_tmp = this->v;

	res = INT_MAX;

	if (v.size() <= 1)
		throw (StoredException());
	sort(v_tmp.begin(), v_tmp.end());
	for (size_t i = 0; i < v_tmp.size() - 1; i++)
	{
			tmp = abs(v_tmp[i] - v_tmp[i + 1]);
			if (res > tmp)
				res = tmp;
	}
	return res;
}

int Span::longestSpan()
{
	std::vector<int> v_tmp = this->v;

	if (v.size() <= 1)
		throw (StoredException());
	sort(v_tmp.begin(), v_tmp.end());
	return (v_tmp[v_tmp.size() - 1] - v_tmp[0]);
}

const char*Span::SizeException::what() const throw()
{
	return "The size limit is reached, you cannot add";
}

const char*Span::StoredException::what() const throw()
{
	return "The are to few elements (0 o 1)";
}
