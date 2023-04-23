tempo_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"e02"));
tamanho_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"VarName3"));
recursive_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"e1"));
depth_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"e00"));

tempo_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"e02"));
tamanho_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"VarName3"));
recursive_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"e1"));
depth_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"e01"));

figure;
plot(tamanho_QS1R_Rand, tempo_QS1R_Rand,'g', tamanho_QS2R_Rand, tempo_QS2R_Rand,'r', 'LineWidth', 2)
title("Q3: tamanho do vetor x tempo")
xlabel("Tamanho do vetor")
ylabel("Tempo(ms)")
legend("QS1R","QS2R")
grid on

figure;
plot(tamanho_QS1R_Rand, recursive_QS1R_Rand,'g', tamanho_QS2R_Rand, recursive_QS2R_Rand,'r', 'LineWidth', 2)
title("Q3: tamanho do vetor x chamadas recursivas")
xlabel("Tamanho do vetor")
ylabel("chamadas recursivas")
legend("QS1R","QS2R")
grid on

figure;
plot(tamanho_QS1R_Rand, depth_QS1R_Rand,'g', tamanho_QS2R_Rand, depth_QS2R_Rand,'r', 'LineWidth', 2)
title("Q3: tamanho do vetor x profundidade pilha de recursao")
xlabel("Tamanho do vetor")
ylabel("profundidade pilha recursao")
legend("QS1R","QS2R")
grid on