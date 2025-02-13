#include <stdio.h>
#include "ponto.h"

int main(void){
    Ponto *p, *q;
    float d;

    p = pto_create(10,21);
    q = pto_create(7,25);

    d = pto_dist(p, q);
    printf("Distancia: %.2f\n", d);
    pto_free(p);
    pto_free(q);

    return 0;
}