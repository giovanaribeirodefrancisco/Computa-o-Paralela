<h1>Laboratório 2b</h1>

<h3>Laboratório realizado para e entrega do dia 20/03</h3>

<ins>Conteúdo:</ins> Enviamos três códigos na linguagem C para o Git utilizando a AWS para responder as perguntas propostas. O código foi compilado e executado no ambiente da WSL pelo Prompt de Comando gerenciado pelo grupo.

<ins>Integrantes:</ins>
- Giovana Ribeiro de Francisco
- Leila Akina Ino
- Letícia Moraes Gutierrez de Oliveira

<h2>Índice:</h2>
<ul>
  <li><code>lab02b.c</code>: Código proposto pelo exercício de forma paralela sem otimização;
  <li><code>lab2bserial.c</code>: Código proposto pelo exercício de forma serial;
</ul>

<h2>Exercícios:</h2>
Construa uma solução paralela e responda às seguintes questões:

1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução
   
<img src = "https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/blob/main/src/Gr%C3%A1fico2b.png" alt = "Gráfico de multiplicação 100000 x 100">

2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.
   
<img src = "https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/blob/main/src/Speedup-2b.png" alt = "Gráfico do Speedup">

3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.

   Não foi possível chegar em uma conclusão para poder melhorar o código, pois não foi 

<h2>Códigos:</h2>

<code>lab02.c</code>

  Primeiro, incluímos todas as bibliotecas, colocamos a biblioteca pthread.h no nosso código pois ela tem as funcionalidades necessárias que precisávamos. Adicionamos também a biblioteca padrão em C de entrada e saída, stdio.h e a biblioteca padrão de funções em C, stdlib.h.
  
  Foi definido um valor N, como 100000, para a declaração de três arrays globais:
    
  - matriz[N][N], uma matriz 100000x100, cujo valores serão aplicados aleatoriamente, utilizando a função <code>preencher</code>.
  - vetor[N], um vetor de tamanho 100 preenchido aleatoriamente pela função <code>preencher</code>
  - resultado[N], um vetor na qual armazena os resultados da multiplicação adquiridos.  
  
  

<h2>Compilação:</h2>
Para fazer a compilação, utilizamos o gcc em um terminal da WSL, <code>gcc -o nome_do_executavel lab2b.c -lpthread</code>. 
No qual, o <code>nome_do_executavel</code> significa o nome do arquivo que será executado. Já o <code>-lpthread</code> é um suporte de threads POSIX utilizado para conectar a biblioteca pthread durante a compilação. 
Para executá-lo basta digitar o seguinte comando: <code>./nome_do_executavel</code>, caso não tenha utilizado nada digitar <code>./a.out</code>, pois é a saída padrão. 

  
<h2>Execução:</h2>

![Captura de Tela (591)](https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/d1bb16a0-21df-46d0-907f-9402a2dbc524)
