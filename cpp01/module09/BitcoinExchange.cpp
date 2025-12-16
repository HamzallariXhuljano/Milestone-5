/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:55:52 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/09 14:32:02 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitocoinExchange::BitocoinExchange() {}
BitocoinExchange::BitocoinExchange(const BitocoinExchange&) {}
BitocoinExchange& BitocoinExchange::operator=(const BitocoinExchange&) {}
BitocoinExchange::~BitocoinExchange() {}

bool BitocoinExchange::check_file(std::string nfile)
{
		size_t len = nfile.length();
	if (len <= 4)
	{
		std::cerr<<"Error: file name or format."<<std::endl;
		return false;
	}
	//(len-4) perche pos e il punto da cui parte la ricerca(cerca .txt come ultimi 4 caratteri)
	else if (nfile.find(".txt", len - 4) == nfile.npos)
	{
		std::cerr<<"Error: wrong format of the file."<<std::endl;
		return false;
	}
	std::fstream file(nfile.c_str());
	if (!file.is_open())
	{
		std::cerr<<"Error: couldn't open the file!"<<std::endl;
		return false;
	}
	std::cout<<"Yeah right file"<<std::endl;
	return true;
}
