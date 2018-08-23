#ifndef POINT3D_H
#define POINT3D_H
#include "Point2d.h"

class Point3D:public Point2D
{
private:
    double z;
public:

    Point3D(double _x=0, double _y=0, double _z=0);
    Point3D(const Point2D&);
    Point3D& operator=(const Point2D&);
    bool operator<(const Point3D&) const;
    bool operator>(const Point3D&) const;
    bool operator==(const Point3D&)const;
    bool operator!=(const Point3D&)const;
    Point3D& operator+(const Point3D&);
    Point3D& operator-(const Point3D&);
    Point3D& operator*(const double&);
    Point3D& operator/(const double&);


    friend std::ostream& operator<<(std::ostream& os, const Point3D& p);
    void set_z(const double& _z);
    double get_z()const;
    static double distanza(const Point3D& first_point, const Point3D& second_point);
    void stampa()const;
    void trasla_asseZ(const double& _z=0);
};

#endif // POINT3D_H
