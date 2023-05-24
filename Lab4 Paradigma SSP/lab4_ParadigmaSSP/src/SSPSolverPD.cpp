#include <SubsetSumSolver.h>

bool SSPSolverPD::solve(const std::vector<long>& input, long value, std::vector<char>& output) {
    // O número de elementos
    int n = input.size();

    // Criando a tabela para a programação dinâmica
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(value + 1, false));

    // A soma 0 pode ser alcançada por qualquer subconjunto (conjunto vazio)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Preenchendo o resto da tabela
    for (int i = 1; i <= n; i++) {
        for (long j = 1; j <= value; j++) {
            if (input[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - input[i - 1]];
        }
    }

    // Se a soma não pôde ser alcançada, retornamos false
    if (!dp[n][value])
        return false;

    // Determinando quais elementos fazem parte da solução
    output.resize(n, false);
    for (int i = n, j = value; j > 0; i--) {
        if (!dp[i - 1][j]) {
            output[i - 1] = true;
            j -= input[i - 1];
        }
    }

    return true;
}
