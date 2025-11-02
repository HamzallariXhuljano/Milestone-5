/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:29:27 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/02 22:03:32 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();
		AForm* makeForm(std::string nameForm, std::string targetForm);
};

AForm* makeShrubberyForm(std::string);
AForm* makeRobotomyForm(std::string);
AForm* makePresidentialForm(std::string);
#endif
