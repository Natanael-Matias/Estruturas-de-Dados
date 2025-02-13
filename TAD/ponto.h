typedef struct ponto Ponto;

Ponto* pto_create(float x, float y);
void pto_free(Ponto* p);
void pto_acess(Ponto *p, float *x, float *y);
void pto_set(Ponto *p, float x, float y);
float pto_dist(Ponto *p1, Ponto *p2);