// part6_roller_coaster
//
// This program was written by Pat Chambers, z5264081
// on 20/2/24


#include <stdio.h>

#define MIN_HEIGHT 100
#define RIDE_ALONE_THRESHOLD 160

int main(void) {

	// 1. Scans in the users height.
	printf("Please enter your height: ");
	double height;
	scanf("%lf", &height);
	
	// 2. If the height is 0 or less, 
	//    it should print an error message
	if (height <= 0) {
		printf("Invalid height inputted!\n");
	} else if (height < MIN_HEIGHT) {
		// 3. If the height is below the minimum height (100cm), 
		//    it should print a message telling the user they are not tall enough to ride
		printf("Sorry, you're not tall enough to ride :(\n");
	} else if (height < RIDE_ALONE_THRESHOLD) {
		// 4. If the height is above the minimum but below the ride alone threshold (160cm),
		//    it should print a message telling the user they can ride with an adult
		printf("You're tall enough to ride! But you must ride with an adult\n");
	} else {
		// 5. If the height is or is above the ride alone threshold, 
		//    it should print a message telling the user they can ride.
		printf("You're tall enough to ride alone! Enjoy your ride!\n");
	}

	return 0;
}