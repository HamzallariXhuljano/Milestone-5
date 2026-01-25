/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:24:59 by xhamzall          #+#    #+#             */
/*   Updated: 2026/01/23 18:57:10 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConvert::ScalarConvert(){}

ScalarConvert::ScalarConvert(const ScalarConvert &obj)
{
	(void)obj;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert &obj)
{
	(void)obj;
	return *this;
}

ScalarConvert::~ScalarConvert(){}

bool ScalarConvert::isChar(std::string str)
{

	std::stringstream ss(str);

		if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
			return true;
	return false;
}

void ScalarConvert::convertChar(std::string s)
{
	int i = static_cast<int>(s[0]);
	float f = static_cast<float>(s[0]);
	double d = static_cast<double>(s[0]);

	if ((s[0] >= 32 && s[0] <= 126))
		std::cout<<"char: "<<s[0]<<std::endl;
	else
		std::cout<<"char: Non displayable"<<std::endl;
	std::cout<<"int: "<<i<<std::endl;
	std::cout<<std::fixed<<std::setprecision(1);
	std::cout<<"float: "<<f<<"f"<<std::endl;
	std::cout<<"double: "<<d<<std::endl;
}


bool ScalarConvert::checkIsInt(std::string s)
{
	int num = atoi(s.c_str());
	int flag = 0;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (i == 0 && !((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' || s[i] =='+')))
			flag++;
		else if (i > 0 && !(s[i] >= '0' && s[i] <= '9'))
			flag++;
	}
	if (num < -2147483648 || num > 2147483647)
		return false;
	else if (flag != 0)
		return false;
	else
		return true;
	return false;
}

void ScalarConvert::convertInt(std::string s)
{
	long i = atol(s.c_str());
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	char c = static_cast<char>(i);

	if (i >= 0 && i <= 255)
	{
		if ((i >= 32 && i <= 126))
			std::cout<<"char: "<<c<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;

	}
	else
		std::cout<<"Char: impossible"<<std::endl;
	if (i < -2147483648 || i > 2147483647)
	{
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1);
		std::cout<<"float: "<<f<<"f"<<std::endl;
		std::cout<<"double: "<<d<<std::endl;
	}
	else
	{
		std::cout<<"int: "<<i<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1);
		std::cout<<"float: "<<f<<"f"<<std::endl;
		std::cout<<"double: "<<d<<std::endl;
	}
}

bool ScalarConvert::checkIsFloat(std::string s)
{
	int dotFlag = 0;
	int effeFlag = 0;
	float num = atof(s.c_str());
	size_t len = s.length();


	if (num < -FLT_MAX || num > FLT_MAX)
		return false;
	for (size_t i = 0; i < len; i++)
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == 'f' ||
			  ((i == 0) && (s[i] == '-' || s[i] == '+'))))
			return false;
	}
	for (size_t i = 0; i < len; i++)
	{
		if (i == 0 && s[i] == '.' && i + 1 < len && (s[i + 1] >= '0' && s[i + 1] <= '9'))
			dotFlag++;
		else if (i == 0 && (s[i] == '-' || s[i] == '+') &&
				 i + 2 < len && s[i + 1] == '.' && (s[i + 2] >= '0' && s[i + 2] <= '9'))
			dotFlag++;
		else if (i > 0 && i + 1 < len && s[i] == '.' &&
				 (s[i - 1] >= '0' && s[i - 1] <= '9') &&
				 (s[i + 1] >= '0' && s[i + 1] <= '9'))
			dotFlag++;
		if (i == len - 1 && s[i] == 'f' && i > 0 &&
			(s[i - 1] >= '0' && s[i - 1] <= '9'))
			effeFlag++;
	}
	if (dotFlag == 1 && effeFlag == 1)
		return true;
	return false;
}

void ScalarConvert::convertFloat(std::string s)
{
	double d = strtod(s.c_str(), NULL);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	char c = static_cast<char>(d);

	if (f >= 0 && f <= 255)
	{
		if ((f >= 32 && f <= 126))
			std::cout<<"char1: "<<c<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
	}
	else
		std::cout<<"Char: impossible"<<std::endl;
	if (d < -2147483648.0f || d > 2147483647.0f)
	{
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1);
		std::cout<<"float: "<<f<<"f"<<std::endl;
		std::cout<<"double: "<<d<<std::endl;
	}
	else
	{

		std::cout<<"int: "<<i<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1);
		std::cout<<"float: "<<f<<"f"<<std::endl;
		std::cout<<"double: "<<d<<std::endl;
	}
}
bool ScalarConvert::checkIsDouble(std::string s)
{
	int dotFlag = 0;
	char *end;
	double d = strtod(s.c_str(), &end);

	size_t len = s.length();
	if (d < -DBL_MAX || d > DBL_MAX)
		return false;
	for (size_t i = 0; i < len; i++)
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || ((i == 0) && (s[i] == '-' || s[i] == '+'))))
			 return false;
	}
	for (size_t i = 0; i < len; i++)
	{
		if (s[i] == '.')
		{
			if (i == 0 && ((s[i + 1] >= '0' && s[i + 1] <= '9')))
				dotFlag++;
			else if (i == 1 && (s[i-1] == '-' || s[i - 1]) && (s[i + 1] >= '0' && s[i + 1] <= '9'))
				dotFlag++;
			else if ((s[i + 1] >= '0' && s[i + 1] <= '9') && (s[i - 1] >= '0' && s[i - 1] <= '9'))
				dotFlag++;
		}
	}
	if (dotFlag == 1)
		return true;
	return false;
}

void ScalarConvert::convertDouble(std::string s)
{
	double d = strtod(s.c_str(), NULL);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	char c = static_cast<char>(d);

	if (d >= 0 && d <= 255)
	{
		if ((s[0] >= 32 && s[0] <= 126) && !(s[0] >= 48 && s[0] <= 57))
			std::cout<<"char: "<<c<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
	}
	else
		std::cout<<"Char: impossible"<<std::endl;
	if (d < -2147483648.0f || d > 2147483647.0f)
	{
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1);
		std::cout<<"float: "<<f<<"f"<<std::endl;
		std::cout<<"double: "<<d<<std::endl;
	}
	else
	{

		std::cout<<"int: "<<i<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1);
		std::cout<<"float: "<<f<<"f"<<std::endl;
		std::cout<<"double: "<<d<<std::endl;
	}
}

void ScalarConvert::converter(std::string s)
{
	if (!s.compare("-inf"))
	{
		std::cout<<"char: impossible "<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: -inf"<<"f"<<std::endl;
		std::cout<<"double: -inf"<<std::endl;
	}
	else if (!s.compare("+inf"))
	{
		std::cout<<"char: impossible "<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: +inf"<<"f"<<std::endl;
		std::cout<<"double: +inf"<<std::endl;
	}
	else if (!s.compare("nan"))
	{
		std::cout<<"char: impossible "<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: nan"<<"f"<<std::endl;
		std::cout<<"double: nan"<<std::endl;

	}
	else if (isChar(s))
		convertChar(s);
	else if (checkIsInt(s))
		convertInt(s);
	else if (checkIsFloat(s))
	{
		std::cout<<"is float"<<std::endl;

		convertFloat(s);
	}
	else if (checkIsDouble(s))
	{
		std::cout<<"is double"<<std::endl;
		convertDouble(s);
	}
	else
		std::cerr << "The input string isn't valid."<<std::endl;
}



