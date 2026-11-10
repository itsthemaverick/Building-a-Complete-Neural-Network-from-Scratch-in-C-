#include <stdio.h>
#include <math.h>



static float sigmiod(float z){
    return 1.0f / (1.0f + expf(-z));
}

typedef struct {
    float wh[2][2];
    float bh[2];
    float wo[2];
    float bo;
}Net;

static float forward( const Net *n, const float x[2],float h[2]){
    int i , j;

    for (i = 0; i < 2; i++){
        float z = n->bh[i];
        for ( j = 0; j < 2; j++)
        {
            z += n->wh[i][j] * x[j];
        }
        h[i] = sigmiod(z);
        
    }

    //

    {
        float z = n->bo;
        for ( i = 0; i < 2; i++)
        {
            z += n->wo *h[i];
        }
        return sigmiod(z);
        
    }
}


int main(){

    //

    Net net = {
        .wh = {{20,20},{20,20}},
        .bh = {-10,-30},
        .wo = {20,-20},
        .bo = -10
    };
}