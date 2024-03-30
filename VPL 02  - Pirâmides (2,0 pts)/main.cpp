#include <iostream>

int main () {
    int altura, i, j;
    std::cout << "Digite a altura:";
    std::cin >> altura;
    std::cout << "\n";

    for (i=1; i<=altura; i++){
       
        for (j=1; j<=i; j++){
            std::cout << "*";
        }
        std::cout << "\n";
    }

    for (i=altura-1; i>=1; i--){
       
        for (j=i; j>=1; j--){
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
