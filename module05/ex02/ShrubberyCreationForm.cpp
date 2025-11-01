/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:08:36 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/01 19:02:21 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() :  AForm("Shrubbery", 145, 137, false), target("BOOO"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137, false)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
	this->operator= (obj);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned() == false)
			throw AForm::SignException();
		else if (executor.getGrade() >= this->getGradeExecute())
			throw AForm::ExecuteException();
		else
		{
			std::ofstream ofile(this->target + "_shrubbery.txt");
			if(!ofile)
				std::cerr << "File ERror!"<< std::endl;
			ofile << "       _-_"<<std::endl;
			ofile << "    /~~   ~~\\"<<std::endl;;
			ofile << " /~~         ~~\\"<<std::endl;;
			ofile << "{               }"<<std::endl;;
			ofile << " \\  _-     -_  /"<<std::endl;;
			ofile << "   ~  \\\\ //  ~"<<std::endl;;
			ofile << "_- -   | | _- _"<<std::endl;;
			ofile << "  _ -  | |   -_"<<std::endl;;
			ofile << "      // \\\\"<<std::endl;;
			ofile.close();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
