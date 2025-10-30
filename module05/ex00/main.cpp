/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:39:02 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 16:45:55 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Thommy", 9);

	std::cout<<"=========== Test no erros increment ========"<<std::endl;
	try
	{
		b.increment(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b;
	std::cout<<"=========== Test erros increment =========="<<std::endl;
	try
	{
		b.increment(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b;
	std::cout<<"=========== Test no erros dincrement ======="<<std::endl;
	try
	{
		b.decrement(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b;
	std::cout<<"=========== Test erros dincrement ======="<<std::endl;
	try
	{
		b.decrement(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b;
	return 0;
}
