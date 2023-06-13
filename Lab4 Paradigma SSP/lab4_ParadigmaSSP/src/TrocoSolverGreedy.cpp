#include <TrocoSolver.h>

void TrocoSolverGreedy::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {
    // Reinicia o vetor de moedas
    coins.resize(denom.size(), 0);
    
    // Solução Gulosa (Greedy)
    Gsolve(denom, value, coins);
}

void TrocoSolverGreedy::Gsolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {
    int currentChange = value;

    // Itera de trás pra frente
    for (int i = denom.size() - 1; i >= 0; i--) {
        while (denom[i] <= currentChange) {
            coins[i]++;                     // Incrementa a quantidade de moedas da denominação atual
            currentChange -= denom[i];      // Subtrai o valor da denominação atual do troco atual
        }
        if (currentChange == 0) { break; }  // Se o troco atual for zero, interrompe o loop
    }
}
