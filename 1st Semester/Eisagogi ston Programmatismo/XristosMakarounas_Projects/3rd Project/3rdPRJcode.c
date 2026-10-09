#include <stdio.h>
#define MAX_ACCOUNTS 200
struct ACCT {             //32 bytes
    int   accnum;           //αριθμός λογαριασμού
    char  custname[20];     // ονομα πελάτη
    float balance;          //χρήματα που χρησιμοποίησε
    float crlimit;          //χρηματικό όριο
};                   
void createlist();
void input();
int getinfo(float *, struct ACCT *, FILE *);
int seek(struct ACCT *, FILE *);
void newcust(FILE *, struct ACCT *, float *);
int check(FILE *, struct ACCT *, float);
void printEND(FILE *);
void printSTART(struct ACCT StartSt[]);

int main(){
    int choice;
    printf("\nEnter your choice:\n" "1 - Create a blank list\n" 
                                    "2 - Insert Data\n" );
    scanf("%d", &choice);
    switch (choice) {               //επιλογή menu
        case 1:
            createlist();           //κλήση συνάρτησης createlist()
            printf("\nDo you want to insert data now? (Y or N): ");
            char mr;
            scanf(" %c", &mr);
            if (mr == 'Y' || mr == 'y')
                input();            //πιθανή κλήση συνάρτησης input()
            break;
        case 2:
            input();          //κλήση συνάρτησης input()
            break;
        default:            //μή έγκυρη απάντηση
            printf("INVALID CHOICE CLOSING PROGRAM\n");    
        }
return 0;
}           //κλείσιμο της main

void createlist(){                            //δημιουργία Κενής Λίστας
    struct ACCT blankfill = {0,"",0.0,0.0};   //αρχικοποίηση
    int i;
    FILE *wptr;
    if ((wptr = fopen("system1.txt", "w"))==NULL)        //δημιουργία txt file ως w
        printf("File could not be created\n");
    else {
        for (i=0;i<MAX_ACCOUNTS;i++)                          //} συμπλήρωση 
            fwrite(&blankfill, sizeof(struct ACCT), 1, wptr); //} κενής λίστας
        fclose(wptr);                                         // κλείσιμο file
        printf("Blank Binary List Created.\n");
    }       //κλίνει το else
}           //κλίνει συνάρτηση createlist()

void input() {                //βασική Συνάρτηση Προγράμματος
    FILE *iptr;
    char ans, enteredName[20];
    float purch;
    struct ACCT data, StartState[MAX_ACCOUNTS];
    int isnew=0;
    if ((iptr = fopen("system1.txt", "r+")) == NULL) { //ανοίγει file ως r+
        printf("File could not be opened\n");
        return;      //στην περίπτωση που δεν ανοίγει κλίνει το πρόγραμμα 
    }
    fread(StartState, sizeof(struct ACCT), MAX_ACCOUNTS, iptr); 
    //διαβάζει ολα τα δεδομένα & τα αποθηκευει σε array 
    while (1){ 
        int accountExists = getinfo(&purch, &data, iptr); //κλήση getinfo()
        if (accountExists == -1)  //περίπτωση τερματισμού
            break;
        if (!accountExists) {  //περίπτωση accountExists=0
            printf("\nIS THIS A NEW ACCOUNT NUMBER? (Y OR N):");           
            scanf(" %c", &ans );           //διάβασμα απάντησης
            if (ans == 'N' || ans == 'n'){ //if ans="No" then asks again
                printf("\nINVALID ACCOUNT NUMBER, RE-ENTER DATA:");
                continue;
            }
            else if (ans == 'Y' || ans == 'y'){ //if ans="Yes" then adds the customer
                newcust(iptr, &data, &purch); //κλήση newcust()
                isnew=1;   //είναι καινούργιος = true
            }
        }
        if (!isnew){ //περίπτωση που δεν είναι καινούργιος
            printf("\nENTER CUSTOMER NAME TO AUTHENTICATE: ");
            scanf(" %[^\n]s", enteredName);   // %[^\n]s διαβάζει μέχρι να βρεί ENTER
            int i, same=1;   //same->μεταβλητή επαλήθευσης
            for (i = 0; i < 20; i++) {         
                if (enteredName[i] != data.custname[i]) { // σύγκριση ονόματος
                    same = 0;    //έστω ενας χαρακτήρας δεν είναι ίδιος, 
                    break;                              //the loop breaks
                }
                if (data.custname[i] == '\0') //οταν βρεις το τέλος του string σταματα
                    break;                    //για να μήν πάει μετά το μέγεθος της
            }
            if (!same) {   //όταν δεν επαληθευτεί
                printf("\nACCOUNT NUMBER & CUSTOMER NAME DO NOT MATCH, RE-ENTER DATA:");
                continue;  //restart while loop 
            }
            printf("\nAuthentication successful! Welcome back, %s.\n", data.custname);
        }
        check(iptr, &data, purch); // έλεγχος (purch)
        isnew = 0;  //reset the flag
    }  //κλίνει το while
    printf("\nSTARTING STATE OF ACCOUNTS:\n");
    printSTART(StartState);     //εκτύπωση αρχικής κατάστασης
    printf("\nENDING STATE OF ACCOUNTS:\n");
    printEND(iptr);     //εκτύπωση τελικής κατάστασης
    fclose(iptr);       //κλείσιμο file r+
}   //κλίνει η συνάρτηση input()

//συνάρτηση διαβάσματος πληροφοριών
int getinfo(float *purch, struct ACCT *data, FILE *iptr){  
    while (1){
        printf("\n(to exit input a Negative Num.)"       // }
               "\n(Acc. Num. must be a multiple of 50)"  // }
               "\n ENTER ACCOUNT NUMBER: \n ");          // } printf
        scanf("%d", &data->accnum);  //διάβασμα λογαριασμού χρήστη
        if (data->accnum <0){        //αν Acc. Num. Αρνητικό τότε σταμάτα
            printf("\nNEGATIVE ACCOUNT NUMBER ENTERED, CLOSING PROGRAM.\n");
            return -1;  // επισρέφει αρν. Αριθμό για έξοδο προγράμματος
        }
        if (data->accnum % 50 != 0){    //περίπτωση που δεν ειναι πολλ/σιο του 50
            printf("ACCOUNT NUMBERS MUST BE MULTIPLES OF 50.\n");
            continue;     //restart while loop
        }
        break;          //έξοδος while loop
    }
    printf("\nENTER AMOUNT OF PURCHASE: ");
    scanf("%f", purch );        //διάβασμα αγοράς
    while (*purch < 0){        //αν αγορά υπό το 0, ξαναζήτα την
        printf("\nINVALID PURCHASE AMOUNT, RE-ENTER PURCHASE\n");
        scanf("%f", purch);             
    }
    return seek(data, iptr);  //επέστρεψε το αποτέλεσμα του seek (αν το βρεί)
}       //κλείσιμο συνάρτησης getinfo()
int seek(struct ACCT *data, FILE *iptr){  //ψάχνει γαι given accnum
    struct ACCT temp;
    fseek(iptr,((data->accnum/50)-1) * sizeof(struct ACCT), SEEK_SET);
    if(fread(&temp, sizeof(struct ACCT), 1, iptr)!=1) //αν δεν το βρεί
        return 0;                                     // Αccount not found
    if (temp.accnum == data->accnum){   //αν το βρήκε
        *data = temp;                   //μεταφορά & Αποθήκευση δεδομένων
        return 1; //Account found 
    }
    return 0; //Αccount not found
}           //κλείσιμο συνάρτησης seek()

void newcust(FILE *iptr, struct ACCT *data, float *purch ){  //συνάρτηση νέου πελάτη
    printf("\nENTER CUSTOMER NAME:");
    scanf(" %[^\n]s", data->custname);         // [^\n] διαβάζει ονομα μεχρι ENTER
    printf("\nENTER CUSTOMER CREDIT LIMIT:");
    scanf(" %f", &data->crlimit);               //διάβασμα credit limit
    while (data->crlimit <= 0){        //αν όριο credit υπό το 0, ξαναζήτα τo
        printf("\nINVALID CEDIT LIMIT, RE-ENTER\n");
        scanf("%f", &data->crlimit); 
    }
    data->balance = 0;                          //αρχικοποίση balance = 0
    fseek(iptr,((data->accnum/50)-1) * sizeof(struct ACCT), SEEK_SET); //θεση * 32bytes = offset
    fwrite(data, sizeof(struct ACCT), 1, iptr);      //αποθήκευση δεδομένων νέου χρήστη
}           //κλείσιμο συνάρτησης newcust()

int check(FILE *iptr, struct ACCT *data, float purch){ //συνάρτηση ελέγχου & ενημέρωσης δεδομένων χρηστών   
    if ((data->balance + purch) <= data->crlimit) {      //αν balance + αγορά < Credit Limit τότε:
        data->balance += purch;                          //προσθέτει την Αγορά στη μεταβλητή balance      
        fseek(iptr, ((data->accnum / 50) - 1) * sizeof(struct ACCT), SEEK_SET); //ανιχνέυει το λογαριασμό
        fwrite(data, sizeof(struct ACCT), 1, iptr);                            // ανανεώνει τo balnace
        printf("\nDEAR %s,\nTHANK YOU FOR THE BUSINESS.\n", data->custname);
        return 1;                                                              // επιτυχές αγορά
    }
    else {
        printf("\nDEAR %s,\nWE CANNOT AUTHORIZE THIS PURCHASE AT THIS TIME AS IT"//}
               "\n WOULD PUT YOU %.2f euro OVER YOUR CREDIT LIMIT.\n",           //}
                data->custname, (data->balance + purch - data->crlimit));        //} printf
        return 0;   //υπερβαίνει το Credit Limit
    }
}           //κλείσιμο συνάρτησης check()
   
void printEND(FILE *iptr){    //συνάρτηση εκτύπωσης τελικών στοιχείων
    struct ACCT EndSt;
    int found=0;         
    rewind(iptr);            //επαναπροσδιορισμός δείκτη
    printf("\nEXISTING ACCOUNTS IN THE SYSTEM:\n");
    printf("=========================================\n");
    printf("%-20s%-14s%-12s%-12s\n",
           "Name:", "Account #:", "Balance:", "Credit Limit:");
    printf("=========================================\n");
    while (fread(&EndSt, sizeof(struct ACCT), 1, iptr)) {  //διάβασμα στοιχείων θέσης
        if (EndSt.accnum != 0) {             //έλεγχος αν υπάρχουν στοιχεία σε αυτη την θέση
            printf("%-20s%-14d%-12.2f%-12.2f\n",                                //}
                   EndSt.custname, EndSt.accnum, EndSt.balance, EndSt.crlimit); //} printf
            found = 1;
        }
    }
    if (!found)       //αν η λίστα είναι άδεια
        printf("No accounts exist in the system.\n");
    else
        printf("=========================================\n");
}       //κλείσιμο συνάρτησης printEND()

void printSTART(struct ACCT StartSt[]){    //συνάρτηση εκτύπωσης αρχικών στοιχείων
    int found=0, i;
    printf("=========================================\n");
    printf("%-20s%-14s%-12s%-12s\n", 
           "Name:", "Account #:", "Balance:", "Credit Limit:");
    printf("=========================================\n");
    for (i=0;i<MAX_ACCOUNTS;i++) {
        if (StartSt[i].accnum != 0) { // έλεχγος αν υπάρχει
            printf("%-20s%-14d%-12.2f%-12.2f\n",
                   StartSt[i].custname, StartSt[i].accnum, StartSt[i].balance, StartSt[i].crlimit);
            found = 1;
        }
    }
    if (!found)     //αν η λίστα είναι άδεια
        printf("No accounts exist in the system.\n");
    else 
        printf("=========================================\n");
}           //κλείσιμο συνάρτησης printSTART()

// η χρήση των "->" γινεται γιατι όταν ένα structure καλείται
// δια αναφοράς σε μια συνάρτηση, γιατι δεν λειτουργεί με το 
// βασικο τροπο του: data.accnum αλλα με data->accnum