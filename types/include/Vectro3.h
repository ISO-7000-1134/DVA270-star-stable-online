#include <FixedPoint.h>

#ifndef VECTOR3_H
#define VECTOR3_H

typedef struct vector3 { FixedPoint x, y, z; } Vector3;

Vector3 add(Vector3 a, Vector3 b);
Vector3 subtract(Vector3 a, Vector3 b);

FixedPoint dot(Vector3 a, Vector3 b);
Vector3 cross(Vector3 a, Vector3 b);

#endif