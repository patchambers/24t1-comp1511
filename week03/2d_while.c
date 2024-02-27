// Demostrating use of a 2D while loop
// Pat Chambers (z5264081), 27/2/24

#include <stdio.h>

#define MAX 4

int main(void) {

    printf("Start of outer loop!\n\n");
    // Initialise outer loop variable
    int row = 0;
    while (row < MAX) {
        printf("Start of inner loop!\n");
        int col = 0;
        while (col < MAX) {
            printf("%d ", col);
            col++;
        }
        printf("\n");
        printf("End of inner loop!\n\n");

        row++;
    }
    printf("End of outer loop!\n");

    return 0;
}

