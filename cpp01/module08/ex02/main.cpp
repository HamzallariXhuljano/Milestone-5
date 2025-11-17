/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:11:25 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/17 17:17:00 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int>
	mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout <<"last element: "<< mstack.top() << std::endl;
	mstack.pop();
	std::cout <<"Size: "<< mstack.size() << std::endl;

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

	std::cout<<"============================= list ============================="<<std::endl;
	std::list<int> container;

	container.push_back(5);
	container.push_back(17);
	std::cout << "Last element: " << container.back() << std::endl;
	container.pop_back();
	std::cout << "Size: " << container.size() << std::endl;
	container.push_back(3);
	container.push_back(5);
	container.push_back(737);
	container.push_back(0);

	std::list<int>::iterator it1 = container.begin();
	std::list<int>::iterator ite1 = container.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	return 0;
}
