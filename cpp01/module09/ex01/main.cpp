/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:58:45 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/08 20:06:09 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int check_in(std::string line)
{
	size_t len = line.size();
	size_t cnt_s = 0;
	size_t cnt_n = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (line[i] == ' ')
			continue;
		else if (line[i] == '+' || line[i] == '/' || line[i] == '-' || line[i] == '*')
		{
			cnt_s++;
			continue;
		}
		else if (isdigit(line[i]) && (!isdigit(line[i - 1])) && (!isdigit(line[i + 1])))
		{
			cnt_n++;
			continue;
		}
		else
			return 1;
	}
	if (cnt_s != cnt_n - 1)
		return 1;
	return 0;
}


int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr<< "Error: you have to got 1 argument"<<std::endl;
		return 1;
	}
	std::string line = av[1];
	if (check_in(line) != 0)
		std::cerr<<"Error!"<<std::endl;
	else
	{
		RPN rpn;
		std::cout <<rpn.total_res(line)<<std::endl;
	}
	return 0;
}
