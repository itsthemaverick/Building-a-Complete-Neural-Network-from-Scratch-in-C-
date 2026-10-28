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

    float X[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    float T[4] = {0,0,0,1};

    


    Perceptron p = {.w = {1.0f,1.0f},.b = -1.5f};

    printf(" 0 & 0 = %.0f \n",foward(&p,0,0));
    
}