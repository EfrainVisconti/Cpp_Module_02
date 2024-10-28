/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:43:22 by codespace         #+#    #+#             */
/*   Updated: 2024/10/28 21:54:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int  pow2(int fractionalBits)
{
    return 1 << fractionalBits; //Equivalent to 2 with exponent fractionalBits
}

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractionalBits; //Equivalent to multiply by 2 with exponent _fractionalBits
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * pow2(this->_fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
    return ((float)this->_value / pow2(this->_fractionalBits));
}

int Fixed::toInt() const
{
    return this->_value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed &other)
{
    out << other.toFloat();
    return out;
}