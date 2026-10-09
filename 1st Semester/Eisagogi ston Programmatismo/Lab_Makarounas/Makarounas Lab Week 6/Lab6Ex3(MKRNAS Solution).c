#include <stdio.h>
#define MAXDEGREE 10
float polynomialValue(float coefficients[], int degree, float x);
int main() {
    float coefficients[MAXDEGREE], x;
    int degree, i;
    printf("Please enter the value of x: ");
    scanf("%f", &x);
    printf("Please enter the degree of the polynomial: ");
    scanf("%d", &degree);
    for (i = 0; i <= degree; i++) {
        printf("Enter the coefficient of the term with degree %d: ", degree - i);
        scanf("%f", &coefficients[i]);
    }
    printf("The value of the polynomial is %.2f\n", polynomialValue(coefficients, degree + 1, x));
    return 0;
}
float polynomialValue(float coefficients[], int degree, float x)
{
    if (degree == 1)
        return coefficients[0];
    else
        return x * polynomialValue(coefficients, degree - 1, x) + coefficients[degree - 1];
}

