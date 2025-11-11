/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:21:35 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/11 16:17:46 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main ()
{
	size_t size = 3;
	int arr[size];

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	const std::string arr1[] = {"ciao", "come", "stai"};

	std::cout<<"***** test int no const array *****"<<std::endl;
	iter(arr, size, printElements);
	std::cout<<"***** test string const array *****"<<std::endl;
	iter(arr1, size, printElements);

}
