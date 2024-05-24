#include<iostream>
using namespace std;
#include<cmath>

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

	//double distance(double x, double y)
	//{
	//	double S;
	//	S = sqrt( (this->x * x) + (this->y * y));
	//	//S = sqrt( (A.get_x() * A.get_x()) + (A.get_y() * A.get_y()));
	//	//S = sqrt( (A.x * A.x) + (A.y * A.y));
	//	return S;
	//}

};
void distance(Point A, Point B)
{
	double AB = 0;
	//AB = sqrt((pow(2, (B.get_x() - A.get_x()))) + (pow(2, (B.get_y() - A.get_y()))));
	AB = sqrt(((B.get_x() - A.get_x()) * (B.get_x() - A.get_x())) + ((B.get_y() - A.get_y()) * (B.get_y() - A.get_y())));	
	cout<< AB;
}


//#define STRUCT_POINT

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

#endif // STRUCT_POINT
	Point A;
	A.set_x(2.16);
	A.set_y(3.25);
	Point B;
	B.set_x(5.25);
	B.set_y(12.9);
	Point D;
	D.set_x(16.16);
	D.set_y(9.25);
	Point C;
	C.set_x(4.25);
	C.set_y(25.16);
	double S = 0;
	cout << A.get_x() << "\t" << A.get_y() << endl;
	
	//distance(B.get_x(), B.get_y());

	cout << "Расстояние до точки B = ";
	distance(A, B);
}