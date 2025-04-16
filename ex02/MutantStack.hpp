/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:07:02 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 11:04:53 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
	
		// CANONICAL FORM //

		MutantStack();
		MutantStack(const MutantStack &cp);
		MutantStack &operator=(const MutantStack &op);
		~MutantStack();

		// ITERATOR //

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		// CONST ITERATOR //

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;

		// REVERSE CONST ITERATOR //

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		// REVERSE CONST ITERATOR //

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"