#include <iostream>
#define N 26
using namespace std;

class symetrikos{
    private:
        int cit, cities[N][N];
        bool isSymetric = true;
        int cord_i,cord_j;

    public:
        symetrikos(){
            cout<<"give number of cities"<< endl;
            cin>> cit;
            while (cit>26 || cit<1){
                cout<<"Wrong number of cities, Enter again\n";
                cin>>cit;
            }
            cout<<"Now Enter the KM between each city!\n";
            for (int i=0;i<cit;i++){
                for (int j=0;j<cit;j++){
                    cin>>cities[i][j];
                    while (cities[i][j]>999 || cities[i][j]<0){
                        cout<<"Wrong number of KM, Enter again\n";
                        cin>>cities[i][j];
                    }
                }
            }
        }
        void checkdiag(){
            for (int i=0;i<cit;i++){
                for (int j=0;j<cit;j++){
                    if (i==j && cities[i][j]!=0){
                        cord_i=i;
                        cord_j=j;
                        isSymetric=false;
                    }
                }
            }
        }
        void checkAtoB(){
            for (int i=0;i<cit;i++){
                for (int j=0;j<cit;j++){
                    if (cities[i][j]!=cities[j][i]){
                        cord_i=i;
                        cord_j=j;
                        isSymetric=false;
                    }
                }
            }
        }
        void final(){
            if (isSymetric)
                cout<<"Mileage Chart Checks OK\n"<<endl;
            else
                cout<<"Mileage Chart In Error, First Error in Row:"<<cord_i <<"& Column:"<<cord_j<<endl;

        }
};

int main(){
    symetrikos ex1;
    ex1.checkdiag();
    ex1.checkAtoB();
    ex1.final();
    return 0;
}