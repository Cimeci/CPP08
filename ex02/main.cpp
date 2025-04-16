/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:00:56 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/16 13:44:49 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include "colors.hpp"
# include <list>

int main()
{
	std::cout << "---------------------------" << std::endl;
	std::cout << GREEN << "        MUTANTSTACK        " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << PURPLE << "         STD::LIST         " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);
	std::list<int>::iterator lit = lstack.begin();
	std::list<int>::iterator lite = lstack.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::stack<int> ls(mstack);

	std::cout << std::endl;
	std::cout << "+---------------------------------+" << std::endl;
	std::cout << "|" << RED << "            MORE TEST            " << RESET << "|" << std::endl;
	std::cout << "+---------------------------------+" << std::endl << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout << GREEN << "        MUTANTSTACK        " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	
	++cit;
	--cit;

	++rit;
	--rit;

	++crit;
	--crit;
	
	std::cout << BOLD << "const_iterator: " << RESET;
	while (cit != cite){std::cout << *cit << ", ";++cit;}
	std::cout << std::endl << std::endl;

	std::cout << BOLD << "reverse_iterator: " << RESET;
	while (rit != rite){std::cout << *rit << ", ";++rit;}
	std::cout << std::endl << std::endl;

	std::cout << BOLD << "const_reverse_iterator: " << RESET;
	while (crit != crite){std::cout << *crit << ", ";++crit;}
	std::cout << std::endl << std::endl;


	std::cout << "---------------------------" << std::endl;
	std::cout << PURPLE << "         STD::LIST         " << RESET << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	std::list<int>::const_iterator clit = lstack.begin();
	std::list<int>::const_iterator clite = lstack.end();
	
	std::list<int>::reverse_iterator rlit = lstack.rbegin();
	std::list<int>::reverse_iterator rlite = lstack.rend();

	std::list<int>::const_reverse_iterator crlit = lstack.rbegin();
	std::list<int>::const_reverse_iterator crlite = lstack.rend();
	
	++clit;
	--clit;

	++rlit;
	--rlit;

	++crlit;
	--crlit;
	
	std::cout << BOLD << "const_iterator: " << RESET;
	while (clit != clite){std::cout << *clit << ", ";++clit;}
	std::cout << std::endl << std::endl;
	
	std::cout << BOLD << "reverse_iterator: " << RESET;
	while (rlit != rlite){std::cout << *rlit << ", ";++rlit;}
	std::cout << std::endl << std::endl;

	std::cout << BOLD << "const_reverse_iterator: " << RESET;
	while (crlit != crlite){std::cout << *crlit << ", ";++crlit;}
	std::cout << std::endl << std::endl;

}