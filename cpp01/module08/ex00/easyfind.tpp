/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:43:43 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/12 19:11:56 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NotFindException::what() const throw()
{
	return "occurrence not found";
}

template <typename T>
typename T::const_iterator easyfind(const T &conteiner, int i)
{
	typename T::const_iterator it;

	it = find(conteiner.begin(), conteiner.end(), i);
	if (it != conteiner.end())
	{
		std::cout<<"occurence found: "<< *it <<std::endl;//defferenza l iteratore e da cosi il valore
		return it;
	}
	throw NotFindException();
	return it;
}
