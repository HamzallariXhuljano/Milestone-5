/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:58:07 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/12 19:11:22 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	try
	{
		easyfind(v, 2);
		easyfind(v, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
