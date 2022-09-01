/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:50:11 by mclam             #+#    #+#             */
/*   Updated: 2022/08/23 11:15:15 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion( void ) :
_type( "wrong literal" ),
_char( 0 ),
_int( 0 ),
_float( 0 ),
_double( 0 ),
_charPossibility( false ),
_intPossibility( false ),
_floatPossibility( false ),
_doublePossibility( false ) {
	this->_floatCase[0] = "-inff";
	this->_floatCase[1] = "+inff";
	this->_floatCase[2] = "inff";
	this->_floatCase[3] = "nanf";
	this->_doubleCase[0] = "-inf";
	this->_doubleCase[1] = "+inf";
	this->_doubleCase[2] = "inf";
	this->_doubleCase[3] = "nan";
}

Conversion::Conversion( const Conversion &conversion ) {
	*this = conversion;
}

Conversion	&Conversion::operator=( const Conversion &conversion )
{
	for (int i = 0; i < 4; i++)
		this->_floatCase[i] = conversion._floatCase[i];
	for (int i = 0; i < 4; i++)
		this->_doubleCase[i] = conversion._doubleCase[i];
	this->_type = conversion._type;
	this->_char = conversion._char;
	this->_int = conversion._int;
	this->_float = conversion._float;
	this->_double = conversion._double;
	this->_charPossibility = conversion._charPossibility;
	this->_intPossibility = conversion._intPossibility;
	this->_floatPossibility = conversion._floatPossibility;
	this->_doublePossibility = conversion._doublePossibility;
	return *this;
}

Conversion::~Conversion( void ) {
}

bool	Conversion::_isChar( char *literal, size_t len ) {
	if (len == 3 && literal[0] == '\'' && literal[2] == '\'')
		return true;
	return false;
}

bool	Conversion::_isInt(char *literal, size_t len) {
	if (len == 1 && isdigit(literal[0]) == true)
		return true;
	else if (len > 1 &&
		(isdigit(literal[0]) == true || literal[0] == '-' || literal[0] == '+')) {
		for (size_t i = 1; i < len; i++) {
			if (isdigit(literal[i]) == false)
				return false;
		}
		return true;
	}
	return false;
}

bool	Conversion::_isFloat(char *literal, size_t len) {
	std::string	stringLiteral(literal);
	
	for (int i = 0; i < 4; i++)
		if (_floatCase[i] == stringLiteral)
			return true;
	if (len == 3 && literal[--len] == 'f') {
		int	pointsNumber = 0;
		for (size_t i = 0; i < len; i++) {
			if (isdigit(literal[i]) == false && literal[i] != '.')
				return false;
			if (literal[i] == '.')
				pointsNumber++;
		}
		if (pointsNumber == 1)
			return true;
	}
	else if (len > 3 && literal[--len] == 'f' &&
		(isdigit(literal[0]) == true || literal[0] == '-' || literal[0] == '+' ||
		 literal[0] == '.')) {
		int	pointsNumber = 0;
		if (literal[0] == '.')
			pointsNumber++;
		for (size_t i = 1; i < len; i++) {
			if (isdigit(literal[i]) == false && literal[i] != '.')
				return false;
			if (literal[i] == '.')
				pointsNumber++;
		}
		if (pointsNumber == 1)
			return true;
	}
	return false;
}

bool	Conversion::_isDouble(char *literal, size_t len) {
	std::string	stringLiteral(literal);
	
	for (int i = 0; i < 4; i++)
		if (_doubleCase[i] == stringLiteral)
			return true;
	if (len == 2) {
		int	pointsNumber = 0;
		for (size_t i = 0; i < len; i++) {
			if (isdigit(literal[i]) == false && literal[i] != '.')
				return false;
			if (literal[i] == '.')
				pointsNumber++;
		}
		if (pointsNumber == 1)
			return true;
	}
	else if (len > 2 &&
		(isdigit(literal[0]) == true || literal[0] == '-' || literal[0] == '+' ||
		 literal[0] == '.')) {
		int	pointsNumber = 0;
		if (literal[0] == '.')
			pointsNumber++;
		for (size_t i = 1; i < len; i++) {
			if (isdigit(literal[i]) == false && literal[i] != '.')
				return false;
			if (literal[i] == '.')
				pointsNumber++;
		}
		if (pointsNumber == 1)
			return true;
	}
	return false;
}

void	Conversion::typeDetector( char *literal ) {
	size_t	len = strlen(literal);

	if (_isChar(literal, len)) {
		_char = literal[1];
		_type = "char";
	}
	else if (_isInt(literal, len)) {
		_int = std::strtol(literal, NULL, 10);
		_type = "int";
	}
	else if (_isFloat(literal, len)) {
		_float = std::strtof(literal, NULL);
		_type = "float";
	}
	else if (_isDouble(literal, len)) {
		_double = std::strtod(literal, NULL);
		_type = "double";
	}
}

void	Conversion::convertor( void ) {
	if (_type == "char" && _char >= 0 && _char <= std::numeric_limits<char>::max()) {
		_charPossibility = true;
		_int = static_cast<long>(_char);
		_intPossibility = true;
		_float = static_cast<float>(_char);
		_floatPossibility = true;
		_double = static_cast<double>(_char);
		_doublePossibility = true;
	}
	else if (_type == "int" && _int >= std::numeric_limits<int>::min() &&
			 _int <= std::numeric_limits<int>::max()) {
		_intPossibility = true;
		if (_int >= 0 && _int <= std::numeric_limits<char>::max()) {
			_char = static_cast<char>(_int);
			_charPossibility = true;
		}
		_float = static_cast<float>(_int);
		_floatPossibility = true;
		_double = static_cast<double>(_int);
		_doublePossibility = true;
	}
	else if (_type == "float") {
		_floatPossibility = true;
		if (_float >= 0 && _float <= std::numeric_limits<char>::max()) {
			_char = static_cast<char>(_float);
			_charPossibility = true;
		}
		if (_float >= std::numeric_limits<int>::min() &&
			_float <= std::numeric_limits<int>::max()) {
			_int =  static_cast<long>(_float);
			_intPossibility = true;
		}
		_double =  static_cast<double>(_float);
		_doublePossibility = true;
	}
	else if (_type == "double") {
		_doublePossibility = true;
		if (_double >= 0 && _double <= std::numeric_limits<char>::max()) {
			_char =  static_cast<char>(_double);
			_charPossibility = true;
		}
		if (_double >= std::numeric_limits<int>::min() &&
			_double <= std::numeric_limits<int>::max()) {
			_int = static_cast<long>(_double);
			_intPossibility = true;
		}
		if ((_double >= -std::numeric_limits<float>::max() &&
			_double <= std::numeric_limits<float>::max()) ||
			_double != _double || // nan
			_double == std::numeric_limits<double>::infinity() ||
			_double == -std::numeric_limits<double>::infinity()) {
			_float = static_cast<float>(_double);
			_floatPossibility = true;
		}
	}
}

std::string	Conversion::getType( void ) const {
	return _type;
}

char	Conversion::getChar( void ) const {
	return _char;
}

long int	Conversion::getInt( void ) const {
	return _int;
}

float	Conversion::getFloat( void ) const {
	return _float;
}

double	Conversion::getDouble( void ) const {
	return _double;
}
bool	Conversion::getCharPossibility( void ) const {
	return _charPossibility;
}

bool	Conversion::getIntPossibility( void ) const {
	return _intPossibility;
}

bool	Conversion::getFloatPossibility( void ) const {
	return _floatPossibility;
}

bool	Conversion::getDoublePossibility( void ) const {
	return _doublePossibility;
}

std::ostream &operator<<(std::ostream &out, const Conversion &conversion) {

	out << "Detected type: ";
	out << conversion.getType() << std::endl;

	out << "char: ";
	if (conversion.getCharPossibility() == true) {
		if (conversion.getChar() < 32 || conversion.getChar() == 127)
			out << "Non displayable" << std::endl;
		else
			out << "'" << conversion.getChar() << "'" << std::endl;
	}
	else
		out << "impossible" << std::endl;
	
	out << "int: ";
	if (conversion.getIntPossibility() == true)
		out << conversion.getInt() << std::endl;
	else
		out << "impossible" << std::endl;
	
	out << "float: " << std::fixed << std::setprecision(1);
	if (conversion.getFloatPossibility() == true)
		out << conversion.getFloat() << "f" << std::endl;
	else
		out << "impossible" << std::endl;
	
	out << "double: " << std::fixed << std::setprecision(1);
	if (conversion.getDoublePossibility() == true)
		out << conversion.getDouble() << std::endl;
	else
		out << "impossible" << std::endl;
	
	return out;
}
