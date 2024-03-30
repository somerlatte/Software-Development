#include <iostream>
#include <iomanip>
#include "Estudante.hpp"
using namespace std;

int main ()
{
    Estudante* Estudantes [10];
    for (int i=0; i<10; i++)
    {
        cin >> Estudantes -> matricula >> Estudantes[i]->nome;
            for (int j=0; j<5; j++)
            {
                cin>> Estudantes[i]->notas[j];
            }
    }
}