/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:45:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 15:22:22 by inowak--         ###   ########.fr       */
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

unsigned int Span::shortestSpan() {

	if (span.size() <= 1)
		throw std::out_of_range("Span is empty or with one number: cannot find the shortest span.");
	
	// --- // CHECK DUPLICATE // --- //

	for (unsigned int i = 0; i < span.size(); i++){
		if (std::count(span.begin(), span.end(), span[i]) > 1){
			if (help)
				std::cout << "Span min : " << span[i] << " is duplicate" << std::endl;
			return (0);
		}
	}

	// --- // MAIN ALGORITHM // --- //
	
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
	if (help)
		std::cout << "Span min :" << save1 << " and " << save2 << std::endl;
	return (diff);
}

unsigned int Span::longestSpan() {

	if (span.size() <= 1)
		throw std::out_of_range("Span is empty or with one number: cannot find the longest span.");
	
	// --- // LAST ALGORITHM // --- //
		
	// unsigned int diff = 0;
	// unsigned int actualDiff = 0;
	// int save1;
	// int save2;

	// for (unsigned int j = 0; j < span.size(); ++j){
	// 	for (unsigned int i = j + 1; i < span.size(); ++i){
			
	// 		if (span[j] < 0 && span[i] < 0){actualDiff = (span[j] * -1 > span[i] * -1 ? span[j] * -1 - span[i] * -1 : span[i] * -1 - span[j] * -1);}
			
	// 		else if (span[j] < 0 && span[i] >= 0){actualDiff = span[j] * -1 + span[i];}

	// 		else if (span[j] >= 0 && span[i] < 0){actualDiff = span[j] + span[i] * -1;}
			
	// 		else{actualDiff = (span[j] > span[i] ? span[j] - span[i] : span[i] - span[j]);}
			
	// 		if (actualDiff > diff){
	// 			save1 = span[j];
	// 			save2 = span[i];
	// 			diff = actualDiff;
	// 		}
	// 	}
	// }
	// return (diff);

	// --- // NEW ALGORITHM // --- //

	std::vector<int>::iterator min = std::min_element(this->span.begin(), this->span.end());
	std::vector<int>::iterator max = std::max_element(this->span.begin(), this->span.end());
	if (help)
		std::cout << "Span max :" << *max << " and " << *min << std::endl;
	return (*max - *min);
}

void Span::addNumberList(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->span.size() + std::distance(begin, end) > this->N)
		throw std::out_of_range("Span is full cannot add more numbers or size to huge for the container size.");
	this->span.insert(this->span.end(), begin, end);
} 