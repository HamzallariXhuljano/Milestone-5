/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:56:02 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/23 17:25:26 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <time.h>

class BitcoinExchange
{
	private:
		std::map <time_t, float> btc;
		bool valid;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();
		bool check_file(std::string);
		int check_piepe(const std::string &line);
		int check_comma(const std::string &line);
		std::string take_date(const std::string &line, char c);
		std::string take_value(const std::string &line, char c);
		std::string str_trim(std::string &line);
		int check_date(std::string &date);
		int check_value(std::string &value);
		int validate_value(std::string &value, int flag);
		int validate_date(std::string &date);
		time_t stringToDate(std::string &date);
		int check_all_data(std::string &date, std::string &value, int flag);
		void print_err(int n_case, std::string line);
		void print_val_exc(time_t &date_value, std::string &date, std::string &value, float value_n);
		bool getValid();
};

#endif
