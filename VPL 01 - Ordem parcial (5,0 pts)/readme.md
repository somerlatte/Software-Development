Neste exercício você irá implementar uma função genérica <T>GetMaxDefault(T a, T b, T c). Essa função recebe três argumentos, e retorna o maior entre os dois primeiros, ou o terceiro argumento, caso não exista um maior entre os dois primeiros. A função opera sobre tipos que reconhecem uma ordem total ou parcial.  Uma ordem, estabelecida sobre um conjunto, é dita total caso, dados dois elementos diferentes do conjunto, sempre for possível definir o maior deles. A ordem é dita parcial quando isso não for possível sempre. Por exemplo, o conjunto dos números inteiros define uma ordem total: dados dois números diferentes, sempre há um maior. Por outro lado, um conjunto potência, ordenado por inclusão, define uma ordem parcial. Se um subconjunto A contiver um subconjunto B, então A é dito maior que B, e de modo análogo, se um subconjunto B contiver um subconjunto A, então B é dito maior que A. Porém, é possível que nem A esteja em B, nem B esteja em A. Nesse caso, a ordem entre A e B não é definida. Quando a ordem parcial entre os dois primeiros elements, a e b, não estiver definida, sua função GetMaxDefault(a, b, c) deve retornar o terceiro elemento, c. Para lhe ajudar, a declaração de GetMaxDefault é dada abaixo:

template <class T>
T GetMaxDefault (T a, T b, T dflt) {
  // TODO: implement the code that is missing here.
}

A função GetMaxDefault deve operar sobre tipos que reconheçam o operador de comparação "maior que ou igual" (>=). Esse operador está definido para todos os tipos primitivos da linguagem C++. Porém, ele não é definido para tipos compostos como classes e structs. Nesse exercício, você deverá implementar esse operador para dois tipos, a saber: Interval e BitSet. Parte da implementação de Interval pode ser vista abaixo. Note que um intervalo I1 somente é maior que outro intervalo I2 se I1 contém I2 inteiramente. Por exemplo, [1, 5] é maior que [2, 4], porém [1, 5] não é maior que [3, 6], pois o primeiro interval não contém o segundo:

struct Interval {
  Interval(int left, int right): _l(left), _r(right) {}
  const int _l;
  const int _r;
  friend std::ostream & operator<<(std::ostream& os, const Interval& i) {
    os << '(' << i._l << ", " << i._r << ')';
    return os;
  }
  /**
   * \brief compares two intervals to see if the first is greater than the
   * second. An interval (a1, a2) is greater than or equal to another interval
   * (b1, b2) if a1 <= b1 and a2 >= b2.
   */
  // TODO: implement the operator >=
};

O segundo tipo que deve ser implementado é um conjunto de bits. Esse conjunto representa elementos como índices em um mapa de bits. Cada conjunto tem capacidade para armazenar os elementos de 1 até 32. Existem 2^32 conjuntos possíveis com esses elementos. Cada conjunto é definido pela representação binária de um número inteiro. Por exemplo, o número três, em binário, é escrito assim: 0...0011. Esse número representa o conjunto formado pelos números 1 e 2 (o primeiro e o segundo bits ativos). Similarmente, o número 10 possui a seguinte representação binária: 0...01010. Esse número representa o conjunto {2, 4}, pois o segundo e o quarto bits estão ativos. Abaixo, é dada parte da implementação de BitSet:

struct BitSet {
  BitSet(unsigned value): _set(value) {}
  const unsigned _set;
  friend std::ostream & operator<<(std::ostream& os, const BitSet& i) {
    const int limit = sizeof(unsigned) * 8;
    os << '<';
    for (int aux = 0; aux < limit; aux++) {
      unsigned mask = 1 << aux;
      if (i._set & mask) {
        os << "|";
      } else {
        os << "-";
      }
    }
    os << '>';
    return os;
  }
  /**
   * \brief compares two bit sets. A bit set b1 is greater than or equal to
   * another bit set b2 if b1 contains all the bits in b2.
   */
  // TODO: implement the operador >=
  }
};

Note que tanto BitSet quanto Interval possuem a implementação do operador de streaming (<<). Assim, é possível imprimir valores desses tipos diretamente via std::cout ou std::cerr, por exemplo. Você deverá testar seu código com a função main abaixo. Essa função lê bit sets (via número inteiros positivos que os representam) ou intervalos da entrada padrão. O primeiro caracter de cada linha indica o tipo que deverá ser lido:

#include <iostream>
#include "GetMax.h"
BitSet* readBitSet() {
  unsigned set;
  std::cin >> set;
  return new BitSet(set);
}
Interval* readInterval() {
  int left, right;
  std::cin >> left >> right;
  return new Interval(left, right);
}
void testBitSet() {
  BitSet *b1 = readBitSet();
  BitSet *b2 = readBitSet();
  BitSet *dflt = new BitSet(0);
  std::cout << GetMaxDefault(*b1, *b2, *dflt) << std::endl;
  delete b1;
  delete b2;
}
void testInterval() {
  Interval *i1 = readInterval();
  Interval *i2 = readInterval();
  Interval *dflt = new Interval(0, 0);
  std::cout << GetMaxDefault(*i1, *i2, *dflt) << std::endl;
  delete i1;
  delete i2;
}
int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'i': testInterval();
                break;
      case 'b': testBitSet();
                break;
      default: std::cerr << "Invalid type\n";
    }
  }
  return 0;
}

Abaixo são mostrados alguns testes. Use-os como exemplo. Eles são parte do conjunto de testes que será usado para corrigir esse exercício.

$> X=0; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
i 2 20 3 15
i 2 4 3 5
i -1 1 0 0
***
(2, 20)
(0, 0)
(-1, 1)


$> X=1; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
b 7 3
b 6 3
b 15 7
b 12 8
***
<|||----------------------------->
<-------------------------------->
<||||---------------------------->
<--||---------------------------->


$> X=2; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
i 2 20 3 15
b 52428 34952
i 2 4 3 5
b 34952 33928
***
(2, 20)
<--||--||--||--||---------------->
(0, 0)
<-------------------------------->


$> X=3; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
i 1 3 1 2
***
(1, 3)


$> X=4; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
b 24 24
b 28 24
b 24 28
***
<---||--------------------------->
<--|||--------------------------->
<--|||--------------------------->
