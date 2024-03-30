#include "Ponto2D.hpp"

std::string Ponto2D::to_string() const{
    std::string s2D= "("+std::to_string(_x)+","+std::to_string(_y)+")"; 
    return s2D;
}

double Ponto2D::distancia(Ponto* p)const{
    Ponto2D* p_x = dynamic_cast<Ponto2D*>(p);;

   double dist = sqrt(pow(_x - p_x->_x,2) + pow(_y - p_x -> _y,2 ));
    return dist;
}

void Ponto2D::converteParaPolar(){
    double l = sqrt(pow(_x, 2)+pow(_y, 2));
    double w = atan(_y/_x);
    _x = l;
    _y = w;

}
