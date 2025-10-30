/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:49:14 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 16:44:54 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
Form::Form() : name("Unemd"), grade_sign(150), grade_execute(150), is_signed(false) {}

Form::Form(std::string name, int grade_sign, int grade_execute, bool sign) : name(name), grade_sign(grade_sign), grade_execute(grade_execute), is_signed(sign){}

Form::Form(const Form &obj) : name(obj.name), grade_sign(obj.grade_sign),  grade_execute(obj.grade_execute), is_signed(obj.is_signed)
{
	this->operator= (obj);
}

Form& Form::operator=(const Form &obj)
{
	if (this != &obj)
		this->is_signed = obj.is_signed;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getSigned() const
{
	return this->is_signed;
}

int Form::getGradeSign() const
{
	return this->grade_sign;
}
int Form::getGradeExecute() const
{
	return this->grade_execute;
}

std::string Form::printIsSigned(bool is_signed) const
{
	std::string s;
	if (is_signed == true)
		s =" The form has been signed";
	else
		s = " The form hasn't been signed";
	return s;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName()<<", form get grade to sign: " << form.getGradeSign()<<" and get grade to execute: "<<form.getGradeExecute()<<"." << form.printIsSigned(form.getSigned())<<std::endl;
	return out;
}

Form::GradeTooHighException::GradeTooHighException() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return "This grade is too high";
}

Form::GradeTooLowException::GradeTooLowException() {}

const char* Form::GradeTooLowException::what() const throw()
{
	return "This grade is too low";

}

void Form::beSigned(Bureaucrat &bureaucrat)
{

	if (bureaucrat.getGrade() > this->grade_sign)
	{
		this->is_signed = false;
		throw GradeTooLowException();
	}
	else
		this->is_signed = true;
}
