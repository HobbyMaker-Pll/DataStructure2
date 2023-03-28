#include <stdio.h>
#include <stdlib.h>


int factorial(int number)
{
    int i, ret=1;

    for(i=number; i>0; i--)
    {
        ret *= i;
    }
    return ret;
}

int factorialRecursive(int number){
    if (number == 1) return number;
    return (factorialRecursive(number-1)*number);
}

void main_Factorial(int sub){
  
    int n;

    printf("Digite o numero: ");
    scanf("%i",&n);

    printf("Calculating using \"for\" factorial to %i: %i\n", n, factorial(n));
    printf("Calculating using \"Recursive function\" factorial to %i: %i\n", n, factorialRecursive(n));
}
