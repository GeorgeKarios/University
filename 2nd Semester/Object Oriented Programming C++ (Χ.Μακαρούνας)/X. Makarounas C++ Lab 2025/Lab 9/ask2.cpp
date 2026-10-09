#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//Encrypted string is: unjtj!fb!ttsdfu
//Decrypted string is: this is a secret!

void encrypt(string &e);

int main(){
    bool flag = false;
    string str1, clean1, str2, clean2;
    while (!flag){
        cout<< "Enter your Password:";
        cin>> str1;
        while (str1.size()>25){
            cout<< "Your Password is bigger than 25 chars, put it again";
            cin>>str1;
        }
        if (str1.size() > 10) 
            clean1 = str1.substr(0, 10);
        else 
            clean1 = str1;
        //phase 2
        cout<< "Re-Enter your Password:";
        cin>> str2;
        while (str2.size()>25){
            cout<< "Your Password is bigger than 25 chars, put it again";
            cin>>str2;
        }
        if (str2.size() > 10) 
        clean2 = str2.substr(0, 10);
    else 
        clean2 = str2;
        
        if (clean1 == clean2)
            flag = true;
    }
    encrypt(clean1);
    cout<<"your Encrypted password is: "<<clean1<<"\n";
    return 0;
}

void encrypt(string &e){
    for (int i =0; i< e.size(); i++){
        e[i] = e[i]+1;   
    }
}