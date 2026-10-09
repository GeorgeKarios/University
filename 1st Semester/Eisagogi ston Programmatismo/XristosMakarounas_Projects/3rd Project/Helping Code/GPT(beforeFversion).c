#include<stdio.h>
#define N 200

struct ACCT {              //32 bytes
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

int main(){
    int choice;
    printf("\nEnter your choice:\n" 
           "1 - Create a blank list\n"
           "2 - Insert Data\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            createlist();
            break;
        case 2:
            input();
            break;    
        default:
            printf("Invalid choice. Exiting program.\n");
    }
    return 0;
}

void createlist() { // Creates a blank list
    struct ACCT blankfill = {0, "", 0.0, 0.0};
    int i;
    FILE *wptr;
    if ((wptr = fopen("system.txt", "w")) == NULL)
        printf("File could not be created\n");
    else {
        for (i = 0; i < N; i++)
            fwrite(&blankfill, sizeof(struct ACCT), 1, wptr);
        fclose(wptr);
        printf("Blank list created successfully.\n");
    }
}

void input() {
    FILE *iptr;
    char ans, enteredName[20];
    float purch;
    struct ACCT data;
    int isnew = 0, stop = 0;

    if ((iptr = fopen("system.txt", "r+")) == NULL) // Opens file as r+
        printf("File could not be opened\n");
    else {
        while (!getinfo(&purch, &data, iptr, &stop)) { // Loop until account is found
            if (stop)
                break;

            printf("\nIS THIS A NEW ACCOUNT NUMBER? (Y OR N): ");
            scanf(" %c", &ans);

            if (ans == 'N' || ans == 'n') { // Invalid account
                printf("\nINVALID ACCOUNT NUMBER, RE-ENTER DATA:");
                continue;
            } else if (ans == 'Y' || ans == 'y') { // New account
                newcust(iptr, &data, &purch);
                isnew = 1;
                check(iptr, &data, purch);
                continue;
            }

            if (!isnew) { // Authenticate existing customers
                printf("\nENTER CUSTOMER NAME TO AUTHENTICATE: ");
                scanf(" %[^\n]s", enteredName);

                // Name Authentication
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
                    printf("\nACCOUNT NUMBER & CUSTOMER NAME DO NOT MATCH, RE-ENTER DATA:");
                    continue;
                }

                printf("\nAuthentication successful! Welcome back, %s.\n", data.custname);
                check(iptr, &data, purch);
            }

            isnew = 0; // Reset flag
        }
        fclose(iptr);
    }
}

int getinfo(float *purch, struct ACCT *data, FILE *iptr, int *stop) {
    printf("\nENTER ACCOUNT NUMBER: ");
    scanf("%d", &data->accnum);

    if (data->accnum < 0) { // Negative account number
        printf("\nNEGATIVE ACCOUNT NUMBER ENTERED, CLOSING PROGRAM.\n");
        *stop = 1;
        return -1;
    }

    printf("\nENTER AMOUNT OF PURCHASE: ");
    scanf("%f", purch);
    return seek(data, iptr); // Return result of seek
}

int seek(struct ACCT *data, FILE *iptr) { // Searches for the given accnum
    struct ACCT temp;
    fseek(iptr, ((data->accnum / 50) - 1) * sizeof(struct ACCT), SEEK_SET);
    if (fread(&temp, sizeof(struct ACCT), 1, iptr) != 1)
        return 0;
    if (temp.accnum == data->accnum) {
        *data = temp;
        return 1; // Account found
    }
    return 0; // Account not found
}

void newcust(FILE *iptr, struct ACCT *data, float *purch) {
    printf("\nENTER CUSTOMER NAME: ");
    scanf(" %[^\n]s", data->custname);
    printf("\nENTER CUSTOMER CREDIT LIMIT: ");
    scanf(" %f", &data->crlimit);
    data->balance = *purch;

    fseek(iptr, ((data->accnum / 50) - 1) * sizeof(struct ACCT), SEEK_SET);
    fwrite(data, sizeof(struct ACCT), 1, iptr);
}

int check(FILE *iptr, struct ACCT *data, float purch) {
    if (purch > 0) {
        if ((data->balance + purch) <= data->crlimit) {
            data->balance += purch;
            fseek(iptr, ((data->accnum / 50) - 1) * sizeof(struct ACCT), SEEK_SET);
            fwrite(data, sizeof(struct ACCT), 1, iptr);
            printf("\nDEAR %s,\nTHANK YOU FOR THE BUSINESS.\n", data->custname);
            return 1;
        } else {
            printf("\nDEAR %s,\nWE CANNOT AUTHORIZE THIS PURCHASE AT THIS TIME AS IT"
                   "\nWOULD PUT YOU €%.2f OVER YOUR CREDIT LIMIT.\n",
                   data->custname, (data->balance + purch - data->crlimit));
            return 0;
        }
    } else {
        printf("\nInvalid purchase amount. Please enter a positive value.\n");
        return -1;
    }
}
