/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:36:43 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/10 18:14:59 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base* generate(void)
{
	Base *base;
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
		break;
	}
	return base;
}

void identify(Base *p)
{
	A *a;
	B *b;
	C *c;

	//dynamic_cast se non e' di quel tipo mette nullptr
	a = dynamic_cast <A*>(p);
	b = dynamic_cast <B*>(p);
	c = dynamic_cast <C*>(p);
	if (a != nullptr)
		std::cout <<"is A type"<<std::endl;
	else if (b != nullptr)
		std::cout <<"is B type"<<std::endl;
	else if (c != nullptr)
		std::cout <<"is C type"<<std::endl;
}

void identify(Base &p)
{
	A &a = dynamic_cast <A&> (p);
	B &b = dynamic_cast <B&> (p);
	C &c = dynamic_cast <C&> (p);

	
}
