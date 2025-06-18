/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:51:12 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/18 17:53:36 by vsanin           ###   ########.fr       */
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

	if (lit[j] == '-')
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
		|| (dotFlag == 1 && (lit[0] == '.' || lit[i - 1] == '.'))
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

static void displayChar(const std::string& lit)
{
	std::cout << "Detected type: char\n" << std::endl;
	char c = lit[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;	
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void displayInt(const std::string& lit)
{
	std::cout << "Detected type: int\n" << std::endl;
	int i = std::atoi(lit.c_str());
	if (std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non-displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;	
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void displayFloat(const std::string& lit)
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

	if (lit == "nanf" || lit == "+inff" || lit == "-inff")
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non-displayable" << std::endl;
	
	std::cout << std::fixed << std::setprecision(1);

	if (lit == "nanf" || lit == "+inff" || lit == "-inff")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;	
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void displayDouble(const std::string& lit)
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
	
	if (lit == "nan" || lit == "+inf" || lit == "-inf")
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non-displayable" << std::endl;
	
	std::cout << std::fixed << std::setprecision(1);

	if (lit == "nan" || lit == "+inf" || lit == "-inf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;	
	std::cout << "double: " << d << std::endl;
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
