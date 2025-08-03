#include "Phase6_PositionCorners.hpp"
#include "CubeRotations.hpp"
#include <iostream>
#include <unordered_set>

using namespace std;

void Phase6_PositionCorners::positionYellowCorners(Cube &cube) {
    int correctIndex = findCorrectCorner(cube);
    int attempts = 0;

    while (attempts < 4) {
        if (correctIndex == -1) {
            applyCornerPermutationAlgo(cube);
        } else {
            for (int i = 0; i < correctIndex; ++i) move_U(cube);
            applyCornerPermutationAlgo(cube);
        }

        correctIndex = findCorrectCorner(cube);
        ++attempts;
    }
}

void Phase6_PositionCorners::applyCornerPermutationAlgo(Cube &cube) {
    // R U R' U' R U R' U'
    move_U(cube);
    move_R(cube);
    move_U_prime(cube);
    move_L_prime(cube);
    move_U(cube);
    move_R_prime(cube);
    move_U_prime(cube);
    move_L(cube);
}

int Phase6_PositionCorners::findCorrectCorner(Cube &cube) {
    string ref = getCornerColor(cube, 0); // Reference: UFR

    for (int i = 0; i < 4; ++i) {
        string corner = getCornerColor(cube, i);
        if (isCornerInPlace(corner, ref)) return i;
    }
    return -1;
}

string Phase6_PositionCorners::getCornerColor(const Cube &cube, int idx) {
    switch (idx) {
        case 0: // UFR
            return {cube.faces[4][2][2], cube.faces[2][0][2], cube.faces[0][0][0]};
        case 1: // UFL
            return {cube.faces[4][2][0], cube.faces[1][0][0], cube.faces[2][0][0]};
        case 2: // UBL
            return {cube.faces[4][0][0], cube.faces[3][0][0], cube.faces[1][0][2]};
        case 3: // UBR
            return {cube.faces[4][0][2], cube.faces[0][0][2], cube.faces[3][0][2]};
        default:
            return "";
    }
}

bool Phase6_PositionCorners::isCornerInPlace(const string &corner, const string &ref) {
    unordered_set<char> refSet(ref.begin(), ref.end());
    for (char c : corner) {
        if (refSet.find(c) == refSet.end()) return false;
    }
    return true;
}
