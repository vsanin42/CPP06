/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:06:04 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/19 13:32:55 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarUtils.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cerrno>

static int getPrecision(const std::string& lit)
{
	size_t i = 0;
	int count = 0;
	
	while (lit[i] != '.')
		i++;
	i++;
	while (i < lit.size() && lit[i] != 'f')
	{
		count++;
		i++;	
	}
	if (count == 0)
		count += 1;
	return count;
}

static void formatInt(const std::string& lit, double num)
{
	if (lit == "nanf" || lit == "+inff" || lit == "-inff"
		|| lit == "nan" || lit == "+inf" || lit == "-inf")
		std::cout << "int: impossible" << std::endl;
	else if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
}

static void formatChar(double num)
{
	if (num >= 32 && num <= 126)
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else if ((num >= 0 && num <= 31) || num == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void displayChar(const std::string& lit)
{
	std::cout << "Detected type: char\n" << std::endl;
	char c = lit[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;	
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void displayInt(const std::string& lit)
{
	std::cout << "Detected type: int\n" << std::endl;

	char *end;
	errno = 0;
	long long testI = std::strtoll(lit.c_str(), &end, 10);
	if (testI > std::numeric_limits<int>::max() || testI < std::numeric_limits<int>::min() || errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: n/a" << std::endl;
		std::cout << "double: n/a" << std::endl;
	}
	else
	{
		int i = std::atoi(lit.c_str());
		formatChar(static_cast<double>(i));

		std::cout << std::fixed << std::setprecision(1);
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;	
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}
}

void displayFloat(const std::string& lit)
{
	std::cout << "Detected type: float\n" << std::endl;

	float f;

	if (lit == "nanf")
		f = std::numeric_limits<double>::quiet_NaN();
	else if (lit == "+inff")
		f = static_cast<float>(std::numeric_limits<double>::infinity());
	else if (lit == "-inff")
		f = static_cast<float>(-(std::numeric_limits<double>::infinity()));
	else
		f = static_cast<float>(std::atof(lit.c_str()));

	formatChar(static_cast<double>(f));
	formatInt(lit, static_cast<double>(f));
	
	int precision = getPrecision(lit);
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void displayDouble(const std::string& lit)
{
	std::cout << "Detected type: double\n" << std::endl;

	double d;

	if (lit == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (lit == "+inf")
		d = std::numeric_limits<double>::infinity();
	else if (lit == "-inf")
		d = -(std::numeric_limits<double>::infinity());
	else
		d = static_cast<double>(std::atof(lit.c_str()));

	formatChar(d);
	formatInt(lit, d);

	int precision = getPrecision(lit);
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;	
	std::cout << "double: " << d << std::endl;
}
