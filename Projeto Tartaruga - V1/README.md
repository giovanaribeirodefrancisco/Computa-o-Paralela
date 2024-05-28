<h1>Projeto Tartaruga - V1</h1>

<h3>Projeto realizado para a entrega do dia 29/05</h3>

<ins>Conteúdo:</ins> Enviamos um código em C com uma solução paralela, no qual o valor de S é o maior possível, possuindo a melhor aproximação para a série de Taylor e calculando o valor de e. Também entregamos o tempo T que leva para atingir o valor. 

<ins>Integrantes:</ins>
- Giovana Ribeiro de Francisco
- Leila Akina Ino
- Letícia Moraes Gutierrez de Oliveira

<h2>Índice</h2>
<li><code>proj.c</code>: Código Utilizado para o Projeto,</li>
<li><code>Outras</code>: Códigos testes.</li>

<h2>Exercícios</h2>
Considere o problema da tartaruga envolvido no projeto final da disciplina. Desenvolva uma primeira versão serial e paralela levando em consideração os seguintes requisitos:

1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução
<h3>Imagem do Processador 1:</h3>
<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/b4d7804d-e6ba-4730-aaf6-3de7080fe431">

<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/e8beb2aa-8f5e-49e1-9b97-eeac2e9f7df4">

<h3>Imagem do Processador 2:</h3>
<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/90b80364-3dc1-40b4-84a5-985f0528ed18">

<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/25a09097-d4e4-4465-bb68-c28a4772db6c">

<h3>Imagem do Processador 4:</h3>
<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/baa01803-66a7-4f03-a918-a42113c7c624">

<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/bb589935-8d82-4e6b-9ca5-6a7d2965b9d5">

<h3>Imagem do Processador 6:</h3>
<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/8b4ac87e-24a8-4653-8aa4-33cda08cfd7c">

<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/4f7d8890-7620-48fd-82d3-d075fe64bfd7">

<h3>Imagem do Processador 8:</h3>
<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/58805179-3b10-49e7-9a68-08045db41c9a">

<img src="https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/d86bc254-884a-4ee3-bcb7-3aa118b9adf0">


<img src = "https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/blob/main/src/N%C3%BAcleo%20x%20Tempo%20(Min)%20-%20Critico.png" alt = "Tempo de Execução">


2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.

   Para 1 Processador: 1m

   Para 2 Processadores: 2m 2288

   Para 4 Processadores: 5m 9587
   
   Para 6 Processadores: 8m 4694
   
   Para 8 Processadores: 11m 0319

   <img src = "https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/blob/main/src/SpeedUp%20Critico.png" alt = "SpeedUp">

4. Introduza na sua solução a diretiva critical. O que muda? Para provar seu ponto, refaça a solução com essa abordagem, calcule os novos valores e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.

   Não foi necessário criar um código crítico, pois o código utilizado já é uma solução crítica.

<h2>Código</h2>
O código foi feito em Linguagem C, e ele calcula uma aproximação do número "e" usando a série de Taylor para a função exponencial. Utilizamos a biblioteca MPFR para cálculos aritméticos de precisão arbitrária e OpenMp para paralelismo.
Bibliotecas utilizadas:
<li><code>#include stdio.h</code>;</li>
<li><code>#include omp.h</code>;</li>
<li><code>#include stdlib.h</code>;</li>
<li><code>#include mpfr.h</code>.</li>

A função <code>fatorial</code> caclcula os fatoriais de 0 até n -1 e armazena os resultados em um vetor de números de precisão arbitrária <code>mpfr_t</code>. A função <code>mpfr_init2</code> é usada para inicializar as variáveis MPFR com uma precisão específica. 

A função <code>soma</code> divide 1 pelo fatorial de cada número na série de fatoriais, somando os resultados parciais. Ela também usa o <code>OpenMP</code> para calcular a soma paralelamente, dividindo o trabalho entre várias threads. Além de que ela também usa uma seção crítica <code>#pragma omp critical</code> para garantirque apenas uma thread atualize a variável global ao mesmo tempo. A utilização do <code>mpfr_div(resultdivisao, vet[0], vet[i], MPFR_RNDU);</code> se deve tanto pela simplicidade de uso, pois é a divisão mais simples dentro do MPFR, o uso do MPFR_RNDU é o modo de arredondamento para cima, garantindo a precisão do resultdivisao, mantendo a consistência e simplicidade da função.

A função <code>calcular_e_paralelo</code> aloca a memória para o vetor de fatoriais e chama a função <code>fatorial</code> para calcular os fatorias. Ela inicializa a variável <code>global</code> para armazenar o resultado da soma dos inversos dos fatoriais. Ela também chama a função <code>soma</code> para calcular a soma paralelamente. E ela limpa a memória alocada e imprime o resultado.

A função <code>main</code> verifica se o número correto de argumenttos da linha de comando foi passado (o número de threads). Ela chama a função <code>calcular_e_paralelo</code> com o número de termos na série de Taylor e o número de threads especificado. 

<h2>Compilação</h2>
Para fazer a compilação, utilizamos o gcc em um terminal Linux, <code>gcc -o nome_do_código nome_do_código.c -lmpfr -lgmp -fopenmp</code>
No qual, o <code>gcc</code> é usado para compilar programas escritos em linguagem C. O <code>-o</code> especifica o nome do arquivo de saída do programa executável gerado após a compilação. O <code>nome_do_código</code> é o nome do arquivo de saída. O <code>nome_do_código.c</code> é o nome do arquivo fonte C que será compilado, neste caso o <code>proj.c</code>. O <code>-lmpfr</code> é opção do linker do compilador que especifica a biblioteca MPFR que será vinculada ao programa. O <code>-lgmp</code> é uma opção do linker que especifica a biblioteca GMP que será vinculada ao programa. O <code>-fopenmp</code> habilita o suporte para OpenMP durante a compilação. 
Para executá-lo utilizando a quantidade de núcleos desejados, basta digitar o seguinte comando: time ./nome_do_executavel x, onde:

x: o número de núcleos utilizados.
Caso não tenha utilizado -o, substituir o nome_do_executavel por ./a.out, pois é a saída padrão.

Obs.: A compilação foi feita no computador de uma pessoa que não está no grupo, devido a um problema de Memória Ram que tivemos no nosso computador. Mas se tivesse dado certo para executar o código no nosso computador, primeiro faríamos a instalação das bibliotecas MPFR e GMP: 
1) Abrir o Prompt de Comando e colocar na WSL;
2) <code>sudo apt-get update</code> para atualizar os repositórios;
3) <code>sudo apt-get install libmpfr-dev libgmp-dev</code> para instalar as bibliotecas MPFR e GMP.

Depois da intalação feita, compilaríamos da seguinte forma: <code>gcc -o nome_do_código nome_do_código.c -lmpfr -lgmp -fopenmp</code> que é igual a compilação de um terminal Linux. 


<h2>CPU</h2>
<img src = "https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/blob/main/src/Captura%20de%20tela%20de%202024-05-22%2005-40-02.png" alt = "Informacao Cpu Mackenzie">

<h2>Referências</h2>
<li>Intalação do MPFR: https://www.mpfr.org/mpfr-current/mpfr.html</li>

