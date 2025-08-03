// Phase3_SecondLayer.cpp
// Solves the second layer edges of a 3x3 Rubik's Cube using standard insert algorithms.

#include "Phase3_SecondLayer.hpp"
#include "CubeRotations.hpp"
#include <iostream>

using namespace std;

void Phase3_SecondLayer::solveSecondLayer(Cube &cube) {
    // Rotate and check all 4 faces to solve second-layer edges
    for (int i = 0; i < 4; ++i) {
        insertEdge(cube);
        move_Y(cube); // Rotate Y to check next face
    }
}

void Phase3_SecondLayer::insertEdge(Cube &cube) {
    for (int face = 0; face < 4; ++face) {
        char center = cube.faces[face][1][1];
        char rightCenter = cube.faces[(face + 1) % 4][1][1];
        char leftCenter  = cube.faces[(face + 3) % 4][1][1];

        char edgeTopColor    = cube.faces[4][2][1]; // Top front edge (U face)
        char edgeFrontColor  = cube.faces[face][0][1]; // Front upper row

        // If it matches for right insertion
        if (edgeTopColor == center && edgeFrontColor == rightCenter) {
            rightInsert(cube, face);
            return;
        }

        // If it matches for left insertion
        if (edgeTopColor == center && edgeFrontColor == leftCenter) {
            leftInsert(cube, face);
            return;
        }
    }
}

// Performs the standard right insert algorithm (U R U' R' U' F' U F)
void Phase3_SecondLayer::rightInsert(Cube &cube, int face) {
    move_U(cube);
    move_R(cube);
    move_U_prime(cube);
    move_R_prime(cube);
    move_U_prime(cube);
    move_F_prime(cube);
    move_U(cube);
    move_F(cube);
}

// Performs the standard left insert algorithm (U' L' U L U F U' F')
void Phase3_SecondLayer::leftInsert(Cube &cube, int face) {
    move_U_prime(cube);
    move_L_prime(cube);
    move_U(cube);
    move_L(cube);
    move_U(cube);
    move_F(cube);
    move_U_prime(cube);
    move_F_prime(cube);
}
