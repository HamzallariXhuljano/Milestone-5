/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:21:53 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/14 20:18:09 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T> void printElements(const T &t)
{
	std::cout<<t<<std::endl;
}
template <typename T> void printElement(T &t)
{
	std::cout<<t<<std::endl;
}

template <typename T> void iter(T *arr, const size_t size, void (*f)(const T &t))
{
	for (size_t i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

#endif
