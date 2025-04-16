/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:46:39 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 10:50:03 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "debug.hpp"

# include <algorithm>
# include <iostream>
# include <vector>
# include <ctime>
# include <cstdlib>
# include <exception>
# include <limits>

int randomNumber();

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
		
		unsigned int shortestSpan();
		unsigned int longestSpan();

		void addNumberList(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		std::vector<int> getSpan(){return span;}

};


