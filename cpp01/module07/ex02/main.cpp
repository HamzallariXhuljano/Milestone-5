/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:40:32 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/11 18:58:56 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		std::cout << "========Costruttore default========" << std::endl;
		Array<int> arr1;
		std::cout << "arr1 size: " << arr1.size() << std::endl;

		std::cout << "========Costruttore con dimensione========" << std::endl;

		Array<int> arr2(5);
		std::cout << "arr2 size: " << arr2.size() << std::endl;

		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = i * 10;

		std::cout << "arr2 contents: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;

		std::cout << "========Costruttore di copia========= "<<std::endl;
		Array<int> arr3 = arr2;
		std::cout << "arr3 (copied from arr2): ";
		for (unsigned int i = 0; i < arr3.size(); i++)
			std::cout << arr3[i] << " ";
		std::cout << std::endl;

		std::cout << "========Operatore di assegnamento========= "<<std::endl;
		Array<int> arr4;
		arr4 = arr2;
		std::cout << "arr4 (assigned from arr2): ";
		for (unsigned int i = 0; i < arr4.size(); i++)
			std::cout << arr4[i] << " ";
		std::cout << std::endl;

		std::cout << "========Test dell'eccezione========= "<<std::endl;
		std::cout << "Accessing out-of-bounds index..." << std::endl;
		std::cout << arr2[10] << std::endl;

	}
	catch (const Array<int>::SizeException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
