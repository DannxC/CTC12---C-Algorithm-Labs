Formato da saída do teste TimedT
Cada linha de texto tem o formato
<int>,<float>,<int>,<int>
Correspondendo a
<input size>, <average execution time>, <number of positive responses>, <number of trials>
Código correspondente:
result_dump << s <<","<< sum_times/(float)e.repeat <<","<< count_yes
<<"," << e.repeat << std::endl;