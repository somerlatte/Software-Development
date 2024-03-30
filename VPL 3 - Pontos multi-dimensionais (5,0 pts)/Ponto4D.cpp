#include "Ponto4D.hpp"

std::string Ponto4D::to_string() const{
    std::string s4D;
    s4D= "("+std::to_string(_x)+","+std::to_string(_y)+","+std::to_string(_z)+","+std::to_string(_w)+")";
    return s4D;
}

double Ponto4D::distancia(Ponto* p) const{
    Ponto4D* p_x = dynamic_cast<Ponto4D*>(p);
    double dist = sqrt(pow(_x - p_x->_x, 2) + pow(_y - p_x -> _y, 2) + pow(_z - p_x -> _z, 2) + pow(_w - p_x -> _w, 2));
    return dist;
}

