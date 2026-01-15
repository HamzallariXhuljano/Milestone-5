/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:32:44 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/15 18:33:34 by xhamzall         ###   ########.fr       */
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
		void sortVector(std::vector<int> vect);
		void margeSortList();
		~PmergeMe();
};

#endif
