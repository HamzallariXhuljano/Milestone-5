/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:39:02 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/22 16:16:58 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Thommy", 9);

	std::cout<<"=========== Test erros costructor ========"<<std::endl;
	try
	{
		Bureaucrat c ("SDSADASDAd", 0);
		std::cout<< c <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<"=========== Test no erros increment =========="<<std::endl;
	try
	{
		b.increment(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b<<std::endl;
	std::cout<<"=========== Test erros increment =========="<<std::endl;
	try
	{
		b.increment(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b<<std::endl;
	std::cout<<"=========== Test no erros dincrement ======="<<std::endl;
	try
	{
		b.decrement(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b<<std::endl;
	std::cout<<"=========== Test erros dincrement ======="<<std::endl;
	try
	{
		b.decrement(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b<<std::endl;
	std::cout<<"=========== Test d Bureacrat ======="<<std::endl;
	Bureaucrat d = b;
	try
	{
		d.decrement(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << d<<std::endl;
	return 0;
}
