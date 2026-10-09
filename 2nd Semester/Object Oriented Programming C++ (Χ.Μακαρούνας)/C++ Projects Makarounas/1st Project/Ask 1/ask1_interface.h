#include <iostream>
using namespace std;

class Rational{
    public:
        Rational(int num1 = 0, int num2 = 1);        //constructor
        double addition(Rational other) const;       //πρόσθεση
        double subtraction(Rational other) const;    //αφαίρεση
        double multiplication(Rational other) const; //πολλαπ/σμός
        double division(Rational other) const;       //διαίρεση
        void print_rational(double, int);     //εκτύπωση κλάσματος
        void print_decimal(double, int);      //εκτύπωση δεκαδικού
        
     private:
        int arithm, paronom;       //δήλωση αριθμητή - παρονομαστή
        void simpler(int &, int &); //συνάρτηση απλοποίησης
};
