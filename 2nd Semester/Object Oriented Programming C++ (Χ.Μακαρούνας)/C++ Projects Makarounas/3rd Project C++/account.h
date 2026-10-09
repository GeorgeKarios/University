#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
class Account{
    public:
        int accnum;       //Account number
        string custname;  //Customer name
        float balance;    //current balance
        float crlimit;    //Credit limit
        //Constructor:
        Account(int accNum = 0, const string& name = "", float bal = 0.0, float limit = 0.0){
            accnum = accNum;
            custname = name;
            balance = bal;
            crlimit = limit;
        }
        //Συναρτηση για ενημερωση account balance
        void updateBalance(float amount){
            balance += amount;
        }
        //Συνάρτηση που ελέγχει τα ονόματα
        bool validateName(const string& enteredName){
            return custname == enteredName;
        }
        //Συναρτηση που γράφει σε αρχέιο (γτ εχει strings)
        void writeToFile(fstream& DeiktisFile) const {
            int len = custname.length();
            DeiktisFile.write(reinterpret_cast<const char*>(&accnum), sizeof(accnum));
            DeiktisFile.write(reinterpret_cast<const char*>(&balance), sizeof(balance));
            DeiktisFile.write(reinterpret_cast<const char*>(&crlimit), sizeof(crlimit));
            DeiktisFile.write(reinterpret_cast<const char*>(&len), sizeof(len));
            DeiktisFile.write(custname.c_str(), len);
        }
        //Συναρτηση που διαβάζει απο αρχέιο (γτ εχει strings)
        bool readFromFile(fstream& DeiktisFile) {
            int len;
            if (!DeiktisFile.read(reinterpret_cast<char*>(&accnum), sizeof(accnum))) return false;
            if (!DeiktisFile.read(reinterpret_cast<char*>(&balance), sizeof(balance))) return false;
            if (!DeiktisFile.read(reinterpret_cast<char*>(&crlimit), sizeof(crlimit))) return false;
            if (!DeiktisFile.read(reinterpret_cast<char*>(&len), sizeof(len))) return false;
            char* buffer = new char[len + 1];
            if (!DeiktisFile.read(buffer, len)) {
                delete[] buffer;
                return false;
            }
            buffer[len] = '\0'; 
            custname = buffer;
            return true;
        }
};
#endif
