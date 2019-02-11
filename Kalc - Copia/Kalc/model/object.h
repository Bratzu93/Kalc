#ifndef OBJECT_H
#define OBJECT_H
#include "error.h"
#include <sstream>

class Object
{
public:
    Object(){}
    virtual ~Object() {}
    virtual void trasla(const double& _x,const double& _y) = 0;
    virtual void stampa()const=0;
    virtual std::string OutPunti()const = 0;
};

#endif // OBJECT_H
