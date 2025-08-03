#ifndef CUBESTATE_HPP
#define CUBESTATE_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Enumeration for cube faces
enum Face { FRONT = 0, BACK, RIGHT, LEFT, UP, DOWN };

class Cube {
public:
    char faces[6][3][3];  // 6 faces, each 3x3 grid

    Cube();                             // Initialize the cube in solved state
    void inputCube();                   // Input cube state from user
    void printCube();                   // Display cube state

};

#endif // CUBESTATE_HPP
