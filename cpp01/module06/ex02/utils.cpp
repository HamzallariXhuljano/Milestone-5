/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:36:43 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/10 19:43:14 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base* generate(void)
{
	Base *base = NULL;
	int num;

	num = rand() % 3;

	switch (num)
	{
	case 0:
		base = new A();
		break;
	case 1:
		base = new B();
		break;
	case 2:
		base = new C();
		break;
	default:
		base = NULL;
		break;
	}
	return base;
}

void identify(Base *p)
{
	A *a;
	B *b;
	C *c;

	//dynamic_cast * se non e' di quel tipo mette nullptr
	a = dynamic_cast <A*>(p);
	b = dynamic_cast <B*>(p);
	c = dynamic_cast <C*>(p);
	if (a != NULL)
		std::cout <<"is A type"<<std::endl;
	else if (b != NULL)
		std::cout <<"is B type"<<std::endl;
	else if (c != NULL)
		std::cout <<"is C type"<<std::endl;
}

void identify(Base &p)
{

	try
	{
		(void)dynamic_cast <A&> (p);
		std::cout << "is type A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast <B&> (p);
		std::cout << "is type B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast <C&> (p);
		std::cout << "is type C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	std::cerr<<"std::bad_cast"<<std::endl;
}
