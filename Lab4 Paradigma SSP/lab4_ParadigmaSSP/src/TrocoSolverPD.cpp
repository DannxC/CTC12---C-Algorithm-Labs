#include <TrocoSolver.h>

void TrocoSolverPD::solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins) {
    // Reinicia o vetor de moedas
    coins.resize(denom.size(), 0);

    // Solução com Programação Dinâmica
    PDsolve(denom, value, coins);
}

void TrocoSolverPD::PDsolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {
    
    // Inicializa vetor para guardar o número de moedas utilizadas
    // Tamanho value + 1 para considerar a solução de troco 0 também
    std::vector<unsigned int> minNumberCoins(value + 1);
    // Solução ótima para troco de valor 0
    minNumberCoins[0] = 0;

    // Vetor para guardar as últimas moedas utilizadas na solução ótima
    // Já inicializa zerado
    std::vector<unsigned int> lastCoins(value + 1);
    lastCoins[0] = 0;

    // Itera nas colunas da tabela
    for (int cents = 1; cents <= value; cents++) {
        int numberCoins_temp = cents;       // Solução provisória (todas as moedas de 1 centavo)
        int lastCoin_temp = 1;          // Última moeda desta solução provisória

        // Att valores da "tabela"
        for (int j = 0; j < denom.size(); j++) {
            if (denom[j] > cents) { continue; }     // Essa moeda não serve
            if (minNumberCoins[cents - denom[j]] + 1 < numberCoins_temp) {
                numberCoins_temp = minNumberCoins[cents - denom[j]] + 1;
                lastCoin_temp = denom[j];
            }
        }

        minNumberCoins[cents] = numberCoins_temp;  // Solução para troco == cents
        lastCoins[cents] = lastCoin_temp;       // Última moeda dessa solução
    }

    // Por fim, recuperamos o vetor resposta a partir dos vetores pré-encontrados
    int idx = minNumberCoins.size() - 1;
    while(minNumberCoins[idx] != 0) {
        // Acha indice auxiliar para o vetor resposta (coins), que é o mesmo do vetor denom.
        int idx_aux = 0;
        for(; denom[idx_aux] != lastCoins[idx]; idx_aux++);
        coins[idx_aux]++;

        // Att idx - desconta do valor da ultima moeda usada
        idx -= lastCoins[idx];
    }
}