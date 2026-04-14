#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

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

    printf("\n");
    printf("uint32_t %s = {}");

    fclose(file);
    return 1;
}