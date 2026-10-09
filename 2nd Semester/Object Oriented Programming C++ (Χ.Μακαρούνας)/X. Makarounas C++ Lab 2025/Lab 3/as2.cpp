#include <iostream>
#include <iomanip>
#define N 50
using namespace std;

void swap(int arr[],int len){
    float fix[N];
    fix[0]=arr[0];
    fix[len-1]=arr[len-1];
    for (int i=1; i<len-1; i++)
        fix[i]=((arr[i-1]+arr[i]+arr[i+1])/3.0);
    for (int i=0; i<len; i++)
        cout<<fixed<<setprecision(2)<<fix[i]<<" ";
}

int main(){
    int arr[N], length;
    cout<<"Enter Length"<<endl;
    cin>> length;
    cout<<"Enter Array"<<endl;
    for(int i=0;i<length;i++)
        cin>>arr[i];
    swap(arr,length);
    return 0;
}