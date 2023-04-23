tempo_busca_MMP = table2array(oaksearch(:,"VarName3"));
tempo_busca_meu = table2array(oaksearch(:,"VarName4"));
tempo_inser_MMP = table2array(oaksearch(:,"VarName5"));
tempo_inser_meu = table2array(oaksearch(:,"VarName6"));

x = 1:100;
xlog = log(x);

p = polyfit(xlog, tempo_busca_meu, 2);
y_busca_2 = polyval(p,xlog);

p = polyfit(xlog, tempo_busca_MMP, 2);
y_busca = polyval(p,xlog);

p = polyfit(xlog, tempo_inser_meu, 1);
y_inser = polyval(p,xlog);

p = polyfit(xlog, tempo_inser_MMP, 1);
y_inser_2 = polyval(p,xlog);


hold on;
plot(x, tempo_busca_meu, 'LineWidth', 1 ,'Color', "g");
plot(x, tempo_busca_MMP, 'LineWidth', 1, 'Color', "b");
plot(x, y_busca, 'LineWidth', 2, 'Color', "r");
plot(x, y_busca_2, 'LineWidth', 2, 'Color', "r");
xlabel("Tamanho da amostra");
ylabel("Tempo");
legend("minha implementação", "stl::multimap");
title("Comparação dos algoritmos na busca");

figure;
hold on;
plot(x, tempo_inser_meu, 'LineWidth', 1, 'Color', "g");
plot(x, tempo_inser_MMP, 'LineWidth', 1, 'Color', "b");
plot(x, y_inser, 'LineWidth', 2, 'Color', "r");
plot(x, y_inser_2, 'LineWidth', 2, 'Color', "r");
xlabel("Tamanho da amostra");
ylabel("Tempo");
legend("minha implementação", "stl::multimap");
title("Comparação dos algoritmos na inserção");

figure;
scatter3(torusALU,"VarName1","VarName2","VarName3");
title("Gráfico do arquivo torusALU");
Unrecognized function or variable 'torusALU'.
Unrecognized function or variable 'torusALU'.
 