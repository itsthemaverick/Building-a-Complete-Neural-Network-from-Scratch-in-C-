#include <stdio.h>

typedef struct Perceptron
{
    float w[2];
    float b;
}Perceptron;


static float step(float z){
    return z >= 0.0f?1.0f:0.0f;
}

static float foward(Perceptron *p,float x0, float x1){
    float z = (x0*p->w[0]+x1*p->w[1])+p->b;
    return step(z);
}

int main(){

    Perceptron p = {.w = {1.0f,1.0f},.b = -1.5f};

    printf(" 0 & 0 = %.0f \n",foward(&p,0,0));
    printf(" 0 & 1 = %.0f \n",foward(&p,0,1));
    printf(" 1 & 0 = %.0f \n",foward(&p,1,0));
    printf(" 1 & 1 = %.0f \n",foward(&p,1,1));
}