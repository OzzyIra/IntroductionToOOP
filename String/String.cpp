#include"String.h"
const char* String::get_str()const
{
    return str;
}
char* String::get_str()
{
    return str;
}
int String::get_size()const
{
    return size;
}
void String::set_str(char* str)
{
    this->str = str;
}
void String::set_size(int size)
{
    this->size;
}

//      constructors:
String::String(int size) :size(size), str(new char[size] {})
{
    cout << "DefaultConctructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
    for (int i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }
    cout << "Constructer1\t\t" << this << endl;
}

String::String(const String& other) :String(other.str)
{
    cout << "CopyConstructor" << this << endl;
}

String::~String()
{
    delete[]this->str;
    cout << "destructor:\t\t" << this << endl;
}

String& String::operator=(const String& other)
{
    if (this == &other)return *this;
    delete[]str;
    this->size = other.size;
    this->str = new char[size + 1]{};
    for (int i = 0; i < size; i++)
        this->str[i] = other.str[i];
    cout << "CopyAssignment:\t\t" << this << endl;
    return *this;
}
//      Methods
void String::print()const
{
    cout << "Obj:\t" << this << "\t";
    cout << "Size:\t" << size << endl;
    cout << "Addr:\t" << &str << "\t";
    cout << "Str:\t" << str << endl;
}
std::ostream& operator<<(std::ostream& os, const String obj)
{
    return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
    String buffer(left.get_size() + right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++)
        buffer.get_str()[i] = left.get_str()[i];
    for (int i = 0; i < right.get_size(); i++)
        buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
    buffer.print();
    return buffer;
}
