/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:51:12 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 21:48:42 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) { (void)ref; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
    (void)ref;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& lit)
{
	int dotFlag = 0;
	int fFlag = 0;
	bool minusFlag = false;
	size_t i = 0;
	
	bool isChar = false;
	bool isInt = false;
	bool isFloat = false;
	bool isDouble = false;
	
	if (lit.size() == 1 && lit[0] <= '0' && lit[i] >= '9')
	if (lit[i] == '-')
	{
		minusFlag = true;
		i += 1;
	}
	// if len == 1 handle only char or int
	for (size_t i; i < lit.size(); i++)
	{
		if (lit[i] == '.')
			dotFlag += 1;
		if (lit[i] == 'f')
			fFlag += 1;	
	}
	if (dotFlag > 1 || fFlag > 1)
		std::cout << "Invalid input\n"; // ?
	if (dotFlag == 1 && lit[0] != '.' && lit[i - 1] != '.')
	{
		// float or double
		// exactly one 'f' as the last char, exactly one dot in the middle - float
		if (fFlag == 1 && lit[0] != 'f' && lit[i - 1] == 'f')
			isFloat = true;
		else //
			isDouble = true;
	}
	// at this point: bruhhhhh this is bad
}
