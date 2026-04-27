#include <Vector3.h>

/// Adds two vectors
/// Returns sum
Vector3 add(Vector3 a, Vector3 b) {
    Vector3 sum;
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    sum.z = a.z + b.z;
    return sum;
}

/// Subtracts two vectors
/// Returns diffrence
Vector3 subtract(Vector3 a, Vector3 b) {
    Vector3 diffrence;
    diffrence.x = a.x - b.x;
    diffrence.y = a.y - b.y;
    diffrence.z = a.z - b.z;
    return diffrence;
}

/// Takes dot product of two vectors
/// Returns dot product
FixedPoint dot(Vector3 a, Vector3 b) {
    return = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

/// Takes cross product of two vectors
/// Returns cross product
Vector3 cross(Vector3 a, Vector3 b) {
    Vector3 cross;
    cross.x = a.y - b.z;
    cross.y = a.z - b.x;
    cross.z = a.x - b.y;
    return cross;
}