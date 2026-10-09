 #include "Manage.h"  //}
#include "account.h" //}header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#define MAX_ACCOUNTS 200 
using namespace std;

void Manage::createList(){ //δημιουργία Κενής Λίστας
    Account blankfill; //δημιουργία κενού αντικειμένου
    fstream wptr("system.txt", ios::out | ios::binary); //δημιουργ txt ως w
    if (!wptr) {    //αν δεν ανοίξει
        cout << "File could not be created\n";
    } else {
        for (int i = 0; i < MAX_ACCOUNTS; i++) //} συμπλήρωση 
            blankfill.writeToFile(wptr);       //} κενής λίστας
        wptr.close();                          // κλείσιμο file
        cout << "Blank Binary List Created.\n";
    }   //κλίνει το else
}       //κλίνει συνάρτηση createlist()

void Manage::input() {      //βασική Συνάρτηση Προγράμματος
    //ανοιγμα file  ως output, input, binary:
    fstream iptr("system.txt", ios::in | ios::out | ios::binary);
    char ans;
    string enteredName;
    float purch;
    Account data;
    Account StartState[MAX_ACCOUNTS];
    bool isnew = false; //if its a new account
    if (!iptr){ //στην περίπτωση που δεν ανοίγει  
        cout << "File could not be opened\n";
        return; //κλίνει το πρόγραμμα
    }
    //διαβάζει ολα τα δεδομένα & τα αποθηκευει σε array 
    for (int i = 0; i < MAX_ACCOUNTS; i++) 
        if (!StartState[i].readFromFile(iptr)) {
            cout << "Error reading account at index " << i << ".\n";
            break;
        }
    while (true){
        int accountExists = getInfo(&purch, &data, iptr); //κλήση getinfo()
        if (accountExists == -1) break; // -1 means ERROR -> EXIT
        if (!accountExists){ //περίπτωση accountExists=0
            cout << "\nIS THIS A NEW ACCOUNT NUMBER? (Y OR N): ";
            cin >> ans; //διάβασμα απάντησης
            if (ans == 'N' || ans == 'n') { //if ans="No" then asks again
                cout << "\nINVALID ACCOUNT NUMBER, RE-ENTER DATA:";
                continue; //restart while loop 
            } else if (ans == 'Y' || ans == 'y'){ //if ans="Yes" then adds the customer
                newCust(iptr, &data, &purch); //κλήση newcust()
                isnew = true; //είναι καινούργιος = true
            }
        }
        if (!isnew){ //περίπτωση που δεν είναι καινούργιος
            cout << "\nENTER CUSTOMER NAME TO AUTHENTICATE: ";
            cin.ignore();
            getline(cin,enteredName); //getline για ολόκληρη προταση
            if (!data.validateName(enteredName)){ //κλ΄ηση Συναρτ. Επαλήθευσης
                cout << "\nACCOUNT NUMBER & CUSTOMER NAME DO NOT MATCH, RE-ENTER DATA:";
                continue; //restart while loop 
            }
            cout<<"\nAuthentication successful! Welcome back, "<<data.custname << ".\n";
        }
        check(iptr, &data, purch);   // έλεγχος (purch)
        isnew = false;  //reset the flag
    }   //κλίνει το while
    cout << "\nSTARTING STATE OF ACCOUNTS:\n";
    printSTART(StartState); //εκτύπωση αρχικής κατάστασης
    cout << "\nENDING STATE OF ACCOUNTS:\n";
    printEND(iptr); //εκτύπωση τελικής κατάστασης
    iptr.close();   //κλείσιμο pointer file
}   //κλίνει η συνάρτηση input()
//συνάρτηση διαβάσματος πληροφοριών:
int Manage::getInfo(float* purch, Account* data, fstream& iptr) {
    while (true){
        cout << "\n(to exit input a Negative Num.)\n"    //}
             << "(Acc. Num. must be a multiple of 50)\n" //}
             << "ENTER ACCOUNT NUMBER: \n";              //} printf
        cin >> data->accnum;        //διάβασμα λογαριασμού χρήστη   
        if (data->accnum <0){   //αν Acc. Num. Αρνητικό τότε σταμάτα
            cout << "\nNEGATIVE ACCOUNT NUMBER ENTERED, CLOSING PROGRAM.\n";
            return -1;  //επισρέφει αρν. Αριθμό για έξοδο προγράμματος
        }
        if (data->accnum % 50 != 0){ //περίπτωση π εν ειναι πολ/σιο του 50
            cout << "ACCOUNT NUMBERS MUST BE MULTIPLES OF 50.\n";
            continue;   //restart while loop
        }
        break;  //έξοδος while loop
    }
    cout << "\nENTER AMOUNT OF PURCHASE: ";
    cin >> *purch;  //διάβασμα αγοράς
    while (*purch < 0){ //αν αγορά υπό το 0, ξαναζήτα 
        cout << "\nINVALID PURCHASE AMOUNT, RE-ENTER PURCHASE\n";
        cin >> *purch;
    }
    return seek(data, iptr); //επέστρεψε το αποτέλεσμα του seek (αν το βρεί)
}  //κλείσιμο συνάρτησης getinfo()
//ψάχνει γαι given accnum
int Manage::seek(Account* data, fstream& iptr){
    Account temp;
    iptr.seekg(((data->accnum/50)-1) * sizeof(Account), ios::beg);
    data->readFromFile(iptr);  //κληση read function
    if (!temp.readFromFile(iptr))   //αν δεν το βρεί
        return 0;  // Αccount not found
    if (temp.accnum == data->accnum){   //αν το βρήκε
        *data = temp;    //μεταφορά & Αποθήκευση δεδομένων
        return 1;   //Account found 
    }
    return 0;   //Αccount not found
}      //κλείσιμο συνάρτησης seek()
//συνάρτηση νέου πελάτη:
void Manage::newCust(fstream& iptr, Account* data, float* purch) {
    cout << "\nENTER CUSTOMER NAME:";
    getline(cin,data->custname);    //διάβασμα custname
    cout << "\nENTER CUSTOMER CREDIT LIMIT:";
    cin >> data->crlimit;   //διάβασμα credit limit
    while (data->crlimit <= 0){ //αν όριο credit υπό το 0, ξαναζήτα τo
        cout << "\nINVALID CREDIT LIMIT, RE-ENTER\n";
        cin >> data->crlimit;
    }
    data->balance = 0;  //αρχικοποίση balance = 0
    iptr.seekp((data->accnum / 50 - 1) * sizeof(Account), ios::beg);//θεση * bytes = offset
    data->writeToFile(iptr);    //αποθήκευση δεδομένων νέου χρήστη
}
//συνάρτηση ελέγχου & ενημέρωσης δεδομένων χρηστών:
int Manage::check(fstream& iptr, Account* data, float purch){
    if ((data->balance + purch) <= data->crlimit){ //αν balance + αγορά < Credit Limit τότε:
        data->updateBalance(purch); //προσθέτει την Αγορά στη μεταβλητή balance
        iptr.seekp((data->accnum/50-1)*sizeof(Account), ios::beg); //ανιχνέυει το λογαριασμό
        data->writeToFile(iptr);    //ανανεώνει τo balnace
        cout << "\nDEAR " << data->custname << ",\nTHANK YOU FOR THE BUSINESS.\n";
        return 1;    // επιτυχές αγορά
    } else {
        cout << "\nDEAR " << data->custname 
             <<",\nWE CANNOT AUTHORIZE THIS PURCHASE AT THIS TIME AS IT"
             << "\n WOULD PUT YOU " << (data->balance + purch - data->crlimit) 
             << " euro OVER YOUR CREDIT LIMIT.\n";
        return 0;   //υπερβαίνει το Credit Limit
    }
}       //κλείσιμο συνάρτησης check()
//συνάρτηση εκτύπωσης τελικών στοιχείων:
void Manage::printEND(fstream& iptr) {
    Account EndSt;
    bool found = false; 
    iptr.clear();   //επαναπροσδιορισμός δείκτη
    iptr.seekg(0, ios::beg);
    cout << "\nEXISTING ACCOUNTS IN THE SYSTEM:\n";
    cout << "=========================================\n";
    printf("%-20s%-14s%-12s%-12s\n","Name:","Account #:","Balance:","Credit Limit:");
    cout << "=========================================\n";
    while (EndSt.readFromFile(iptr)){   //διάβασμα στοιχείων θέσης
        if (EndSt.accnum != 0) {    //έλεγχος αν υπάρχουν στοιχεία σε αυτη την θέση
            cout << left << setw(20) << EndSt.custname
                 << setw(14) << EndSt.accnum
                 << setw(12) << fixed << setprecision(2) << EndSt.balance
                 << setw(12) << EndSt.crlimit << '\n';
            found = true;
        }
    }
    if (!found)     //αν η λίστα είναι άδεια, τοτε
        cout << "No accounts exist in the system.\n";
    else
        cout << "=========================================\n";
}   //κλείσιμο συνάρτησης printEND()
//συνάρτηση εκτύπωσης αρχικών στοιχείων:
void Manage::printSTART(Account StartSt[]) {
    bool found = false;
    cout << "=========================================\n";
    printf("%-20s%-14s%-12s%-12s\n","Name:","Account #:","Balance:","Credit Limit:");
    cout << "=========================================\n";
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (StartSt[i].accnum != 0){    //έλεχγος αν υπάρχει
            cout << left << setw(20) << StartSt[i].custname
                 << setw(14) << StartSt[i].accnum
                 << setw(12) << fixed << setprecision(2) << StartSt[i].balance
                 << setw(12) << StartSt[i].crlimit << '\n';
            found = true;
        }
    }
    if (!found){    //αν η λίστα είναι άδεια
        cout << "No accounts exist in the system.\n";
    } else {
        cout << "=========================================\n";
    }
}   //κλείσιμο συνάρτησης printSTART()

