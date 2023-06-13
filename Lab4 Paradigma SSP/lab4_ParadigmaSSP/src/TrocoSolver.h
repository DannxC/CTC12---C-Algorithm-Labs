#ifndef TROCO_SOLVER
#define TROCO_SOLVER


#include <vector>
#include <string>
#include <TrocoSolverAbstract.h>


class TrocoSolverDivConquer : public TrocoSolverAbstract {
private:
    long recursivecalls;

    // Declaração do método Recursivo
    //bool DCsolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins);
    void DCsolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins, std::vector<unsigned int> &best_coins, unsigned int &best_num_coins, unsigned int num_coins);

public:
    
    virtual void solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins); 
    
     /// how many recursive calls in the last run of solve()
    virtual long countRecursiveCalls() { return recursivecalls; }
    
    virtual std::string getName() { return "DC"; }
    
}; 

class TrocoSolverPD : public TrocoSolverAbstract {
private:

    void PDsolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins);

public:
    
    virtual void solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins); 
    
    virtual std::string getName() { return "PD"; }
    
}; 

class TrocoSolverGreedy : public TrocoSolverAbstract {

private:

    void Gsolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins);

public:
    
    virtual void solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins); 

    virtual std::string getName() { return "GR"; }    
}; 


#endif
