/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:56:02 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/09 14:20:17 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

class BitocoinExchange
{
	public:

		BitocoinExchange();
		BitocoinExchange(const BitocoinExchange&);
		BitocoinExchange& operator=(const BitocoinExchange&);
		~BitocoinExchange();
		bool check_file(std::string);
};

#endif
