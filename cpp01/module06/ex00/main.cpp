/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:25:27 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/05 20:37:09 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>// per stampare dopo la virgola std::fixed
#include "ScalarConverter.hpp"


int main(int ac, char **av)
{

	if (!av[1])
	{
		std::cerr << "Empty line" <<std::endl;
		return (1);
	}
	if (ac != 2)
	{
		std::cerr << "Error input file"<<std::endl;
		return (1);
	}
	ScalarConvert::converter(av[1]);
	return 0;
}
