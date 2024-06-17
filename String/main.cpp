//String
#include <iostream>

using namespace std;
#define delimeter "---------------------------------------------"
class String
{
    int size; //размер строки в байтах
    char* str; // адрес строки в динамической памяти
public:
    const char* get_str()const
    {
        return str;
    }
    char* get_str()
    {
        return str;
    }
    int get_size()const
    {
        return size;
    }
    void set_str(char* str)
    {
        this->str = str;
    }
    void set_size(int size)
    {
        this->size;
    }

    //      constructors:
   explicit String(int size = 80)
    {
        this->size = size;
        this->str = new char[size + 1] {};
        cout << "DefaultConctructor:\t" << this << endl;
    }
    String(const char* str)
    {
        this->size = strlen(str)+1;
        this->str = new char[size]{};
        for (int i = 0; i < size; i++)
        {
            this->str[i] = str[i];
        }
        cout << "Constructer1\t\t" << this << endl;
    }
    ~String()
    {
        delete[]this->str;
        cout << "destructor:\t\t" << this << endl;
    }
  
    String(const String& other)
    {
        this->size = other.size;
        this->str = new char[other.size + 1]{};
        for (int i = 0; i < size; i++)
        {
            this->str[i] = other.str[i];
        }
        cout << "CopyConstructor" << this << endl;
    }
    String& operator=(const String& other)
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
    //String operator+(const String& other)
    //{
    //    String str_new;
    //    int str1Size = this->get_size();
    //    int str2Size = other.get_size();

    //    int newSize = str1Size + str2Size;
    //    str_new = new char[newSize + 2]{};
    //    //  копируем
    //    int i;
    //    for ( i = 0; i < str1Size + 1; i++)
    //    {
    //        str_new.str[i] = this->str[i];
    //    }
    //    str_new.str[i] = ' ';
    //    for (int j = 0; j < str2Size; j++)
    //    {
    //        str_new.str[j] = other.str[j];
    //    }
    //    return str_new;
    //}
    //      Methods
    void print()const
    {
        cout << "Obj:\t" << this << "\t";
        cout << "Size:\t" << size << endl;
        cout << "Addr:\t" << &str << "\t";
        cout << "Str:\t" << str << endl;
    }
};

 String operator+(const String& left, const String& right)
{
    String buffer(left.get_size() + right.get_size() - 1 );
    for (int i = 0; i < left.get_size(); i++)
        buffer.get_str()[i] = left.get_str()[i];
    for (int i = 0; i < right.get_size(); i++)
        buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
    buffer.print();
    return buffer;
}

void main()
{
    setlocale(LC_ALL, "Russian");
  /*  String str;
    str.print();*/
    String str1 = "Hello";
    //str1.print();
    String str2 = "World";
   // str2.print(); 
   cout<< delimeter << endl;
    String str3 = str1 + str2;
    str3.print();
    /*cout << str1 << endl;
    cout << str2 << endl;*/


}