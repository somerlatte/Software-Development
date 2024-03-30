#include "Circunferencia.hpp"
#include "cmath"

Circunferencia::Circunferencia (double x, double y, double raio)
{
    this -> xc = x;
    this -> yc = y;
    this -> raio = raio;
}

double Circunferencia::calcularArea() 
{
    return 3.14 *pow(this -> raio, 2);
}

bool Circunferencia::possuiIntersecao (Circunferencia*c)
{
   double a = (this -> xc - c ->xc) * (this ->xc - c ->xc);
   double b = (this -> yc - c ->yc) * (this ->yc - c ->yc);
   double e = this-> raio + c->raio;
   double d = sqrt (a + b);

    if (d >= e + c->raio)
    {
        return false;
    }
    return true;
}