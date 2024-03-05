// print_array
//
// Written by Pat Chambers (z5264081), 5/3/24
//
// This program initialises an array an prints each value in it

#include <stdio.h>

#define SIZE 5

int main(void) {

    // Initialise array
    int array[5] = {5, 6, 7, 8, 9};

    // Print array in format: 5 6 7 8 9
    int i = 0;
    while (i < SIZE) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");


    return 0;
}

