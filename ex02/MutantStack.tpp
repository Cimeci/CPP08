/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:07:00 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 11:04:36 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "MutantStack.hpp"

// CANONICAL FORM //

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &cp) : std::stack<T>(cp){}


template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &op){
	if (this != &op)
		std::stack<T>::operator=(op);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(){}

// ITERATOR //

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(){return this->c.begin();}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(){return this->c.end();}

// CONST ITERATOR //

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const {return this->c.begin();}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const {return this->c.end();}

// REVERSE CONST ITERATOR //

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin(){return this->c.rbegin();}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend(){return this->c.rend();}

// REVERSE CONST ITERATOR //

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const {return this->c.rbegin();}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const {return this->c.rend();}