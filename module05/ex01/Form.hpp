/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:49:16 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 16:41:19 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		const int grade_sign;
		const int grade_execute;
		bool is_signed;
	public:
		Form();
		Form(std::string, int, int, bool);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute()const;
		void beSigned(Bureaucrat&) ;
		std::string  printIsSigned(bool) const;

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
std::ostream &operator<<(std::ostream &out, const Form &fix);

#endif
