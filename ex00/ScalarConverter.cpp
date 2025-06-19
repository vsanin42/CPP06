/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:51:12 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/19 20:45:51 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarUtils.hpp"
#include <iostream>
#include <cctype>

static LitType detectType(const std::string& lit)
{
	int dotFlag = 0;
	int fFlag = 0;
	size_t i = 0;
	size_t j = 0;
	
	if (lit == "nanf" || lit == "+inff" || lit == "-inff")
		return FLOAT;
	if (lit == "nan" || lit == "+inf" || lit == "-inf")
		return DOUBLE;

	if (lit.size() == 1)
	{
		if (std::isdigit(lit[0]))
			return INT;
		if (std::isprint(lit[0]))
			return CHAR;
		return NONE;
	}

	if (lit[j] == '-' || lit[j] == '+')
		j += 1;

	for (i = j; i < lit.size(); i++)
	{
		if (!std::isdigit(lit[i]) && lit[i] != '.' && lit[i] != 'f')
			return NONE;
		if (lit[i] == '.')
			dotFlag += 1;
		if (lit[i] == 'f')
			fFlag += 1;
	}
	
	if ((dotFlag > 1 || fFlag > 1)
		|| (fFlag == 1 && lit[i - 1] != 'f'))
		return NONE;

	if (dotFlag == 1 && fFlag == 1)
		return FLOAT;
	if (dotFlag == 1 && fFlag == 0)
		return DOUBLE;
	if (dotFlag == 0 && fFlag == 0)
		return INT;
	return NONE;
}

void ScalarConverter::convert(const std::string& lit)
{
	LitType type = detectType(lit);

	switch (type)
	{
		case CHAR:
			displayChar(lit);
			break;
		case INT:
			displayInt(lit);
			break;
		case FLOAT:
			displayFloat(lit);
			break;
		case DOUBLE:
			displayDouble(lit);
			break;
		default:
			std::cout << "Invalid input" << std::endl;
	}
}
