#include <FixedPoint.h>
#include <stdio.h>

/// Adds two numbers
/// Returns sum
FixedPoint add(FixedPoint a, FixedPoint b) {
    return a + b;
}

/// Subtracts two numbers
/// Returns difference
FixedPoint subtract(FixedPoint a, FixedPoint b) {
    return a - b;
}

/// Multiplies two numbers
/// Returns product
FixedPoint multiply(FixedPoint a, FixedPoint b) {
    int64_t product = (int64_t)a * (int64_t)b;
    return ((product & 0x00007fffffff0000) >> 16) | ((product & 0x8000000000000000) >> 32);
}

/// Divides two numbers
/// Returns quotient
FixedPoint divide(FixedPoint a, FixedPoint b) {
    int64_t quotient = ((int64_t)a << 32) / (int64_t)b;
    return (quotient & 0xffffffff00000000) >> 32;
}

// Print function for current enviorment
static void print(const char* str) {
    printf(str);
}

/// Prints out a fixed point number
void printFixedPoint(FixedPoint num) {
    char str[64];
    snprintf(str, 64 * sizeof(char), "%f", (float)num / (1 << 16));
    print(str);
}