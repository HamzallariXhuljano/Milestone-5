/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:48:36 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/07 15:23:18 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data data ;
	data.c = 'c';
	data.i = 1273;
	data.f = 127.3f;
	data.d = 127.3;
	uintptr_t ptr;

	ptr = Serialization::serialize(&data);
	std::cout << "Data after serialize: " << &data<< std::endl;

	Data *res = Serialization::deserialize(ptr);
	std::cout << "Data after deserialize: " << res<< std::endl;

	return 0;
}
