<h1>Laboratório 3</h1>

<h3>Laboratório realizado para e entrega do dia 24/04</h3>

<ins>Conteúdo:</ins> Sendo a curva representada pela função f(x) = sen(x), construímos uma solução paralela utilizando OpenMP e calculamos o valor aproximado da área sob a curva, também tivemos que responder às seguintes perguntas.

<ins>Integrantes:</ins>
- Giovana Ribeiro de Francisco
- Leila Akina Ino
- Letícia Moraes Gutierrez de Oliveira

<h2>Índice:</h2>
<ul>
  <li><code>lab03.c</code>: Código proposto pelos exercícios 1 e 2;
  <li><code>a.c<\code>: Código proposto pelo exercício com solução a diretiva crítica.</li>
</ul>

<h2>Exercícios:</h2>
Construa uma solução paralela e responda às seguintes questões:

1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução

<img src = "https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/e9f630cc-ec61-45ab-a543-6fe1fb8981a3">

2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.

3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.


<h2>Código:</h2>
Para a resolução dos exercícios foram utilizados 2 códigos o <code>lab03.c</code> e o <code>a.c</code>.

<code>lab03.c</code>
Primeiramente, foram importadas as bibliotecas <code>omp.h</code> para facilitar a criação de programas paralelos em sistemas com múltiplos núcleos de processamento; outra biblioteca utilizada foi <code>math.h</code>, pois foi utilizado a função <code>sin</code> para calcular o seno. Foram adicionadas também a biblioteca padrão em C de entrada e saída, stdio.h e a biblioteca padrão de funções em C, stdlib.h.

A função <code>Trap</code> calcula a contribuição local de cada thread para a estimativa da integral. Ela recebe como entrada os limites de integração a e b, o número de trapézios n e um ponteiro para a variável que armazenará o resultado global, ela distribui a tarefa de calcular a integral entre os threads disponíveis. Cada thread calcula uma parte da integral para uma faixa específica do intervalo de integração e depois atualiza o resultado global de forma segura.

Após a conclusão da função, foi criado a função <code>main</code>, na qual configura o ambiente de execução para a paralelização do cálculo da integral usando a biblioteca OpenMP. Primeiro, ela lê o número de threads a serem utilizadas a partir dos argumentos da linha de comando. Em seguida, chama a função Trap dentro de uma região paralela, onde cada thread realiza o cálculo de uma parte da integral. Após a execução da região paralela, o resultado global é impresso na tela.


<h2>Compilação:</h2>
Para fazer a compilação, utilizamos o gcc em um terminal da WSL, <code>gcc -g - Wall -fopenmp -o nome_do_executavel nome_do_código -lm</code>.
<br>
No qual, o <code>nome_do_executavel</code> significa o nome do arquivo que será executado, <code>nome_do_código</code> signifa o nome do código, neste caso o <code>lab03.c</code> ou <code>a.c</code>. O <code>-g</code> inclui informações de depuração no arquivo executável gerado. O <code>-Wall</code> ativa a maioria das mensagens de aviso do compilador. O <code>-fopenmp</code> habilita o suporte para OpenMP durante a compilação. E por fim <code>-lm</code> liga o compilador a biblioteca <code>math.h</code> no código de execução da função <code>sin</code>.

Para executá-lo utilizando a quantidade de núcleos desejados, basta digitar o seguinte comando: <code>time ./nome_do_executavel a b n x</code>, onde:
  - a e b: equivalem ao limite da integração;
  - n: equivalente ao número de trapézios neste limite;
  - x: o número de núcleos utilizados.

Caso não tenha utilizado -o, substituir o <code>nome_do_executavel</code> por <code>./a.out</code>, pois é a saída padrão. 


<h2>Especificações:</h2>
<img src = "https://github.com/giovanaribeirodefrancisco/Computa-o-Paralela/assets/161640729/15f47fb8-22dd-4004-af91-81fef86a238e"
> 

