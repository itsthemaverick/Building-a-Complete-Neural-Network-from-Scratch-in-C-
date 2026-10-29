#include <stdio.h>
#include <math.h>


static float sigmoid(float z){

        return 1.0f/(1.0f + expf(-z));
}

float w0 = 0.2f , w1 = 0.1f , b = -0.2f;

float X[4][2] = {{0,0},{0,1},{1,0},{1,1}};