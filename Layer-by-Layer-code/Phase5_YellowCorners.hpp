#ifndef PHASE5_YELLOWCORNERS_HPP
#define PHASE5_YELLOWCORNERS_HPP

#include "CubeState.hpp"

class Phase5_YellowCorners {
public:
    void solveYellowCorners(Cube &cube);

private:
    void applyCornerAlgo(Cube &cube);
    bool areAllYellowCornersOriented(const Cube &cube);
    bool isUFRCornerOriented(const Cube &cube);
    int findIncorrectCornerIndex(const Cube &cube);
};

#endif // PHASE5_YELLOWCORNERS_HPP
