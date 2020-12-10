#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;


#include "Type_Define.hpp"


int main() {
    Avion a1;//generates default constr + destructor
    //Avion a("general",1200);

    AvionDeCalatori aCalatori("wizzer",2000);
    AvionDeLupta aLupta("boeing",2500);
    

    //Item 10 
    /*
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
    */

    // Item 11
    Bilet b;

    int pretBilet= b.doSmth();
    cout << "Pret dupa delete: " << pretBilet << endl;
    //cout << "Pointerul din afara functiei este la adresa: " << &pBilet << " si arata spre: " << pBilet  << endl;
  
    Bilet b2(150);

    BiletManagement bm(&b2);
    b2.pret = 100;

   // BiletManagement bm2(&bm);
   // nu poate fi accesat copy-constructorul pentru ca e private
    return 0;
}