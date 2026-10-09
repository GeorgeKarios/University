#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include "ClientData.cpp"

int main()
{
    ofstream outCredit( "credit.dat", ios::binary );

    if ( !outCredit )
    {
        cerr << "File could not be opened." << endl;
        exit( 1 );
    }
    else 
        cout<<"file created"<<endl;

    ClientData blankClient;

    for ( int i = 0; i < 100; i++ )
        outCredit.write( reinterpret_cast< const char * >( &blankClient ),
                         sizeof( ClientData ) );

    return 0;
}
