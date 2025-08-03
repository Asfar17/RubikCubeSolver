#ifndef PHASE6_POSITIONCORNERS_HPP
#define PHASE6_POSITIONCORNERS_HPP

#include "CubeState.hpp"
#include <string>

class Phase6_PositionCorners {
public:
    void positionYellowCorners(Cube &cube);

private:
    void applyCornerPermutationAlgo(Cube &cube);
    int findCorrectCorner(Cube &cube);
    std::string getCornerColor(const Cube &cube, int idx);
    bool isCornerInPlace(const std::string &corner, const std::string &ref);
};

#endif
