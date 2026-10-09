#ifndef MANAGE_H
#define MANAGE_H
#include "Account.h" //include account class
#include <fstream>
using namespace std;
class Manage { //δηλωση class
    private:
        static const int MAX_ACCOUNTS = 200;  //max
        Account accounts[MAX_ACCOUNTS];
    public:    //εξήγηση στο implementation
        void createList();
        void input();
        int getInfo(float *purch, Account *data, fstream &iptr);
        int seek(Account *data, fstream &iptr);
        void newCust(fstream &iptr, Account *data, float *purch);
        int check(fstream &iptr, Account *data, float purch);
        void printEND(fstream &iptr);
        void printSTART(Account StartSt[]);
};
#endif
