/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:53:20 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/04 15:03:31 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>//per srand() rand()
#include <ctime>//per cloc e CLOCKS_PER_SEC
#include <unistd.h>//sleep()
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
};

#endif
