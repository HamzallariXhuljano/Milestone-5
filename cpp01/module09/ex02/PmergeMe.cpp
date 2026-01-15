/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:33:33 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/15 18:39:03 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	this->operator= (obj);
}
PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->_vector = obj._vector;
		// this->_list = obj._list;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{

}

int PmergeMe::pars(std::string &s)
{
	size_t len = s.size();
	long n ;
	int num;

	if (s.empty() || len > 10)
		return -1;
	for (size_t i = 0; i < len; i++)
	{
		if (!isdigit(s[i]))
			return -1;
	}
	n = atol(s.c_str());
	if (n > INT_MAX)
		return -1;
	else
		num = n;
	return num;
}

void PmergeMe::fillContainers(int &num)
{
	this->_vector.push_back(num);
	// this->_list.push_back(s);
}

// std::vector<int> PmergeMe::getVect()
// {
// 	return this->_vector;
// }

// std::list<std::string> PmergeMe::getList()
// {
// 	return this->_list;
// }

void PmergeMe::sortVector(std::vector<int> _vect)
{
	std::vector < std::pair<int, int> > _pairs;
	size_t len = _vect.size();
	std::vector<int> _winners;
	std::vector<int> _losers;
	int _alone;
	bool _odd = false;

	if (len % 2 != 0)
	{
		_alone = _vect.back();
		_vect.pop_back();
		_odd = true;
	}
	len = _vect.size();
	for (size_t i = 0; i < len; i += 2)
	{
		if (_vect[i] <= _vect[i + 1])
		{
			_pairs.push_back(std::make_pair(_vect[i], _vect[i + 1]));
			_winners.push_back(_vect[i+1]);
			_losers.push_back(_vect[i]);
		}
		else
		{
			_pairs.push_back(std::make_pair(_vect[i + 1], _vect[i]));
			_winners.push_back(_vect[i]);
			_losers.push_back(_vect[i + 1]);
		}
	}
	if (_vect.size() > 1)
	{
		for (unsigned long i = 0; i < _winners.size() ; i++)
		{

			std::cout <<"Vett: "<<_winners[i]<<" " ;
		}
		std::cout<<std::endl;
		sortVector(_winners);
		/* code */
	}

	return;
}

std::vector< int> PmergeMe::getVect(){return this->_vector;}
