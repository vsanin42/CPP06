/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/20 18:53:41 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Non-Base object:" << std::endl;
	Base* obj = generate();
	identify(obj);
	identify(*obj);

	std::cout << std::endl;;

	std::cout << "Base object:" << std::endl;
	Base* obj2 = new Base();
	identify(obj2);
	identify(*obj2);
	delete obj;
	delete obj2;
	return 0;
}
