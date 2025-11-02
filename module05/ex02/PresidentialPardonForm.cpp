/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:58:55 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/02 17:08:30 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, false), target("BOOO"){};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5, false)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
	this->operator= (obj);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	if(this->getSigned() == false)
		throw AForm::SignException();
	else if (executor.getGrade() >= this->getGradeExecute())
		throw AForm::ExecuteException();
	else
	{
		std::cout << this->target <<"  has been pardoned by Zaphod Beeblebrox."<<std::endl;
	}
}
