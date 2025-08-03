// CubeState.cpp
#include "CubeState.hpp"
#include <map>

Cube::Cube() {
    char colors[6] = {'R', 'O', 'B', 'G', 'Y', 'W'};
    for (int f = 0; f < 6; f++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                faces[f][i][j] = colors[f];
}

void Cube::inputCube() {
    const string faceNames[6] = {"FRONT", "BACK", "RIGHT", "LEFT", "UP", "DOWN"};
    for (int f = 0; f < 6; ++f) {
        cout << "Enter colors for " << faceNames[f] << " face (row-wise, 9 characters): ";
        string input;
        cin >> input;

        // Validate input length
        if (input.length() != 9) {
            cerr << "Invalid input length. Must be exactly 9 characters.\n";
            --f;
            continue;
        }

        // Fill the 3x3 grid for that face
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                faces[f][i][j] = input[i * 3 + j];
    }
}


void Cube::printCube() {
    std::string faceNames[6] = {"Front", "Back", "Right", "Left", "Up", "Down"};
    for (int f = 0; f < 6; f++) {
        std::cout << faceNames[f] << " face:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << faces[f][i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}


