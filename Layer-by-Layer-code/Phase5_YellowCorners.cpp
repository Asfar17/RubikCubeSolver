#include "Phase5_YellowCorners.hpp"
#include "CubeRotations.hpp"
#include <iostream>
using namespace std;

void Phase5_YellowCorners::solveYellowCorners(Cube &cube) {
    while (!areAllYellowCornersOriented(cube)) {
        int idx = findIncorrectCornerIndex(cube);
        
        // Rotate U to bring incorrect corner to UFR
        for (int i = 0; i < idx; ++i) {
            move_U(cube);
        }

        int tries = 0;
        while (!isUFRCornerOriented(cube) && tries < 3) {
            applyCornerAlgo(cube);
            ++tries;
        }

        // Move to next corner
        move_U(cube);
    }

    // Restore solved UFR to correct position (adjust final orientation)
    while (cube.faces[4][2][2] != 'Y') {
        move_U(cube);
    }
}

// Corner orientation algorithm: R' D' R D
void Phase5_YellowCorners::applyCornerAlgo(Cube &cube) {
    move_R_prime(cube);
    move_D_prime(cube);
    move_R(cube);
    move_D(cube);
}

bool Phase5_YellowCorners::areAllYellowCornersOriented(const Cube &cube) {
    return (cube.faces[4][0][0] == 'Y' &&
            cube.faces[4][0][2] == 'Y' &&
            cube.faces[4][2][0] == 'Y' &&
            cube.faces[4][2][2] == 'Y');
}

bool Phase5_YellowCorners::isUFRCornerOriented(const Cube &cube) {
    return cube.faces[4][2][2] == 'Y';
}

// Returns 0–3 representing position of misoriented corner on top face
int Phase5_YellowCorners::findIncorrectCornerIndex(const Cube &cube) {
    if (cube.faces[4][2][2] != 'Y') return 0; // UFR
    if (cube.faces[4][2][0] != 'Y') return 1; // UFL
    if (cube.faces[4][0][0] != 'Y') return 2; // UBL
    if (cube.faces[4][0][2] != 'Y') return 3; // UBR
    return 0;
}
