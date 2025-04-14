/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:45:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/14 16:41:38 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

// -------- // CANONICAL FORM // -------- //

Span::Span() : N(0) {}

Span::Span(const Span &cp){*this = cp;}

Span &Span::operator=(const Span &op){
	if(this != &op)
	{
		N = op.N;
		span = op.span;
	}
	return (*this);
}

Span::~Span(){}

// -------- // ADDED FONCTION // -------- //

Span::Span(unsigned int N) : N(N) {}

void Span::addNumber(int value){
	if (span.size() >= N)
		throw std::out_of_range("Span is full: cannot add more numbers.");
	span.push_back(value);
}

unsigned int Span::shortestSpan()const {
	if (span.size() <= 1)
		throw std::out_of_range("Span is empty or with one number: cannot find the shortest span.");
	
	unsigned int diff = std::numeric_limits<unsigned int>::max();
	unsigned int actualDiff = 0;
	int save1;
	int save2;

	for (unsigned int j = 0; j < span.size(); ++j){
		for (unsigned int i = j + 1; i < span.size(); ++i){
			
			if (span[j] < 0 && span[i] < 0){actualDiff = (span[j] * -1 > span[i] * -1 ? span[j] * -1 - span[i] * -1 : span[i] * -1 - span[j] * -1);}
			
			else if (span[j] < 0 && span[i] >= 0){actualDiff = span[j] * -1 + span[i];}

			else if (span[j] >= 0 && span[i] < 0){actualDiff = span[j] + span[i] * -1;}
			
			else{actualDiff = (span[j] > span[i] ? span[j] - span[i] : span[i] - span[j]);}
			
			if (actualDiff < diff){
				save1 = span[j];
				save2 = span[i];
				diff = actualDiff;
			}
		}
	}
	std::cout << "Span min :" << save1 << " and " << save2 << std::endl;
	return (diff);
}

unsigned int Span::longestSpan() const {
	if (span.size() <= 1)
		throw std::out_of_range("Span is empty or with one number: cannot find the longest span.");
	
	unsigned int diff = 0;
	unsigned int actualDiff = 0;
	int save1;
	int save2;

	for (unsigned int j = 0; j < span.size(); ++j){
		for (unsigned int i = j + 1; i < span.size(); ++i){
			
			if (span[j] < 0 && span[i] < 0){actualDiff = (span[j] * -1 > span[i] * -1 ? span[j] * -1 - span[i] * -1 : span[i] * -1 - span[j] * -1);}
			
			else if (span[j] < 0 && span[i] >= 0){actualDiff = span[j] * -1 + span[i];}

			else if (span[j] >= 0 && span[i] < 0){actualDiff = span[j] + span[i] * -1;}
			
			else{actualDiff = (span[j] > span[i] ? span[j] - span[i] : span[i] - span[j]);}
			
			if (actualDiff > diff){
				save1 = span[j];
				save2 = span[i];
				diff = actualDiff;
			}
		}
	}
	std::cout << "Span max :" << save1 << " and " << save2 << std::endl;
	return (diff);
}