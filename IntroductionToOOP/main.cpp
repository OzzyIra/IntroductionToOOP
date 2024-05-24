#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//		Constructor:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = 0;
		this->y = 0;
		cout << "1ArgConstructor:\t " << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << " CopyConstructer:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//		Methods:
	double distance (Point other)const
	{
		
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}
//#define STRUCT_POINT
#define DISTANCE_CHACK
//#define CONSTRUCTORS_CHACK
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	cout << "Hello,OOP" << endl;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	cout << sizeof(A) << endl;
#endif //STRUCT_POINT
#ifdef DISTANCE_CHACK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	/*Point D;
	D.set_x(16.16);
	D.set_y(9.25);
	Point C;
	C.set_x(4.25);
	C.set_y(25.16);*/

	//distance(B.get_x(), B.get_y());
	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << distance(A, B);
#endif // DISTANCE_CHACK

#ifdef CONSTRUCTORS_CHACK
	Point A;	//DefaultConstructor
	A.print();

	Point B = 5;
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHACK

	
	
}