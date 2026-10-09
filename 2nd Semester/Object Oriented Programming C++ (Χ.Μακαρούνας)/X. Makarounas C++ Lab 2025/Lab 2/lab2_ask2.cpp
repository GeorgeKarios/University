#include<iostream>
using namespace std;

void reversed(int num){
    cout<<num%10;
    if (num/10!=0)
        reversed(num/10);
}
int main(){
    int num;
    cout<<"input an integer number"<<endl;
    cin>>num;
    reversed(num);
    return 0;
}