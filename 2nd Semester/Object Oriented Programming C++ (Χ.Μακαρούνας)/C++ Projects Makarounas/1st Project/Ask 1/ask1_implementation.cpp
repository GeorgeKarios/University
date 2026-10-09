#include "ask1_interface.h"
#include <iomanip>
#include <cmath>
using namespace std;

Rational::Rational(int num1, int num2){ //constructor
    arithm = num1;  //μεταβλητή αριθμητή
    paronom = num2; //μεταβλητή παρονομαστή
    if (paronom == 0){ //αν ο διαιρούμε δια 0 (δεν ορίζεται)
        cout<<"Error: Denominator cannot be zero. Setting to 1 by default."<<endl;
        paronom = 1;   //θέτουμε τον παρονομαστή σε 1 για να μην εχουμε crash
    }
    simpler(arithm, paronom); //κλήση για απολοποίηση
}
//συνάρτηση πρόσθεσης:
double Rational::addition(Rational rat2) const {
    int newA = arithm*rat2.paronom + rat2.arithm*paronom;
    int newP = paronom * rat2.paronom;
    return (double) newA/newP;
};
//συνάρτηση αφαίρεσης:
double Rational::subtraction(Rational rat2) const {
    int newA = (arithm * rat2.paronom - rat2.arithm * paronom);
    int newP = (paronom * rat2.paronom);
    return (double) newA/newP;
};
//συνάρτηση πολλαπλασιασμού:
double Rational::multiplication(Rational rat2) const {
    int newA = (arithm * rat2.arithm);
    int newP = (paronom * rat2.paronom);
    return (double) newA/newP;
};
//συνάρτηση διαίρεσης:
double Rational::division(Rational rat2) const {
    if (rat2.arithm == 0){ //σε περίπτωση διαίρεσης με 0
        cout << "Error: Division by zero (Aprosdioristi Morfi)" << endl;
        return 0.0; //σε περίπτωση διαίρεσης με 0
    }
    int newA = (arithm * rat2.paronom);
    int newP = (paronom * rat2.arithm);
    return (double) newA/newP;
}
//συνάρτηση εκτύπωσης κλάσματος:
void Rational::print_rational(double num, int denom = 1) {
    if (denom == 0){  //σε περίπτωση διαίρεσης με 0
        cerr<<"Error: Denominator cannot be zero (Aprosdioristi Morfi)"<<endl;
        return;
    }
    if (denom == 1) {  //σε περιπτωση που εστάλει μονο 1 αριθμός
        while (num != (int) num){ //}
            num *= 10;            //} μετάλλαξη δεκαδικού σε κλασμα
            denom *= 10;          //}
        }
    }
    int intNum = (int) num; //δημιουργία ακέραιου num
    simpler(intNum, denom); //κλήση για απλοποιήση
    cout << intNum << "/" << denom << endl; //εκτύπωση σε μορφη κλάσματος
}
//συνάρτηση εκτύπωσης δεκαδικού:
void Rational::print_decimal(double num, int denom = 1) {
    if (denom == 0){ //σε περίπτωση διαίρεσης με 0
        cout << "Error: Denominator cannot be zero!" << endl;
        return;
    }       //εκτύπωση με 3 δεκαδικά ψηφία:
    cout<<fixed<<setprecision(3)<<((double)num/denom)<<endl; 
}
//συνάρτηση απολοποίησης κλάσματος
void Rational::simpler(int &arithm, int &paronom) {
    int i = 2;
    while (i <= abs(arithm) && i <= abs(paronom)){
        if (arithm % i == 0 && paronom % i == 0){
            arithm /= i;  //απλοποίηση αριθμητή
            paronom /= i; //απλοποίηση παρονομαστή
        } else
            i++;
    }
    //σε περίπτωση που ο παρονομαστής ειναι αρνητικός
    //να ανταλλάξουν τα πρόσημα για καλύτερη απεικόνιση:
    if (paronom < 0){
        arithm = -arithm;
        paronom = -paronom;
    }
}

