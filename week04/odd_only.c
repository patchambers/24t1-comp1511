// odd_only
//
// Written by Pat Chambers (z5264081), 5/3/24
//
// This program adds 1 to any even element in an array and after prints 
// all elements in the array

#include <stdio.h>

#define SIZE 5

int main(void) {

    // Initialise array 
    int array[SIZE] = {1, 2, 3, 4, 5};

    // Loop through to add 1 to each even number in array
    int i = 0;
    while (i < SIZE) {
        if (array[i] % 2 == 0) {
            array[i] += 1;
        }
        i++;
    }

    // Loop to print each value in array
    int j = 0;
    while (j < SIZE) {
        printf("%d ", array[j]);
        j++;
    }
    printf("\n");

    return 0;
}
