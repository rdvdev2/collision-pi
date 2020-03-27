/*
 * Title: Collision Pi
 * Author: rdvdev2 (rdvdev2@gmail.com)
 * Description: Calculate Pi with the extremely inefficient method of counting perfectly elastic collisions
 */

#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main() {
    int digits; // The quantity of digits to calculate (defined by the user)

    // Just add a header
    printf("============================================================================================================\n");
    printf("* Title: Collision Pi                                                                                      *\n");
    printf("* Author: rdvdev2 (rdvdev2@gmail.com)                                                                      *\n");
    printf("* Description: Calculate Pi with the extremely inefficient method of counting perfectly elastic collisions *\n");
    printf("============================================================================================================\n");

    // Get settings
    printf("\nInput the number of digits to calculate: ");
    scanf("%i", &digits);

    // Validate input
    if (digits <= 0) {
        printf("\nERROR: The number of digits can't be less than one!\n");
        printf("ERROR: Aborting...\n");
        return 1;
    }

    printf("\nSimulating collisions... ");

    // Time the simulation
    auto initTime = chrono::high_resolution_clock::now();

    // The masses and velocities for the physics simulations (All in the IS)
    double m2 = pow(100, digits - 1); // Depends on user input
    double v1 = 0;
    double v2 = -10;
    double collisions = 0;

    // Our physics engine loop
    while (!(v1 >= 0 && v2 > 0 && v2 >= v1)) { // Repeat while blocks can collide
        if (v1 < 0 && v1 <= v2) { // Check if we're colliding with the wall
            v1 = 0 - v1; // Just invert direction
        } else { // Else, we're colliding blocks, calculate using momentum and energy conservation
            double v2f = ((2 * v1) + ((m2 - 1) * v2)) / (m2 + 1);
            double v1f = v2f - v1 + v2;
            v1 = v1f;
            v2 = v2f;
        }
        collisions++; // Count the collision
    }

    double pi = collisions * pow(10, 1 - digits);

    // Stop timing
    auto endTime = chrono::high_resolution_clock::now();
    auto time = endTime - initTime;


    // Display results
    printf("Success!\n\n");
    printf("Simulation results\n");
    printf("------------------\n");
    printf("Number of collisions: %.0f\n", collisions);
    printf("Calculated Pi: %.*f\n", digits - 1, pi);
    printf("math.h Pi: %.*f\n", max(digits - 1, 2), M_PI);

    // Calculate and display relative error
    double relativeError = (abs(M_PI - pi) / M_PI) * 100;
    printf("Relative error (given math.h Pi is the exact value): %.10f%%\n", relativeError);

    // Calculate and display execution time
    auto numericTime = chrono::duration_cast<chrono::milliseconds>(time).count();
    if (numericTime > 10000) {
        numericTime = chrono::duration_cast<chrono::seconds>(time).count();
        printf("Execution time: %ld s\n", numericTime);
    } else {
        printf("Execution time: %ld ms\n", numericTime);
    }

    return 0;
}