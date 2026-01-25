/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:54:36 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/23 17:29:08 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "utils.hpp"

int main()
{
	srand(time(0));//meglio chiamare una sola volta per avere numeri randomici usata in generate
	Base *base;
	Base *test = new Base();
	B b;
	Base none;
	base = generate();
	identify(base);
	identify(test);
	identify(b);
	identify(none);
	delete test;
	delete base;
}
