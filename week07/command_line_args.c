// Prints out the number of command line arguments given then prints 
// each argument 
// Pat Chambers (z5264081), 26/3/24

#include <stdio.h>

int main(int argc, char *argv[]) {

    // ./command_line_args here are some arguments
    // argc = 5
    // argv = {
    //      "./command_line_args", 
    //      "here", 
    //      "are", 
    //      "some", 
    //      "args", 
    //}

    // Count number of command line args and print them

    printf("Total args: %d\n", argc); 

    printf("Argument values: \n");
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}