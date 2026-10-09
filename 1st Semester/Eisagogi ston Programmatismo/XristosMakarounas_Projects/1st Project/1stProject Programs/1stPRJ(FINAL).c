#include<stdio.h>                    // ΑΠΑΓΟΡΕΥΕΤΑΙ ΑΥΣΤΗΡΑ Η ΧΡΗΣΗ ΠΙΝΑΚΩΝ (ARRAYS) ΓΙΑ ΤΗ ΛΥΣΗ ΤΗΣ ΑΣΚΗΣΗΣ
int calculate(char sym, int num);               //Υπολογισμός απο Ρωμαικο -> Κανονικο Αριθμο
int equation(int num1, int num2, char func);    //κάνει την τελική πράξη
void PRNT(int temp);                            //Υπολογισμός απο Κανονικο Αριθμο->Ρωμαικο
int Epitrepetai(char sym, int pre_val, int cnt); //Ελεγχος αν μπορεί να μπει ο χαρακτήρας
int valid_order(int current_val, int prev_val); //αν ο προηγουμενος ειναι μεγαλυτερος απο τον επόμενο
void clear_input();                             //διαγραφει την προηγουμενη απαντηση αν ηταν λαθος

int main(){                                     // ΑΡΧΗ ΠΡΟΓΡΑΜΜΑΤΟΣ
    char sym='1', func;                         //sym->διάβασμα χαρακτηρων, func->διαβασμα συντελεστη
    int num1 =0, num2=0, final, prev_val;       //final->τελικος αριθμος, prev_val->για συγκριση

    printf("Enter the first number: (press '0' to Finish) \n");
    while (sym != '0'){
        num1 = 0;
        prev_val = 1001;                         // αρχικοποίηση σε αδύνατο MAX αριθμό
        int cnt = 0;                             // Counter για συνεχόμενους αριθμούς
        while (num1 == 0) {
            sym = '1';
            while (sym != '0') {
                scanf(" %c", &sym);             //διαβάζει το χαρακτήρα
                if (sym != '0') {
                    int current_val = calculate(sym, num1); //υπολογίζει τον αριθμό
                    if (current_val == 0) {                 //αν ειναι 0 τοτε ειναι λαθος
                        printf("Wrong Roman Characters, please write it again!\n");
                        clear_input();          //διαγραφη της προηγουμενης απαντησης
                        num1 = 0;               // Reset num1 όταν γίνει λάθος input
                        sym = '0';              // exit loop
                        prev_val = 1001;        // αρχικοποίηση σε αδύνατο MAX αριθμό
                        cnt = 0;                //αρχικοποίηση του counter
                    } else if (!valid_order(current_val, prev_val)) {
                        printf("Invalid Roman numeral order, please enter again.\n");
                        clear_input();          //διαγραφη της προηγουμενης απαντησης
                        num1 = 0;               // Reset num1 οταν μπο΄θν σε λάθος σειρά
                        sym = '0';              // Exit loop
                        prev_val = 1001;        // αρχικοποίηση σε αδύνατο MAX αριθμό
                        cnt = 0;                //αρχικοποίηση του counter
                    } else {
                        if (Epitrepetai(sym, prev_val, cnt)) {
                            num1 += current_val;    //σωστός αριθμός, + to num1
                            cnt++;                  //αύξηση συνεχόμενου count
                        } else if (current_val == prev_val) {
                            num1 += current_val;    // + to num1
                            cnt++;                  //αύξηση count
                        } else {
                            cnt = 1;                // Reset count για διαφορετικό αριθμό
                        }
                        prev_val = current_val;     // προηγούμενο = τρέχων
                    }
                }
            }
        }
    }
    printf("The first number is %d\n", num1);       // τυπώνει το 1ο αριθμό
    sym = '1';                                  //αρχικοποιει το sym για να διαβάσει αλλο αριθμο
    
    printf("Enter the Second number: (press'0' to Finish) \n");
    while (sym != '0'){
        num2 =0;                            //αρχικοποιηση του num2=0 για σιγουριά
        prev_val = 1001;                    // Το ΜΑΞ που μπορεί να πιάσει (για σύγκριση)
        int cnt=0;                          // Counter για συνεχόμενους αριθμούς
        while (num2==0){
            sym ='1';
             while (sym != '0') {
                scanf(" %c", &sym);         //διαβάζει το character
                if (sym != '0') {
                    int current_val = calculate(sym, num2); //υπολογίζει τον αριθμό
                    if (current_val == 0) {
                        printf("Wrong Roman Characters, please write it again!\n");
                        clear_input();              //διαγραφη της προηγουμενης απαντησης
                        num2 = 0;                   // Reset num2 όταν γίνει λάθος input
                        sym = '0';                  // Exit loop
                        prev_val = 1001;            // αρχικοποίηση σε αδύνατο MAX αριθμό
                        cnt = 0;                    //αρχικοποίηση του counter
                    }
                    else if (!valid_order(current_val, prev_val)) {
                        printf("Invalid Roman numeral order, please enter again.\n");
                        clear_input();              //διαγραφη της προηγουμενης απαντησης
                        num2 = 0;                   // Reset num2 όταν γίνει λάθος input
                        sym = '0';                   // Exit loop
                        prev_val = 1001;            // αρχικοποίηση σε αδύνατο MAX αριθμό
                        cnt = 0;                    //αρχικοποίηση του counter
                    }
                    else {
                        if (Epitrepetai(sym, prev_val, cnt)) {
                            num2 += current_val;       //σωστός αριθμός, + to num2
                            cnt++;                     //αύξηση συνεχόμενου count
                        } 
                        else if (current_val == prev_val) {
                            num2 += current_val;        // + to num2
                            cnt++;                      //αύξηση count
                        } 
                        else 
                            cnt = 1;                 // Reset count για διαφορετικό αριθμό
                        prev_val = current_val;      // προηγούμενο = τρέχων
                    }
                }
            }
        }
    }
    printf("The second number is %d\n", num2);          // τυπώνει το 2ο αριθμό
    printf("Enter the desired arithmetic operation:\n");  //δώσε συντελεστή πράξης
    scanf(" %c", &func);
    while((func!='+')&&( func!='*')&&(func!='-')&&(func!='/')){ //σιγούρεψε πως ειναι σωστός ο συντελεστής      
	    printf("wrong Math Operation please whrite it again!");     //σε περίπτωση λάθους διαβάσματος
        scanf(" %c", &func);
    }
    final=equation(num1, num2, func);               /* ΥΠΟΛΟΓΙΣΕ ΤΗΝ ΤΕΛΙΚΟ ΑΡΙΘΜΟ*/

    switch (func){                                       //switch for printing the Function Name
        case '+': printf("  Sum(+) of: ");
            break;
        case '-': printf(" The Abstraction(-) of: ");
            break;
        case '*': printf(" The Multiplication(*) of: ");
            break;
        case '/': printf(" The Division(/) of: ");
            break;
    }                                                              
    PRNT(num1);                         //prints the First Number in Roman στο Terminal
    printf(" and ");                    //prints "and" στο Terminal
    PRNT(num2);                         //prints the Second Number in Roman στο Terminal
    printf(" is ");                     //prints "is" στο Terminal
    PRNT(final);                        //prints the Final Number in Roman στο Terminal
    printf("( %d )", final);            //prints the final number in regular numbers στο Terminal

    return 0;                           // ΤΕΛΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ 
}

int equation(int num1, int num2, char func){  //συνάρτηση που επιστρέφει το αποτέλεσμα της εξίσωσης
    switch (func){
        case '*': return num1*num2;
        case '+': return num1+num2;
        case '/': return num1/num2;
        case '-': return num1-num2;
    }
    return 0;
}

int calculate(char sym, int num){  
	num=0;                               //calculates the number via the input Characters
    switch (sym){
        case 'M':
        case 'm': num+=1000;
            break;
        case 'D':
        case 'd': num+=500;
            break;
        case 'C':
        case 'c': num+=100; 
            break;
        case 'L':
        case 'l': num+=50;
            break;
        case 'X':
        case 'x': num+=10;
            break;
        case 'V':
        case 'v': num+=5;
            break;
        case 'I':
        case 'i': num+=1;
            break;
        default:
            break;
    }
    return num;
}

int Epitrepetai(char sym, int pre_val, int cnt) {   //Η Συνάρτηση ελέγχει αν μπορεί να μπει ο χαρακτήρας
    switch (sym) {
        case 'I':
            return (pre_val == 1 && cnt < 3) || (pre_val != 1);
        case 'X':
            return (pre_val == 10 && cnt < 3) || (pre_val != 10);
        case 'C':
            return (pre_val == 100 && cnt < 3) || (pre_val != 100);
        case 'M':
            return (pre_val == 1000 && cnt < 3) || (pre_val != 1000);
        default: return 1;                       // Epitrepetai na valei & allous Xaraktires
    }
}

int valid_order(int current_val, int prev_val) {    //Σιγουρέυει αν είναι σε σωστή σειρά
    return current_val <= prev_val;                   //αν εν σωστό επιστρέφει true(1)
}           

void clear_input() {                            //συνάρτηση γιατι εν μου θκιάβαζε τον πρώτο χαρακτήρα αν
    int ch;                                     // το πρώτο input ηταν λαθος
    while ((ch = getchar()) != '\n' && ch != EOF);  // διαγραψε ολους τους προηγουμενους χαρακτηρες μεχρι νεα γραμμη
}

void PRNT(int temp){                            //συνάρτηση για να τυπώνει αριθμούς 
    while (temp>0){                             // σε Ρωμαικούς χαρακτήρες
        while (temp>=1000){
            temp-=1000;
            printf("M"); }
        while (temp>=500){
            temp-=500;
            printf("D"); }
        while (temp>=100){
            temp-=100;
            printf("C"); }
        while (temp>=50){
            temp-=50;
            printf("L"); }
        while (temp>=10){
            temp-=10;
            printf("X"); }
        while (temp>=5){
            temp-=5;
            printf("V");}
        while (temp>=1){
            temp-=1;
            printf("I");
        } } }