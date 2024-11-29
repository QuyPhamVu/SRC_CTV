/* 
    + What is the purpose of this program: 
    ...Write your answer here...
    the programme defines whether a number is a prime number or not and turns their forms into binary
    + Determine the features of function: 
    ...What is the function doing... Leave the comment on the top of the function

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>

//how to define a prime number
int isPrime(int num) {
    if (num <= 1) return 0; // prime number has to be bigger than 1
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

//how to convert demical form to binary form
void printBinary(int num) { 
    if (num > 1) { // consider number bigger than 1
        printBinary(num / 2); 
    }
    printf("%d", num % 2); 
}

//set value of N 
int main() {
    int N;
    printf("Nhập giá trị N: ");
    scanf("%d", &N);

    int *primes = (int *)malloc(N * sizeof(int)); 
    int count = 0;

   //count prime numbers satisfy the condition
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    //print the result
    printf("Cac so nguyen to nho hon %d la:\n", N);
    for (int i = 0; i < count; i++) { // i has to be < count then the loop would run
        printf("%d: ", primes[i]);
        printBinary(primes[i]); //primes[i+1] could cause an "out-of-bounds" error
        printf("\n");
    }

    free(primes); 
    return 0;
}