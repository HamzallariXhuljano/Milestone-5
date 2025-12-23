/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:18:33 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/23 17:26:50 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;

	std::string intput_line;
	std::string tmp;
	std::string date;
	std::string value;
	int n_check;

	if (ac != 2)
	{
		std::cerr << "Error: wrong numbers of argument."<<std::endl;
		return 1;
	}

	if (btc.getValid() == false)
		return 2;
	if (btc.check_file(av[1]) == false)
	{
		std::cerr <<"Name of file: " <<av[1] << std::endl;
		return 2;
	}
	std::fstream file(av[1]);
	if (file.is_open())
	{
		if (!(std::getline(file, intput_line)))
		{
			std::cerr<<"Error: empty input file!"<<std::endl;
			return 3;
		}
		else if (intput_line != "date | value")
		{
			std::cerr<<"Error: first line it must be date | value !"<<std::endl;
			return 4;
		}
		while (std::getline(file, intput_line))
		{
			tmp = intput_line;
			if (btc.check_piepe(tmp) != 0)
			{
				std::cerr<< "Bad input => "<< intput_line << std::endl;
				continue;
			}
			date = btc.take_date(intput_line, '|');
			value = btc.take_value(intput_line, '|');
			n_check = btc.check_all_data(date, value, 1);
			if (n_check != 0)
				btc.print_err(n_check, intput_line);
			else
			{
				time_t date_val = btc.stringToDate(date);
				float value_n = atof(value.c_str());

				btc.print_val_exc(date_val, date, value, value_n);
			}
		}
	}
	else
	{
		std::cerr<<"Error: could not open the file."<<std::endl;
		return 5;
	}
	return 0;
}
