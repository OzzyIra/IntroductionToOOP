#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& in, Fraction& obj);


class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//		constructors
	Fraction();

	explicit Fraction(int integer);

	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);

	Fraction(const Fraction& other);

	~Fraction();


	//		operators
	explicit operator int();
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(Fraction other);

	Fraction& operator/=(const Fraction& other);

	Fraction& to_proper();

	Fraction& to_improper();

	Fraction& reduct();

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& operator+=(Fraction other);
	Fraction& operator-=(Fraction other);

	void Print()const;
	Fraction inverted()const;
};

