/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:33:33 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/16 21:04:57 by xhamzall         ###   ########.fr       */
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

std::vector<int> PmergeMe::sortVector(std::vector<int> _vect)
{
	std::vector < std::pair<int, int> > _pairs;
	size_t len = _vect.size();
	std::vector<int> _winners;
	std::vector<int> _pendants;
	int _alone;
	bool _odd = false;

	if (_vect.size() <= 1)
	{
		return _vect;
	}
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
		}
		else
		{
			_pairs.push_back(std::make_pair(_vect[i + 1], _vect[i]));
			_winners.push_back(_vect[i]);
		}
	}
	for (unsigned long i = 0; i < _winners.size() ; i++)
		{
			std::cout <<"Alone: "<<_alone<<" " <<std::endl;
			std::cout<<"Pairs: "<< _pairs[i].first << " " << _pairs[i].second <<std::endl;
			std::cout <<"winner: "<<_winners[i]<<" " <<std::endl;
		}
	std::cout<<std::endl;
	std::vector<int> _mainChain = sortVector(_winners);
	for (size_t i = 0; i < _mainChain.size(); i++)
	{
		int _big = _mainChain[i];
		for (size_t j = 0; j < _pairs.size(); j++)
		{
			if (_pairs[j].second == _big)
			{
				_pendants.push_back(_pairs[j].first);
				break;
			}

		}
	}
	_mainChain.insert(_mainChain.begin(), _pendants[0]);
	unsigned long _insert_num = 1;//_pendats[0] gia inserito;
	int _steps = 0;
	int _winFriend;
	while (_insert_num < _pendants.size())
	{
		unsigned long j_num = jacobsthal(_steps);
		if (j_num > _pendants.size() )
			j_num =_pendants.size();
		for (int i = j_num; i > 0; i--)
		{
			int _min = _pendants[i];
			for (unsigned long  j = 0; j < j_num; j++)
			{
				if (_min == _pairs[j].first)
				{
					_winFriend = _pairs[j].second;
					std::vector<int>::iterator it = std::find(_mainChain.begin(), _mainChain.end(), _winFriend);
					std::vector<int>::iterator pos = std::lower_bound(_mainChain.begin(), it, _min);
					_mainChain.insert(pos, _min);
					_insert_num++;
				}
			}
		}
		_steps++;
	}
	if (_odd == true)
	{
		std::vector<int>::iterator it = std::lower_bound(_mainChain.begin(), _mainChain.end(), _alone);
		_mainChain.insert(it, _alone);
	}
	return _mainChain;
}

std::vector< int> PmergeMe::getVect(){return this->_vector;}

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
