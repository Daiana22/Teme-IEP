#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

class Pasager {
    private:
        string numePasager;
        string clasa;//economic,business,intai
    public:
        Pasager(string numePasager, string clasa);

        ~Pasager() {
            cout << "\nAm omorat pasagerul " << numePasager;
        }
        void print() {
             cout << numePasager;
        }
};

Pasager::Pasager(string numePasager, string clasa) :
numePasager(numePasager),
clasa(clasa) { cout << "Tocmai am creat pasagerul " << numePasager <<endl;}

class Avion {
    public:
        string idAvion;
        int putereMotor;
        Avion(string idAvion, int putereMotor):
        idAvion(idAvion),
        putereMotor(putereMotor) {}
        

        string toString() {
            return idAvion + " " + to_string(putereMotor);
        }

        void decolare(){
            cout<< "Avionul " + idAvion + "a decolat./n";
        }
        void zboara(){
            cout<< "Avionul " + idAvion + " zboara./n";
        }
        void aterizare(){
            cout<< "Avionul " + idAvion + "a aterizat./n";
        }
};

class AvionDeCalatori : public Avion{
    public:
        int nrMaxPasageri;//initializata cu 0
        vector<Pasager> pasageri;
        AvionDeCalatori(string idAvion, int putereMotor) :
        Avion::Avion(idAvion, putereMotor),
        
        nrMaxPasageri(12){}

        void adaugaPasageri(Pasager p){
            if(nrMaxPasageri > 0){
                pasageri.push_back(p);
                nrMaxPasageri--;
            }
            else
            {
                cout<< "Avionul este plin!";
            }
        }
        void afisarePasageri(){
            cout<< "Pasageri imbarcati:/n";
            for(Pasager p: pasageri){
                p.print();
            }
        }
};

class AvionDeLupta : public Avion {
    public:
        int nrRachete;
        AvionDeLupta(string idAvion, int putereMotor) :
        Avion::Avion(idAvion, putereMotor),
        nrRachete(10) {}

        string toString() {
            string buf = Avion::toString() + "\n" + to_string(nrRachete);
            return buf;
        }
        void lanseazaRacheta(){
            if(nrRachete >0){
                cout<< "Avionul " + idAvion + "a lansat racheta";
                nrRachete--;
            }
            else
            {
                cout<<"Nu mai sunt rachete!";
            }
            
        }
};



int main() {
    int optiune;
    Avion avion("alex",1);
    //AvionDeLupta adl("miruna", 200, 5);
    //cout << adl.toString();

    switch(optiune){
        case 1:
            break;
        case 2:
            break;
        default:
            cout<<"Alege optiunea:\n";
            cout<<"1-Creare pasager\n";
            cout<<"2\n";
    }


    return 0;
}