/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/19 17:06:27 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.member1 = 1;
	data.member2 = 'a';

	std::cout << "Original pointer: \t" << &data << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&data);
	
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized pointer: \t" << deserialized << std::endl;
	return 0;
}
