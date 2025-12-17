/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:14:55 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/16 18:32:14 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "=== TEST 1: Basic addNumber + spans ===" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: Range insert with addMultNum ===" << std::endl;
	try
	{
		Span sp(5);
		std::vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		sp.addNumber(5);
		sp.addNumber(1);

		sp.addMultNum(v.begin(), v.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: addMultNum overflow ===" << std::endl;
	try
	{
		Span sp(4);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);

		sp.addNumber(100);
		sp.addMultNum(v.begin(), v.end());
		sp.addMultNum(v.begin(), v.end());
	}
	catch (std::exception &e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: Not enough numbers for span ===" << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 5: Span empty ===" << std::endl;
	try
	{
		Span sp(10);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: Large test (10,000 random numbers) ===" << std::endl;
	try
	{
		Span sp(100000);
		std::vector<int> v;

		for (int i = 0; i < 100000; i++)
			v.push_back(rand());
		sp.addMultNum(v.begin(), v.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
		// for (int i = 0; i < 100000; i++)
		// 	std::cout << "######" << v[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

