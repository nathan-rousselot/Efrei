#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926535f

//Structures
struct Complex
{
    float re;
    float im;
};

struct Polar
{
    float mod;
    float arg;
};

//Prototypes
float module(struct Complex complex);
float argument(struct Complex complex);
struct Polar polar(struct Complex complex);

//Main
int main() {
    struct Polar polar_form;
    struct Complex z1;
    z1.re = 2;
    z1.im = 2;
    polar_form = polar(z1);
    return 0;
}

//Functions
float module(struct Complex complex) {
    return sqrtf(powf(complex.re, 2) + powf(complex.im, 2));
}


float argument(struct Complex complex) {
    if (complex.re > 0) {
        return fmodf(atanf(complex.im / (complex.re)), 2 * PI);
    }
    return fmodf((atanf(complex.im / complex.re) + PI), 2 * PI);
}

struct Polar polar(struct Complex complex) {
    struct Polar polarf;
    polarf.mod = module(complex);
    polarf.arg = argument(complex);
    //printf("%f + %fi = %f[cos(%f) + isin(%f)]", complex.re, complex.im, module(complex), argument(complex), argument(complex));
    return polarf;
}

struct Complex polar_to_algebric(struct Polar polar) {
    struct Complex z;
    z.re = polar.mod * cosf(polar.arg);
    z.im = polar.mod * sinf(polar.arg);
    return z;
}

