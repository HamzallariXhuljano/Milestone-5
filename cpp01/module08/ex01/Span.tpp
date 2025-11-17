/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:55:19 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/15 18:01:10 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


template <typename T> void Span::addMultNum(T start, T end)
{
	size_t dist = std::distance(start, end);
	if (v.size() + dist > max_n)
		throw(SizeException());
	v.insert(v.end(), start, end);
}
