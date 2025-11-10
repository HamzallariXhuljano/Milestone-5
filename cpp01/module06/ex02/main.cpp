/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:54:36 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/10 19:32:43 by xhamzall         ###   ########.fr       */
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
	Base a;

	base = generate();

	identify(base);
	identify(a);
}
