/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:46:39 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/14 11:44:24 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <algorithm>
# include <iostream>
# include <vector>
# include <ctime>
# include <cstdlib>
# include <exception>
# include <limits>

class Span{
	private:
		unsigned int N;
		std::vector<int> span;
	
	public:
		Span();
		Span(const Span &cp);
		Span &operator=(const Span &op);
		~Span();
		
		Span(unsigned int N);
		
		void addNumber(int value);
		
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

};
