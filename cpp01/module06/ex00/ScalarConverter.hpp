/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:24:57 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/03 19:14:07 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConvert
{
	private:
		ScalarConvert();
		ScalarConvert(const ScalarConvert&);
		ScalarConvert& operator=(const ScalarConvert&);
	public:
		~ScalarConvert();
		static void converter(std::string );
};

#endif
