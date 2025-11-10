/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:08:51 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/07 15:07:58 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include "Serialization.hpp"

struct Data
{
	char c;
	int i;
	float f;
	double d;
	std::string s;
};

#endif
