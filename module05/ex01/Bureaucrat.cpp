/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:38:59 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/30 16:21:16 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("UnNamed")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name)
{
	this->operator= (obj);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		this->grade = obj.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()const
{
	return this->name;
}
int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName()<<", bureaucrat grade " << bureaucrat.getGrade()<<std::endl;
	return out;
}

void Bureaucrat::decrement(int n)
{
		if (this->grade + n > 150)
			throw GradeTooLowException();
		else
			this->grade += n;
}

void Bureaucrat::increment(int n)
{
	if (this->grade - n < 1)
			throw GradeTooHighException();
	else
		this->grade -= n;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(){}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grazie tommy is to high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Oh no tommy is to low";
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout<< this->name << " signed " << form.getName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<this->name<< " couldn’t sign " <<form.getName()<<" because "<<e.what() << std::endl;
	}
}
