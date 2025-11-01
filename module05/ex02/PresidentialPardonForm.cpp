/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:58:55 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/01 19:10:22 by xhamzall         ###   ########.fr       */
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
	try
	{
		if(this->getSigned() == false)
			throw AForm::SignException();
		else if (executor.getGrade() >= 5)
			throw AForm::ExecuteException();
		else
		{
			std::cout << this->target <<"  has been pardoned by Zaphod Beeblebrox."<<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
