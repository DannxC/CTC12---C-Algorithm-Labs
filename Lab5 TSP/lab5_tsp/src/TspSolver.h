#ifndef TSP_SOLVER
#define TSP_SOLVER

#include <TspReader.h>
#include <vector>


class TspSolver {
public:
    // you should fill percourse with a permutation that represents the TSP solution
    void solve(TspReader &tr, std::vector<int> &percourse);
}; 


#endif
