/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:39:01 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/01 16:51:11 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void decrement(int);
	void increment(int);
	void signAform(Form&);
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException();
			const char* what() const throw() ;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException();
			const char* what() const throw() ;
	};
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &fix);

#endif
