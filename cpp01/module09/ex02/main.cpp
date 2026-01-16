/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:33:29 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/16 20:52:42 by xhamzall         ###   ########.fr       */
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
		_marge.fillContainers(num);
	}
		std::vector<int> _sorted = _marge.sortVector(_marge.getVect());
	std::cout <<"Old Vett: ";
	for (unsigned long i = 0; i < _marge.getVect().size(); i++)
	{
		std::cout<<" " <<_marge.getVect()[i];
	}
	std::cout <<std::endl;
	std::cout <<std::endl;
	std::cout <<"Sort Vett: ";
	for (unsigned long i = 0; i < _sorted.size() ; i++)
	{
		std::cout<<" " <<_sorted[i];
	}
	std::cout <<std::endl;
	return 0;
}
