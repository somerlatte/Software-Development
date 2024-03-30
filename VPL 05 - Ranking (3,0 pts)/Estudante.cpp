#include "Estudante.hpp"

float Estudante::calcularRSG()
{
    float total = 0;
    for (int i =0; i< 5; i++)
    {
        total += notas[i];
    }
    return total/5;
}