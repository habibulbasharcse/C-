#include <bits/stdc++.h>
using namespace std;

class Cricketer {
    public :
    string country;
    int jersey;

    Cricketer(string country,int jersey) {
        this->country = country;
        this-> jersey = jersey;
    }

};

int main () {
    Cricketer * Dhoni = new Cricketer("india",96);
    Cricketer * Koholi = new Cricketer("india",100);

    //Dhoni->country = Koholi->country;
   // Dhoni->jersey = Koholi->jersey;
   *Dhoni = *Koholi;

    delete Dhoni;

    //cout << "Dhoni " << Dhoni->country <<" " << Dhoni->jersey;
    cout << "Koholi " <<Koholi->country <<" " << Koholi->jersey;
}