#include "Manage.cpp" //include implementation
using namespace std;
int main(){
    int choice;
    cout << "\nEnter your choice:\n" "1 - Create a blank list\n" 
                                     "2 - Insert Data\n";
    cin >> choice;
    Manage manage;  //δημιοθργία object
    switch (choice){    //επιλογή menu
    case 1:
        manage.createList();    //κλήση συνάρτησης createlist()
        cout << "\nDo you want to insert data now? (Y or N): ";
        char mr;
        cin >> mr;
        if (mr == 'Y' || mr == 'y')
            manage.input(); //πιθανή κλήση συνάρτησης input()
        break;
    case 2:
        manage.input(); //κλήση συνάρτησης input()
        break;
    default:    //για μή έγκυρη απάντηση
        cout << "INVALID CHOICE CLOSING PROGRAM\n";
        break;
    }
    return 0;
}   //κλείσιμο της main

