#include <math.h>
#include <types.h>
#include <stdint.h>

#define WIDTH 30
#define HEIGHT 30

const char gradient[16] = " `',;!s3S9K$Q\u25&@"

void drawScreenBuffer(FixedPoint* screenBuffer) {
    char screenTextBuffer[WIDTH * HEIGHT * 2 + 1];

    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        screenTextBuffer[i * 2    ] = gradient[((screenBuffer[i] * 16) & (0xff << FIXED_POINT_DECIMAL_PLACE)) >> FIXED_POINT_DECIMAL_PLACE];
        screenTextBuffer[i * 2 + 1] = gradient[((screenBuffer[i] * 16) & (0xff << FIXED_POINT_DECIMAL_PLACE)) >> FIXED_POINT_DECIMAL_PLACE];
    }

    printf("%s", screenTextBuffer);
}

void drawLine(FixedPoint* screenBuffer, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, FixedPoint value) {
    uint32_t k; // fixed decimal point
    uint16_t x = x1;
    uint32_t y = y1; // fixed decimal point

    if (x1 == x2) {
        for (uint16_t y = y1; y > y2; y--)   
            screenBuffer[x + WIDTH * y] = value;
        for (; y < y2; y++)   
            screenBuffer[x + WIDTH * y] = value;
    } else {
        uint16_t x = x1;
        uint32_t y = y1 << 16;
        uint32_t k = ((y2 - y1) << 16) / (x2 - x1);
        for (; x > x2; x--) {
            screenBuffer[x + WIDTH * ((y & 0xffff0000) >> 16)] = value; // floor y
            y += k;
        }
        for (; x < x2; x++) {
            screenBuffer[x + WIDTH * ((y & 0xffff0000) >> 16)] = value; // floor y
            y += k;
        }
    } 

}

