#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;


#include "Type_Define.hpp"


int main() {

    
    Pasager p5("daiana","intai");
   
    Pasager p66;
    Pasager *p6;
    Pasager p7;
    p7 = p5;

    p6 = &p5;
    cout << "p6 arata spre adresa: " << p6 << endl;
    cout << "p5 este la adresa: " <<  &p5  << " ; p6 este la adresa: " << &p6 << "\n\n\n\n";
    p66.operator=(p7.operator=(p5));
    p5.print(); cout << " : " << &p5 << endl;
    p66.print(); cout << " : " << &p6 << endl;
    p7.print(); cout << " : " << &p7 << "\n\n\n";


    Pasager a1;
    Pasager a2;
    Pasager a3("maria", "doi");

   // a1.operator-=(a2.operator-=(a3));
    a1 -= a2 -= a3;
   a3.print(); cout << " : " << &a3 << endl;
    a2.print(); cout << " : " << &a2 << endl;
    a1.print(); cout << " : " << &a1 << "\n\n\n";
    return 0;
}