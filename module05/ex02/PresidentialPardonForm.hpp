/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:50:10 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/01 18:59:39 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};

#endif
