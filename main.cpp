//main.cpp
// This is the main file for the Rubik's Cube solver program.
#include <iostream>
#include "CubeState.hpp"
#include "MoveTest.hpp"
using namespace std;

int main() {
    Cube cube;

   
    cout<<"Testing the moves on the cube..."<<endl;
    testCubeMoves();
    return 0;
}
