// MoveTest.cpp
#include "MoveTest.hpp"
#include "CubeRotations.hpp"
#include <iostream>

void testCubeMoves() {
    Cube cube;
     
    cout << "Enter the scrambled cube state:" << endl;
    cube.inputCube();

    std::cout << "Initial Cube State:\n";
    cube.printCube();
    
    std::cout << "\n--- Applying move D' ---\n";
    move_D_prime(cube);
    cube.printCube();

    std::cout << "\n--- Applying move U' ---\n";
    move_U_prime(cube);
    cube.printCube();

    std::cout << "\n--- Applying move L' ---\n";
    move_L_prime(cube);
    cube.printCube();

   
    std::cout << "\n--- Applying move R' ---\n";
    move_R_prime(cube);
    cube.printCube();




}
