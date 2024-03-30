O objetivo deste exercício é implementar um sistema que lê pontos da entrada padrão, um por linha,
e imprime as distâncias entre pontos de mesma dimensão.
Além disso, no caso de pontos 2D, o programa faz a conversão de pontos de coordenadas cartesianas para coordenadas polares (https://pt.wikipedia.org/wiki/Coordenadas_polares).
Para testar seu programa, você deverá usar o programa principal abaixo:

#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include "Ponto.hpp"
#include "Ponto2D.hpp"
#include "Ponto3D.hpp"
#include "Ponto4D.hpp"

Ponto* lerProximoPonto(std::string line) {
  std::istringstream ss(line);
  std::string token;
  std::getline(ss, token, ' ');
  double x = stod(token);
  if (std::getline(ss, token, ' ')) {
    double y = stod(token);
    if (std::getline(ss, token, ' ')) {
      double z = stod(token);
      if (std::getline(ss, token, ' ')) {
        double w = stod(token);
        return new Ponto4D(x, y, z, w);
      }
      return new Ponto3D(x, y, z);
    } else {
      return new Ponto2D(x, y);
    }
  }
}

int main() {
  // le o arquivo
  std::vector<Ponto*> pontos;
  std::string line;
  while (std::getline(std::cin, line)) {
    // Converte a linha em um ponto, e o insere no vetor:
    pontos.push_back(lerProximoPonto(line));
  }
 
  for (Ponto* v1: pontos) {
    for (Ponto* v2: pontos) {
        if(v1->getDimensao() == v2->getDimensao() && v1 != v2){
            printf("%.2lf ", v1->distancia(v2));
        }
    }
    printf("\n");
  }
 
  for (Ponto* v1: pontos) {
        if(v1->getDimensao() == 2){
            Ponto2D* p2d = dynamic_cast<Ponto2D*>(v1);
            p2d->converteParaPolar();
            std::cout << p2d->to_string() << "\n";
        }
    }
  return 0;
}


Neste exercício teremos pontos de duas, três e quatro dimensões. Todos os pontos devem obedecer à interface abaixo:

class Ponto {
  public:
    /**
     * \Representação de string do ponto.
     * \retorna uma string que representa o ponto, como uma tupla de n-dimensões.
     */
    virtual std::string to_string() const = 0;
    /**
     * \Computa a distância entre o Ponto armazenado no objeto e o Ponto passado por parâmetro (se possuem a mesma dimensão)
     */
    virtual double distancia(Ponto* p) const = 0;
    /**
     * Retorna uma inteiro que representa a dimensão do ponto.
     */
    virtual int getDimensao() const = 0;
    /**
     * \o destruidor virtual (ou então o compilador irá criar um para você).
     */
    virtual ~Ponto() {};
};

Você deverá implementar as classes que estendem essa interface, a saber, Ponto2D, Ponto3D e Ponto4D.
A definição de cada uma das classes será provida para você (baixe os arquivos na descrição do problema).
Veja o funcionamento de alguns casos de teste neste abaixo:

A entrada é um conjunto de pontos (cada linha representando um ponto de dimensão arbitrária).
A saída mostra a distância de cada ponto aos demais de mesma dimensão.
Caso não hajam outros pontos de mesma dimensão, a linha fica vazia.
Assim, se o ponto na primeira linha do arquivo de entrada tem dimensão n, a primeira linha da saída será a lista de distâncias deste ponto para todos os outros pontos de dimensão n declarados no arquivo de entrada, separados por um espaço. A lista de distâncias deve seguir a mesma ordem da lista de entrada dos pontos. Note que para cada ponto da entrada deve existir uma linha na saída, independente da distância entre os pontos p1 e p2 ser a mesma distância dos pontos p2 para p1.
Ainda na saída você deve imprimir a transformação dos pontos 2D para coordenadas polares.

Entrada:
1 2 3
4 5
1 2 3 4
1 1
3 4 3
1 2

Saída:
2.83
5.00 4.24

5.00 1.00
2.83
4.24 1.00
(6.403124,0.896055)
(1.414214,0.785398)
(2.236068,1.107149)

No exemplo acima,  veja que para o ponto (1,2,3,4) há uma linha vazia, pois não existe outro vetor de dimensão 4.

Esse exercício ilustra o Princípio da Abertura-Fechamento, que diz que um programa deve ser aberto para extensão, e fechado para uso. Em outras palavras, é possível usar esse programa, porém, é também possível estendê-lo. A extensão se dá via herança. Mesmo após o programa já estar em produção, ainda é possível, por exemplo, criar pontos 5D ou 6D, sem que seja necessário alterar os outros tipos de pontos que já existem.
