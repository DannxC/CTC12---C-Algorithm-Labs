#ifndef SSP_SOLVER
#define SSP_SOLVER


#include <vector>
#include <string>
#include <SubsetSumSolverAbstract.h>

/* tem que fazer o method solve para as 3 */

// método solve recebe como entrada:
// ● Input: vetor de long, inteiros contendo os pesos dos itens.
// ● value: capacidade da mochila
// Long aqui não é exagero, inclusive um dos geradores de instâncias teve que ser limitado para
// não estourar o tipo long.
//
// Como saída:
// ● O método deve retornar true se existe solução; e false caso contrário.
// ● Se o método retorna true, deve preencher, como saída, o vetor output com true/false (é
// char, mas usamos como bool), onde output[i] == true significa que o item i faz
// parte da solução encontrada.
// ○ Se não existe solução e o método retorna false, o vetor output não deve
// representar uma solução válida, obviamente.


class SSPSolverAluno2 : public SubsetSumSolverAbstract {

    
public:
    virtual bool solve(const std::vector< long> &input,
                        long value, std::vector< char> &output);
        
    virtual std::string getName() { return "A2"; }
    
}; 

class SSPSolverExtra : public SubsetSumSolverAbstract {

    
public:
    
    virtual bool solve(const std::vector< long> &input,
                        long value, std::vector< char> &output);
        
    virtual std::string getName() { return "EX"; }
    
}; 

class SSPSolverPD : public SubsetSumSolverAbstract {

public:
    
    virtual bool solve(const std::vector< long> &input,
                        long value, std::vector< char> &output);
    
    virtual std::string getName() { return "PD"; }
    
}; 

#endif
