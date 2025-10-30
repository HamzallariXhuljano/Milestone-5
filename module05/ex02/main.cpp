/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:39:02 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 18:22:05 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	Bureaucrat b("Thommy", 1);
	AForm f("Ciao", 1, 15, false);

	std::cout<<"=========== Test no erros sign Aform ========"<<std::endl;
	std::cout<<b;
	b.signAform(f);
	std::cout<<f;
	std::cout<<"=========== Test erros sign Aform =========="<<std::endl;
	try
	{
		b.decrement(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<b;
	b.signAform(f);
	std::cout<<f;
	return 0;
}
