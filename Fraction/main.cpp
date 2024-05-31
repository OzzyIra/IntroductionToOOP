#include<iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
public:
	//		Constructors
	Fraction()
	{
		numerator = denominator = 0;
		cout << "Constructor default\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor\t\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Constructor copy\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t\t" << this << endl;
	}
	//		Operators
	Fraction& operator++()
	{
		numerator++;
		denominator++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction temp = *this;
		numerator++;
		denominator++;
		return temp;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}
	//		Methods
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	void Print()const
	{
		cout << numerator << "/" << denominator << endl;
	}
};

//		Operators outside the class
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()));
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()));
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_numerator());
	return res;
}

void main()
{
	setlocale(LC_ALL, "Ru");
	Fraction A(7, 8);
	A.Print();
	Fraction B(5, 9);
	B.Print();
	Fraction C = A + B;
	C.Print();
	C = A - B;
	C.Print();
	C = A * B;
	C.Print();
	C = A / B;
	C.Print();
	C++;
	C.Print();

}