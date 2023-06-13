#include <TrocoSolver.h>
#include <algorithm>

void TrocoSolverDivConquer::solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins) {
    // Inicia o vetor de moedas com zeros
    coins.resize(denom.size(), 0);

    // Vetor para armazenar a melhor solução encontrada
    std::vector<unsigned int> best_coins(denom.size(), 0);

    // Define o melhor número de moedas como um valor muito alto inicialmente
    unsigned int best_num_coins = value + 1;

    // Chamada inicial para a função recursiva
    DCsolve(denom, value, coins, best_coins, best_num_coins, 0);

    // Copia a melhor solução encontrada para o vetor de moedas
    coins = best_coins;
}

void TrocoSolverDivConquer::DCsolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins, std::vector<unsigned int> &best_coins, unsigned int &best_num_coins, unsigned int num_coins) {
    // Caso Base
    if (value == 0) {
        // Se a solução atual usa menos moedas que a melhor encontrada até agora
        if (num_coins < best_num_coins) {
            // Atualiza a melhor solução e o melhor número de moedas
            best_coins = coins;
            best_num_coins = num_coins;
        }
        return;
    }

    // Verifica moeda por moeda disponível, começando da maior para a menor
    for (int i = denom.size() - 1; i >= 0; i--) {
        if (denom[i] > value) { continue; }     // Essa moeda não serve

        // Acha indice auxiliar para o vetor resposta (coins)
        int idx_aux = 0;
        for(; denom[idx_aux] != denom[i]; idx_aux++);

        // Adiciona a moeda atual à solução
        coins[idx_aux]++;
        
        // Procura uma solução com o valor restante
        DCsolve(denom, value - denom[i], coins, best_coins, best_num_coins, num_coins + 1);

        // Remove a moeda atual da solução (backtracking)
        coins[idx_aux]--;
    }
}
