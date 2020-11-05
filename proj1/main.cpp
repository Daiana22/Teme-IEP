#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;


#include "Type_Define.hpp"


int main() {

    AvionDeCalatori avionDeCalatori1("Boeing777",2500);
    AvionDeCalatori avionDeCalatori2("bbb",3000);
    AvionDeCalatori avionDeCalatori3("ccc",3000);

    AvionDeLupta avionDeLupta1("ddd",3500);
    AvionDeLupta avionDeLupta2("eee",4500);

    Avion *a2 = new AvionDeLupta("lupta", 5);
    cout << a2->toString();

    Pasager p1("miruna","intai");
    Pasager p2("alex","economic");
    Pasager p3("andrei","business");
    Pasager p4("razvan","intai");
    Pasager p5("daiana","intai");

    avionDeCalatori1.adaugaPasageri(p1);
    avionDeCalatori1.adaugaPasageri(p3);
    avionDeCalatori1.adaugaPasageri(p4);

    avionDeCalatori1.afisarePasageri();


    avionDeCalatori1.adaugaPasageri(p2);
    avionDeCalatori1.afisarePasageri();

    avionDeLupta1.decolare();
    do {
        avionDeLupta1.lanseazaRacheta();
    } while (avionDeLupta1.nrRachete > 0);
    avionDeLupta1.aterizare();

    return 0;
}