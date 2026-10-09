#include <stdio.h>
#include <math.h>
#define N 100           //σταθερά Ν 100
#define K 10           //σταθερά Κ 10
void PRNT(int, char[], int[], float, float, int[]);    //πρώτυπο συνάρτησης
int main(){  
    int grades[N], sum=0, fasma[K]={0},pl,i;
    char subject[15];
    float avg, std_dv;
    printf("what subject?\n");
    for (i=0;i<15;i++)
        scanf("%c", &subject[i]);            //εισαγωγή του ονόματος Μαθήματος
    printf("how many grades will you input? (1-100)\n");
    scanf(" %d", &pl);                       //εισαγωγή πλήθους βαθμών
    while (pl>100 || pl<1){                  //έλεγχος εισαγωγής λάθους πλήθους αριθμών
        printf("%d is not a valid size: (1-100). Please input again: ", pl);
        scanf(" %d", &pl);
    }
    printf("Input %d Grades: \n", pl);
    for (i=0;i<pl;i++){
        scanf(" %d", &grades[i]);                   //εισαγωγή όλων των βαθμών
        while (grades[i]>100 || grades[i]<0){       //έλεγχος εισαγωγής λάθος αριθμών
            printf("%d is not a valid grade: (0-100). Please input again: ", grades[i]);
            scanf(" %d", &grades[i]);
        }
        sum+=grades[i];                //υπολογιζει τον αθροισμα ολων των αριθμων
        fasma[grades[i]/10]++;         //αυξάνει τις εμφανίσεις πεδίων αριθμών για χρήση στο Ιστόγραμμα
    }
    avg=sum/pl;                        //υπολογισμος μέσου όρου
    sum=0;                             //sum=0 για να το χρησιμοποιήσω στο Standard Deviation
    for (i=0;i<pl;i++)
        sum+=pow(grades[i]-avg,2);  //Τυπος υπολογισμόυ Standard Deviation (part 1)
    std_dv=sqrt(sum/pl);            //Τυπος υπολογισμόυ Standard Deviation (part 2)
    //κληση συνάρτησης "PRNT" για τύπωμα:
    PRNT(pl,subject,grades,std_dv,avg,fasma);
return 0;
}
//Συνάρτηση "PRNT":
void PRNT(int pl, char sub[], int grd[], float stdv, float avg, int fasma[]){
    int holder=0,i,j,maxF=0;
    for (i=0;i<K;i++)
        if(fasma[i]>maxF)            // υπολογισμος μέγιστου στον πίνακα
            maxF=fasma[i];           // για γραμμες στην εκτύπωση Histogram

    printf("%d Scores in: ", pl);    //τυπώνει "Score In" και το μάθημα
    for (i=0;i<15;i++)
        printf("%c",sub[i]);
    printf("\n");
    
    for (i=0;i<pl;i++){
        printf(" %d", grd[i]);      //τυπώνει τους Βαθμούς
        holder++;                   //αυξάνει το holder για να αλλάσει γραμμή
        if (holder==10){            
            printf("\n");           //αλλασει γραμμη οταν τυπώσει 10 βαθμούς
            holder=0;  
        }
    }
    printf("\nAverage: %2.f\n", avg);               //τυπωνει τον μέσο όρο
    printf("Standard Deviation: %2.f\n", stdv);     //τυπωνει την τυπική απόκλιση
    //Γραφική Παράσταση - Ιστόγραμμα Συχνότητας Βαθμών:
    printf("<10   10-19   20-29   30-39   40-49   50-59   60-69   70 -79   80-89   >=90\n");  
    for (i=0;i<maxF;i++){
        for (j=0;j<K;j++){
            if (fasma[j]>0){
                printf("%c\t", '#');          //χρήση χαρακτήρα '#' για απεικόνιση Γραφικής
                fasma[j]--;  
            }
            else
                printf(" \t");        //το '\t' πατάει TAB
        }
        printf("\n");                 //αλλάζει γραμμή
    }
}