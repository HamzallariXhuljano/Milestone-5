/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:34:05 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/07 14:53:28 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization() {}
Serialization::Serialization(const Serialization &obj)
{
	(void)obj;
}
Serialization& Serialization::operator=(const Serialization &obj)
{
	(void)obj;
	return *this;
}

Serialization::~Serialization(){}

uintptr_t Serialization::serialize(Data* ptr)
{
	uintptr_t pointer = reinterpret_cast <uintptr_t>(ptr);
	return pointer;
}

Data* Serialization::deserialize(uintptr_t raw)
{
	Data *data = reinterpret_cast <Data*>(raw);
	return data;
}
