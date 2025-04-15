/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/15 15:48:53 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include "colors.hpp"

int help = 0;

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

	if (argc >= 2){
		std::string input = argv[1];
		if (input == "--help")
			help = 1;
	}

	std::cout << "---------------------------" << std::endl;
	std::cout << GREEN << "      CLASSIC TESTOR       " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	Span sp = Span(5);
	try{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		if (help){
			std::cout << "Container(" << UNDERLINE << "5" << RESET << "): ";
			std::cout << "6, 3, 17, 9, 11" << std::endl << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << GREEN << "     EMPTY SPAN TESTOR     " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	Span sp1 = Span(0);

	try{sp1.addNumber(42);}
	catch(std::out_of_range &e){std::cout << RED << e.what() << RESET << std::endl;}

	if (help){
		std::cout << "Container(" << UNDERLINE << "0" << RESET << "): " << std::endl;
	}

	std::cout << std::endl;

	std::cout << UNDERLINE << "shortestSpan:" << RESET << std::endl;
	try{
		unsigned int shortest = sp1.shortestSpan();
		std::cout << shortest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
	
	std::cout << std::endl;
	std::cout << "-------------" << std::endl << std::endl;

	std::cout << UNDERLINE << "longestSpan:" << RESET << std::endl;
	try{
		unsigned int longest = sp1.longestSpan();
		std::cout << longest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
	

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << GREEN << "      ITERATOR TESTOR      " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;
	
    Span sp2 = Span(5);
	
    std::vector<int> array;
    array.push_back(30);
    array.push_back(23);
    array.push_back(05);
    array.push_back(01);
    array.push_back(11);
	
    try
    { sp2.addNumberList(array.begin(), array.end()); }
    catch(std::out_of_range &e) { std::cout << e.what() << std::endl; }
	
	if (help){
		std::cout << "Container(" << UNDERLINE << "5" << RESET << "): ";
		std::cout << "30, 23, 05, 01, 11" << std::endl << std::endl;
	}

	std::cout << UNDERLINE << "shortestSpan:" << RESET << std::endl;
	try{
		unsigned int shortest = sp2.shortestSpan();
		std::cout << shortest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
	
	std::cout << std::endl;
	std::cout << "-------------" << std::endl << std::endl;

	std::cout << UNDERLINE << "longestSpan:" << RESET << std::endl;
	try{
		unsigned int longest = sp2.longestSpan();
		std::cout << longest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
    std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << GREEN << "       RANDOM TESTOR       " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	std::srand(std::time(0));

	unsigned int N = randomSize();
	
	Span span(N);
	
	unsigned int size = randomSize();
	
	std::cout << "Number of times to add number: " << UNDERLINE << size << RESET << std::endl;
	std::cout << std::endl;
	std::cout << "Container(" << UNDERLINE << N << RESET << "): ";
	
	int nb;
	for (unsigned int i = 0; i < size; i++){
		nb = randomNumber();
		if (help)
			std::cout << nb << ", ";
		try{span.addNumber(nb);}
		catch(std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET;break;}
	}
	
	std::cout << std::endl << std::endl;

	std::cout << UNDERLINE << "shortestSpan:" << RESET << std::endl;
	try{
		unsigned int shortest = span.shortestSpan();
		std::cout << shortest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
	
	std::cout << std::endl;
	std::cout << "-------------" << std::endl << std::endl;

	std::cout << UNDERLINE << "longestSpan:" << RESET << std::endl;
	try{
		unsigned int longest = span.longestSpan();
		std::cout << longest << std::endl;
	}
	catch (std::out_of_range &e){std::cout << RED << std::endl << e.what() << RESET << std::endl;}
	
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	
}
