// bubble_tea.c
//
// Written by Pat Chambers (z5264081), 5/3/24
//
// This program is a simple bubble tea store used to teach functions

#include <stdio.h>

#define LARGE 'L'
#define REGULAR 'R'
#define ADDED_COST 0.5
#define BASE_TEA 10
#define BASE_TOPPINGS 5
#define BASE_COST 6.5

// enum definitions
enum bubble_tea_type {
    MILK_TEA,
    FRUIT_TEA,
    TARO_MILK,
    MATCHA_LATTE,
};

enum topping_types {
    TAPIOCA_PEARLS,
    JELLY,
    POPPING_PEARLS,
    ALOE_VERA,
};

// struct definitions
struct bubble_tea {
    enum bubble_tea_type type;
	enum topping_types topping;
	int topping_qty;
    char size;
};

struct inventory {
    int tea;
    int toppings;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// FUNCTION PROTOYPES //////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Add functions protoypes here
struct bubble_tea scan_order();
int check_available_stock(struct inventory inventory, struct bubble_tea order);
double calculate_cost(struct bubble_tea order);
void print_order(struct bubble_tea order, double total_cost);
struct inventory update_inventory(
    struct inventory inventory, struct bubble_tea order
);
void print_inventory(struct inventory inventory);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// MAIN FUCNTION ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    struct inventory inventory;
    inventory.tea = BASE_TEA;
    inventory.toppings = BASE_TOPPINGS;

    // Step 1: Scan the user's bubble tea order
    struct bubble_tea order = scan_order();
    
    // Step 2: Check available stock and end the program if insufficient stock
    if (check_available_stock(inventory, order) == 1) {
        return 1;
    }

    // Step 3: Calculate the cost
    double total_cost = calculate_cost(order);

    // Step 4: Print the final order and cost
    print_order(order, total_cost);

    // Step 5: Update the stock after fulfilling the order
    inventory = update_inventory(inventory, order);

    // Step 6: print the remining inventory
    print_inventory(inventory);


    return 0;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// FUNCTION DEFINITIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Write function definitions here

// Scans a user's bubble tea order - the tea type, toppings, number of 
// toppings and size
// Parameters:  none
// Returns:     struct bubble tea initialised from the user's inputs
struct bubble_tea scan_order() {

    struct bubble_tea order;
    int type;

    printf("Enter bubble tea type (0: MILK TEA, 1: FRUIT TEA, 2: TARO MILK, "
            "3: MATCHA LATTE): ");
    scanf("%d", &type);
    if (type == 0) {
        order.type = MILK_TEA;
    } else if (type == 1) {
        order.type = FRUIT_TEA;
    } else if (type == 2) {
        order.type = TARO_MILK;
    } else if (type == 3) {
        order.type = MATCHA_LATTE;
    }

    printf("Enter topping (0: TAPIOCA PEARLS, 1: JELLY, 2: POPPING PEARLS, "
            "3: ALOE VERA): ");
    scanf("%d", &type);
    if (type == 0) {
        order.topping = TAPIOCA_PEARLS;
    } else if (type == 1) {
        order.topping = JELLY;
    } else if (type == 2) {
        order.topping = POPPING_PEARLS;
    } else if (type == 3) {
        order.topping = ALOE_VERA;
    }

    printf("Enter topping qty: ");
    scanf("%d", &order.topping_qty);

    printf("Enter size (L for Large, R for Regular): ");
    scanf(" %c", &order.size);
    
    return order;
}

// Checks whether there is available stock to fulfil the given order
// Parameters:  
//              inventory - current inventory of the store
//              order - bubble tea order to be fulfilled
// Returns:     1 if there is not enough available stock, otherwise 0
int check_available_stock(struct inventory inventory, struct bubble_tea order) {
    if (inventory.tea - 1 <= 0 ||
        inventory.toppings - order.topping_qty <= 0) {
        printf("Sorry, we cannot fulfill your bubble tea order due to "
                "insufficient stock.\n");
        return 1; 
    }
    return 0;
}

// Calculates the cost of a bubble tea order
// Parameters:  order - bubble tea order to be fulfilled
// Returns:     total cost of the order
double calculate_cost(struct bubble_tea order) {

    double total_cost = BASE_COST;

    if (order.size == LARGE) {
        total_cost += ADDED_COST;
    }

    if (order.type == MILK_TEA ||
        order.type == TARO_MILK ||
        order.type == MATCHA_LATTE) {
        total_cost += ADDED_COST;
    }

    int count = 0;
    while (count < order.topping_qty) {
        total_cost += ADDED_COST;
        count++;
    }

    return total_cost;
}

// Prints a formatted bubble tea order
// Parameters: 
//              order - bubble tea order to be printed
//              total_cost - cost of `order`
// Returns:     none
void print_order(struct bubble_tea order, double total_cost) {
    printf("Order:\n");
    printf("Type: %d\n", order.type);
    printf("Topping Qty: %d\n", order.topping_qty);
    printf("Size: %c\n", order.size);
    printf("Total Cost: %.2lf\n", total_cost);
}


// Updates the inventory to account for the order that was fulfilled
// Parameters: 
//              inventory - current inventory of the store
struct inventory update_inventory(
    struct inventory inventory, struct bubble_tea order
) {
    if (order.size == LARGE) {
        inventory.tea -= 2;
    } else {
        inventory.tea -= 1;
    }
            
    inventory.toppings -= order.topping_qty;
    return inventory;
}


void print_inventory(struct inventory inventory) {
    printf("The current inventory is: ");
    printf("Bubble tea(s): %d\n", inventory.tea);
    printf("Topping(s): %d\n", inventory.toppings);
}
