/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:11:38 by xhamzall          #+#    #+#             */
/*   Updated: 2025/12/17 17:53:52 by xhamzall         ###   ########.fr       */
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
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator r_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator r_const_iterator;


		MutantStack();
		MutantStack(const MutantStack&);
		MutantStack& operator= (const MutantStack&);
		~MutantStack();
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		r_iterator rbegin();
		r_iterator rend();
		r_const_iterator rbegin() const;
		r_const_iterator rend() const;
};
#include "MutantStack.tpp"
#endif

