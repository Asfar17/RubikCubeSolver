#include "Phase4_YellowCross.hpp"
#include "CubeRotations.hpp"
#include <iostream>

void Phase4_YellowCross::solveYellowCross(Cube &cube) {
    int state = yellowCrossState(cube);
    
    while (state != 4) {
        switch (state) {
            case 0:
                applyCrossAlgo(cube); // Dot case
                break;
            case 1:
                orientLShape(cube);
                applyCrossAlgo(cube); // L-shape
                break;
            case 2:
                orientLine(cube);
                applyCrossAlgo(cube); // Line
                break;
            default:
                break;
        }
        state = yellowCrossState(cube); // Recalculate state after each attempt
    }
}

int Phase4_YellowCross::yellowCrossState(const Cube &cube) const {
    int count = 0;
    const char center = 'Y';

    bool up = cube.faces[4][0][1] == center;
    bool left = cube.faces[4][1][0] == center;
    bool right = cube.faces[4][1][2] == center;
    bool down = cube.faces[4][2][1] == center;

    if (up) count++;
    if (left) count++;
    if (right) count++;
    if (down) count++;

    if (count == 0) return 0; // Dot
    if (count == 2 && ((up && down) || (left && right))) return 2; // Line
    if (count == 2) return 1; // L-shape
    return 4; // Cross complete
}

void Phase4_YellowCross::applyCrossAlgo(Cube &cube) const {
    move_F(cube);
    move_R(cube);
    move_U(cube);
    move_R_prime(cube);
    move_U_prime(cube);
    move_F_prime(cube);
}

void Phase4_YellowCross::orientLShape(Cube &cube) const {
    // Rotate U layer until L-shape is at top-left
    for (int i = 0; i < 4; ++i) {
        if (cube.faces[4][0][1] == 'Y' && cube.faces[4][1][0] == 'Y')
            return;
        move_U(cube);
    }
}

void Phase4_YellowCross::orientLine(Cube &cube) const {
    // If horizontal, do nothing; if vertical, rotate once
    if (cube.faces[4][1][0] == 'Y' && cube.faces[4][1][2] == 'Y') return;
    move_U(cube);
}
