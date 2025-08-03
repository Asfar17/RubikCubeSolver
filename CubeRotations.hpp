// CubeRotations.hpp
#ifndef CUBEROTATIONS_HPP
#define CUBEROTATIONS_HPP
#include "CubeState.hpp"

void rotateFaceCW(char face[3][3]);
void rotateFaceCCW(char face[3][3]);
void move_U(Cube &cube);
void move_U_prime(Cube &cube);
void move_R(Cube &cube);
void move_R_prime(Cube &cube);
void move_L(Cube &cube);
void move_L_prime(Cube &cube);
void move_F(Cube &cube);
void move_F_prime(Cube &cube);
void move_B(Cube &cube);
void move_B_prime(Cube &cube);
void move_D(Cube &cube);
void move_D_prime(Cube &cube);
void move_Y(Cube &cube);
void move_U2(Cube &cube);
void move_D2(Cube &cube);
void move_L2(Cube &cube);
void move_R2(Cube &cube);
void move_F2(Cube &cube);
void move_B2(Cube &cube);
void move_X(Cube &cube);      // Rotate the whole cube along the X-axis
void move_X_prime(Cube &cube);
void move_X2(Cube &cube);
void move_Y_prime(Cube &cube);
void move_Y2(Cube &cube);
void move_Z(Cube &cube);      // Rotate the whole cube along the Z-axis
void move_Z_prime(Cube &cube);
void move_Z2(Cube &cube);
void move_M(Cube &cube);        // Middle layer (between L and R), like L'
void move_M_prime(Cube &cube);
void move_E(Cube &cube);        // Equator layer (between U and D), like D'
void move_E_prime(Cube &cube);
void move_S(Cube &cube);        // Standing layer (between F and B), like F
void move_S_prime(Cube &cube);

#endif
