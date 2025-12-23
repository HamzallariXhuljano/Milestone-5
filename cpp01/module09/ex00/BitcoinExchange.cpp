/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:55:52 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/23 17:26:21 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::string line;
	this->valid = true;
	std::fstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr<<"Error: the database file must named date.csv and it has to got the right perissions!"<<std::endl;
		valid = false;
		return;
	}
	else
	{
		std::getline(file, line);
		if (line != "date,exchange_rate")
		{
			std::cerr<<"Error: first line isn't: date,exchange_rate"<<std::endl;
			this->valid = false;
			return;
		}
		while (std::getline(file, line))
		{
			if(BitcoinExchange::check_comma(line) != 0)
			{

				std::cerr<<"Erro: no comma in line."<<std::endl;
				continue;
			}
			std::string date = take_date(line, ',');;
			std::string price = take_value(line, ',');
			int n_cheks = check_all_data(date, price, 0);
			if (n_cheks != 0)
				print_err(n_cheks, line);
			else
			{
				time_t date_value = stringToDate(date);
				float price_value = atof(price.c_str());
				btc.insert(std::pair<time_t, float>(date_value, price_value));
			}
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	this->operator=(obj);
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		this->btc = obj.btc;
		this->valid = obj.valid;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::getValid()
{
	return this->valid;
}

bool BitcoinExchange::check_file(std::string nfile)
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
	return true;
}

int BitcoinExchange::check_piepe(const std::string &line)
{
	int cnt = 0;
	int flag = 0;
	size_t len = line.length();
	size_t p_pos = line.find("|");

	if ( p_pos == line.npos || line[0] == '|' || line[len - 1] == '|')
		return 1;
	if (line[p_pos - 1] != ' ' && line[p_pos + 1] != ' ')
		return 1;
	for (size_t i = 0; i < len; i++)
	{
		if (line[i] == '|')
			cnt++;
	}
	if (cnt != 1)
		return 1;
	for (size_t i = 0; i < p_pos; i++)
	{
		if (line[i] != ' ')
		{
			flag++;
			break;
		}
	}
	if (flag == 0)
		return 1;
	flag = 0;
	for (size_t i = len - 1; i > p_pos; i--)
	{
		if (line[i] != ' ')
		{
			flag++;
			break;
		}
	}
	if (flag == 0)
		return 1;
	return 0;
}

int BitcoinExchange::check_comma(const std::string &line)
{
	int cnt = 0;
	size_t len = line.length();
	size_t p_pos = line.find(",");

	if ( p_pos == line.npos || line[0] == ',' || line[len - 1] == ',')
		return 1;
	for (size_t i = 0; i < len; i++)
	{
		if (line[i] == ',')
			cnt++;
	}
	if (cnt != 1)
		return 1;
	return 0;
}

std::string BitcoinExchange::take_date(const std::string &line, char c)
{
	std::string	date;
	size_t p_pos = line.find(c);

	date = line.substr(0, p_pos);
	return date;
}

std::string BitcoinExchange::take_value(const std::string &line, char c)
{
	std::string	value;
	size_t p_pos = line.find(c);

	value = line.substr(p_pos + 1, line.size());
	return value;
}

std::string BitcoinExchange::str_trim(std::string &line)
{
	size_t i = 0;
	size_t j;

	while ( i < line.size() && line[i] == ' ' )
		i++;
	line.erase(0, i);
	if (line.empty())
		return line;
	j = line.size() - 1;
	while (line[j] == ' ')
		j--;
	line.erase(j + 1);
	return line;
}

int BitcoinExchange::check_date(std::string &date)
{
	date = str_trim(date);
	size_t len = date.length();
	if (date.empty())
		return 1;
	if (len != 10)
		return 1;
	for (size_t i = 0; i < len;  i++)
	{
		if (i == 0 && !(isdigit(date[i])))
			return 1;
		if (((i > 0 && i <= 3) || (i >= 5 && i <= 6) || (i >= 8 && i <= 9) ) && !(isdigit(date[i])))
			return 1;
		if ((i==4 || i== 7) && date[i] != '-')
			return 1;
	}
	return 0;
}

int BitcoinExchange::check_value(std::string &value)
{
	value = str_trim(value);
	size_t point_pos = value.find('.');
	size_t len = value.length();
	int cnt = 0;

	if (point_pos == value.npos)
	{
		for (size_t i = 0; i < len; i++)
		{
			if (value[i] == '-' )
				return 2;
			if (!isdigit(value[i]))
				return 1;
		}
	}
	else
	{
		for (size_t i = 0; i < len; i++)
		{
			if (value[i] == '.')
				cnt++;
			if (cnt > 1)
				return 1;
		}
		if (point_pos == 0 || point_pos == len - 1 || value[point_pos - 1] == ' ' || value[point_pos + 1 ] == ' ' )
			return 1;
		for (size_t i = 0; i < point_pos; i++)
		{
			if (!isdigit(value[i]))
				return 1;
		}
		for(size_t i = len - 1; i > point_pos; i--)
		{
			if (!isdigit(value[i]))
				return 1;
		}
	}
	return 0;
}

int BitcoinExchange::validate_value(std::string &value, int flag)
{
	if (flag != 0)
	{
		float n = atof(value.c_str());
		if (n < 0)
			return 2;
		else if (n > 1000)
			return 3;
	}
	return 0;
}
int BitcoinExchange::validate_date(std::string &date)
{
	int year = atoi((date.substr(0, 4)).c_str());
	int month = atoi((date.substr(5, 2)).c_str());
	int day = atoi((date.substr(8, 2)).c_str());
	int flag = 0;

	if (month == 2 && (year == 2012 || year == 2016 || year == 2020))
		flag = 1;
	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		return 4;
	else if (year > 2022 || (year == 2022 && (month > 3)) || (year == 2022 && month == 3 && day > 29))
		return 5;
	else if (!(month >= 1 && month <= 12))
		return 6;
	else if (!(day >= 1 && day <= 31))
		return 7;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && !(day >= 1 && day <= 30))
		return 7;
	else if (month == 2 && flag == 1 && !(day >= 1 && day <= 29))
		return 8;
	else if (month == 2 && flag == 0 && !(day >= 1 && day <= 28))
		return 7;
	return 0;
}
time_t BitcoinExchange::stringToDate(std::string &date)
{
	struct tm time_date;
	int year = atoi((date.substr(0, 4)).c_str());
	int month = atoi((date.substr(5, 2)).c_str());
	int day = atoi((date.substr(8, 2)).c_str());

	time_date.tm_year = year - 1900;
	time_date.tm_mon = month - 1;
	time_date.tm_mday = day;
	time_date.tm_hour = 0;
	time_date.tm_min = 0;
	time_date.tm_sec = 0;
	time_date.tm_isdst = -1;//serve per vedere se l ora legale e attiva 1->on, 0->off, -1 decide mktime dopo
	//mktime-> come time ma il numero rappresenta la data da noi inserita
	return(mktime(&time_date));
}
int BitcoinExchange::check_all_data(std::string &date, std::string &value, int flag)
{
	if (check_date(date) != 0)
		return (check_date(date));
	else if (check_value(value) != 0)
		return (check_value(value));
	else if (validate_date(date) != 0)
		return (validate_date(date));
	else if (validate_value(value, flag) != 0)
		return (validate_value(value, flag));
	return 0;
}

void BitcoinExchange::print_err(int n_case, std::string line)
{
	switch (n_case)
	{
		case 1:
			std::cerr<< "Error: bad input => "<< line << std::endl;
			break;
		case 2:
			std::cerr << "Error: not a positive number."<<std::endl;
			break;
		case 3:
			std::cerr << "Error: too large a number."<<std::endl;
			break;
		case 4:
			std::cerr << "Error: wrong year, btc wasn't crate. -->"<<line<<std::endl;
			break;
		case 5:
			std::cerr << "Error: wrong year, you cannot see in the future (check the DB)."<<std::endl;
			break;
		case 6:
			std::cerr << "Error: wrong date, the months goes from 1 to 12."<<std::endl;
			break;
		case 7:
			std::cerr << "Error: wrong date, check the month and the day."<<std::endl;
			break;
		case 8:
			std::cerr << "Error: wrong date, check the month and the day (isn't a leap year)."<<std::endl;
			break;
		default:
			break;
	}
}
void BitcoinExchange::print_val_exc(time_t &date_value, std::string &date, std::string &value, float value_n)
{
	//lower_bound restituisce un puntatore al primo valore piu alto di quello cercato
	std::map<time_t, float>::iterator it = btc.lower_bound(date_value);

	if (it != btc.end())
	{
		--it;
		std::cout<<date<<" => "<<value <<" = " << it->second * value_n<<std::endl;
	}

}
