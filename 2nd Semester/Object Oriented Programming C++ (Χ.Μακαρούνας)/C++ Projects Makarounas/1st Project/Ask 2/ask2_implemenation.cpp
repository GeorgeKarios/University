#include "ask2_interface.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int Calendar::daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const string Calendar::monthNames[12] = {"January","February","March",
                                        "April","May","June", 
                                        "July","August","September",
                                        "October","November","December"};
Calendar::Calendar(){ //constructor
    cout << "What year do you want a calendar for?"<<endl;
    cin>> year;  //ζητάει το έτος του ημερολογίου
    cout << "\nWhat day of the week does January 1 fall on?" << endl;
    cout << "(Enter 0 for Sunday, 1 for Monday, etc.)" << endl;
    cin>> startDay; // ζητάει την πρώτη μέρα του Έτους
}

bool Calendar::disektos() const { //ελέγχει αν είναι δίσεκτος
    return ((year%4==0 && year%100!=0) || (year%400==0));
}

void Calendar::generateCalendar() const { //εκτύπωση Ημερολογίου
    int firstWeek = startDay;       // μεταβλητή για spacing
    for (int i = 0; i < 12; i++) {
        cout <<endl<< monthNames[i] <<endl; //εκτύπωση μήνα
        cout << "S\tM\tT\tW\tT\tF\tS"<<endl; //εκτύπωση ημερών
        int days = daysInMonth[i]; //ενημέρωση συνολικών ημερών 

        if (i == 1 && disektos())  // i=1 -> Φλεβάρης
            days = 29;  //Άλλαξε σε 29 αν ειναι δισεκτος

        // Εκτύπωση αρχικών κενών κάθε μήνα:
        for (int j = 0; j < firstWeek; j++) //αφήνει space για την
            cout << "\t";                   //πρώτη εβδομάδα

        for (int k = 1; k<= days; k++){ //εκτύπωση κενού 
            cout <<k<<"\t";             //μεταξύ κάθε μέρας
            if (++firstWeek == 7){  //}
                firstWeek = 0;      //}νέα εβδομάδα
                cout << endl;       //}
            }
        }
        cout << endl;
        //υπολογισμός κενών για επόμενο μήνα:
        firstWeek=(firstWeek+days)%7; 
    }
}

