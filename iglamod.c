/* iglamod.c - encode Igla AFSK */
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "igla.h"

#define DRATE 64000.0

static double rate = DRATE;

static void write_tone(double frequency, double duration)
{
    float v;
    double t;
    double chronon = 1.0 / rate;
    double length = duration - chronon;
    for(t = 0.0; t < length; t += chronon) {
        v = sin(2.0 * M_PI * frequency * t);
        fwrite(&v, sizeof(v), 1, stdout);
    }
}

int main(int argc, char **argv)
{
    int c;
    int bit;
    double frequency;

    rate = (argc > 1) ? strtod(argv[1], NULL) : DRATE;
    rate = (rate < 0) ? DRATE : rate;

    while((c = fgetc(stdin)) != EOF) {
        for(bit = 0; bit < 8; bit++) {
            if(c & (1 << bit))
                frequency = IGLA_MARK;
            else
                frequency = IGLA_SPACE;
            write_tone(frequency, 1.0 / IGLA_SPEED);
        }
    }

    return 0;
}
