//question: What is the purpose of the Phase1_WhiteCross.hpp file in the context of a Rubik's Cube solver program?
// The Phase1_WhiteCross.hpp file defines the Phase1_WhiteCross class, which is responsible for solving the white cross on a Rubik's Cube. It includes the declaration of the solveWhiteCross method that takes a Cube object as an argument and modifies it to achieve the white cross configuration.
// It also includes a function to align the top edge of the cube during the solving process.
#ifndef PHASE1_WHITECROSS_HPP
#define PHASE1_WHITECROSS_HPP

#include "CubeState.hpp"

class Phase1_WhiteCross {
public:
    void solveWhiteCross(Cube& cube);
};

void alignTopEdge(Cube &cube, int side, char targetColor);

#endif


