// CubeRotations.cpp
#include "CubeRotations.hpp"

void rotateFaceCW(char face[3][3]) {
    char tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[j][2 - i] = face[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            face[i][j] = tmp[i][j];
}

void rotateFaceCCW(char face[3][3]) {
    char tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[2 - j][i] = face[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            face[i][j] = tmp[i][j];
}

void move_U(Cube &cube) {
    rotateFaceCW(cube.faces[UP]);
    char tmp[3];
    
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[FRONT][0][i];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][0][i] = cube.faces[LEFT][0][i];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][0][i] = cube.faces[BACK][0][i];
    for (int i = 0; i < 3; i++) cube.faces[BACK][0][i] = cube.faces[RIGHT][0][i];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][0][i] = tmp[i];
   
}

void move_U_prime(Cube &cube) {
    rotateFaceCCW(cube.faces[UP]);
    char tmp[3];
     for (int i = 0; i < 3; i++) tmp[i] = cube.faces[FRONT][0][i];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][0][i] = cube.faces[RIGHT][0][i];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][0][i] = cube.faces[BACK][0][i];
    for (int i = 0; i < 3; i++) cube.faces[BACK][0][i] = cube.faces[LEFT][0][i];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][0][i] = tmp[i];
    
}

void move_R(Cube &cube) {
    rotateFaceCW(cube.faces[RIGHT]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][i][2];
    for (int i = 0; i < 3; i++) cube.faces[UP][i][2] = cube.faces[FRONT][i][2];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][i][2] = cube.faces[DOWN][i][2];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][i][2] = cube.faces[BACK][2 - i][0];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2 - i][0] = tmp[i];
}

void move_R_prime(Cube &cube) {
    rotateFaceCCW(cube.faces[RIGHT]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][i][2];
    for (int i = 0; i < 3; i++) cube.faces[UP][i][2] = cube.faces[BACK][2 - i][0];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2 - i][0] = cube.faces[DOWN][i][2];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][i][2] = cube.faces[FRONT][i][2];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][i][2] = tmp[i];
}

void move_L(Cube &cube) {
    rotateFaceCW(cube.faces[LEFT]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][i][0];
    for (int i = 0; i < 3; i++) cube.faces[UP][i][0] = cube.faces[BACK][2 - i][2];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2 - i][2] = cube.faces[DOWN][i][0];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][i][0] = cube.faces[FRONT][i][0];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][i][0] = tmp[i];
}

void move_L_prime(Cube &cube) {
    rotateFaceCCW(cube.faces[LEFT]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][i][0];
    for (int i = 0; i < 3; i++) cube.faces[UP][i][0] = cube.faces[FRONT][i][0];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][i][0] = cube.faces[DOWN][i][0];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][i][0] = cube.faces[BACK][2 - i][2];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2 - i][2] = tmp[i];
}

void move_F(Cube &cube) {
    rotateFaceCW(cube.faces[FRONT]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][2][i];
    for (int i = 0; i < 3; i++) cube.faces[UP][2][i] = cube.faces[LEFT][2 - i][2];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][i][2] = cube.faces[DOWN][0][i];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][0][i] = cube.faces[RIGHT][2 - i][0];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][i][0] = tmp[i];
}

void move_F_prime(Cube &cube) {
    rotateFaceCCW(cube.faces[FRONT]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][2][i];
    for (int i = 0; i < 3; i++) cube.faces[UP][2][i] = cube.faces[RIGHT][i][0];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][2 - i][0] = cube.faces[DOWN][0][i];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][0][i] = cube.faces[LEFT][i][2];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][2 - i][2] = tmp[i];
}

void move_B(Cube &cube) {
    rotateFaceCW(cube.faces[BACK]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][0][i];
    for (int i = 0; i < 3; i++) cube.faces[UP][0][i] = cube.faces[RIGHT][i][2];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][2 - i][2] = cube.faces[DOWN][2][i];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][2][i] = cube.faces[LEFT][i][0];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][2 - i][0] = tmp[i];
}

void move_B_prime(Cube &cube) {
    rotateFaceCCW(cube.faces[BACK]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][0][i];
    for (int i = 0; i < 3; i++) cube.faces[UP][0][i] = cube.faces[LEFT][2 - i][0];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][i][0] = cube.faces[DOWN][2][i];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][2][i] = cube.faces[RIGHT][2 - i][2];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][i][2] = tmp[i];
}

void move_D(Cube &cube) {
    rotateFaceCW(cube.faces[DOWN]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[FRONT][2][i];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][2][i] = cube.faces[RIGHT][2][i];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][2][i] = cube.faces[BACK][2][i];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2][i] = cube.faces[LEFT][2][i];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][2][i] = tmp[i];
    
}

void move_D_prime(Cube &cube) {
    rotateFaceCCW(cube.faces[DOWN]);
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[FRONT][2][i];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][2][i] = cube.faces[LEFT][2][i];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][2][i] = cube.faces[BACK][2][i];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2][i] = cube.faces[RIGHT][2][i];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][2][i] = tmp[i];
    
}

void move_Y(Cube &cube) {
    Cube temp = cube;
    rotateFaceCW(cube.faces[UP]);
    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                cube.faces[i][r][c] = temp.faces[i + 1][r][c];
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            cube.faces[3][r][c] = temp.faces[0][r][c];
}
void move_U2(Cube &cube) {
    move_U(cube);
    move_U(cube);
}

void move_D2(Cube &cube) {
    move_D(cube);
    move_D(cube);
}

void move_L2(Cube &cube) {
    move_L(cube);
    move_L(cube);
}

void move_R2(Cube &cube) {
    move_R(cube);
    move_R(cube);
}
void move_F2(Cube &cube) {
    move_F(cube);
    move_F(cube);
}       
void move_B2(Cube &cube) {
    move_B(cube);
    move_B(cube);
}
void move_X(Cube &cube) {
    Cube temp = cube;
    rotateFaceCW(cube.faces[RIGHT]);
    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                cube.faces[i][r][c] = temp.faces[i + 1][r][c];
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            cube.faces[3][r][c] = temp.faces[0][r][c];
}
void move_X_prime(Cube &cube) {
    Cube temp = cube;
    rotateFaceCCW(cube.faces[RIGHT]);
    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                cube.faces[i][r][c] = temp.faces[i + 1][r][c];
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            cube.faces[3][r][c] = temp.faces[0][r][c];
}
void move_X2(Cube &cube) {
    move_X(cube);
    move_X(cube);
}
void move_Y_prime(Cube &cube) {
    Cube temp = cube;
    rotateFaceCCW(cube.faces[UP]);
    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                cube.faces[i][r][c] = temp.faces[i + 1][r][c];
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            cube.faces[3][r][c] = temp.faces[0][r][c];
}
void move_Y2(Cube &cube) {
    move_Y(cube);
    move_Y(cube);
}
void move_Z(Cube &cube) {
    Cube temp = cube;
    rotateFaceCW(cube.faces[BACK]);
    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                cube.faces[i][r][c] = temp.faces[i + 1][r][c];
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            cube.faces[3][r][c] = temp.faces[0][r][c];
}

void move_Z_prime(Cube &cube) {
    Cube temp = cube;
    rotateFaceCCW(cube.faces[BACK]);
    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                cube.faces[i][r][c] = temp.faces[i + 1][r][c];
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            cube.faces[3][r][c] = temp.faces[0][r][c];
}
void move_Z2(Cube &cube) {
    move_Z(cube);
    move_Z(cube);
}
void move_M(Cube &cube) {
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][i][1];
    for (int i = 0; i < 3; i++) cube.faces[UP][i][1] = cube.faces[DOWN][i][1];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][i][1] = tmp[i];
}
void move_M_prime(Cube &cube) {
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[UP][i][1];
    for (int i = 0; i < 3; i++) cube.faces[UP][i][1] = cube.faces[DOWN][i][1];
    for (int i = 0; i < 3; i++) cube.faces[DOWN][i][1] = tmp[i];
}
void move_E(Cube &cube) {
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[LEFT][1][i];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][1][i] = cube.faces[RIGHT][1][i];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][1][i] = tmp[i];
}
void move_E_prime(Cube &cube) {
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[LEFT][1][i];
    for (int i = 0; i < 3; i++) cube.faces[LEFT][1][i] = cube.faces[RIGHT][1][i];
    for (int i = 0; i < 3; i++) cube.faces[RIGHT][1][i] = tmp[i];
}
void move_S(Cube &cube) {
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[FRONT][i][1];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][i][1] = cube.faces[BACK][2 - i][1];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2 - i][1] = tmp[i];
}
void move_S_prime(Cube &cube) {
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube.faces[FRONT][i][1];
    for (int i = 0; i < 3; i++) cube.faces[FRONT][i][1] = cube.faces[BACK][2 - i][1];
    for (int i = 0; i < 3; i++) cube.faces[BACK][2 - i][1] = tmp[i];
}

// The above functions implement the basic rotations and moves for a Rubik's Cube.
// Each function modifies the cube's state by rotating the specified face and adjusting the adjacent faces accordingly
