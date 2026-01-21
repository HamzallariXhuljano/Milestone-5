/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:32:44 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/21 18:06:38 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <fstream>
#include <time.h>
#include <climits>
#include <ctime>
#include <iomanip>//per set precision

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int>	_deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		int pars(std::string&);
		void fillVect(int &num);
		void fillDeque(int &num);
		std::vector< int> getVect();
		std::deque<int> getDeque();
		std::vector<int> sortVector(std::vector<int>);
		std::deque<int> sortDeque(std::deque<int>);
		void printInput(char **av, int ac);
		int jacobsthal(int);

		template <typename Container>
		void printContainer(Container &c)
		{
			size_t len = c.size();
			std::cout <<"After: ";
			for (size_t i = 0; i < len; i++)
			{
				std::cout<<" " <<c[i];
			}
			std::cout<<std::endl;
		}

		template <typename Container, typename Pair>
		void divideContainer(Container &_c, Container &_winContainer, Pair &_p)
		{
			size_t len = _c.size();
			for (size_t i = 0; i < len; i += 2)
			{
				if (_c[i] <= _c[i + 1])
				{
					_p.push_back(std::make_pair(_c[i], _c[i + 1]));
					_winContainer.push_back(_c[i + 1]);
				}
				else
				{
					_p.push_back(std::make_pair(_c[i + 1], _c[i]));
					_winContainer.push_back(_c[i]);
				}
			}
		}

		template <typename Container, typename Pair>
		void fillPendants(Container &_main ,Container &_pedants , Pair &_p)
		{
			size_t _mLen = _main.size();
			size_t _pLen = _p.size();

			for (size_t i = 0; i < _mLen; i++)
			{
				int _win = _main[i];
				for (size_t j = 0; j < _pLen; j++)
				{
					if (_win == _p[j].second)
					{
						_pedants.push_back(_p[j].first);
						break;
					}
				}
			}
		}

		template <typename Container, typename Pair>
		void insertLosers(Container &_main ,Container &_pedants , Pair &_p)
		{
			_main.insert(_main.begin(), _pedants[0]);
			size_t _num_inserted = 1;//_pendats[0] gia inserito
			int _steps = 0;
			int _winFriend = -1;
			size_t _jcb_prev = 0;
			while (_num_inserted < _pedants.size())
			{
				size_t _jcb_current = jacobsthal(_steps);
				if (_jcb_current >= _pedants.size())
					_jcb_current = _pedants.size() - 1;
				for (size_t i = _jcb_current; i > _jcb_prev; i--)
				{
					int _min = _pedants[i];
					for (size_t j = 0; j < _p.size(); j++)
					{
						if (_min == _p[j].first)
						{
							_winFriend = _p[j].second;
							typename Container::iterator it = std::find(_main.begin(), _main.end(), _winFriend);
							typename Container::iterator pos = std::lower_bound(_main.begin(), it, _min);
							_main.insert(pos, _min);
							_num_inserted++;
							break;
						}
					}
				}
				_jcb_prev = _jcb_current;
				_steps++;
			}
		}
		~PmergeMe();
};

#endif
