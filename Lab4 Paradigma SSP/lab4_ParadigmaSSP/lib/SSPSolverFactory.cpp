
#include <SSPSolverFactory.h>


SubsetSumSolverAbstract* SSPSolverFactory::makeSSP(std::string name) {
    if (name == "BS" )
        return new SSPSolverBalsub();
    else if (name == "PD" )
        return new SSPSolverPD();
    else if (name == "A2" )
        return new SSPSolverAluno2();
    else if (name == "EX" )
        return new SSPSolverExtra();
    else if (name == "DD" )
        return new SSPSolverDecPis();
    else return nullptr;
    }
