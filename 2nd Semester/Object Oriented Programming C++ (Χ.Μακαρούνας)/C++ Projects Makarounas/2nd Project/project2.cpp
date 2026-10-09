#include<iostream>
#include<string>
#include <cctype> //για καποια functions
#include <vector>
#define N 50
using namespace std;
string cleaned_st="", key, encrypted_og="", encrypted_order;
char starting_table[N][N], reorder_table[N][N];
char grid[5][5]={{'A', 'B', 'C', 'D', 'E'}, //grid Αλφαβήτου
                 {'F', 'G', 'H', 'I', 'J'},
                 {'K', 'L', 'M', 'N', 'O'},
                 {'P', 'Q', 'R', 'S', 'T'},
                 {'U', 'V', 'W', 'X', 'Y'}};
int rowSize, colSize, choice;
// Π΄ρώτυπα Συναρτήσεων:
void decrypt();
void reverse_to_original_order();
void fill_reorder_table();
void get_sorted_positions(string &sorted_key, int positions[]);
void to_alphabet();
void encrypt();
void place();
void read_starting();
void read_encrypted();
void read_key();
void print_table(char table[][N], string st);
void calc_rowsize_colsize();

int main() {
    cout<<"*******************************\n"
        "* Encryption/Decryption System *\n"
        "*******************************\n"
        "1. Code the message\n"
        "2. Decode the message\n"
        "3. Exit\n"
        "Make your choice: ";
    cin>>choice; //εισαγωγή επιλογής
    cin.ignore(); //για να αγνοεί το \n οταν μπαίνει το choice
    if (choice==1){
        read_starting(); //Διάβασε Αρχική Γραμματοσειρά
        read_key();      //Διάβασε Λέξη Κλειδί
        encrypt();       //Κρυπτογράφηση Φράσης
        place();         //Τοποθέτηση σε πίνακα
        to_alphabet();   //Ανασυγκρώτηση βάση Αλφαβήτου
    }
    else if (choice==2){
        read_encrypted(); //Διάβασε Ciphertext
        read_key();       //Διάβασε Λέξη Κλειδί
        fill_reorder_table(); //Γέμισμα 2Δ Πίνακα ανα στήλη
        reverse_to_original_order(); //Ανασυγκρώτηση βάση Κλειδιού
        decrypt();        //Αποκρυπτογράφηση Φράσης
    }
    return 0;
}
// Συνάρτηση έυρεσης ορίων 2D Πινάκων:
void calc_rowsize_colsize(){
    colSize= key.size(); //αριθμός στηλών
    if (choice==2){ 
        int digits=0; //αριθμός ψηφίων
        for (int i=0; i<encrypted_order.size(); i++)
            if (isdigit(encrypted_order[i]))
                digits++; //α΄υξηση αρθμού ψηφίων
        rowSize = digits/colSize+2; //αριθμός γραμμών
    } else if (choice==1)
        rowSize = (cleaned_st.size()*2/colSize)+2;
}
// Συνάρτηση Αποκρυπτογράφησης Φράσης:
void decrypt(){
    vector<char> starting_1d; //δήλωση vector Array για να μπει
    for (int i = 0; i < rowSize; i++){ //το 2D Array σε μία σειρά
        for (int j = 0; j < colSize; j++) {
            if (isdigit(starting_table[i][j]))  
                starting_1d.push_back(starting_table[i][j]);
        }
    }
    for (int i=0; i+1<starting_1d.size(); i+=2){ //διάβασμα Ζευγαριών 
        //πρόσθεση χαρακτήρων στην Αποκρυπτογράφημένη Φράση:
        cleaned_st += grid[starting_1d.at(i)-'0'][starting_1d.at(i+1)-'0'];
    }
    cout<<endl<<"Decoded Message is:"<<endl<<cleaned_st;
}
// Συνάρτηση Ανασυγκρώτησης βάση Κλειδιού για Decryprion:
void reverse_to_original_order(){
    string sorted_key = key;
    int positions[colSize]; //πίνακας με θέσεις ανασυγκρώτησης
    get_sorted_positions(sorted_key, positions); //κλ΄ήση συνάρτησης
    print_table(reorder_table, sorted_key); //εκτ΄ύπωση αρχικού 2D πίνακα
    for (int oldCol = 0; oldCol < colSize; oldCol++){  
        int newCol = positions[oldCol];  //αποθήκευση νέας θέσης στήλης
        for (int row = 0; row < rowSize; row++)
            //αποθήκευση Ανασυγκρώτημένων Στηλών σε άλλο 2D Array
            starting_table[row][newCol] = reorder_table[row][oldCol];  
    }
    print_table(starting_table, key); //εκτ΄ύπωση Ανασυγκρωτημένου 2D Array
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << starting_table[i][j]; //εκτ΄ύπωση Ψηφίων σε σειρά
        }
    }
    cout << endl;
}
// Συνάρτηση γεμίζει τον πίνακα ανα στήλη:
void fill_reorder_table(){ 
    int index = 0;
    for (int j = 0; j < colSize; j++){  
        int rowIndex = 0; //μηδενισμός για να πάει στην πρώτη γραμμή 
        for (int i = 0; i < rowSize; i++){  
            if (index < encrypted_order.size()){ 
                if(encrypted_order[index]!= ' ') //οταν δέν έχει space
                    //αποθήκευση string: encrypted_order σε 2D Array
                    reorder_table[rowIndex++][j] = encrypted_order[index];
            }
            index++; //αύξηση Subscript
        }
    }    
}
//Συνάρτηση Αλφαβιτικής σειράς με Selection Sort
void get_sorted_positions(string &sorted_key, int positions[]){ 
    for (int i = 0; i < colSize; i++) 
        positions[i] = i; //αρχικοποίηση σε original
    //Selection Sort στο key και κράτηση των νέων θέσεων
    for (int i = 0; i < colSize - 1; i++) {
        for (int j = i + 1; j < colSize; j++){
            if (sorted_key[i] > sorted_key[j]){  
                //ανταλλαγή χαρακτ΄΄ηρων
                char temp = sorted_key[i];
                sorted_key[i] = sorted_key[j];
                sorted_key[j] = temp;
                //αποθήκευση νέων θέσεων
                int tempINDEX = positions[i];
                positions[i] = positions[j];
                positions[j] = tempINDEX;
            }
        }
    }
}
// Συνάρτηση Ανασυγκρώτησης βάση Αλφαβήτου για Encryprion:
void to_alphabet(){ 
    string key_copy=key;  
    int positions[colSize];
    get_sorted_positions(key_copy, positions); //απόκτηση αλφαβητ. σειράς
    //Reorder τις στήλες βάση τις θέσεις του positions
    for (int newCol = 0; newCol < colSize; newCol++) {
        int oldCol = positions[newCol]; //παίρνει αρχική θέση της στήλης
        for (int row = 0; row < rowSize; row++)
            //αποθήκευση σε ανασυγκρωτημένο 2D Array
            reorder_table[row][newCol] = starting_table[row][oldCol];  
    }    
    print_table(reorder_table, key_copy); //εκτ΄ύπωση Ανασυγκρωτημ. 2D Array
    cout<<endl<<"Encoded Message is:"<<endl; 
    for (int j=0; j<colSize; j++){
        for (int i=0; i<rowSize; i++)
            cout<<reorder_table[i][j]; //εκτ΄ύπωση Ciphertext σε σειρά
        cout<<" ";
    }
}
//Συνάρτηση Αρχικής Δημιουργίας Κρυπτογραφημένης Γραμματοσειράς:
void encrypt(){
    for (int k = 0; k < cleaned_st.size(); k++) { //loop εντος του cleaned_st
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                //αν τα γράμματα συμπίπτουν με καποιο στοιχείο του grid:
                if (toupper(cleaned_st[k]) == grid[i][j]){
                    //πρόσθεσε τους αριθμους του Subscript:
                    encrypted_og += to_string(i) + to_string(j);
                    break;  
                }
            }
        }
    }
    cout<<endl<<cleaned_st<<endl;
    cout<<encrypted_og<<endl<<endl;
}
//Συνάρτηση Τοποθέτησης σε 2D Array: starting_table για Encryption:
void place(){
    int temp = encrypted_og.size()/key.size()+1;
    int i=0;
    for (int k=0; k<temp; k++){ 
        for (int j=0; j<key.size(); j++){
            if (i < encrypted_og.size()){ //Έλεγχος Ορίων
                starting_table[k][j] = encrypted_og[i]; //αποθήκευση
                i++; //increment το i για Subscript
            } else
                starting_table[k][j] = ' '; //Αν εείναι εκτός ορίων
        }
    }
    print_table(starting_table, key); //εκτ΄ύπωση Αρχικού 2D Array
}
//Συνάρτηση Διαβάσματος Μυνήματος για Κρυπτογράφηση:
void read_starting(){ 
     cout<<"Please Enter your Message:";
     string starting_st;
     getline(cin, starting_st); //read μεχρι ENTER
     for (int i = 0; i < starting_st.size(); i++){
        if (isalpha(starting_st[i])) //αν ειναι γράμμα
            cleaned_st += starting_st[i]; //Πρόσθεση ΜΟΝΟ χαρακτήρων σε string
    }
}
//Συνάρτηση Διαβάσματος Ciphertext για Αποκρυπτογράφηση:
void read_encrypted(){
    cout<<"Please Enter your Encrypted Message: ";
    getline(cin, encrypted_order);
    for (int i=0; i<encrypted_order.size(); i++){
        if (!isdigit(encrypted_order[i]) && encrypted_order[i]!=' '){
            read_encrypted(); //Αναδρομή
            return;
        }
    }
}
//Συνάρτηση Διαβάσματος Key: Encryption & Decryprion
void read_key(){
     cout<<"Please Enter your Keyword: ";
     getline(cin, key); //read μεχρι ENTER
     for (int i = 0; i < key.size(); i++){
        if (!isalpha(key[i]) ){ //Αν char είναι: Ψηφίο/Σύμβολο
            read_key(); //RECURSION μέχρι να είναι VALID
            return;
        }
        for (int j = i + 1; j < key.size(); j++){
            if (key[i] == key[j]) { //Αν char βρεθεί 2 φορές
                read_key(); //RECURSION μέχρι να είναι VALID
                return;
            }
        }
    }
    calc_rowsize_colsize(); //δημιουργία σταθερών ορίων 2D Πινάκων
}
//Συνάρτηση Εκτύπωσης 2D Πινάκων & Key:
void print_table(char table[][N], string st){
    for(int i=0;i<st.size(); i++)
        cout<<st[i]<<" "; //εκτύπωση KEY
    cout <<endl;
    for (int i = 0; i < rowSize; i++){  //Nested For Loop
        for (int j = 0; j <st.size(); j++){  
            if (table[i][j] == '\0')
                cout << "  ";
            else
                cout << table[i][j] << " "; //Εκτύπωση 2D Πίνακα
        }
        cout<<endl;  
    }
    cout<<endl;
}