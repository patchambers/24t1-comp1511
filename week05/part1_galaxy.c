// TODO: Add function comments!! Will do by 13/2
//
// part1_galaxy.c
//
// This program was written by Pat Chambers (z5264081), 12/3/24
//
// This program is a simple game that allows the user to build a galaxy. 
// The user can place stars, planets, and nebulae in the galaxy.


// Your program will need to scan in the player's starting position. This will be 
// given as a pair of integers which denotes the row and column (in that order). 
// If the starting position does not place the player within the boundary, the  
// program should print out 
// `Invalid starting position!`. 
// Then the program should prompt with 
// `Re-enter starting position:` 
// and re-scan the position of the player, repeating until a valid position is scanned in.

// After spawning the player, the program should prompt for how many celestial  
// bodies will be added to the galaxy with 
//     `How many planets and nebulae are there? [count]` 
// and take input for count number of planets and nebula.
//     Planets are added with p [row] [col] [points]
//     Nebulae are added with n [row] [col]

// After spawning planets and nebulae the program should prompt for stars with  
// `Enter the position and points of the star(s): ` 
// and take input in the form [row] [col] [points] until ctrl + d is pressed.

// Finally, after spawning all celestial bodies, the program should print the 
// galaxy with the print_galaxy function provided.



#include <stdio.h>

#define SIZE 5
#define NEBULA_POINTS -10

enum entity {
    STAR,
    PLANET,
    NEBULA,
    SPACESHIP,
    EMPTY,
};

struct celestial_body {
    enum entity entity; // Initialise to EMPTY
    int points;         // Initialise to NEBULA_POINTS
};

void initialise_galaxy(struct celestial_body galaxy[SIZE][SIZE]);
void add_player(struct celestial_body galaxy[SIZE][SIZE]);
void add_planets_nebulae(struct celestial_body galaxy[SIZE][SIZE]);
void add_stars(struct celestial_body galaxy[SIZE][SIZE]);
void print_map(struct celestial_body galaxy[SIZE][SIZE]);

int main(void) {

    struct celestial_body galaxy[SIZE][SIZE];

    // Initialize the galaxy to EMPTY
    initialise_galaxy(galaxy);

    // Place the player in the galaxy
    add_player(galaxy);
    // Scan number of planets and nebulae in the galaxy
    add_planets_nebulae(galaxy);

    // Place the stars in the galaxy
    add_stars(galaxy);

    // Print the map
    print_map(galaxy);

}

// Function prints the map of the galaxy
// 
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void print_map(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("\n---------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|");
            if (galaxy[i][j].entity == SPACESHIP) {
                printf(" X ");
            } else if (galaxy[i][j].entity == EMPTY) {
                printf("   ");
            } else if (galaxy[i][j].entity == STAR) {
                printf(" * ");
            } else if (galaxy[i][j].entity == PLANET) {
                printf(" o ");
            } else if (galaxy[i][j].entity == NEBULA) {
                printf(" # ");
            }
        }
        printf("|\n");
        printf("---------------------\n");
    }
}

void initialise_galaxy(struct celestial_body galaxy[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            galaxy[row][col].entity = EMPTY;
            galaxy[row][col].points = NEBULA_POINTS;
        }
    }
}

void add_player(struct celestial_body galaxy[SIZE][SIZE]) {

    printf("Enter the starting position of the player: ");
    int player_row;
    int player_col;
    scanf("%d %d", &player_row, &player_col);
    while (
        player_row < 0 || player_row >= SIZE || 
        player_col < 0 || player_col >= SIZE
    ) {
        printf("Invalid starting position!\n");
        printf("Re-enter starting position: ");
        scanf("%d %d", &player_row, &player_col);
    }
    galaxy[player_row][player_col].entity = SPACESHIP;

}

void add_planets_nebulae(struct celestial_body galaxy[SIZE][SIZE]) {

    printf("How many planets and nebulae are there? ");
    int num_bodies;
    scanf("%d", &num_bodies);

    // Place the planets and nebulae in the galaxy
    printf("Enter the position and points of the planet(s) and nebula(e): ");
    for (int i = 0; i < num_bodies; i++) {
        char type;
        int row;
        int col; 
        scanf(" %c %d %d", &type, &row, &col);
        if (type == 'p') {
            int points;
            scanf("%d", &points);
            galaxy[row][col].entity = PLANET;
            galaxy[row][col].points = points; 
        } else if (type == 'n') {
            galaxy[row][col].entity = NEBULA;
        }
    }
}

void add_stars(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("Enter the position and points of the star(s): \n");
    int star_row;
    int star_col;
    int points;
    while (scanf("%d %d %d", &star_row, &star_col, &points) == 3) {
        galaxy[star_row][star_col].entity = STAR;
        galaxy[star_row][star_col].points = points;
    }
}