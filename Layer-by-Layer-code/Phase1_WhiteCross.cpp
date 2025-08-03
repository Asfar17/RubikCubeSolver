// Phase1_WhiteCross.cpp
// This file implements the Phase1_WhiteCross class, which solves the white cross on a Rubik's Cube.

#include "Phase1_WhiteCross.hpp"
#include "CubeRotations.hpp"
#include <iostream>

void Phase1_WhiteCross::solveWhiteCross(Cube& cube) {
    std::cout << "Solving White Cross..." << std::endl;

    char white = 'W';
    bool crossDone = false;
    int loopSafety = 0;

    while (!crossDone && loopSafety < 30) {
        crossDone = true;

        for (int side = 0; side < 4; side++) { // FRONT, RIGHT, BACK, LEFT
            char centerColor = cube.faces[side][1][1];

            // Check if white edge is in correct position
            if (!(cube.faces[DOWN][0][1] == white && cube.faces[side][2][1] == centerColor)) {
                crossDone = false;

                // If white edge is in UP face
                if (cube.faces[UP][2][1] == white) {
                    alignTopEdge(cube, side, centerColor);
                    move_F(cube);
                    move_F(cube); // 180°
                }
                // White edge in FRONT face top row
                else if (cube.faces[side][0][1] == white) {
                    move_U(cube);
                }
                // White edge in FRONT face middle row (right edge)
                else if (cube.faces[side][1][2] == white) {
                    move_R(cube);
                    move_U(cube);
                    move_R_prime(cube);
                }
                // White edge in FRONT face middle row (left edge)
                else if (cube.faces[side][1][0] == white) {
                    move_L_prime(cube);
                    move_U_prime(cube);
                    move_L(cube);
                }
                // White edge in FRONT face bottom row
                else if (cube.faces[side][2][1] == white) {
                    move_F(cube);
                    move_U(cube);
                    move_R(cube);
                    move_U_prime(cube);
                    move_R_prime(cube);
                    move_F_prime(cube);
                }
                // Flipped edge in DOWN face
                else if (cube.faces[DOWN][0][1] == white && cube.faces[side][2][1] != centerColor) {
                    move_F(cube);
                    move_U(cube);
                    move_R(cube);
                }
            }
        }

        loopSafety++;
    }

    if (loopSafety >= 30) {
        std::cout << "Warning: White cross solving loop exceeded safety limit!" << std::endl;
    } else {
        std::cout << "White cross solved successfully!" << std::endl;
    }
}

// alignTopEdge - NOT a member of Phase1_WhiteCross
void alignTopEdge(Cube& cube, int side, char centerColor) {
    // Rotate the UP face to align the white edge with the correct side
    int rotateCount = 0;
    while (cube.faces[UP][2][1] != centerColor && rotateCount < 4) {
        move_U(cube);
        rotateCount++;
    }

    // Now the white edge is aligned
    move_F(cube);
}
