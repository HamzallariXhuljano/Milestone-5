/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:24:57 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/05 19:26:32 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>// per stampare dopo la virgola std::fixed
#include <cfloat>// per max e min float

class ScalarConvert
{
	private:
		ScalarConvert();
		ScalarConvert(const ScalarConvert&);
		ScalarConvert& operator=(const ScalarConvert&);
	public:
		~ScalarConvert();
		static void converter(std::string );

		static bool isChar(std::string);
		static void convertChar(std::string);

		static bool checkIsInt(std::string);
		static void convertInt(std::string);

		static bool checkIsFloat(std::string);
		static void convertFloat(std::string);

		static bool checkIsDouble(std::string s);
		static void convertDouble(std::string);
		int checkInput(std::string);
};

#endif
