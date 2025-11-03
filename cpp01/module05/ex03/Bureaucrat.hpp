/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:39:01 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/01 20:25:35 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

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
		void signAform(AForm&);
		void executeForm(AForm const & form) const;

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

	class ExecuteFromException : public std::exception
	{
		public:
			const char* what() const throw() ;
	};
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &fix);

#endif
