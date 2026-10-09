#include <iostream>
#define N 50
using namespace std;

void mover( int list[], int length,int  item, int plh, int cnt);

int main (){
    int list[N], item, placeholder, counter=0,length;
    cout<<"Enter Length"<<endl;
    cin>>length;
    cout<<"Enter List"<<endl;
    for(int i=0;i<length;i++)
        cin>>list[i];
    cout<<"item:";  
    cin>>item;
    cout<<"item: "<<item<<endl<<" Prin: Length:"<<length<<endl<<" List:";
    for(int i=0;i<length;i++){
        cout<<list[i]<<" ";
        if (list[i]==item){
            if(counter==0)
                placeholder = i;
            counter++;
        }
    }
    cout<<endl;
    mover(list, length, item, placeholder, counter);

    cout<<" Meta: Length:"<<length-counter<<endl<<" List:";
    for(int i=0;i<length-counter;i++)
        cout<<list[i]<<" ";
    return 0;
}

void mover(int list[], int length,int  item, int plh, int cnt){
    int tmp;
    while(list[length-1]!=item){
        for (int i=plh; i<length-cnt; i++){
            tmp=list[i];
            list[i]=list[i+cnt];
            list[i+cnt]=tmp;
        }
    }
}