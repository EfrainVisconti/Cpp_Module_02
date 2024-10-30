/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:27:24 by codespace         #+#    #+#             */
/*   Updated: 2024/10/30 03:14:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int  pow2(int fractionalBits)
{
    return 1 << fractionalBits; //Equivalent to 2 with exponent fractionalBits
}

Fixed::Fixed() : _value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called" << std::endl;
    this->_value = value << _fractionalBits; //Equivalent to multiply by 2 with exponent _fractionalBits
}

Fixed::Fixed(const float value)
{
    //std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * pow2(_fractionalBits));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    return this->_value;
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float   Fixed::toFloat() const
{
    return ((float)this->_value / pow2(_fractionalBits));
}

int Fixed::toInt() const
{
    return this->_value >> _fractionalBits;
}

std::ostream    &operator<<(std::ostream &out, const Fixed &other)
{
    out << other.toFloat();
    return out;
}

bool    Fixed::operator>(const Fixed &other) const
{
    return this->_value > other.getRawBits();
}

bool    Fixed::operator<(const Fixed &other) const
{
    return this->_value < other.getRawBits();
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return this->_value >= other.getRawBits();
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return this->_value <= other.getRawBits();
}

 bool   Fixed::operator==(const Fixed &other) const
 {
    return this->_value == other.getRawBits();
 }
        
bool    Fixed::operator!=(const Fixed &other) const
{
    return this->_value != other.getRawBits();
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    Fixed   result;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    Fixed   result;
    result.setRawBits(this->_value - other.getRawBits());
    return result;
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed   &Fixed::operator++()
{
    this->_value += _epsilon;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed   tmp(*this);
    this->_value += _epsilon;
    return tmp;
}

Fixed   &Fixed::operator--()
{
    this->_value -= _epsilon;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed   tmp(*this);
    this->_value -= _epsilon;
    return tmp;
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}