#include <stdio.h>
#define MAX_ACCOUNTS 200

struct ACCT {              
    int   accnum;
    char  custname[20];
    float balance;
    float crlimit;
};                   

void createlist();
void input();
int getinfo(float *, struct ACCT *, FILE *, int *);
int seek(struct ACCT *, FILE *);
void newcust(FILE *, struct ACCT *, float *);
int check(FILE *, struct ACCT *, float);
void printEND(FILE *);
void printSTART(struct ACCT StartSt[]);

int main() {
    int choice;
    printf("\nEnter your choice:\n1 - Create a blank list\n2 - Insert Data\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            createlist();
            printf("\nDo you want to insert data now? (Y or N): ");
            char mr;
            scanf(" %c", &mr);
            if (mr == 'Y' || mr == 'y')
                input();
            break;
        case 2:
            input();
            break;
        default:
            printf("INVALID CHOICE CLOSING PROGRAM\n");    
    }
    return 0;
}

void createlist() {
    struct ACCT blankfill = {0, "", 0.0, 0.0};
    int i;
    FILE *wptr;
    if ((wptr = fopen("system.txt", "w")) == NULL)
        printf("[DEBUG] File could not be created.\n");
    else {
        for (i = 0; i < MAX_ACCOUNTS; i++)
            fwrite(&blankfill, sizeof(struct ACCT), 1, wptr);
        fclose(wptr);
        printf("Blank Binary List Created.\n");
    }
}

void input() {
    FILE *iptr;
    char ans, enteredName[20];
    float purch;
    struct ACCT data, StartState[MAX_ACCOUNTS];
    int isnew = 0, stop = 0;

    if ((iptr = fopen("system.txt", "r+")) == NULL) {
        printf("[DEBUG] File could not be opened.\n");
        return;
    }
    fread(StartState, sizeof(struct ACCT), MAX_ACCOUNTS, iptr); 
    printf("[DEBUG] Read starting state of accounts.\n");

    while (!(getinfo(&purch, &data, iptr, &stop))) {  
        if (stop) {
            printf("[DEBUG] Stop signal received. Exiting input loop.\n");
            break;
        }

        printf("\nIS THIS A NEW ACCOUNT NUMBER? (Y OR N): ");
        scanf(" %c", &ans);

        if (ans == 'N' || ans == 'n') {  
            printf("[DEBUG] User indicated this is NOT a new account.\n");
            printf("\nINVALID ACCOUNT NUMBER, RE-ENTER DATA:");
            continue;
        } else if (ans == 'Y' || ans == 'y') {
            printf("[DEBUG] User indicated this is a NEW account.\n");
            newcust(iptr, &data, &purch);
            isnew = 1;
        }

        if (!isnew) {  
            printf("\nENTER CUSTOMER NAME TO AUTHENTICATE: ");
            scanf(" %[^\n]s", enteredName);

            int i, same = 1;
            for (i = 0; i < 20; i++) {
                if (enteredName[i] != data.custname[i]) {
                    same = 0;
                    break;
                }
                if (data.custname[i] == '\0')
                    break;  
            }

            if (!same) {
                printf("[DEBUG] Name authentication failed.\n");
                printf("\nACCOUNT NUMBER & CUSTOMER NAME DO NOT MATCH, RE-ENTER DATA:");
                continue;
            }
            printf("[DEBUG] Authentication successful for: %s\n", data.custname);
        }

        printf("[DEBUG] Calling check() for Account: %d, Purchase: %.2f\n", data.accnum, purch);
        check(iptr, &data, purch);
        printf("[DEBUG] Returned from check().\n");

        isnew = 0;  
    }

    printf("\nSTARTING STATE OF ACCOUNTS:\n");
    printSTART(StartState);
    printf("\nENDING STATE OF ACCOUNTS:\n");
    printEND(iptr);
    fclose(iptr); 
}

int getinfo(float *purch, struct ACCT *data, FILE *iptr, int *stop) {
    printf("[DEBUG] Entering getinfo().\n");
    while (1) {
        printf("\n(to exit input a Negative Num.)(Acc. Num. must be a multiple of 50)\n ENTER ACCOUNT NUMBER: ");
        scanf("%d", &data->accnum);
        if (data->accnum < 0) {
            printf("\nNEGATIVE ACCOUNT NUMBER ENTERED, CLOSING PROGRAM.\n");
            *stop = 1;
            printf("[DEBUG] Stop signal sent from getinfo().\n");
            return -1;
        }
        if (data->accnum % 50 != 0) {
            printf("ACCOUNT NUMBERS MUST BE MULTIPLES OF 50.\n");
            continue;
        }
        break;
    }
    printf("\nENTER AMOUNT OF PURCHASE: ");
    scanf("%f", purch);
    while (*purch <= 0) {
        printf("\nINVALID PURCHASE AMOUNT, RE-ENTER PURCHASE\n");
        scanf("%f", purch);
    }
    int result = seek(data, iptr);
    printf("[DEBUG] Returning from getinfo() with result: %d\n", seekResult);
    return result;
}

int seek(struct ACCT *data, FILE *iptr) {
    struct ACCT temp;
    fseek(iptr, ((data->accnum / 50) - 1) * sizeof(struct ACCT), SEEK_SET);
    if (fread(&temp, sizeof(struct ACCT), 1, iptr) != 1) 
        return 0;
    if (temp.accnum == data->accnum) {
        *data = temp;
        return 1;
    }
    return 0;
}

void newcust(FILE *iptr, struct ACCT *data, float *purch) {
    printf("\nENTER CUSTOMER NAME: ");
    scanf(" %[^\n]s", data->custname);
    printf("\nENTER CUSTOMER CREDIT LIMIT: ");
    scanf(" %f", &data->crlimit);  
    data->balance = *purch;
    fseek(iptr, ((data->accnum / 50) - 1) * sizeof(struct ACCT), SEEK_SET);
    fwrite(data, sizeof(struct ACCT), 1, iptr);
    printf("[DEBUG] New customer added with Account #: %d\n", data->accnum);
}

int check(FILE *iptr, struct ACCT *data, float purch) {
    printf("[DEBUG] Entering check() for Account: %d\n", data->accnum);
    if ((data->balance + purch) <= data->crlimit) {
        data->balance += purch;
        fseek(iptr, ((data->accnum / 50) - 1) * sizeof(struct ACCT), SEEK_SET);
        fwrite(data, sizeof(struct ACCT), 1, iptr);
        printf("[DEBUG] Updated balance written to file.\n");
        printf("\nDEAR %s,\nTHANK YOU FOR THE BUSINESS.\n", data->custname);
        return 1;
    } else {
        printf("\nDEAR %s,\nWE CANNOT AUTHORIZE THIS PURCHASE AT THIS TIME AS IT"
               "\n WOULD PUT YOU €%.2f OVER YOUR CREDIT LIMIT.\n",
               data->custname, (data->balance + purch - data->crlimit));
        return 0;
    }
}

void printEND(FILE *iptr) {
    struct ACCT EndSt;
    int found = 0;
    rewind(iptr);
    printf("\nEXISTING ACCOUNTS IN THE SYSTEM:\n");
    printf("=========================================\n");
    printf("%-20s%-10s%-10s%-10s\n", "Name:", "Account #:", "Balance:", "Credit Limit:");
    printf("=========================================\n");
    while (fread(&EndSt, sizeof(struct ACCT), 1, iptr)) {
        if (EndSt.accnum != 0) {
            printf("%-20s%-10d%-10.2f%-10.2f\n",
                   EndSt.custname, EndSt.accnum, EndSt.balance, EndSt.crlimit);
            found = 1;
        }
    }
    if (!found)
        printf("No accounts exist in the system.\n");
    else
        printf("=========================================\n");
}

void printSTART(struct ACCT StartSt[]) {
    int found = 0, i;
    printf("=========================================\n");
    printf("%-20s%-10s%-10s%-10s\n", "Name:", "Account #:", "Balance:", "Credit Limit:");
    printf("=========================================\n");
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (StartSt[i].accnum != 0) {
            printf("%-20s%-10d%-10.2f%-10.2f\n",
                   StartSt[i].custname, StartSt[i].accnum, StartSt[i].balance, StartSt[i].crlimit);
            found = 1;
        }
    }
    if (!found)
        printf("No accounts exist in the system.\n");
    else
        printf("=========================================\n");
}
