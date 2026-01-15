/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:33:29 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/15 18:35:50 by xhamzall         ###   ########.fr       */
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
		_marge.sortVector(_marge.getVect());
	// for (unsigned long i = 0; i < _marge.getVect().size() ; i++)
	// {

	// 	std::cout <<"Vett: "<<_marge.getVect()[i]<<std::endl;
	// }
	return 0;
}
