#ifndef PHASE7_POSITIONEDGES_HPP
#define PHASE7_POSITIONEDGES_HPP

#include "CubeState.hpp"

class Phase7_PositionEdges {
public:
    void positionYellowEdges(Cube &cube);

private:
    void applyEdgeCycle(Cube &cube);
    bool isEdgeCorrect(Cube &cube, int pos);
    int countSolvedEdges(Cube &cube);
};

#endif // PHASE7_POSITIONEDGES_HPP
