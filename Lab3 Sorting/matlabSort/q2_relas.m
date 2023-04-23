tempo_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"e02"));
tamanho_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"VarName3"));
recursive_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"e00"));
depth_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"e1"));

tempo_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"e02"));
tamanho_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"VarName3"));
recursive_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"e1"));
depth_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"e00"));


figure;
plot(tamanho_MRGI_Rand, tempo_MRGI_Rand,'g', tamanho_MRGR_Rand, tempo_MRGR_Rand,'r', 'LineWidth', 2)
title("Q2: tamanho do vetor x tempo")
xlabel("Tamanho do vetor")
ylabel("Tempo(ms)")
legend("MRGI","MRGR")
grid on

figure;
plot(tamanho_MRGR_Rand, recursive_MRGR_Rand,'b', 'LineWidth', 2)
title("Q2:numero de chamadas recursivas MRGR")
xlabel("Tamanho do vetor")
ylabel("chamadas recursivas")
legend("chamadas recursivas")
grid on

figure;
plot(tamanho_MRGR_Rand, depth_MRGR_Rand,'b', 'LineWidth', 2)
title("Q2:tamanho da arvore MRGR")
xlabel("Tamanho do vetor")
ylabel("profundidade pilha recursao")
legend("profundidade pilha recursao")
grid on