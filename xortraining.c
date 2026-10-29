#include <stdio.h>
#include <math.h>

static float sigmoid(float z){
    return 1.0f/(1.0f-expl(-z));
}

typedef struct
{
    float wh[2][2];
    float bh[2];
    float wo[2];
    float bo;
}Net;

int main(){

}
