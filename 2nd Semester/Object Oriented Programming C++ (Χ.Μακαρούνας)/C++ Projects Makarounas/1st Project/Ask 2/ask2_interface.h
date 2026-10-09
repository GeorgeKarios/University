#include <iostream>
#include <string>
using namespace std;

class Calendar {
    public:
        Calendar(); //constructor
        void generateCalendar() const; //εκτύπωση Ημερολογίου
    private:
        int year;     // Έτος
        int startDay; // Πρώτη μέρα Έτους
        static const int daysInMonth[12]; //ημέρες του μήνα
        static const string monthNames[12]; //ονόματα μηνών
        bool disektos() const; //αν είναι δίσεκτος
};

