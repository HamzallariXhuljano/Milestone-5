/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:33:53 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/07 15:07:30 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include <iostream>
#include "Data.hpp"
#include <stdint.h>//per unitptr_t

class Serialization {
	private:
		Serialization();
		Serialization(const Serialization&);
		Serialization& operator=(const Serialization&);
	public:
		~Serialization();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
