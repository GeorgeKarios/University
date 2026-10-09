#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "ClientData.cpp"

int main()
{
    int accountNumber;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
    fstream outCredit( "credit.dat", ios::in | ios::out | ios::binary );

    if ( !outCredit )
    {
        cerr << "File could not be opened." << endl;
        exit( 1 );
    }

    cout << "Enter account number (1 to 100, 0 to end input)\n? ";
    ClientData client;
    cin >> accountNumber;

    while ( accountNumber > 0 && accountNumber <= 100 )
    {
        cout << "Enter lastname, firstname, balance\n? ";
        cin >> setw( 15 ) >> lastName;
        cin >> setw( 10 ) >> firstName;
        cin >> balance;

        client.setAccountNumber( accountNumber );
        client.setLastName( lastName );
        client.setFirstName( firstName );
        client.setBalance( balance );

        outCredit.seekp( ( client.getAccountNumber() - 1 ) * sizeof( ClientData ) );
        outCredit.write( reinterpret_cast< const char * >( &client ),
                         sizeof( ClientData ) );

        cout << "Enter account number\n? ";
        cin >> accountNumber;
    }

    return 0;
}
