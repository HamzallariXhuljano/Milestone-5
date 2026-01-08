/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:46:37 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/08 20:12:21 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	
}

RPN::RPN(const RPN &obj)
{
	this->operator= (obj);
}

RPN& RPN::operator=(const RPN &obj)
{
	if (this != &obj)
		this->stack = obj.stack;
	return *this;
}

RPN::~RPN(){}

int RPN::total_res(std::string &line)
{
	size_t len = line.size();
	int res;

	if (len < 2)
		return -1;
	for (size_t i = 0; i < len; i++)
	{
		if (std::isspace(line[i]))
			continue;
		if (isdigit(line[i]))
			stack.push(atoi(&line[i]));
		else if (line[i] == '-' || line[i] == '+' || line[i] == '*' || line[i] == '/')
		{
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			res = operation(line[i], a, b);
			if (res == -1)
				return -1;
			stack.push(res);
		}
	}
	return res;
}


int RPN::operation(char c, int a, int b)
{
	if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '*')
		return (a * b);
	else if (c == '/')
	{
		if (b == 0)
			return -1;
		else
			return (a / b);
	}
	return -1;
}
