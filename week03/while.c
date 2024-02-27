// Structure of a basic while loop
// Pat Chambers (z5264081), 27/2/24

#include <stdio.h>

#define MAX 10

int main(void) {

    printf("Start of loop!\n");

    // initialise loop variable
    int counter = 0;
    while (counter < MAX) {
        // loop body
        printf("%d\n", counter);
        // increment loop variable
        counter++;
    }

    // continue running code from here after loop terminates
    printf("End of loop!\n");

    return 0;
}