/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/14 09:36:54 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include "colors.hpp"

int randomNumber(){
	int nb = std::rand() % 100;
	if (!(std::rand() % 2))
		nb *= -1;
	return nb;
}

int main() {

	std::srand(std::time(0));

	std::vector<int> v;

	int size = randomNumber();
	if (size < 0)
		size *= -1;

	for(int i = 0; i <= size; i++){
		v.push_back(randomNumber());
	}

	int nb = randomNumber();

	std::cout << "---------------------------" << std::endl;
	std::cout << PURPLE << "       RANDOM TESTOR       " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;
	
	std::cout << "Container: ";
	for (unsigned int i = 0; i < v.size() - 1; i++){
		std::cout << v[i] << ", ";
	}
	std::cout << v[v.size() - 1] << std::endl;

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	std::cout << "Number to search: " << nb << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	std::vector<int>::iterator it;
	
	it = easyfind(v, nb);

	std::cout << "Result: ";

	if (it != v.end()){
		std::cout << nb << GREEN <<" find in the container" << RESET << std::endl;
	}
	else
		std::cout << nb << RED <<" not found in the container" << RESET << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	
}

