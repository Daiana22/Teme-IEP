
#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H

#include <iostream>
#include <string.h>

class Pasager  {
    private:
        string numePasager;
        string clasa;//economic,business,intai
    public:

        int casru;
        Pasager(string numePasager, string clasa);//parameterized constr
        Pasager() {}//default constr
        Pasager& operator-=(Pasager rhs) {//transmis prin valoare 
            this->numePasager = rhs.numePasager;
            this->clasa = rhs.clasa;
            this->casru = rhs.casru - 2;
            return *this; }
        Pasager& operator=(Pasager rhs) { //transmis prin valoare
            this->numePasager = rhs.numePasager;
            this->clasa = rhs.clasa;
            this->casru = rhs.casru;
            return *this; }

        ~Pasager() {}//destructor
        void print() {
             cout << numePasager << " la clasa " << clasa << " si " << casru;
        }
};

Pasager::Pasager(string numePasager, string clasa) : //initializare constr
numePasager(numePasager),
clasa(clasa),
casru(10) { 
    cout << "Tocmai am creat pasagerul " << numePasager <<endl;}

class Avion {
    private:
        int dimensiune;
    public:
        string idAvion;
        int putereMotor;

        Avion(string idAvion, int putereMotor):
        dimensiune(100),
        idAvion(idAvion),
        putereMotor(putereMotor) {}//initializare constr
        Avion(){};//default constr

        virtual string toString() {
            return idAvion + " " + to_string(putereMotor) + "\n";
        }

        void decolare(){
            cout<< "Avionul " + idAvion + "a decolat.\n";
        }
        void aterizare(){
            cout<< "Avionul " + idAvion + "a aterizat.\n";
        }

        ~Avion() { }
    private://declared private so that we don't make copies of an object we don't want copies of
        Avion(const Avion&);//copy constr
        Avion& operator=(const Avion&);//assignment operator

};

class AvionDeCalatori : public Avion{
    
    public:
        int nrMaxPasageri;
        vector<Pasager> pasageri;
        AvionDeCalatori(string idAvion, int putereMotor) :
        Avion::Avion(idAvion, putereMotor),
        nrMaxPasageri(12){}//initializare constructor

        void adaugaPasageri(Pasager p){
            if(nrMaxPasageri > 0){
                pasageri.push_back(p);
                cout<<"Pasagerul ";
                p.print(); 
                cout<<" a fost imbarcat in " << idAvion << "\n";
                nrMaxPasageri--;
            }
            else
            {
                cout<< "Avionul este plin!\n";
            }
        }
        void afisarePasageri(){
            cout<< "Pasageri imbarcati in " << idAvion << ":\n";
            for(Pasager p: pasageri){
                cout << "\t - ";
                p.print();
                cout << endl;
            }
            cout << "Locuri ramase: " << nrMaxPasageri << endl;
        }

};

class AvionDeLupta : public Avion {
    public:
        int nrRachete;
        AvionDeLupta(string idAvion, int putereMotor) :
        Avion::Avion(idAvion, putereMotor),
        nrRachete(2) {}

        string toString() {
            string buf = Avion::toString() + "\n" + to_string(nrRachete) + "\n";
            return buf;
        }
        void lanseazaRacheta(){
            if(nrRachete >0){
                cout<< "Avionul " + idAvion + "a lansat racheta\n";
                nrRachete--;
            }
            else
            {
                cout<<"Nu mai sunt rachete!" << endl;
            }
            
        }
};

#endif