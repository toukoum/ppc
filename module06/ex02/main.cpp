/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:04:08 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/30 14:07:47 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
class Base
{
public:
	virtual ~Base() {}
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

Base *generate(void)
{

	int randomValue = std::rand() % 3;
	switch (randomValue)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		return NULL;
		break;
	}
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << "p point to a A class (" << p << ")" << std::endl;
		return;
	}
	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << "p point to a B class (" << p << ")" << std::endl;
		return;
	}
	std::cout << "p point to a C class (" << p << ")" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "p refer to a A class (" << &a << ")" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "p refer to a B class (" << &b << ")" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "p refer to a C class (" << &c << ")" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
}

int main(void)
{
	std::srand(std::time(0));

	Base *a = generate();
	Base *b = generate();
	Base *c = generate();
	Base *d = generate();

	std::cout << "\n==========================\n\n";
	std::cout << "a* = ";
	identify(a);
	std::cout << "a& = ";
	identify(*a);
	std::cout << std::endl;

	std::cout << "\n==========================\n\n";
	
	std::cout << "b* = ";
	identify(b);
	std::cout << "b& = ";
	identify(*b);
	std::cout << std::endl;

	std::cout << "\n==========================\n\n";

	std::cout << "c* = ";
	identify(c);
	std::cout << "c& = ";
	identify(*c);
	std::cout << std::endl;

	std::cout << "\n==========================\n\n";

	std::cout << "d* = ";
	identify(d);
	std::cout << "d& = ";
	identify(*d);
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	delete d;

	return (0);
}