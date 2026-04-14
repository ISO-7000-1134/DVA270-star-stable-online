#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define FIXED_POINT_DECIMAL_PLACE 20

/// convert stl to asset

int main() {
    char fileName[] = "model.stl";
    
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 0;
    }

    uint8_t header[80];
    uint32_t numTriangles;
    float* triangles;

    fread_s(header, sizeof(uint8_t) * 80, sizeof(uint8_t), 80, file);
    fread_s(numTriangles, sizeof(uint32_t), sizeof(uint32_t), 1, file);

    triangles = (float*)malloc(sizeof(float) * numTriangles);
    if (triangles == NULL) {
        printf("Unable to open file.\n");
        fclose(file);
        return 0;
    }

    fread_s(header, sizeof(float) * numTriangles * 12, sizeof(float), numTriangles * 12, file);

    int i;
    for (i = 0; i < numTriangles * 12; i++) {
        double num = triangles[i];
        triangles[i] = (uint32_t)floor((1 << FIXED_POINT_DECIMAL_PLACE) * num)
    }

    printf("\n// Triangles\n");
    printf("Point3 model = { { %x, %x, %x },\n", triangles[0], triangles[1], triangles[2]);
    printf("                 { %x, %x, %x },\n", triangles[3], triangles[4], triangles[5]);
    printf("                 { %x, %x, %x },\n", triangles[6], triangles[7], triangles[8]);

    for (i = 1; i < numTriangles; i++) {
        printf("                 { %x, %x, %x },\n", triangles[    i * 12], triangles[1 + i * 12], triangles[2 + i * 12]);
        printf("                 { %x, %x, %x },\n", triangles[3 + i * 12], triangles[4 + i * 12], triangles[5 + i * 12]);
        printf("                 { %x, %x, %x },\n", triangles[6 + i * 12], triangles[7 + i * 12], triangles[8 + i * 12]);
    }
    
    printf("\n// Normals\n");
    printf("Point3 model_n = { { %x, %x, %x },\n", triangles[9], triangles[10], triangles[11]);
    for (i = 1; i < numTriangles; i++) {
        printf("                   { %x, %x, %x },\n", triangles[9 + i * 12], triangles[10 + i * 12], triangles[11 + i * 12]);
    }

    fclose(file);
    return 1;
}