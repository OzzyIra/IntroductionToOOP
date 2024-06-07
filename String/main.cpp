//String
#include <iostream>

using namespace std;

class String
{
    int size; //размер строки в байтах
    char* str; // адрес строки в динамической памяти
public:
    //      constructors:
    String(int size = 80)
    {
        this->size = size;
        this->str = new char[size] {};
        cout << "DefaultConctructor:\t" << this << endl;
    }
    ~String()
    {
        delete[]this->str;
        cout << "destructor:\t\t" << this << endl;
    }
    //      Methods
    void print()const
    {
        cout << "Sixe:\t" << size << endl;
        cout << "Str:\t" << str << endl;
    }
};


void main()
{
    setlocale(LC_ALL, "Russian");
    String str;
    str.print();
}