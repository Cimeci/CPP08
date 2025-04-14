/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/14 17:07:15 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include "colors.hpp"

int randomNumber(){
	int nb = std::rand() % 10000;
	if (!(std::rand() % 2))
		nb *= -1;
	return nb;
}

unsigned int randomSize(){
	unsigned int nb = std::rand() % 10000;
	return nb;
}

int main(int argc, char **argv) {

	std::cout << "---------------------------" << std::endl;
	std::cout << PURPLE << "      CLASSIC TESTOR       " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	Span sp = Span(5);
	try{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}


	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << PURPLE << "       RANDOM TESTOR       " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;
	
	int help = 0;
	if (argc >= 2){
		std::string input = argv[1];
		if (input == "--help")
			help = 1;
	}

	std::srand(std::time(0));

	unsigned int N = randomSize();
	
	Span span(N);
	
	unsigned int size = randomSize();
	
	std::cout << "Number of times to add number: " << size << std::endl;
	std::cout << "Container(" << N << "): ";
	
	int nb;
	for (unsigned int i = 0; i < size; i++){
		nb = randomNumber();
		if (help)
			std::cout << nb << ", ";
		try{span.addNumber(nb);}
		catch(std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;break;}
	}

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::cout << GREEN << "          RESULT:          " << RESET << std::endl;

	std::cout << "---------------------------" << std::endl << std::endl;

	std::cout << UNDERLINE << "shortestSpan:" << RESET << std::endl;
	try{
		unsigned int shortest = span.shortestSpan();
		std::cout << shortest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
	
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	std::cout << UNDERLINE << "longestSpan:" << RESET << std::endl;
	try{
		unsigned int longest = span.longestSpan();
		std::cout << longest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
	
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	
}

