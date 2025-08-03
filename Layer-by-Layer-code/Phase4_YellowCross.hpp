#ifndef PHASE4_YELLOWCROSS_HPP
#define PHASE4_YELLOWCROSS_HPP

#include "CubeState.hpp"

class Phase4_YellowCross {
public:
    void solveYellowCross(Cube &cube);

private:
    int yellowCrossState(const Cube &cube) const;
    void applyCrossAlgo(Cube &cube) const;
    void orientLShape(Cube &cube) const;
    void orientLine(Cube &cube) const;
};

#endif // PHASE4_YELLOWCROSS_HPP
