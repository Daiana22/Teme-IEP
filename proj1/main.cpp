#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Avion {
    public:
        string nume;
        int motor;
        Avion(string nume,  int motor):
        nume(nume),
        motor(motor) {}
        

        string toString() {
            return nume + " " + to_string(motor);
        }
};


class AvionDeLupta : public Avion {
    public:
        int rachete;
        AvionDeLupta(string nume, int motor, int rachete) :
        Avion::Avion(nume, motor),
        rachete(rachete) {}

        string toString() {
            string buf = Avion::toString() + "\n" + to_string(rachete);
            return buf;
        }
};




class Pasager {
    private:
        string nume;
        Avion p;
    public:
        Pasager(string nume, Avion p);
        void print() {
             cout << "Pasagerul " << nume << " este in avionul " << p.toString();
        }
        ~Pasager() {
            cout << "\nam omorit pasagerul " << nume;
        }
};

Pasager::Pasager(string nume, Avion p) :
nume(nume),
p(p) { cout << "Tocmai am creat pe " << nume <<endl;}



int main() {
    Avion p("alex",1);
    AvionDeLupta adl("miruna", 200, 5);
    cout << adl.toString();
    return 0;
}