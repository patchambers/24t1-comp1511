// Demonstrating the use of struct pointers in functions
// Also shows the use of the -> operator
// Pat Chambers (z5264081), 26/3/24

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[100];
    int year;
};

void modify_book(struct book *book);

int main(void) {
    struct book book;

    strcpy(book.title, "To Kill a Mockingbird");
    strcpy(book.author, "Harper Lee");
    book.year = 1960;

    printf("Before modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    modify_book(&book);

    printf("After modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    return 0;
}

// Modifies the fields of a struct book
// Arguments:   book - pointer to the struct book to be modified
// Returns:     none
void modify_book(struct book *book) {
    // (*book).year = 1925;
    // is equivalent to:
    book->year = 1925;
    strcpy(book->title, "The Great Gatsby");
    strcpy(book->author, "F. Scott Fitzgerald");
}