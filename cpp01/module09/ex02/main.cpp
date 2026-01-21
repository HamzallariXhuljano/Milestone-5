/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:33:29 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/21 18:09:38 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe _marge;
	if (ac < 2)
	{
		std::cerr << "Error"<<std::endl;
		return 1;
	}
	std::clock_t _t_start_vect = clock();
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		int num =-1;
		if (str.empty())
		{
			std::cerr <<"Error"<<std::endl;
			return 2;
		}
		num = _marge.pars(str);
		if ( num == -1)
		{
			std::cerr<<"Error"<<std::endl;
			return 3;
		}
		_marge.fillVect(num);
	}
	std::vector<int> _sortedVector = _marge.sortVector(_marge.getVect());
	std::clock_t _t_end_vect = (clock() - _t_start_vect);
	//----------------------------------------------------
	std::clock_t _t_start_deque = clock();
	for (int i = 1; i < ac; i++)
		{
			std::string str = av[i];
			int num =-1;
			if (str.empty())
			{
				std::cerr <<"Error"<<std::endl;
				return 2;
			}
			num = _marge.pars(str);
			if ( num == -1)
			{
				std::cerr<<"Error"<<std::endl;
				return 3;
			}
			_marge.fillDeque(num);
		}
	std::deque<int> _sortedDeque = _marge.sortDeque(_marge.getDeque());
	std::clock_t _t_end_deque = (clock() - _t_start_deque);
	//------------------------------------------------------
	_marge.printInput(av,ac);
	double _time_vec = ((double)_t_end_vect) / CLOCKS_PER_SEC ;
	double _time_deque = ((double)_t_end_deque) / CLOCKS_PER_SEC ;
	// _marge.printContainer(_sortedVector);
	// std::cout<<"************************************"<<std::endl;
	_marge.printContainer(_sortedDeque);
	std::cout<<"Time to process a range of "<< ac - 1 <<" elements with std::vector: "<< std::fixed << std::setprecision(5)<< _time_vec << " sec"<< std::endl;
	std::cout<<"Time to process a range of " << ac - 1 <<" elements with std::deque: "<< std::fixed << std::setprecision(5) << _time_deque <<"sec"<< std::endl;
	return 0;
}
