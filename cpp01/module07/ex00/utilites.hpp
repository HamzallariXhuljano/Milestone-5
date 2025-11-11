/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:48:53 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/11 15:18:44 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITES_HPP
#define UTILITES_HPP

#include <iostream>

template <typename T> void swap(T &first, T &second)
{
	T tmp;
	tmp = first;
	first = second;
	second = tmp;
}

template <typename T> T min(T first, T second)
{
	if (first > second)
		return second;
	else if (first < second)
		return first;
	return second;
}

template <typename T> T max(T first, T second)
{
if (first > second)
		return first;
	else if (first < second)
		return second;
	return second;

}

#endif
