/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:55:43 by mclam             #+#    #+#             */
/*   Updated: 2022/08/23 11:14:53 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 0;
	}
	Conversion	conversion;
	
	conversion.typeDetector(av[1]);
	conversion.convertor();
	std::cout << conversion;
	return 0;
}
