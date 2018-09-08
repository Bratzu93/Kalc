#ifndef OBJECT_H
#define OBJECT_H
#include "error.h"

class Object
{
public:
    Object(){}
    virtual ~Object() {}
    virtual void trasla(const double& _x,const double& _y) = 0;
};

#endif // OBJECT_H
