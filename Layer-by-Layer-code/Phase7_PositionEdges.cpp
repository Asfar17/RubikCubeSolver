#include "Phase7_PositionEdges.hpp"
#include "CubeRotations.hpp"
#include <iostream> // Optional: for debugging

void Phase7_PositionEdges::positionYellowEdges(Cube &cube) {
    int solvedEdges = countSolvedEdges(cube);
    int attempts = 0;

    while (solvedEdges < 4 && attempts < 4) {
        if (solvedEdges == 0) {
            applyEdgeCycle(cube);
        } else {
            while (!isEdgeCorrect(cube, 0)) {
                move_U(cube);
            }
            applyEdgeCycle(cube);
        }

        solvedEdges = countSolvedEdges(cube);
        ++attempts;
    }

    // Optional logging
    std::cout << "Total solved yellow edges: " << solvedEdges << "\n";
}

void Phase7_PositionEdges::applyEdgeCycle(Cube &cube) {
    move_F(cube); move_F(cube);
    move_U(cube);
    move_L(cube);
    move_R_prime(cube);
    move_F(cube); move_F(cube);
    move_L_prime(cube);
    move_R(cube);
    move_U(cube);
    move_F(cube); move_F(cube);
}

bool Phase7_PositionEdges::isEdgeCorrect(Cube &cube, int pos) {
    // U = 4, F = 0, L = 1, B = 3, R = 2
    switch (pos) {
        case 0: return cube.faces[4][1][2] == cube.faces[4][1][1] &&
                      cube.faces[0][0][1] == cube.faces[0][1][1]; // UF
        case 1: return cube.faces[4][0][1] == cube.faces[4][1][1] &&
                      cube.faces[1][0][1] == cube.faces[1][1][1]; // UL
        case 2: return cube.faces[4][1][0] == cube.faces[4][1][1] &&
                      cube.faces[3][0][1] == cube.faces[3][1][1]; // UB
        case 3: return cube.faces[4][2][1] == cube.faces[4][1][1] &&
                      cube.faces[2][0][1] == cube.faces[2][1][1]; // UR
        default: return false;
    }
}

int Phase7_PositionEdges::countSolvedEdges(Cube &cube) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (isEdgeCorrect(cube, i)) ++count;
    }
    return count;
}
