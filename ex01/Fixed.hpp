/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:43:51 by codespace         #+#    #+#             */
/*   Updated: 2024/10/28 21:53:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(int const value);
        Fixed(float const value);
        Fixed(const Fixed &other); //Copy constructor
        ~Fixed();
        Fixed &operator=(const Fixed &other); //Copy assignment operator
        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat() const;
        int     toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &other);

#endif