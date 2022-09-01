/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:48:00 by mclam             #+#    #+#             */
/*   Updated: 2022/08/24 11:00:17 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

typedef struct	s_Data
{
	bool		isIt;
	std::string	str;
	double		doubleVar;
}				Data;

uintptr_t	serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data		data;
	uintptr_t	serialized;
	Data		*deserialized;

	data.isIt = true;
	data.str = "Zwei Boxkämpfer jagen Eva quer durch Sylt";
	data.doubleVar = std::numeric_limits<unsigned long>::max();
	serialized = serialize(&data);
	deserialized = deserialize(serialized);
	
	std::cout	<< "\ndata: " << std::boolalpha
				<< data.isIt << ", \""
				<< data.str << "\", "
				<< data.doubleVar << std::endl;

	std::cout << "\ndata: " << &data << std::endl;
	std::cout << "serialized: " << serialized << std::endl;
	std::cout << "deserialized: " << deserialized << std::endl;

	std::cout	<< "\ndeserialized: " << std::boolalpha
				<< data.isIt << ", \""
				<< data.str << "\", "
				<< deserialized->doubleVar << std::endl;

	std::cout << std::endl;
	
	return 0;
}
