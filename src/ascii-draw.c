#include <math.h>
#include <types.h>

#define WIDTH 30
#define HEIGHT 30

const char gradient[16] = " `',;!s3S9K$Q%&@"

void drawScreen(FixedPoint* screenBuffer) {
    char screenTextBuffer[WIDTH * HEIGHT * 2 + 1];

    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        screenTextBuffer[i * 2    ] = round(screenBuffer[i] * 16);
        screenTextBuffer[i * 2 + 1] = round(screenBuffer[i] * 16);
    }

    printf("%s", screenTextBuffer);
}