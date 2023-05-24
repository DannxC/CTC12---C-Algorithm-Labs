#include <SubsetSumSolver.h>
#include <numeric>  // Para std::accumulate

// Função recursiva para o método de backtracking
bool backtracking(const std::vector<long>& input, long value, std::vector<char>& output, long currentSum, long remainingSum, int currentIndex) {
    // Base case: Se a soma atual é igual ao valor, encontramos uma solução
    if (currentSum == value) {
        return true;
    }
    
    // Base case: Se nós iteramos por todos os elementos e não encontramos uma solução ou se os elementos restantes não podem somar "value"
    if (currentIndex == input.size() || currentSum + remainingSum < value) {
        return false;
    }
    
    // Incluímos o elemento atual e procuramos o resto do valor na próxima etapa
    output[currentIndex] = true;
    if (backtracking(input, value, output, currentSum + input[currentIndex], remainingSum - input[currentIndex], currentIndex + 1)) {
        return true;
    }
    
    // Se incluir o elemento atual não leva a uma solução, nós excluímos e procuramos o resto do valor na próxima etapa
    output[currentIndex] = false;
    if (backtracking(input, value, output, currentSum, remainingSum - input[currentIndex], currentIndex + 1)) {
        return true;
    }

    // Se nenhuma das opções acima retornar verdadeiro, então não existe solução
    return false;
}

// Aluno2: segunda solução do aluno = Meet-in-the-Middle OU Branch & Bound
bool SSPSolverAluno2::solve(const std::vector<long>& input, long value, std::vector<char>& output) {
    // Inicializando o vetor de saída com false
    output.assign(input.size(), false);

    // Calculando a soma total dos elementos na entrada
    long totalSum = std::accumulate(input.begin(), input.end(), 0L);

    // Chamando a função de backtracking
    return backtracking(input, value, output, 0, totalSum, 0);
}
