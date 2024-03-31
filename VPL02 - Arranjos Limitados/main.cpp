#include <iostream>

class ErroNaoInicializado{};

class ErroNegativo {};

class ErroMaiorQueArranjo{};

template <class T, int N> class BoundedArray {
	public:
		BoundedArray() {
			int i;
			for (i=0; i<N; i++)
			{
				ind[i] = false;
			}
		}
		
		void set(int index, T value) {
			if (index >= N)
			{ 
				throw ErroMaiorQueArranjo();
			}
			else if (index < 0) 
			{ 
				throw ErroNegativo();
			}
			ind[index] = true;
			buf[index] = value;
		}
   
		T get(int index) {
			if (index >= N) 
			{ 
				throw ErroMaiorQueArranjo();
			}
			else if (index < 0) 
			{ 
				throw ErroNegativo();
			}
			else if (ind[index] == false)
			{
				throw ErroNaoInicializado();
			}
		return buf[index];
		}
	private:
		T buf[N];
		bool ind[N];
};

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
    } catch (ErroNaoInicializado) {
		std::cerr << "Erro: indice nao inicializado." << std::endl;
    } catch (ErroNegativo) {
		std::cerr << "Erro: indice negativo." << std::endl;
	} catch (ErroMaiorQueArranjo) {
		std::cerr << "Erro: indice maior que arranjo" << std::endl;
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