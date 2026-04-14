#include <stdint.h>

#ifndef TYPES
#define TYPES

#define FIXED_POINT_DECIMAL_PLACE 20
typedef uint32_t FixedPoint
typedef struct Point { FixedPoint x,y } Point
typedef struct Point3 { FixedPoint x,y,z } Point3

#endif