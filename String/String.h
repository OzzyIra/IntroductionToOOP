#pragma once
#include <iostream>

using namespace std;

//ќбъ€вление класса/class declaration

class String
{
    int size; //размер строки в байтах
    char* str; // адрес строки в динамической пам€ти
public:
    const char* get_str()const;
    char* get_str();
    int get_size()const;
    void set_str(char* str);
    void set_size(int size);

    //      constructors:
    explicit String(int size = 80);
    String(const char* str);

    String(const String& other);

    ~String();

    String& operator=(const String& other);
    void print()const;
};
std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);
