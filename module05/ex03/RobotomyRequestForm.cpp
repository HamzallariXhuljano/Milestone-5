/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:12:07 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/02 17:08:54 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45, false), target("BOOO") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45, false)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
	this->operator= (obj);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
		this->target = obj.target;
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void ft_sleep(unsigned int milliseconds)
{
	clock_t start = clock();
	clock_t wait_ticks = (milliseconds * CLOCKS_PER_SEC) / 1000;
	while (clock() - start < wait_ticks)
	{

	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::SignException();
	else if (executor.getGrade() >= this->getGradeExecute())
		throw AForm::ExecuteException();
	else
	{
		for(int i = 0; i < 5; i++)
		{
			ft_sleep(2);
			std::cout<<"[BEEP]\a"<<std::endl;
		}
			srand(time(0));//si mette questo per assicurare un numero randomico ogni volta
		int num = rand();
		if (num % 2 == 0)
			std::cout << this->target << " has been robotomized successfully 50% of the time."<<std::endl;
		else
			std::cout << this->target << " the robotomy failed."<<std::endl;
	}
}

