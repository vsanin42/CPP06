/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:51:05 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/19 12:15:09 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum LitType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OVERFLOW,
	NONE
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& ref);
        ScalarConverter &operator=(const ScalarConverter &ref);
        ~ScalarConverter();
	public:
		static void convert(const std::string& literal);
};

#endif

