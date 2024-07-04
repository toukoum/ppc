/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:50:56 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/02 13:00:13 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"
#include <stack>
#include <vector>

int main()
{
	{
		std::cout << "-------- TEST 1 (My Stack) --------" << std::endl;
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
	}
	{
		std::cout << "---------- Test 2 (List) ----------" << std::endl;
		std::cout << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	{
		std::cout << "---------- Test 3 (String) ----------" << std::endl;
		MutantStack<std::string> mstack;

		mstack.push("Hello");
		mstack.push("World");
		mstack.push("!");

		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << std::endl;
		std::cout << "Does my stack empty ? " << std::endl;
		std::cout << mstack.empty() << std::endl;

		std::cout << "What is the size of my stack ? " << std::endl;
		std::cout << mstack.size() << std::endl;

		std::cout << "What is the top of my stack ? " << std::endl;
		std::cout << mstack.top() << std::endl;

		std::cout << "Pop the top of my stack" << std::endl;
		mstack.pop();

		
	}

	return (0);
}