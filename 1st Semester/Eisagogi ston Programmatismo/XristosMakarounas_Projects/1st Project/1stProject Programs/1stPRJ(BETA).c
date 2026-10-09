#include<stdio.h>
int calculate(char sym, int num);
int equation(int num1, int num2, char func);
void PRNT(int temp);

int main(){
    char sym='1', func;
    int num1 =0, num2=0, final;
    printf("Enter the first number: (press '0' to Finish) \n");
    while (sym != '0'){
        scanf(" %c", &sym);
        num1 = calculate(sym, num1);    /*the number goes in the Function & the final number is the sum of the two */
        if (num1==0)
        	sym='1';
        }
    printf("The first number is %d\n", num1);
    sym = '1';                                                     //Reseting sym to 1
    printf("Enter the Second number: (press'0' to Finish) \n");
    while (sym != '0'){
        scanf(" %c", &sym);
        num2 = calculate(sym, num2); /*the number goes in the Function & the final number is the sum of the two */
        if (num2==0)
        	sym='1';
        }
    printf("The second number is %d\n", num2);
    printf("Enter the desired arithmetic operation:\n");
    scanf(" %c", &func);
    while((func!='+')&&( func!='*') && (func!='-') && (func!='/')){ //Verify if the Function is Correct        
	printf("wrong Math Operation please whrite it again!");
        scanf(" %c", &func);
    }
    final=equation(num1, num2, func);
    switch (func){                                       //switch for printing the Funtion Name
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
     
    return 0;
}

int equation(int num1, int num2, char func){
    switch (func){
        case '*': return num1*num2;
            break;
        case '+': return num1+num2;
            break;
        case '/': return num1/num2;
            break;
        case '-': return num1-num2;
            break;
    }
}

int calculate(char sym, int num){        //calculates the number via the input Characters
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
        case '0': 
            break;
        default:
            printf("wrong Roman Characters, please whrite it again!");		  //if wrong input then print this message
            break;
    }
    return num;
}

void PRNT(int temp){
    int temp2=temp;
    while (temp2>0){
        while (temp2>=1000){
            temp2-=1000;
            printf("M");
        }
        while (temp2>=500){
            temp2-=500;
            printf("D");
        }
        while (temp2>=100){
            temp2-=100;
            printf("C");
        } 
        while (temp2>=50){
            temp2-=50;
            printf("L");
        }
        while (temp2>=10){
            temp2-=10;
            printf("X");
        }
        while (temp2>=5){
            temp2-=5;
            printf("V");
        }
        while (temp2>=1){
            temp2-=1;
            printf("I");
        }
        
    }
}

// ΑΠΑΓΟΡΕΥΕΤΑΙ ΑΥΣΤΗΡΑ Η ΧΡΗΣΗ ΠΙΝΑΚΩΝ (ARRAYS) ΓΙΑ ΤΗ ΛΥΣΗ ΤΗΣ ΑΣΚΗΣΗΣ