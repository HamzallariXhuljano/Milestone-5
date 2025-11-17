/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:11:38 by xhamzall          #+#    #+#             */
/*   Updated: 2025/11/17 17:13:06 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack&);
		MutantStack& operator= (const MutantStack&);
		~MutantStack();
		typename std::stack<T>::container_type::iterator begin();
		typename std::stack<T>::container_type::iterator end();
		typename std::stack<T>::container_type::iterator begin() const;
		typename std::stack<T>::container_type::iterator end() const;

};
#include "MutantStack.tpp"
#endif
