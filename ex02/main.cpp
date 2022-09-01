/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:54:12 by mclam             #+#    #+#             */
/*   Updated: 2022/08/24 11:54:12 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate( void ) {
	int	r = std::rand() % 3;

	switch (r) {
		case 1:
			std::cout << "A";
			return new A();
		case 2:
			std::cout << "B";
			return new B();
		default:
			std::cout << "C";
			return new C();
	}
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
}

void	identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch(std::exception&) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
	}
	catch(std::exception&) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
	}
	catch(std::exception&) {}
}

int	main() {
	Base	*p;
	
	std::srand((unsigned int)time(NULL));
	
	std::cout << "The class was generated: ";
	p = generate();
	std::cout << std::endl;
	
	std::cout << "The class was identified by identify(Base *p) function: ";
	identify(p);
	std::cout << std::endl;

	std::cout << "The class was identified by identify(Base &p) function: ";
	identify(*p);
	std::cout << std::endl;

	delete p;
	return 0;
}
