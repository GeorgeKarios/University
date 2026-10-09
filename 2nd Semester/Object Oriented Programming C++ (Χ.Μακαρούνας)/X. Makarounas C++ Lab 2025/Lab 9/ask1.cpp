#include <iostream>
#include <cstring>
using namespace std;
//Encrypted string is: unjtj!fb!ttsdfu
//Decrypted string is: this is a secret!

void encrypt(char e[]);
void decrypt(char *ePtr);

int main(){
    char string[] = "this is a secret!";
    encrypt(string);
    cout<<"Encrypted string is: "<<string<<"\n";
    decrypt(string);
    cout<<"Decrypted string is: "<<string<<endl;
    return 0;
}

void encrypt(char e[]){
    for (int i =0; i< strlen(e); i++){
        e[i] = e[i]+1;   
    }
}

void decrypt(char *ePtr) {
    for (int i =0; i< strlen(ePtr); i++){
        ePtr[i]= ePtr[i]-1;
    }
}