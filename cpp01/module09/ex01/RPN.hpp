/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:46:35 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/08 20:04:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <fstream>
#include <time.h>

class RPN
{
	private:
		std::stack<int> stack;
		int operation(char, int, int);
	public:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		int total_res(std::string&);
		~RPN();
};

#endif
