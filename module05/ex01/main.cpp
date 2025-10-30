/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:39:02 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 16:31:09 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b("Thommy", 1);
	Form f("Ciao", 1, 15, false);

	std::cout<<"=========== Test no erros sign Form ========"<<std::endl;
	std::cout<<b;
	b.signForm(f);
	std::cout<<f;
	std::cout<<"=========== Test erros sign Form =========="<<std::endl;
	try
	{
		b.decrement(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b;
	b.signForm(f);
	std::cout<<f;
	return 0;
}
