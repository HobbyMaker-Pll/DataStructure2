#include <stdio.h>
#include <stdlib.h>


int sequentialSum(int number){
    if (number==0) return number; 
    return number+sequentialSum(number-1);
}
void main_Sum(){
  
    int n;

    printf("Digite o numero: ");
    scanf("%i",&n);

    printf("Calculating using \"Recursive function\" sum from 0 to %i: %i\n", n, sequentialSum(n));
}
