/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:58:38 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/12 19:25:20 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

template <typename T>
typename T::const_iterator easyfind(const T&, int);

class NotFindException : public std::exception
{
	public:
		const char* what() const throw();
};

#include "easyfind.tpp"
#endif
