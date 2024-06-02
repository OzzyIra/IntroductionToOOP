#include <iostream>

using namespace std;

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

	Fraction(int integer)
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
	//		operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << endl;
		return *this;
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
	 
	void reduct()
	{
		int num = this->numerator, denom = this->denominator;
		int vr;
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

	Fraction& operator*=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = this->numerator * other.numerator;
		this->denominator = this->denominator * other.denominator;
		this->to_proper();
		return *this;
	}

	Fraction& operator/=(Fraction other)
	{
		return *this *= other.inverted();
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

Fraction operator*( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
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

Fraction operator/(const Fraction& left, Fraction& right)
{
	return left * right.inverted();
}
bool operator==(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	left.reduct();
	right.reduct();
	return ((left.get_numerator() == right.get_denominator() && right.get_numerator() == left.get_denominator()));
}
//#define CONSTRUCTORS_CHACK
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
	




}