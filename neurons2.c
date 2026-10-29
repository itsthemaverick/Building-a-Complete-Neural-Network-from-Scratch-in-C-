#include <stdio.h>
#include <math.h>

static float sigmoid(float z){

    return 1.0f/(1.0f+expl(-z));
}


int main(){

    // Weights to Get OR Gate 
    float wh0[2] = {20.0f,20.0f};
    float bh0 = -10.0f;

    // Weights to Get AND Gate 
    float wh1[2] = {20.0f,20.0f};
    float bh1 = -30.0f;

    float X[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    
    int s;

    for ( s = 0; s < 4; s++)
    {
        float z0 = (X[s][0]*wh0[0]+X[s][1]*wh0[1]) + bh0;
        float h0 = sigmoid(z0);

        float z1 = (X[s][0]*wh1[0]+X[s][1]*wh1[1]) + bh1;
        float h1 = sigmoid(z1);

        printf("x = (%.0f , %.0f) h0=%.4f h1=%.4f\n",X[s][0],X[s][1],h0,h1);

    }
    return 0;
    
}