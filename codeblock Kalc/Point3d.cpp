#include "Point3d.h"

Point3D::Point3D(double _x, double _y, double _z):Point2D(_x,_y),z(_z){}

Point3D::Point3D(const Point2D &p):Point2D(p),z(0){}

Point3D& Point3D::operator=(const Point2D& d){
set_x(d.get_x());
set_y(d.get_y());
    z=0;
return *this;
}
bool Point3D::operator<(const Point3D& p) const{
    return ( ((*this).Point2D::operator <(p)) || ((*this).Point2D::operator ==(p) && z<p.z) );
}

bool Point3D::operator>(const Point3D& p) const{
    return ( ((*this).Point2D::operator >(p)) || ((*this).Point2D::operator ==(p) && z>p.z) );
}

bool Point3D::operator==(const Point3D& p)const{
    return  ((*this).Point2D::operator==(p) && z==p.z);
}


bool Point3D::operator!=(const Point3D& p)const{
    return  ((*this).Point2D::operator!=(p) || z!=p.z);
}


Point3D& Point3D::operator+(const Point3D& p){
    Point3D aux((*this).Point2D::operator+(p));
    aux.z=z+p.z;
    *this=aux;
    return *this;
}

Point3D& Point3D::operator-(const Point3D& p){
    Point3D aux((*this).Point2D::operator-(p));
    aux.z=z-p.z;
    *this=aux;
    return *this;
}

Point3D& Point3D::operator*(const double& d){
    Point3D aux((*this).Point2D::operator*(d));
    aux.z=z*d;
    *this=aux;
    return *this;
}


Point3D& Point3D::operator/(const double& d){
    Point3D aux((*this).Point2D::operator/(d));
    aux.z=z/d;
    *this=aux;
    return *this;
}

void Point3D::set_z(const double& _z){
    z=_z;
}

double Point3D::get_z()const{
    return z;
}
void Point3D::stampa()const{
    std::cout<<*this;
}

void Point3D::trasla_asseZ(const double& _z){
z=z+_z;
}

double Point3D::distanza(const Point3D& first_point, const Point3D& second_point){
return sqrt(aux_distance(first_point,second_point)+pow(second_point.z-first_point.z,2));
}


std::ostream& operator<<(std::ostream& os, const Point3D& p){
    os<<"("<<p.get_x()<<","<<p.get_y()<<","<<p.z<<")";
    return os;
}
