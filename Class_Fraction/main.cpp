#include"Fraction.h"

//#define CONSTRUCTORS_CHACK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define STREAM_CHECK
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
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
	
	Fraction A(4, 5, 6);
	A.Print();
	Fraction B = A;
	B.Print();
}


