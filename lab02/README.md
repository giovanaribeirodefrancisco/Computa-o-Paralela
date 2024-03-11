<h1>Laboratório 2</h1>

<h3>Laboratório realizado para e entrega do dia 13/03</h3>

<ins>Conteúdo:</ins> Enviamos um código na linguagem C para o Git que executa uma solução usando threads para resolver o problema multiplicação matriz-vetor. 
O código foi compilado e executado no ambiente da AWS gerenciado pelo grupo.

<ins>Integrantes:</ins>
- Giovana Ribeiro de Francisco
- Leila Akina Ino
- Letícia Moraes Gutierrez de Oliveira

<h2>Código</h2>

Primeiro, incluímos todas as bibliotecas, colocamos a biblioteca pthread.h no nosso código pois ela tem as funcionalidades necessárias que precisávamos. Adicionamos também a biblioteca padrão em C de entrada e saída, stdio.h e a biblioteca padrão de funções em C, stdlib.h.

Criamos e fizemos a declaração de três arrays globais:
- matriz[3][3], uma matriz 3x3 cujo os valores são {{1,2,3},{1,2,3},{1,2,3}}.
- vetor[3], um vetor de tamanho 3 cujo o valor é {1,3,3}.
- resultado[3], um vetor no qual os resultados da multiplicação serão armazenados.
  
Depois criamos a função mult, que é executada por cada thread criada, ela recebe um argumento do tipo void* que é convertido para long (ele representa um número inteiro longo em C, armazenando assim números inteiros maiores do que o tipo  int), depois multiplica a linha correspondente da matriz pelo vetor e armazena o resultado no resultado[].

Após isso criamos a função main, que declara as variáveis linhas e colunas para armazenar o tamanho da matriz, ela também aloca dinamicamente o espaço para um array de threads chamado thread_rope com tamanho igual ao número de linhas da matriz. Ela cria também um loop para criar threads, onde cada thread executa a função mult. Em seguida, outro loop espera pela conclusão de cada thread usando pthread_join.

Após as threads serem feitas, é imprimido as respostas armazenadas em resultado. 

Depois, utilizando a função free(), a memória alocada é liberada para thread_rope.

E por último é retornado 0 para indicar que o programa foi executado com sucesso.

<h2>Compilação</h2>

Para realização da compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. A compilação dos arquivos .c deste repositório podem ser compilados da seguinte forma: `gcc -g -Wall -o nome_do_executável lab02.c -lpthread`. 

No qual o -g é o debug;
O -Wall são os warnings, ele ativa a maioria dos avisos durante a compilação;
O -lpthread, é um suporte de thread POSIX, ele é usado para conectar a biblioteca pthread durante a compilação. 
O -o especifica o nome do arquivo de saída após a compilação, permitindo assim, que você escolha o nome do arquivo executável que será gerado pelo compilador. 
O `nome_do_executável` seria o arquivo executável gerado.

No `lab02.c` você substituiria esse nome para o nome do seu arquivo. 
Para executá-lo, basta digitar o seguinte comando: `./lab02.out`. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo `lab.out` pelo nome do arquivo gerado no comando anterior.

<h2>Índice</h2>

<ul>
<li><img  >.</li>

</ul>
