/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:32:44 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/16 18:08:47 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
#include <time.h>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		// std::list<std::string>	_list;e
	public:
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		int pars(std::string&);
		void fillContainers(int &);
		std::vector< int> getVect();
		std::list<std::string> getList();
		std::vector<int> sortVector(std::vector<int> vect);
		int jacobsthal(int);
		// void margeSortList();
		~PmergeMe();
};

#endif
