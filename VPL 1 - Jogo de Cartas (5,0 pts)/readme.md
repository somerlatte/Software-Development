Este programa simula um jogo de cartas.
Cada jogador recebe k cartas e vence o jogador que tiver a maior pontuação.
Cada carta têm um valor associado, e sua tarefa, entre outras, é determinar a pontuação de cada jogador e definir quem vence o jogo.

Entradas:
Na primeira linha da entrada temos dois números: o primeiro indica o número de jogadores n (n >= 1), e o segundo o número de cartas que cada jogador vai receber (k).
A seguir temos n*k + n linhas com a seguinte ordem: O nome do jogador, e a seguir as k (k >= 1) cartas que esse jogador recebeu.
Nas linhas que representam cartas a primeira posição é a pontuação da carta (que varia de 1 a 9), e a segunda o naipe da carta.
**não se preocupe com empates

Os naipes existentes são:
ouros
espadas
copas
paus

O naipe tem um papel na pontuação da carta:
Se o naipe é de ouros a pontuação aumenta em 2
Se o naipe é de espadas a pontuação diminui em 3
Se o naipe é de copas a pontuação aumenta em 5
Se o naipe é de paus a pontuação diminui em 1

Entrada:

4 3
João
4 ouros
6 copas
2 paus
Maria
1 espadas
2 ouros
2 espadas
Vitor
5 ouros
5 paus
1 copas
Marcos
1 paus
3 paus
2 ouros

Saídas:
A saída corresponde a lista de jogadores ordenados por sua pontuação (do menor para o maior), e na última linha o nome do jogador vencedor.

Maria 1
Marcos 6
Vitor 17
João 18
João

Outro exemplo de entrada e saída:
Entrada:

3 3
Marcos
4 ouros
6 paus
2 copas
Felipe
1 espadas
2 ouros
2 paus
Hugo
5 copas
5 paus
1 ouros

Saída:
Felipe 3
Hugo 17
Marcos 18
Marcos

Para facilitar seu trabalho, a implementação das classes Jogador e Carta já foram feitas, assim como a função main (baixe na descrição da VPL no começo da página).

Você precisa completar os arquivos Partida.hpp e Partida.cpp.
Você deve implementar os métodos que estão faltando
(construtor, getNumJogadores, setJogadores, getJogadores, getCampeao, getJogadoresOrdenados, imprimeJogadoresOrdenados).

O principal objetivo desse exercício é observar a comunicação entre objetos de diferentes classes.
Você pode incluir novos métodos e atributos nas demais classes se achar necessário.
