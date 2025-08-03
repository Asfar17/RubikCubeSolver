#pragma once

#include "CubeState.hpp"

class Phase3_SecondLayer {
public:
    void solveSecondLayer(Cube &cube);

private:
    void insertEdge(Cube &cube);
    void rightInsert(Cube &cube, int face);
    void leftInsert(Cube &cube, int face);
};
