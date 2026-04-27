#include <stdint.h>

#ifndef FIXED_POINT_H
#define FIXED_POINT_H

// Decimalpoint at 2^16
typedef int32_t FixedPoint;

FixedPoint add(FixedPoint a, FixedPoint b);
FixedPoint subtract(FixedPoint a, FixedPoint b);

FixedPoint multiply(FixedPoint a, FixedPoint b);
FixedPoint divide(FixedPoint a, FixedPoint b);

void printFixedPoint(FixedPoint num);
#endif