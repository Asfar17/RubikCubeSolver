// Phase2_CornerInsert.cpp
// This file implements the Phase2_CornerInsert class, which solves the first layer corners on 
#include "Phase2_CornerInsert.hpp"
#include "CubeRotations.hpp" 
#include <iostream>

void Phase2_CornerInsert::solveFirstLayerCorners(Cube &cube) {
    std::cout << "Solving White Corners..." << std::endl;

    // Try to insert top white corners
    for (int cycle = 0; cycle < 4; ++cycle) {
        char up = cube.faces[UP][2][2];
        char right = cube.faces[RIGHT][0][0];
        char front = cube.faces[FRONT][0][2];

        if (up == 'W' || right == 'W' || front == 'W') {
            // Use algorithm: R' D' R D
            move_R_prime(cube);
            move_D_prime(cube);
            move_R(cube);
            move_D(cube);
        }

        move_U(cube); // Rotate U face to check next corner
    }

    // Fix misoriented white corners in bottom layer
    for (int cycle = 0; cycle < 4; ++cycle) {
        char down = cube.faces[DOWN][0][0];
        char left = cube.faces[LEFT][2][2];
        char front = cube.faces[FRONT][2][0];

        if (down == 'W' || left == 'W' || front == 'W') {
            // Pop out misoriented corner using: R D R' D'
            move_R(cube);
            move_D(cube);
            move_R_prime(cube);
            move_D_prime(cube);
        }

        move_D(cube); // Rotate bottom face to fix next one
    }

    std::cout << "White corners solved!" << std::endl;
}
