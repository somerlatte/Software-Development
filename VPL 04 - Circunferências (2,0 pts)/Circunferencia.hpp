#ifndef CIRCUNFERENCIA 
#define CIRCUNFERENCIA

struct Circunferencia 
{
    double xc;
    double yc;
    double raio;

    Circunferencia (double x, double y, double raio);
    double calcularArea();
    bool possuiIntersecao (Circunferencia * c);
};

#endif