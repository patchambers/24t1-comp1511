// Using malloc and free to manually manage memory
// Pat Chambers (z5264081), 2/4/24

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct my_struct {
    int number;
    char letter;
    double another_number;
};

int main(void) {

    // malloc memory for int, double, char: 
    // int num = 42;
    // malloc takes size of memory to be allocated, returns pointer to that memory
    // sizeof takes a variable type, returns number of bytes that variable type requires
    int *num_ptr = malloc(sizeof(int));
    *num_ptr = 42;
    printf("int at address that num_ptr stores: %d\n", *num_ptr);
    // double *double_ptr = malloc(sizeof(double));

    // malloc memory for array of chars:
    // char *string = malloc(sizeof(char) * SIZE);
    
    // malloc memory for a `struct my_struct`:
    // struct my_struct *struct_ptr = malloc(sizeof(struct my_struct));

    // free malloc'd memory
    free(num_ptr);
    // This line will cause a `malloc use after free` error if it is run
    // printf("int at address that num_ptr stores: %d\n", *num_ptr);

    return 0;
}
