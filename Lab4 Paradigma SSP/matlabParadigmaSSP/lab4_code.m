function lab4_code()
    disp('--------------- Starting ---------------');
    % Reset
    close all
    clear

    disp('Executing main logic...');


    % Load every .dat data files

    % OBS: Cada linha de texto tem o formato
    % <int>,<float>,<int>,<int>
    % Correspondendo a
    % <input size>, <average execution time>, <number of positive responses>, <number of trials>

    % SSP DD (Backtracking)
    SSP_DD_AVIS = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_DD_DD_AVIS.dat');
    SSP_DD_EVOD = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_DD_DD_EVOD.dat');
    SSP_DD_P3   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_DD_DD_P3.dat');
    SSP_DD_P4   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_DD_DD_P4.dat');
    SSP_DD_P5   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_DD_DD_P5.dat');
    SSP_DD_RAND = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_DD_DD_RAND.dat');

    % SSP A2 (Backtracking)
    SSP_A2_AVIS = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_A2_A2_AVIS.dat');
    SSP_A2_EVOD = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_A2_A2_EVOD.dat');
    SSP_A2_P3   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_A2_A2_P3.dat');
    SSP_A2_P4   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_A2_A2_P4.dat');
    SSP_A2_P5   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_A2_A2_P5.dat');
    SSP_A2_RAND = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_A2_A2_RAND.dat');

    % SSP A2 (Backtracking)
    SSP_PD_AVIS = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_PD_PD_AVIS.dat');
    SSP_PD_EVOD = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_PD_PD_EVOD.dat');
    SSP_PD_P3   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_PD_PD_P3.dat');
    SSP_PD_P4   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_PD_PD_P4.dat');
    SSP_PD_P5   = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_PD_PD_P5.dat');
    SSP_PD_RAND = readtable('../lab4_ParadigmaSSP/build/SSP_Tests_Timed_PD_PD_RAND.dat');


    % Comparing each case

    disp('comparing AVIS...');
    % AVIS
    AVIS(SSP_DD_AVIS, SSP_A2_AVIS, SSP_PD_AVIS);
    disp('AVIS done!')

    disp('comparing EVOD...');
    % EVOD
    EVOD(SSP_DD_EVOD, SSP_A2_EVOD, SSP_PD_EVOD);
    disp('EVOD done!')

    disp('comparing P3...');
    % P3
    P3(SSP_DD_P3, SSP_A2_P3, SSP_PD_P3);
    disp('P3 done!')

    disp('comparing P4...');
    % P4
    P4(SSP_DD_P4, SSP_A2_P4, SSP_PD_P4);
    disp('P4 done!')

    disp('comparing P5...');
    % P5
    P5(SSP_DD_P5, SSP_A2_P5, SSP_PD_P5);
    disp('P5 done!')

    disp('comparing RAND...');
    % RAND
    RAND(SSP_DD_RAND, SSP_A2_RAND, SSP_PD_RAND);
    disp('RAND done!')

    disp('Saving pictures...')
    % Salvar as figuras abertas
    save_figures();
    disp('All pictures saved!')
    disp('--------------- Finishing ---------------')
end

function AVIS(SSP_DD_AVIS, SSP_A2_AVIS, SSP_PD_AVIS)
    % DD
    DD_input_size                       = table2array(SSP_DD_AVIS(:,'Var1'));
    DD_average_execution_time           = table2array(SSP_DD_AVIS(:,'Var2'));
    DD_number_of_positive_responses     = table2array(SSP_DD_AVIS(:,'Var3'));
    DD_number_of_trials                 = table2array(SSP_DD_AVIS(:,'Var4'));

    % A2
    A2_input_size                       = table2array(SSP_A2_AVIS(:,'Var1'));
    A2_average_execution_time           = table2array(SSP_A2_AVIS(:,'Var2'));
    A2_number_of_positive_responses     = table2array(SSP_A2_AVIS(:,'Var3'));
    A2_number_of_trials                 = table2array(SSP_A2_AVIS(:,'Var4'));
    
    % PD
    PD_input_size                       = table2array(SSP_PD_AVIS(:,'Var1'));
    PD_average_execution_time           = table2array(SSP_PD_AVIS(:,'Var2'));
    PD_number_of_positive_responses     = table2array(SSP_PD_AVIS(:,'Var3'));
    PD_number_of_trials                 = table2array(SSP_PD_AVIS(:,'Var4'));

    % Plot input size vs average execution time
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(DD_input_size, DD_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(A2_input_size, A2_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(PD_input_size, PD_average_execution_time, 'LineWidth', 2);
    hold on;
    title("Test AVIS", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms) - Escala Log', 'FontSize', 14, 'interpreter', 'latex');
    legend({'DD', 'A2', 'PD'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    set(gca, 'YScale', 'log');
    hold on;
end

function EVOD(SSP_DD_EVOD, SSP_A2_EVOD, SSP_PD_EVOD)
    % DD
    DD_input_size                       = table2array(SSP_DD_EVOD(:,'Var1'));
    DD_average_execution_time           = table2array(SSP_DD_EVOD(:,'Var2'));
    DD_number_of_positive_responses     = table2array(SSP_DD_EVOD(:,'Var3'));
    DD_number_of_trials                 = table2array(SSP_DD_EVOD(:,'Var4'));

    % A2
    A2_input_size                       = table2array(SSP_A2_EVOD(:,'Var1'));
    A2_average_execution_time           = table2array(SSP_A2_EVOD(:,'Var2'));
    A2_number_of_positive_responses     = table2array(SSP_A2_EVOD(:,'Var3'));
    A2_number_of_trials                 = table2array(SSP_A2_EVOD(:,'Var4'));
    
    % PD
    PD_input_size                       = table2array(SSP_PD_EVOD(:,'Var1'));
    PD_average_execution_time           = table2array(SSP_PD_EVOD(:,'Var2'));
    PD_number_of_positive_responses     = table2array(SSP_PD_EVOD(:,'Var3'));
    PD_number_of_trials                 = table2array(SSP_PD_EVOD(:,'Var4'));

    % Plot input size vs average execution time
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(DD_input_size, DD_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(A2_input_size, A2_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(PD_input_size, PD_average_execution_time, 'LineWidth', 2);
    hold on;
    title("Test EVOD", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms) - Escala Log', 'FontSize', 14, 'interpreter', 'latex');
    legend({'DD', 'A2', 'PD'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    set(gca, 'YScale', 'log');
    hold on;
end

function P3(SSP_DD_P3, SSP_A2_P3, SSP_PD_P3)
    % DD
    DD_input_size                       = table2array(SSP_DD_P3(:,'Var1'));
    DD_average_execution_time           = table2array(SSP_DD_P3(:,'Var2'));
    DD_number_of_positive_responses     = table2array(SSP_DD_P3(:,'Var3'));
    DD_number_of_trials                 = table2array(SSP_DD_P3(:,'Var4'));

    % A2
    A2_input_size                       = table2array(SSP_A2_P3(:,'Var1'));
    A2_average_execution_time           = table2array(SSP_A2_P3(:,'Var2'));
    A2_number_of_positive_responses     = table2array(SSP_A2_P3(:,'Var3'));
    A2_number_of_trials                 = table2array(SSP_A2_P3(:,'Var4'));
    
    % PD
    PD_input_size                       = table2array(SSP_PD_P3(:,'Var1'));
    PD_average_execution_time           = table2array(SSP_PD_P3(:,'Var2'));
    PD_number_of_positive_responses     = table2array(SSP_PD_P3(:,'Var3'));
    PD_number_of_trials                 = table2array(SSP_PD_P3(:,'Var4'));

    % Plot input size vs average execution time
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(DD_input_size, DD_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(A2_input_size, A2_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(PD_input_size, PD_average_execution_time, 'LineWidth', 2);
    hold on;
    title("Test P3", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms) - Escala Log', 'FontSize', 14, 'interpreter', 'latex');
    legend({'DD', 'A2', 'PD'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    set(gca, 'YScale', 'log');
    hold on;

end

function P4(SSP_DD_P4, SSP_A2_P4, SSP_PD_P4)
    % DD
    DD_input_size                       = table2array(SSP_DD_P4(:,'Var1'));
    DD_average_execution_time           = table2array(SSP_DD_P4(:,'Var2'));
    DD_number_of_positive_responses     = table2array(SSP_DD_P4(:,'Var3'));
    DD_number_of_trials                 = table2array(SSP_DD_P4(:,'Var4'));

    % A2
    A2_input_size                       = table2array(SSP_A2_P4(:,'Var1'));
    A2_average_execution_time           = table2array(SSP_A2_P4(:,'Var2'));
    A2_number_of_positive_responses     = table2array(SSP_A2_P4(:,'Var3'));
    A2_number_of_trials                 = table2array(SSP_A2_P4(:,'Var4'));

    % PD
    PD_input_size                       = table2array(SSP_PD_P4(:,'Var1'));
    PD_average_execution_time           = table2array(SSP_PD_P4(:,'Var2'));
    PD_number_of_positive_responses     = table2array(SSP_PD_P4(:,'Var3'));
    PD_number_of_trials                 = table2array(SSP_PD_P4(:,'Var4'));

    % Plot input size vs average execution time
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(DD_input_size, DD_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(A2_input_size, A2_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(PD_input_size, PD_average_execution_time, 'LineWidth', 2);
    hold on;
    title("Test P4", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms) - Escala Log', 'FontSize', 14, 'interpreter', 'latex');
    legend({'DD', 'A2', 'PD'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    set(gca, 'YScale', 'log');
    hold on;
end

function P5(SSP_DD_P5, SSP_A2_P5, SSP_PD_P5)
    % DD
    DD_input_size                       = table2array(SSP_DD_P5(:,'Var1'));
    DD_average_execution_time           = table2array(SSP_DD_P5(:,'Var2'));
    DD_number_of_positive_responses     = table2array(SSP_DD_P5(:,'Var3'));
    DD_number_of_trials                 = table2array(SSP_DD_P5(:,'Var4'));

    % A2
    A2_input_size                       = table2array(SSP_A2_P5(:,'Var1'));
    A2_average_execution_time           = table2array(SSP_A2_P5(:,'Var2'));
    A2_number_of_positive_responses     = table2array(SSP_A2_P5(:,'Var3'));
    A2_number_of_trials                 = table2array(SSP_A2_P5(:,'Var4'));

    % PD
    PD_input_size                       = table2array(SSP_PD_P5(:,'Var1'));
    PD_average_execution_time           = table2array(SSP_PD_P5(:,'Var2'));
    PD_number_of_positive_responses     = table2array(SSP_PD_P5(:,'Var3'));
    PD_number_of_trials                 = table2array(SSP_PD_P5(:,'Var4'));

    % Plot input size vs average execution time
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(DD_input_size, DD_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(A2_input_size, A2_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(PD_input_size, PD_average_execution_time, 'LineWidth', 2);
    hold on;
    title("Test P5", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms) - Escala Log', 'FontSize', 14, 'interpreter', 'latex');
    legend({'DD', 'A2', 'PD'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    set(gca, 'YScale', 'log');
    hold on;
end

function RAND(SSP_DD_RAND, SSP_A2_RAND, SSP_PD_RAND)
    % DD
    DD_input_size                       = table2array(SSP_DD_RAND(:,'Var1'));
    DD_average_execution_time           = table2array(SSP_DD_RAND(:,'Var2'));
    DD_number_of_positive_responses     = table2array(SSP_DD_RAND(:,'Var3'));
    DD_number_of_trials                 = table2array(SSP_DD_RAND(:,'Var4'));

    % A2
    A2_input_size                       = table2array(SSP_A2_RAND(:,'Var1'));
    A2_average_execution_time           = table2array(SSP_A2_RAND(:,'Var2'));
    A2_number_of_positive_responses     = table2array(SSP_A2_RAND(:,'Var3'));
    A2_number_of_trials                 = table2array(SSP_A2_RAND(:,'Var4'));

    % PD
    PD_input_size                       = table2array(SSP_PD_RAND(:,'Var1'));
    PD_average_execution_time           = table2array(SSP_PD_RAND(:,'Var2'));
    PD_number_of_positive_responses     = table2array(SSP_PD_RAND(:,'Var3'));
    PD_number_of_trials                 = table2array(SSP_PD_RAND(:,'Var4'));

    % Plot input size vs average execution time
    figure;
    set(gcf, 'Position', [100 100 800 600]);
    plot(DD_input_size, DD_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(A2_input_size, A2_average_execution_time, 'LineWidth', 2);
    hold on;
    plot(PD_input_size, PD_average_execution_time, 'LineWidth', 2);
    hold on;
    title("Test RAND", 'FontSize', 18, 'interpreter', 'latex');
    xlabel('Tamanho do Vetor', 'FontSize', 14, 'interpreter', 'latex');
    ylabel('Tempo (ms) - Escala Log', 'FontSize', 14, 'interpreter', 'latex');
    legend({'DD', 'A2', 'PD'}, 'FontSize', 14, 'interpreter', 'latex', 'Location', 'best');
    grid on;
    set(gca, 'YScale', 'log');
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