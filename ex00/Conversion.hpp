/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:50:14 by mclam             #+#    #+#             */
/*   Updated: 2022/08/23 11:15:01 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <iomanip>


class Conversion
{
private:
	std::string _floatCase[4];
	std::string	_doubleCase[4];
	std::string	_type;
	char		_char;
	long		_int;
	float		_float;
	double		_double;
	bool		_charPossibility;
	bool		_intPossibility;
	bool		_floatPossibility;
	bool		_doublePossibility;
	bool		_isChar(char *literal, size_t len);
	bool		_isInt(char *literal, size_t len);
	bool		_isFloat(char *literal, size_t len);
	bool		_isDouble(char *literal, size_t len);
public:
				Conversion( void );
				Conversion( const Conversion &conversion );
	Conversion	&operator=( const Conversion &conversion );
				~Conversion (void);
	std::string	getType( void ) const;
	char		getChar( void ) const;
	long		getInt( void ) const;
	float		getFloat( void ) const;
	double		getDouble( void ) const;
	bool		getCharPossibility( void ) const;
	bool		getIntPossibility( void ) const;
	bool		getFloatPossibility( void ) const;
	bool		getDoublePossibility( void ) const;
	void		typeDetector( char *literal );
	void		convertor( void );
};

std::ostream &operator<<(std::ostream &out, const Conversion &conversion);

#endif
