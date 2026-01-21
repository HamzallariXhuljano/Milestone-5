/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:33:33 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/21 18:02:17 by xhamzall         ###   ########.fr       */
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
		this->_deque = obj._deque;
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

void PmergeMe::fillVect(int &num)
{
	this->_vector.push_back(num);
}

void PmergeMe::fillDeque(int &num)
{
	this->_deque.push_back(num);
}

std::vector<int> PmergeMe::getVect()
{
	return this->_vector;
}

std::deque<int> PmergeMe::getDeque()
{
	return this->_deque;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> _vect)
{
	std::vector < std::pair<int, int> > _pairs;
	size_t len = _vect.size();
	std::vector<int> _winners;
	std::vector<int> _pendants;
	int _alone;
	bool _odd = false;

	if (_vect.size() <= 1)
		return _vect;
	if (len % 2 != 0)
	{
		_alone = _vect.back();
		_vect.pop_back();
		_odd = true;
	}
	divideContainer(_vect, _winners, _pairs);
	std::vector<int> _mainChain = sortVector(_winners);
	fillPendants(_mainChain,_pendants, _pairs);
	insertLosers(_mainChain, _pendants, _pairs);
	if (_odd == true)
	{
		std::vector<int>::iterator it = std::lower_bound(_mainChain.begin(), _mainChain.end(), _alone);
		_mainChain.insert(it, _alone);
	}
		return _mainChain;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> _deque)
{
	std::deque < std::pair<int, int> > _pairs;
	size_t len = _deque.size();
	std::deque<int> _winners;
	std::deque<int> _pendants;
	int _alone;
	bool _odd = false;

	if (_deque.size() <= 1)
		return _deque;
	if (len % 2 != 0)
	{
		_alone = _deque.back();
		_deque.pop_back();
		_odd = true;
	}
	divideContainer(_deque, _winners, _pairs);
	std::deque<int> _mainChain = sortDeque(_winners);
	fillPendants(_mainChain,_pendants, _pairs);
	insertLosers(_mainChain, _pendants, _pairs);
	if (_odd == true)
	{
	std::deque<int>::iterator it = std::lower_bound(_mainChain.begin(), _mainChain.end(), _alone);
		_mainChain.insert(it, _alone);
	}
		return _mainChain;
}

int PmergeMe::jacobsthal(int index)
{
	int _j_prev = 0;
	int _j_curr = 1;
	int _j_next = 1;
	if (index == 1 || index == 0)
		return index;
	for (int i = 2; i <= index; i++)
	{
		_j_next = _j_curr + 2 * _j_prev;
		_j_prev = _j_curr;
		_j_curr = _j_next;
	}
	return _j_next;
}

void PmergeMe::printInput(char **av, int ac)
{
	std::cout<<"Before:";
	for (int i = 1; i < ac; i++)
	{
		std::cout<<" "<<av[i];
	}
	std::cout<<std::endl;
}
