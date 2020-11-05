
#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H


class Pasager  {
    private:
        string numePasager;
        string clasa;//economic,business,intai
    public:
        Pasager(string numePasager, string clasa);

        ~Pasager() {}
        void print() {
             cout << numePasager << " la clasa " << clasa;
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
    private:
        Avion(const Avion&);
        Avion& operator=(const Avion&);

};

class AvionDeCalatori : public Avion{
    
    public:
        int nrMaxPasageri;
        vector<Pasager> pasageri;
        AvionDeCalatori(string idAvion, int putereMotor) :
        Avion::Avion(idAvion, putereMotor),
        
        nrMaxPasageri(12){}

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