/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:49:16 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 18:20:42 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAform_HPP
#define AAform_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const int grade_sign;
		const int grade_execute;
		bool is_signed;
	public:
		AForm();
		AForm(std::string, int, int, bool);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual~AForm();
		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute()const;
		void beSigned(Bureaucrat&) ;
		std::string  printIsSigned(bool) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

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

		class SignException : public std::exception
		{
			public://se non mett il costruttore lo mette in default exception
				const char* what() const throw() ;
		};

		class ExecuteException : public std::exception
		{
			public:
				const char* what() const throw() ;
		};
};
std::ostream &operator<<(std::ostream &out, const AForm &fix);

#endif
