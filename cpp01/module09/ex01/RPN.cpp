/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:46:37 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/08 17:29:28 by xhamzall         ###   ########.fr       */
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
