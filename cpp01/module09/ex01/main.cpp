/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:58:45 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/09 15:53:42 by xhamzall         ###   ########.fr       */
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
		if (isspace(line[i]))
			continue;
		if (line[i] == '+' || line[i] == '/' || line[i] == '-' || line[i] == '*')
			cnt_s++;
		else if (isdigit(line[i]))
		{
			if (i + 1 < len && isdigit(line[i + 1]))
				return 1;
			cnt_n++;
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
		std::cerr<<"Error"<<std::endl;
	else
	{
		RPN rpn;
		rpn.total_res(line);
	}
	return 0;
}
