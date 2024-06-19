#include"Fraction.h"
int Fraction::get_integer() const
{
	return integer;
}

int Fraction::get_numerator() const
{
	return numerator;
}

int Fraction::get_denominator() const
{
	return denominator;
}

void Fraction::set_integer(int integer)
{
	this->integer = integer;
}

void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}

void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}


Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{
	/*integer = 0;
	numerator = 0;
	denominator = 1;
	*/
	cout << "Constructor default\t\t" << this << endl;

}

Fraction::Fraction(int integer) :Fraction()
{
	this->integer = integer;
	//this->numerator = 0;
	//this->denominator = 1;
	cout << "1ArgConstructor\t\t" << this << endl;
}

Fraction::Fraction(int numerator, int denominator) :Fraction()
{
	/*this->integer = 0;*/
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "2ArgConstructor\t\t\t" << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator) :Fraction(numerator, denominator)
{
	this->integer = integer;
	/* this->numerator = numerator;
	 this->set_denominator(denominator);*/
	cout << "Constructor\t\t\t" << this << endl;
}

Fraction::Fraction(const Fraction& other) :Fraction(other.integer, other.numerator, other.denominator)
{
	/*this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;*/
	cout << "Constructor copy\t\t" << this << endl;
}

Fraction::~Fraction()
{
	cout << "Destructor:\t\t\t" << this << endl;
}

Fraction:: operator int()
{
	return integer;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << endl;
	return *this;
}

Fraction& Fraction:: operator*=(Fraction other)
{
	return *this = *this * other;
}

Fraction& Fraction:: operator/=(const Fraction& other)
{
	return *this = *this / other;
}

Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}

Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::reduct()
{
	int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else more = denominator, less = numerator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction:: operator--()
{
	integer--;
	return *this;
}
Fraction Fraction:: operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}

Fraction& Fraction::operator+=(Fraction other)
{
	this->to_improper();
	other.to_improper();
	this->numerator = ((this->numerator * other.denominator) + (this->denominator * other.denominator));
	this->denominator = (this->denominator * other.denominator);
	return *this;
}
Fraction& Fraction::operator-=(Fraction other)
{
	this->to_improper();
	other.to_improper();
	this->numerator = ((this->numerator * other.denominator) - (this->denominator * other.denominator));
	this->denominator = (this->denominator * other.denominator);
	return *this;
}

void Fraction::Print()const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";
	}
	else if (integer == 0)cout << 0;
	cout << endl;
}

Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduct();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return ((left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator()));
}

bool operator!=(const Fraction& left, const Fraction right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();

}

bool operator<(Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();

}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	os << endl;
	return os;
}
std::istream& operator>>(std::istream& in, Fraction& obj)
{
	const int SIZE = 64;
	char buffer[SIZE]{};
	in.getline(buffer, SIZE);
	int number[3];
	int n = 0;
	const char delimeters[] = "(/) +";
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters))
		number[n++] = atoi(pch);

	for (int i = 0; i < n; i++)
		switch (n)
		{
		case 1: obj = Fraction(number[0]); break;
		case 2: obj = Fraction(number[0], number[1]); break;
		case 3: obj = Fraction(number[0], number[1], number[2]); break;
		default:
			break;
		}

	return in;
}
