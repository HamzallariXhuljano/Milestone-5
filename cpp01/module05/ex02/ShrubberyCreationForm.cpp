/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:08:36 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/02 17:09:11 by xhamzall         ###   ########.fr       */
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::SignException();
	else if (executor.getGrade() >= this->getGradeExecute())
		throw AForm::ExecuteException();
	else
	{
		std::ofstream ofile((this->target + "_shrubbery.txt").c_str());//c_str perche oftream prende const char
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
