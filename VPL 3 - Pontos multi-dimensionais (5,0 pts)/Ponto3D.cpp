#include "Ponto3D.hpp"

std::string Ponto3D::to_string() const{
    std::string s3D ;
    s3D = "("+ std::to_string(_x) +","+ std::to_string(_y)+","+std::to_string(_z)+")";
    return s3D;
}
double Ponto3D::distancia(Ponto* p) const{
    Ponto3D* p_x = dynamic_cast<Ponto3D*>(p);
    double dist = sqrt(pow(_x - p_x->_x, 2) + pow(_y - p_x -> _y, 2) + pow(_z - p_x -> _z, 2));
    return dist;
}


