#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class   Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);

    Fixed(const Fixed &other);

    Fixed& operator=(const Fixed &other);

    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;    //casts the fixed point number back to float
    int toInt(void) const;       //casts the fixed point number back to int

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;   //second const does not modify the current object
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed&other) const;
    Fixed operator-(const Fixed&other) const;
    Fixed operator*(const Fixed&other) const;
    Fixed operator/(const Fixed&other) const;

    Fixed& operator++();
    Fixed operator++(int a);

    Fixed& operator--();
    Fixed operator--(int a);

    static Fixed& min(Fixed& first, Fixed& second);
    static const Fixed& min(const Fixed& first, const Fixed& second);

    static Fixed& max(Fixed& first, Fixed& second);
    static const Fixed& max(const Fixed& first, const Fixed& second);
};

    //std::cout-i mej std-n namespace e, cout-y object, vori type-y std::ostream e(class vory parunakum e en amen inchy inchy vor petq e output anelu hamar)

    std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
    //return enq anum ostream-y, vor orinak std::cout << "Hello" << "World" <<std::endl;
    //es depqy skzbum return e anum "Hello", heto dra vra avelacnum "World"

#endif