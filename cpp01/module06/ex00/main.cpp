/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:25:27 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/23 17:44:54 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::cerr << "Error input"<<std::endl;
		return (1);
	}
	ScalarConvert::converter(av[1]);
	return 0;
}
