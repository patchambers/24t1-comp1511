// part1_variables
//
// This program was written by Pat Chambers, z5264081
// on 20/2/24
//
// This program shows how to declare and initalise variables.
// It also shows how to define and use constants.

#include <stdio.h>

int main(void) {
	// 1. Declare the variables
    int number;
    char letter;
	
    // 2. Initalise the variables
    number = 42;
    letter = 'A';

    double pi = 3.14;
    
    // 3. Print the variables
    printf("Letter: %c\n", letter);
    printf("Number: %d\n", number);
    printf("Pi: %lf\n", pi);
    
    // 4. Reassign the values of some of the variables
    number = 17;

	// 5. Print the variables
    printf("Number: %d\n", number);

	return 0;
}