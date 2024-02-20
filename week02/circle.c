// Calculates area of circle with inputted radius
// Pat Chambers (z5264081), 20/2/24

#include <stdio.h>

#define PI 3.14159265

int main(void) {

    // Print prompt
    printf("Please enter the radius of the circle: ");

    // Scan in radius from user
    double radius;
    scanf("%lf", &radius);

    // Calculate area
    double area = radius * radius * PI;

    // Print out radius and area of circle
    printf("A circle with radius %lf has an area of %lf\n", radius, area);

    return 0;
}