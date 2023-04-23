tempo_QS2R_AO = table2array(QS2RMSAO20020000(:,"e02"));
tamanho_QS2R_AO = table2array(QS2RMSAO20020000(:,"VarName3"));
recursive_QS2R_AO = table2array(QS2RMSAO20020000(:,"e1"));
depth_QS2R_AO = table2array(QS2RMSAO20020000(:,"e00"));

tempo_QSFP_AO = table2array(QSFPMSAO20020000(:,"e02"));
tamanho_QSFP_AO = table2array(QSFPMSAO20020000(:,"VarName3"));
recursive_QSFP_AO = table2array(QSFPMSAO20020000(:,"e1"));
depth_QSFP_AO = table2array(QSFPMSAO20020000(:,"e2"));

tempo_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"e02"));
tamanho_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"VarName3"));
recursive_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"e1"));
depth_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"e01"));

tempo_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"e02"));
tamanho_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"VarName3"));
recursive_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"e1"));
depth_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"e01"));

figure;
plot(tamanho_QS2R_Rand, tempo_QS2R_Rand,'g', tamanho_QSFP_Rand, tempo_QSFP_Rand,'r', 'LineWidth', 2)
title("Q4: tamanho do vetor x tempo (Vetor aleatorio)")
xlabel("Tamanho do vetor")
ylabel("Tempo(ms)")
legend("Mediana de 3","Pivo Fixo")
grid on


figure;
plot(tamanho_QS2R_AO, tempo_QS2R_AO,'g', tamanho_QSFP_AO, tempo_QSFP_AO,'r', 'LineWidth', 2)
title("Q4: tamanho do vetor x tempo (Vetor quase ordenado) ")
xlabel("Tamanho do vetor")
ylabel("Tempo(ms)")
legend("Mediana de 3","Pivo Fixo")
grid on