// part4_coffee_shop.c
//
// Written by Pat Chambers (z5264081), 27/2/24
//
// This program is a simple coffee shop used to demonstrate the use of 
// structs and enums in C. This program takes user input for a coffee order
// and outputs the cost of the order.

#include <stdio.h>

#define LARGE 'L'
#define REGULAR 'R'
#define ADDED_COST 0.5
#define BASE_COST 4.5


// Define an enum `coffee_type` that stores the different types of coffees 
// the shop sells. These are: LATTE, CAPPUCCINO, ESPRESSO, AMERICANO & MATCHA.
enum coffee_type {
    LATTE, 
    CAPPUCCINO, 
    ESPRESSO, 
    AMERICANO, 
    MATCHA
};

// Define a struct `coffee` that stores 
// 1. the coffee type (an enum)
// 2. the number of sugars 
// 3. the size of a coffee 
struct coffee {
    enum coffee_type type;
    int num_sugars;
    char size;
};

int main(void) {
    // Declare struct
    struct coffee order;

    printf("Enter coffee type (0: LATTE, 1: CAPPUCCINO, 2: ESPRESSO, "
           "3: AMERICANO, 4: MATCHA): ");
    
    int type;
    scanf("%d", &type);
    // Determine what 'enum coffee_type' each number refers to
    if (type == 0) {
        order.type = LATTE;
    } else if (type == 1) {
        order.type = CAPPUCCINO;
    } else if (type == 2) {
        order.type = ESPRESSO;
    } else if (type == 3) {
        order.type = AMERICANO;
    } else if (type == 4) {
        order.type = MATCHA;
    }
 
    printf("Enter number of sugars: ");
    scanf("%d", &order.num_sugars);

    printf("Enter size (L for Large, R for Regular): ");
    scanf(" %c", &order.size);

    // Calculate cost of order
    double total_cost = BASE_COST;
    if (order.size == 'L') {
        total_cost += ADDED_COST;
    }
    
    total_cost += order.num_sugars * ADDED_COST;

    if (order.type == LATTE || order.type == CAPPUCCINO || order.type == MATCHA) {
        total_cost += ADDED_COST;
    }

	printf("Total cost: %.2lf\n", total_cost);
	return 0;
}
