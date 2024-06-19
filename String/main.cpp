//String
#include"String.h"

#define delimiter "\n-----------------------------------\n"

#define CAT_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
    setlocale(LC_ALL, "Russian");

#ifdef CAT_CHECK
    /*  String str;
    str.print();*/
    String str1 = "Hello";
    //str1.print();
    String str2 = "World";
    // str2.print(); 
    cout << delimiter << endl;
   // String str3 = str1 + str2;
    //str3.print();
    /*cout << str1 << endl;
    cout << str2 << endl;*/

#endif // CAT_CHECK

#ifdef CONSTRUCTORS_CHECK
    String str1;
    str1.print();

    String str2(8);
    str2.print();

    String str3 = "Hello";
    str3.print();

    String str4(); // здесь не вызываетс€ конструктор и не создаетс€ объект,
                   // в этом выражении объ€вл€етс€ функци€ str4
                   // котора€ ничего не принимает и не возвращает объект класса String     
   // str4.print();

    String str5{};  //€вный вызов конструктора по умолчанию
    str5.print();

    String str6{ str3 };
    str6.print();

#endif // CONSTRUCTORS_CHECK


}