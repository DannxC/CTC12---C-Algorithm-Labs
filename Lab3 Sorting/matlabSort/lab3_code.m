function lab3_code()
    disp('--------------- Starting ---------------');
    % Reset
    close all
    clear

    disp('Executing main logic...');
    % Load every .csv data files
    MRGIMSRAND20020000 = readtable('MRG_I_MS_RAND_200_20000.csv');
    MRGRMSRAND20020000 = readtable("MRG_R_MS_RAND_200_20000.csv");
    QS1RMSAO20020000 = readtable('QS_1R_MS_AO_200_20000.csv');
    QS1RMSRAND20020000 = readtable('QS_1R_MS_RAND_200_20000.csv');
    QS2RMSAO20020000 = readtable('QS_2R_MS_AO_200_20000.csv');
    QS2RMSRAND20020000 = readtable('QS_2R_MS_RAND_200_20000.csv');
    QSFPMSAO20020000 = readtable('QS_FP_MS_AO_200_20000.csv');
    QSFPMSRAND20020000 = readtable('QS_FP_MS_RAND_200_20000.csv');
    RADIXMSRAND20020000 = readtable('RADIX_MS_RAND_200_20000.csv');
    STLSORTMSAO20020000 = readtable('STL_SORT_MS_AO_200_20000.csv');
    STLSORTMSRAND20020000 = readtable('STL_SORT_MS_RAND_200_20000.csv');

    disp('call Q1...');
    % Q1
    q1(STLSORTMSRAND20020000, QS1RMSRAND20020000, MRGIMSRAND20020000, RADIXMSRAND20020000);
    disp('Q1 done!')

    disp('call Q2...');
    % Q2
    q2(MRGIMSRAND20020000, MRGRMSRAND20020000);
    disp('Q2 done!')

    disp('call Q3...');
    % Q3
    q3(QS1RMSRAND20020000, QS2RMSRAND20020000);
    disp('Q3 done!')

    disp('call Q4...');
    % Q4
    q4(QS2RMSAO20020000, QSFPMSAO20020000, QS2RMSRAND20020000, QSFPMSRAND20020000);
    disp('Q4 done!')

    disp('Saving pictures...')
    % Salvar as figuras abertas
    save_figures();
    disp('All pictures saved!')
    disp('--------------- Finishing ---------------')
end

function q1(STLSORTMSRAND20020000, QS1RMSRAND20020000, MRGIMSRAND20020000, RADIXMSRAND20020000)
    % STLSort
    tempo_stl_Rand = table2array(STLSORTMSRAND20020000(:,'Var1'));
    tamanho_stl_Rand = table2array(STLSORTMSRAND20020000(:,'Var3'));
    recursive_stl_Rand = table2array(STLSORTMSRAND20020000(:,'Var4'));
    depth_stl_Rand = table2array(STLSORTMSRAND20020000(:,'Var5'));

    % QuickSort
    tempo_QS1R_Rand = table2array(QS1RMSRAND20020000(:,'Var1'));
    tamanho_QS1R_Rand = table2array(QS1RMSRAND20020000(:,'Var3'));
    recursive_QS1R_Rand = table2array(QS1RMSRAND20020000(:,'Var4'));
    depth_QS1R_Rand = table2array(QS1RMSRAND20020000(:,'Var5'));
    
    % MergeSort
    tempo_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var1"));
    tamanho_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var3"));
    recursive_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var4"));
    depth_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var5"));

    % RadixSort
    tempo_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"Var1"));
    tamanho_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"Var3"));
    recursive_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"Var4"));
    depth_RADIX_Rand = table2array(RADIXMSRAND20020000(:,"Var5"));

    % Plot
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_stl_Rand, tempo_stl_Rand, 'LineWidth', 2);
    hold on;
    plot(tamanho_QS1R_Rand, tempo_QS1R_Rand, 'LineWidth', 2);
    hold on;
    plot(tamanho_MRGI_Rand, tempo_MRGI_Rand, 'LineWidth', 2);
    hold on;
    plot(tamanho_RADIX_Rand, tempo_RADIX_Rand, 'LineWidth', 2);
    hold on;
    title("Q1: Tamanho do Vetor x Tempo", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms)', 'FontSize', 14, 'interpreter', 'latex');
    legend({'STL', 'QS1R', 'MRGI', 'RADIX'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    hold on;
end

function q2(MRGIMSRAND20020000, MRGRMSRAND20020000)

    % MergeSort_Iterative
    tempo_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var1"));
    tamanho_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var3"));
    recursive_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var4"));
    depth_MRGI_Rand = table2array(MRGIMSRAND20020000(:,"Var5"));
    
    % MergeSort_Recursive
    tempo_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"Var1"));
    tamanho_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"Var3"));
    recursive_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"Var4"));
    depth_MRGR_Rand = table2array(MRGRMSRAND20020000(:,"Var5"));

    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_MRGI_Rand, tempo_MRGI_Rand, 'LineWidth', 2)
    hold on;
    plot(tamanho_MRGR_Rand, tempo_MRGR_Rand, 'LineWidth', 2)
    hold on;
    title("Q2: Tamanho do Vetor x Tempo", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms)', 'FontSize', 14, 'interpreter', 'latex');
    legend({'MRGI', 'MRGR'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    hold on;

    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_MRGR_Rand, recursive_MRGR_Rand, 'LineWidth', 2)
    hold on;
    title("Q2: Numero de Chamadas Recursivas MRGR", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Chamadas Recursivas', 'FontSize', 14, 'interpreter', 'latex');
    grid on;
    hold on;
    
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_MRGR_Rand, depth_MRGR_Rand, 'LineWidth', 2)
    title("Q2: tamanho da Arvore MRGR", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Profundidade Pilha Recursao', 'FontSize', 14, 'interpreter', 'latex');
    grid on;
    hold on;
end

function q3(QS1RMSRAND20020000, QS2RMSRAND20020000)
    tempo_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"Var1"));
    tamanho_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"Var3"));
    recursive_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"Var4"));
    depth_QS1R_Rand = table2array(QS1RMSRAND20020000(:,"Var5"));
    
    tempo_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var1"));
    tamanho_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var3"));
    recursive_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var4"));
    depth_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var5"));
    
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_QS1R_Rand, tempo_QS1R_Rand, 'LineWidth', 2);
    hold on;
    plot(tamanho_QS2R_Rand, tempo_QS2R_Rand, 'LineWidth', 2);
    hold on;
    title("Q3: Tamanho do Vetor x Tempo", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms)', 'FontSize', 14, 'interpreter', 'latex');
    legend({'QS1R', 'QS2R'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    hold on;
    
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_QS1R_Rand, recursive_QS1R_Rand, 'LineWidth', 2);
    hold on;
    plot(tamanho_QS2R_Rand, recursive_QS2R_Rand, 'LineWidth', 2);
    hold on;
    title("Q3: Tamanho do Vetor x Chamadas Recursivas", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Chamadas Recursivas', 'FontSize', 14, 'interpreter', 'latex');
    legend({'QS1R', 'QS2R'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    hold on;
    
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_QS1R_Rand, depth_QS1R_Rand, 'LineWidth', 2);
    hold on;
    plot(tamanho_QS2R_Rand, depth_QS2R_Rand, 'LineWidth', 2);
    hold on;
    title("Q3: Tamanho do Vetor x Profundidade Pilha de Recursao", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Profundidade Pilha de Recursao', 'FontSize', 14, 'interpreter', 'latex');
    legend({'QS1R', 'QS2R'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    hold on;
end

function q4(QS2RMSAO20020000, QSFPMSAO20020000, QS2RMSRAND20020000, QSFPMSRAND20020000)
    tempo_QS2R_AO = table2array(QS2RMSAO20020000(:,"Var1"));
    tamanho_QS2R_AO = table2array(QS2RMSAO20020000(:,"Var3"));
    recursive_QS2R_AO = table2array(QS2RMSAO20020000(:,"Var4"));
    depth_QS2R_AO = table2array(QS2RMSAO20020000(:,"Var5"));
    
    tempo_QSFP_AO = table2array(QSFPMSAO20020000(:,"Var1"));
    tamanho_QSFP_AO = table2array(QSFPMSAO20020000(:,"Var3"));
    recursive_QSFP_AO = table2array(QSFPMSAO20020000(:,"Var4"));
    depth_QSFP_AO = table2array(QSFPMSAO20020000(:,"Var5"));
    
    tempo_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var1"));
    tamanho_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var3"));
    recursive_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var4"));
    depth_QS2R_Rand = table2array(QS2RMSRAND20020000(:,"Var5"));
    
    tempo_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"Var1"));
    tamanho_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"Var3"));
    recursive_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"Var4"));
    depth_QSFP_Rand = table2array(QSFPMSRAND20020000(:,"Var5"));
    
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_QS2R_Rand, tempo_QS2R_Rand, 'LineWidth', 2);
    hold on;
    plot(tamanho_QSFP_Rand, tempo_QSFP_Rand, 'LineWidth', 2);
    hold on;
    title("Q4: Tamanho do Vetor x Tempo (Vetor aleatorio)", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms)', 'FontSize', 14, 'interpreter', 'latex');
    legend({'Mediana de 3', 'Pivo Fixo'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    hold on;
    
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(tamanho_QS2R_AO, tempo_QS2R_AO, 'LineWidth', 2);
    hold on;
    plot(tamanho_QSFP_AO, tempo_QSFP_AO, 'LineWidth', 2);
    hold on;
    title("Q4: Tamanho do Vetor x Tempo (Vetor quase ordenado)", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms)', 'FontSize', 14, 'interpreter', 'latex');
    legend({'Mediana de 3', 'Pivo Fixo'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    hold on;
end

function save_figures()
    % Obter todos os objetos de figura abertos
    all_figures = findall(0, 'Type', 'figure');
    
    % Iterar sobre todas as figuras abertas
    for i = 1:length(all_figures)
        % Selecionar a figura atual
        current_figure = all_figures(i);
    
        % Obter o objeto do título da figura atual
        title_obj = get(get(current_figure.CurrentAxes, 'Title'), 'String');
    
        % Converter o título em uma string (caso não seja)
        if iscell(title_obj)
            title_str = strjoin(title_obj, '');
        else
            title_str = title_obj;
        end
    
        % Substituir espaços por underscores e remover caracteres não permitidos
        valid_filename = regexprep(title_str, '[^\w]', '_');
    
        % Salvar a figura como um arquivo .png usando o título como nome do arquivo
        saveas(current_figure, [valid_filename, '.png']);
    end
end