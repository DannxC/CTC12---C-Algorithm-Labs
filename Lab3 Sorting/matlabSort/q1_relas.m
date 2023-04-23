tempo_stl_Rand = table2array(STLSORTMSRAND20020000(:,"e02"));
tamanho_stl_Rand = table2array(STLSORTMSRAND20020000(:,"VarName3"));
recursive_stl_Rand = table2array(STLSORTMSRAND20020000(:,"e00"));
depth_stl_Rand = table2array(STLSORTMSRAND20020000(:,"e1"));

%figure;
%plot(tamanho_stl_Rand, tempo_stl_Rand, 'LineWidth', 2)
%title("stl: tamanho do vetor x tempo")
%xlabel("Tamanho")
%ylabel("Tempo(ms)")

tempo_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"e02"));
tamanho_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"VarName3"));
recursive_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"e00"));
depth_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"e1"));

%figure;
%plot(tamanho_QS1R_Rand, tempo_QS1R_Rand, 'LineWidth', 2)
%title("QS1R: tamanho do vetor x tempo")
%xlabel("Tamanho")
%ylabel("Tempo(ms)")

tempo_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"e02"));
tamanho_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"VarName3"));
recursive_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"e00"));
depth_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"e1"));

%figure;
%plot(tamanho_MRGI_Rand, tempo_MRGI_Rand, 'LineWidth', 2)
%title("MRGI: tamanho do vetor x tempo")
%xlabel("Tamanho")
%ylabel("Tempo(ms)")

tempo_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"e01"));
tamanho_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"VarName3"));
recursive_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"e00"));
depth_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"e1"));

%figure;
%plot(tamanho_RADIX_Rand, tempo_RADIX_Rand, 'LineWidth', 2)
%title("RADIX: tamanho do vetor x tempo")
%xlabel("Tamanho")
%ylabel("Tempo(ms)")

figure;
plot(tamanho_stl_Rand, tempo_stl_Rand,'g',tamanho_QS1R_Rand, tempo_QS1R_Rand,'b',tamanho_MRGI_Rand, tempo_MRGI_Rand,'y', tamanho_RADIX_Rand, tempo_RADIX_Rand,'r', 'LineWidth', 2)
title("Q1: tamanho do vetor x tempo")
xlabel("Tamanho do vetor")
ylabel("Tempo(ms)")
legend("stl","QS1R","MRGI","RADIX")
grid on
