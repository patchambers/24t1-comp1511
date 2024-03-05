// functions.c
//
// Written by Pat Chambers (z5264081), 5/3/24
//
// This program is a simple demonstration of functions

#include <stdio.h>

int add(int value1, int value2);

int main(void) {

    int num1 = 5;
    int num2 = 3;
    int result = add(num1, num2);
    printf("Result: %d\n", result);

    int a = 5;
    int b = 55;
    int result2 = add(a, b);
    printf("Result2: %d\n", result2);

    return 0;
}

// Adds 2 numbers together
// Takes in the numbers to be added
// Returns the sum of these valuebers
int add(int value1, int value2) {
    int sum = a + b;
    return sum;
}