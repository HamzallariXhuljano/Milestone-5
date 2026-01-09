/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:46:37 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/09 15:57:39 by xhamzall         ###   ########.fr       */
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

void RPN::total_res(std::string &line)
{
	size_t len = line.size();
	int res;

	if (line.empty())
	{
		std::cerr<<"Error"<<std::endl;
		return;
	}
	for (size_t i = 0; i < len; i++)
	{
		if (isspace(line[i]))
			continue;
		if (isdigit(line[i]))
			stack.push(line[i] - '0');
		else if (line[i] == '-' || line[i] == '+' || line[i] == '*' || line[i] == '/')
		{
			if (stack.size() < 2)
			{
				std::cerr<<"Error"<<std::endl;
				return;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (line[i] == '+')
				res = a + b;
			else if (line[i] == '-')
				res =a - b;
			else if (line[i] == '*')
				res =a * b;
			else if (line[i] == '/')
			{
				if (b == 0)
				{
					std::cerr<<"Error"<<std::endl;
					return;
				}
				else
					res = a / b;
			}
			stack.push(res);
		}
		else
		{
			std::cerr<<"Error"<<std::endl;
			return;
		}
	}
	if (stack.size() != 1)
	{
		std::cerr<<"Error"<<std::endl;
		return;
	}
	std::cout << stack.top() << std::endl;
}

