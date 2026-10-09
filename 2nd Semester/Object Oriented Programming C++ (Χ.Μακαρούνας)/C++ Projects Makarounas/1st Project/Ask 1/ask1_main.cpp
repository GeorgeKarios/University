#include "ask1_implementation.cpp"
using namespace std;
int main() {
    Rational rat1(3,4); //πρώτο κλάσμα
    Rational rat2(5,8 ); //δεύτερο κλάσμα
    //εκτ΄ύπωση δεκαδικών
    cout<<"Decimal Form:"<<endl;
    cout<< "Addition Result: ";
    rat1.print_decimal(rat1.addition(rat2), 1);
    cout<<"Multiplication Result: ";
    rat1.print_decimal(rat1.multiplication(rat2), 1);
    cout<<"Subtraction Result: ";
    rat1.print_decimal(rat1.subtraction(rat2), 1);
    cout<<"Dividsion Result: ";
    rat1.print_decimal(rat1.division(rat2), 1);
    //εκτύπωηση κλασμάτων
    cout<<"Rational Form:"<<endl;
    cout<< "Addition Result: ";
    rat1.print_rational(rat1.addition(rat2), 1);
    cout<<"Multiplication Result: ";
    rat1.print_rational(rat1.multiplication(rat2), 1);
    cout<<"Subtraction Result: ";
    rat1.print_rational(rat1.subtraction(rat2), 1);
    cout<<"Division Result: ";
    rat1.print_rational(rat1.division(rat2), 1);
    return 0;
}

