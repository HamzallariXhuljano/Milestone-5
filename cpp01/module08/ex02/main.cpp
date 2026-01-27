/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:11:25 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/26 16:23:21 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "--- SUBJECT TEST (MutantStack vs List) ---" << std::endl;

	std::cout << "[MutantStack Output]:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n[std::list Output]:" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "Top: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "Size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	// =========================================================================
	// 2. TEST REVERSE ITERATOR (Deve stampare al contrario)
	// =========================================================================
	std::cout << "\n--- REVERSE ITERATOR TEST ---" << std::endl;

	MutantStack<int>::r_iterator rit = mstack.rbegin();
	MutantStack<int>::r_iterator rite = mstack.rend();

	std::cout << "Elements in reverse order:" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	return 0;
}
