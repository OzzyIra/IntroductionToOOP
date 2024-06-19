#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//		constructors
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "Constructor default\t\t" << this << endl;

	}

	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor\t\t" << this << endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "2ArgConstructor\t\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor\t\t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Constructor copy\t\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t\t" << this << endl;
	}

	explicit operator int()
	{
		return integer;
	}
	//		operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << endl;
		return *this;
	}

	Fraction& operator*=(Fraction other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& reduct()
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

		/*int num = this->numerator, denom = this->denominator;
		int vr;
	if(numerator > denom)
		if (num < denom)
		{
			int temp = num;
			num = denom;
			denom = temp;
		}
		while (vr = num % denom)
		{
			num = denom;
			denom = vr;
		}
		this->numerator = this->numerator / denom;
		this->denominator = this->denominator / denom;
	}*/
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	Fraction& operator+=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = ((this->numerator * other.denominator) + (this->denominator * other.denominator));
		this->denominator = (this->denominator * other.denominator);
		return *this;
	}
	Fraction& operator-=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = ((this->numerator * other.denominator) - (this->denominator * other.denominator));
		this->denominator = (this->denominator * other.denominator);
		return *this;
	}

	void Print()const
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

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
};

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
	const char delimeters[]="(/) +";
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters))
		number[n++] = atoi(pch);

	for (int i = 0; i < n; i++)
		//cout << number[i] << "\t"; cout << endl;
	/*integer, numerator, denominator;
	cout << "Введите целую часть дроби= ";
	in >> integer;

	cout << "Введите числитель= ";
	in >> numerator;

	cout << "Введите знаменатель= ";
	in >> denominator;

	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
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

//#define CONSTRUCTORS_CHACK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
#define STREAM_CHECK
#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define CONVERSIONS_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHACK
	//Fraction A;
	//A.Print();
	Fraction B = 5;
	B.Print();
	Fraction C(1, 2);
	C.Print();
	Fraction D(2, 3, 4);
	D.Print();
	Fraction E = D;
	E.Print();
	Fraction F = E;
	F.Print();
	Fraction A(2, 3, 4);
	A.to_improper();
	A.Print();
	A.to_proper();
	A.Print();
#endif // CONSTRUCTORS_CHACK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.Print();

	Fraction B(3, 4, 5);
	B.Print();

	Fraction C = A / B;
	C.Print();

	cout << "Инкремент:\n";
	C--;
	C.Print();

	cout << "Декремент:\n";
	C++;
	C.Print();

	cout << "\nСложение:\n";
	C = A + B;
	C.Print();

	cout << "Вычитание:\n";
	C = A - B;
	C.Print();
	cout << "Умножение:\n";
	Fraction F = A * B;
	F.Print();

	cout << "Составное сложение:\n";
	C += B;
	C.Print();

	cout << "Составное вычитание:\n";
	C -= A;
	C.Print();

	cout << "Составное деление:\n";
	C /= A;
	C.Print();

	cout << "Оператор сравнения: \n";
	cout << (A == B) << endl;
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK

	cout << (2 == 3) << endl;

	cout << (Fraction(1, 2) > Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef STREAM_CHECK
	Fraction A;
	cout << "Введите простую дробь"<<endl;
	cin >> A;
	cout << A;


#endif // STREAM_CHECK
	 
}