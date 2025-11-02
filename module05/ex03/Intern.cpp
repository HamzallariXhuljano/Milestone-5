/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:29:28 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/02 22:04:26 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &obj)
{
	(void)obj;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern(){}

AForm* makeShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* makeRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm* makePresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string nameForm, std::string targetForm)
{
	std::string fromsName[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	AForm* (*froms[3])(std::string t) = {
			makeShrubberyForm,
			makeRobotomyForm,
			makePresidentialForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (fromsName[i] == nameForm)
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return froms[i](targetForm);
		}
	}
	std::cout << "Intern: form name '" << nameForm << "' does not exist." << std::endl;
	return NULL;
}

