/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:39:02 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/02 21:50:34 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat b("Thommy", 1);
	AForm *f;
	AForm *f1;
	AForm *f2;
	AForm *error;
	Intern random;
	std::cout<<"=========== Test no errors Shruberry sign Aform ========"<<std::endl;
	f = random.makeForm("Shrubbery Creation", "Test");
	b.signAform(*f);
	b.executeForm(*f);
	std::cout<<*f;

	std::cout<<"=========== Test no errors Robotomy sign Aform ========"<<std::endl;
	f1 = random.makeForm("Robotomy Request", "Test");
	b.signAform(*f1);
	b.executeForm(*f1);
	std::cout<<*f1;

	std::cout<<"=========== Test no errors Presidential sign Aform ========"<<std::endl;
	f2 = random.makeForm("Presidential Pardon", "Test");
	b.signAform(*f2);
	b.executeForm(*f2);
	std::cout<<*f2;

	try
	{
		b.decrement(149);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout<<"=========== Test errors Shruberry sign Aform ========"<<std::endl;
	b.signAform(*f);
	b.executeForm(*f);
	std::cout<<*f;

	std::cout<<"=========== Test errors Robotomy sign Aform ========"<<std::endl;
	b.signAform(*f1);
	b.executeForm(*f1);
	std::cout<<*f1;

	std::cout<<"=========== Test errors Presidential sign Aform ========"<<std::endl;
	b.signAform(*f2);
	b.executeForm(*f2);
	std::cout<<*f2;

	std::cout<<b;

	error = random.makeForm("Ciao", "test");
	delete f;
	delete f1;
	delete f2;
	delete error;

	return 0;
}
