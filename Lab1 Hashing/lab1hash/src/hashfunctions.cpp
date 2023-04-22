#include "hashfunctions.h"

// DICA: existe o operador : na classe std::string
// e nas classes std::vector e nas classes std::Container em geral
// i.e., a mesma sintaxe funciona tambem com outras estruturas de dados
// use assim:
// for (char c : mystring ) {   
//     do some stuff with c 
// }
// onde 'mystring' eh so o nome da variavel
// eh mais facil do que pensar se comeca com 0 ou com 1, se termina em size() ou em size()-1, se eh < ou <=, etc.
// exemplo completo no final: https://en.cppreference.com/w/cpp/container/vector

// IMPLEMENTE HASH POR DIVISAO (com soma, nao XOR)
// obviamente, considere todos os caracteres
// usar so o primeiro caractere eh so um exemplo didatico do que NAO fazer,
// seria estupido demais para usar na pratica.
//
// porque existe 'return 0' neste codigo? 
// para executar os testes, mesmo falhando, eh preciso compilar
// assim, eh preciso retornar algum valor.
// ** o aluno deve implementar a funcao completa e retornar o valor correto **
int hashdiv(std::string str, int m ) {
    int char_sum = 0;
    for(char c : str) {
        char_sum += int(c);
    }

    return char_sum % m;
}//hashdiv

// convenience function to fix the size to 29
int hashdiv29(std::string str) {
    return hashdiv(str, 29);
}


