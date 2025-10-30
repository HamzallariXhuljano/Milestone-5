/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:49:14 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 16:44:54 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("Unemd"), grade_sign(150), grade_execute(150), is_signed(false) {}

AForm::AForm(std::string name, int grade_sign, int grade_execute, bool sign) : name(name), grade_sign(grade_sign), grade_execute(grade_execute), is_signed(sign){}

AForm::AForm(const AForm &obj) : name(obj.name), grade_sign(obj.grade_sign),  grade_execute(obj.grade_execute), is_signed(obj.is_signed)
{
	this->operator= (obj);
}

AForm& AForm::operator=(const AForm &obj)
{
	if (this != &obj)
		this->is_signed = obj.is_signed;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getSigned() const
{
	return this->is_signed;
}

int AForm::getGradeSign() const
{
	return this->grade_sign;
}
int AForm::getGradeExecute() const
{
	return this->grade_execute;
}

std::string AForm::printIsSigned(bool is_signed) const
{
	std::string s;
	if (is_signed == true)
		s =" The Aform has been signed";
	else
		s = " The Aform hasn't been signed";
	return s;
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << Aform.getName()<<", Aform get grade to sign: " << Aform.getGradeSign()<<" and get grade to execute: "<<Aform.getGradeExecute()<<"." << Aform.printIsSigned(Aform.getSigned())<<std::endl;
	return out;
}

AForm::GradeTooHighException::GradeTooHighException() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "This grade is too high";
}

AForm::GradeTooLowException::GradeTooLowException() {}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "This grade is too low";

}

void AForm::beSigned(Bureaucrat &bureaucrat)
{

	if (bureaucrat.getGrade() > this->grade_sign)
	{
		this->is_signed = false;
		throw GradeTooLowException();
	}
	else
		this->is_signed = true;
}
