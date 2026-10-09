#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int count, num, pl=0, space=0;
    for (count=2; count<10000; count++){
        pl=0;
        for (num=1; num<=count; num++){
            if ((count%num)==0)
                pl++;
        }    
    if (pl==2){
        cout<<count<<"\t";
        space++;
    }
    if (space==10){
        cout<<endl;
        space=0;
        }
    }
    return 0;
}