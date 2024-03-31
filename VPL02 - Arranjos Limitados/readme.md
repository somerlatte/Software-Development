Neste exercício você deverá adicionar tratamento de erros a classe abaixo. Essa classe implementa um arranjo que sempre guarda uma quantidade de elementos pré-definida quando o programa é compilado:

template <class T, int N> class BoundedArray {
  public:
    void set(int index, T value) {
      buf[index] = value;
    }
    T get(int index) {
      return buf[index];
    }
  private:
    T buf[N];
};

Você deverá modificar essa classe, a fim de que ela possa lançar três tipos de exceções, a saber:

* Índice não inicializado: esse erro ocorre quando o método get é invocado sobre um índice que ainda não recebeu qualquer elemento. Quando esta exceção é lançada, o código tratador deve exibir a seguinte mensagem : "Erro: indice nao inicializado."  (Perceba que existe um ponto ao final da mensagem).

* Índice negativo: esse erro ocorre quando os métodos get e set são invocados com um índice negativo.  Quando esta exceção é lançada, o código tratador deve exibir a seguinte mensagem: "Erro: indice negativo.".

* Índice maior que arranjo: esse erro ocorre quando os métodos get e set são invocados com um índice maior ou igual ao parâmetro N da classe. Quando esta exceção é lançada, o código tratador deve exibir a seguinte a mensagem: "Erro: indice maior que arranjo."

Para testar seu programa, você deve usar o programa abaixo, que já está implementado no arquivo main.cpp. 

#include<iostream>

template <class T> void testArray() {
  BoundedArray<T, 8> a;
  char action;
  while (std::cin >> action) {
    int index;
    std::cin >> index;
    try {
      if (action == 's') {
        T value;
        std::cin >> value;
        a.set(index, value);
      } else if (action == 'g') {
        std::cout << a.get(index) << std::endl;
      }
    } catch (...) {
      std::cerr << "Erro desconhecido." << std::endl;
    }
  }
}



int main() {
  char type;
  std::cin >> type;
  switch(type) {
    case 'd':
      testArray<double>();
      break;
    case 'i':
      testArray<int>();
      break;
    case 's':
      testArray<std::string>();
      break;
  }
  return 0;
}


DICA: Além de alterar a classe BoundedArray (para sinalizar as exceções) e a função testArray (para tratar as exceções), você terá de implementar uma classe para representar cada uma das exceções. 

Abaixo são vistos alguns casos de teste:

=== input ===
d s 1 3.14 g 1 s 4 2.76 g 4 g 1
=== output ===
3.14
2.76
3.14

=== input ===
i s 0 42 s 1 43 s 2 56 s 3 15 g 0 g 1 g 2 g 3 g 0 g 1
=== output ===
42
43
56
15
42
43

=== input ===
s s 7 perdido s 6 o s 5 amar g 5 g 6 g 7
=== output ===
amar
o
perdido

=== input ===
d s 1 3.14 g 1 s 8 2.76 g 4 g 1
=== output ===
3.14
Erro: indice maior que arranjo.
Erro: indice nao inicializado.
3.14

=== input ===
i s 0 42 s 1 43 s 3 15 g 0 g 1 g 2 g 3 s 2 56 g 2 g 9
=== output ===
42
43
Erro: indice nao inicializado.
15
56
Erro: indice maior que arranjo.

=== input ===
s s 1 perdido s 0 o s -1 amar g 1 g 0 g -1
=== output ===
Erro: indice negativo.
perdido
o
Erro: indice negativo.
