/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:21:45 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/19 19:17:45 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base* generate(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	std::srand(tv.tv_usec);
	int rng = std::rand() % 3;
	switch (rng)
	{
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
	}
	return NULL;
}

void identify(Base* p)
{
	A* ptrA = dynamic_cast<A*>(p);
	B* ptrB = dynamic_cast<B*>(p);
	C* ptrC = dynamic_cast<C*>(p);
	
	if (ptrA)
		std::cout << "ID by pointer:\t\ttype A" << std::endl;
	if (ptrB)
		std::cout << "ID by pointer:\t\ttype B" << std::endl;
	if (ptrC)
		std::cout << "ID by pointer:\t\ttype C" << std::endl;
}

void identify(Base& p)
{
	try {
		A& refA = dynamic_cast<A&>(p);
		std::cout << "ID by reference:\ttype A" << std::endl;
		(void)refA;
		return ;
	} catch (const std::exception& e) {
		std::cout << "ID by reference:\tNOT  A (" << e.what() << ")" << std::endl;
	}

	try {
		B& refB = dynamic_cast<B&>(p);
		std::cout << "ID by reference:\ttype B" << std::endl;
		(void)refB;
		return ;
	} catch (const std::exception& e) {
		std::cout << "ID by reference:\tNOT  B (" << e.what() << ")" << std::endl;
	}

	try {
		C& refC = dynamic_cast<C&>(p);
		std::cout << "ID by reference:\ttype C" << std::endl;
		(void)refC;
		return ;
	} catch (const std::exception& e) {
		std::cout << "ID by reference:\tNOT  C (" << e.what() << ")" << std::endl;
	}
}
